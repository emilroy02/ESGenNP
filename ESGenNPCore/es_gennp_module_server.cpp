#include "es_gennp_module_server.h"
#include "es_gennp_socket_stream_tcp.h"

ESGenNPModuleServer::ESGenNPModuleServer(bool bTCP):
    m_bTCP(bTCP)
{
}

ESGenNPModuleServer::~ESGenNPModuleServer()
{
}

std::string ESGenNPModuleServer::GetID () const
{
    return "TEMP_SERVER_ID";
}


ESGC_ERROR ESGenNPModuleServer::Start()
{
    std::lock_guard<std::mutex> lock(GetLock());
    if(NULL == m_TCPSocket)
        return ESGC_ERR_NOT_INITIALIZED;

    //TBD put in thread
    return ESGC_ERR_SUCCESS;
}

ESGC_ERROR ESGenNPModuleServer::Stop()
{
    std::lock_guard<std::mutex> scopeLock(GetLock());
    if(NULL == m_TCPSocket)
        return ESGC_ERR_NOT_INITIALIZED;

    return ESGC_ERR_SUCCESS;

}

void ESGenNPModuleServer::DoInit()
{
    m_TCPSocket = std::make_shared<ESGenNPSocketStreamTCP>();
}

ESGC_ERROR ESGenNPModuleServer::DoOpen()
{
    if(NULL == m_TCPSocket)
        return ESGC_ERR_NOT_INITIALIZED;

//    bool bRet = m_TCPSocket->Create();
//    if(false == bRet)
//        return ESGC_ERR_ERROR;

    return ESGC_ERR_SUCCESS;
}

ESGC_ERROR ESGenNPModuleServer::DoClose()
{
    if(NULL == m_TCPSocket)
        return ESGC_ERR_NOT_INITIALIZED;

    m_TCPSocket->Destroy();
    return ESGC_ERR_SUCCESS;
}

void ESGenNPModuleServer::DoMarkDead()
{
    m_TCPSocket = NULL;
}

