#include <iostream>
#include "es_gennp_service_direct.h"
#include "es_gennp_config_init_branding.h"

#include "es_gennp_socket_message.h"

ESGenNPServiceDirect::ESGenNPServiceDirect()
{
}

ESGenNPServiceDirect::~ESGenNPServiceDirect()
{
}

ESGC_ERROR ESGenNPServiceDirect::ESGCInit()
{
    std::cout << "ESGCInit" << std::endl;
    std::cout << "Product Name: " << ESGenNPConfigInitBranding::GetBranding().ProductName() << std::endl;
    std::cout << "Vendor Name: " << ESGenNPConfigInitBranding::GetBranding().VendorName() << std::endl;

    ESGenNPSocketMessage *pSocket = new ESGenNPSocketMessage;
    bool bRet = pSocket->Connect(6, 0, 0);
    if(bRet)
        std::cout << "Socket Connect Successful!" << std::endl;
    else
        std::cout << "Socket Connect Failed!" << std::endl;
    return ESGC_ERR_SUCCESS;
}

ESGC_ERROR ESGenNPServiceDirect::ESGCClose()
{
    std::cout << "ESGCClose" << std::endl;
    return ESGC_ERR_SUCCESS;
}
