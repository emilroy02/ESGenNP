#include "es_gennp_module_client.h"

#include "WinSock2.h" //TBD only temporary

ESGenNPModuleClient::ESGenNPModuleClient():
    ESGenNPModule(),
    m_pConnectSocket(NULL),
    m_pDiscoverySocket(NULL)
{
}

ESGenNPModuleClient::~ESGenNPModuleClient()
{
}

ESGC_ERROR ESGenNPModuleClient::Connect(const std::string &ipAddress, const uint16_t port)
{
    std::lock_guard<std::recursive_mutex> lock(GetLock());
    if(NULL == m_pConnectSocket)
        return ESGC_ERR_TBD;

    bool bRet = m_pConnectSocket->Connect(inet_addr(ipAddress.c_str()), port);
    if(false == bRet)
        return ESGC_ERR_ERROR;

    return ESGC_ERR_SUCCESS;
}

std::string ESGenNPModuleClient::GetID() const
{
    return "TEMP_CLIENT_ID";
}

void ESGenNPModuleClient::DoInit()
{
}

ESGC_ERROR ESGenNPModuleClient::DoOpen()
{
    m_pConnectSocket = std::make_shared<ESGenNPSocket>();

    bool bRet = m_pConnectSocket->Create(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(false == bRet)
        return false;

    return ESGC_ERR_SUCCESS;
}

ESGC_ERROR ESGenNPModuleClient::DoClose()
{
    m_pConnectSocket->Destroy();
    m_pConnectSocket = NULL;
    return ESGC_ERR_SUCCESS;
}

void ESGenNPModuleClient::DoMarkDead()
{
}
