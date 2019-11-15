#include "es_gennp_service_direct.h"
#include "es_gennp_config_init_branding.h"

#include "es_gennp_module_client.h"

#include <memory>
#include <iostream>

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
    //TBD only temporary
    std::shared_ptr<ESGenNPModuleClient> client = std::make_shared<ESGenNPModuleClient>();;
    return m_Library->OpenHandle(client, phClientOut);
}
