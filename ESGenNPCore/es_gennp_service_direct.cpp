#include "es_gennp_service_direct.h"
#include "es_gennp_config_init_branding.h"

#include "es_gennp_event.h"
#include "es_gennp_event_source.h"
#include "es_gennp_module_client.h"
#include "es_gennp_module_server.h"

#include <memory>
#include <iostream>

#define GET_HANDLE(h,T,inst) std::shared_ptr<T> inst; \
                             { \
                                 ESGC_ERROR error = m_Library->GetHandle(h, inst); \
                                 if (error != ESGC_ERR_SUCCESS) \
                                 { \
                                   return error; \
                                 } \
                             }


ESGenNPServiceDirect::ESGenNPServiceDirect(const std::shared_ptr<ESGenNPLibrary> &library):
    m_Library(library)
{
}

ESGenNPServiceDirect::~ESGenNPServiceDirect()
{
    if( m_Library && m_Library->IsInitialized())
        m_Library->Uninitialize();
}

ESGC_ERROR ESGenNPServiceDirect::ESGCInit()
{
    std::cout << "--ESGenNPCore" << std::endl;
    std::cout << "--Date:" << __DATE__ << " Time:" << __TIME__ << std::endl;
    std::cout << "--Product Name:" << ESGenNPConfigInitBranding::GetBranding().ProductName() << std::endl;
    std::cout << "--Vendor Name:" << ESGenNPConfigInitBranding::GetBranding().VendorName() << std::endl;

    return m_Library->Initialize();
}

ESGC_ERROR ESGenNPServiceDirect::ESGCClose()
{
    return m_Library->Uninitialize();
}

ESGC_ERROR ESGenNPServiceDirect::ESGCRegisterEvent(ESGC_EVENTSRC_HANDLE hEventSrc, ESGC_EVENT_TYPE type, ESGC_EVENT_HANDLE *phEventOut)
{
    GET_HANDLE(hEventSrc,ESGenNPEventSource, eventSource)
    std::shared_ptr<ESGenNPEvent> event;
    ESGC_ERROR retError = eventSource->RegisterEvent(type, event);
    if(ESGC_ERR_SUCCESS != retError)
        return retError;

    return m_Library->OpenHandle(event, phEventOut);
}

ESGC_ERROR ESGenNPServiceDirect::ESGCEventGetData(ESGC_EVENT_HANDLE hEvent, void *pBuffer, size_t *piSize, uint64_t iTimeout)
{
    GET_HANDLE(hEvent,ESGenNPEvent, event)
    return event->GetData(pBuffer, piSize, iTimeout);
}

ESGC_ERROR ESGenNPServiceDirect::ESGCClientCreate(ESGC_CLIENT_HANDLE *phClientOut)
{
    std::shared_ptr<ESGenNPModuleClient> client = std::make_shared<ESGenNPModuleClient>();
    client->Init(); //Always init modules
    return m_Library->OpenHandle(client, phClientOut);
}

ESGC_ERROR ESGenNPServiceDirect::ESGCClientConnect(ESGC_CLIENT_HANDLE hClient, const std::string &ipAddress, const uint16_t port)
{
    GET_HANDLE(hClient,ESGenNPModuleClient, client)
    return client->Connect(ipAddress, port);
}

ESGC_ERROR ESGenNPServiceDirect::ESGCServerCreate(ESGC_SERVER_HANDLE *phServerOut)
{
    std::shared_ptr<ESGenNPModule> server = std::make_shared<ESGenNPModuleServer>();
    server->Init(); //Always init modules
    return m_Library->OpenHandle(server, phServerOut);
}

ESGC_ERROR ESGenNPServiceDirect::ESGCServerStart(ESGC_SERVER_HANDLE hServer)
{
    GET_HANDLE(hServer,ESGenNPModuleServer, server)
    return server->Start();
}

ESGC_ERROR ESGenNPServiceDirect::ESGCServerStop(ESGC_SERVER_HANDLE hServer)
{
    GET_HANDLE(hServer,ESGenNPModuleServer, server)
    return server->Stop();
}
