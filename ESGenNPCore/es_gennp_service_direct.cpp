#include "es_gennp_service_direct.h"
#include "es_gennp_config_init_branding.h"

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
