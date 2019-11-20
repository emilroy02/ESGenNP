#include "es_gennp_module_server.h"

#include "WinSock2.h" //TBD only temporary
#define DEFAULT_PORT 4711 //TBD only temporary

#include <iostream> //TBD only temporary

ESGenNPModuleServer::ESGenNPModuleServer():
    ESGenNPModule(),
    ESGenNPRunnableLooped(16),
    m_pClientSocket(NULL),
    m_pListenSocket(NULL)
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
    if(NULL != m_pThread)
        return ESGC_ERR_TBD;//TBD

    m_pThread = std::make_unique<std::thread>(&ESGenNPRunnableLooped::Run, this);
    return ESGC_ERR_SUCCESS;
}

ESGC_ERROR ESGenNPModuleServer::Stop()
{
    std::lock_guard<std::mutex> lock(GetLock());
    if(NULL == m_pThread)
        return ESGC_ERR_TBD;//TBD

    m_pListenSocket->Destroy();
    this->RequestExit();
    m_pThread->join();
    return ESGC_ERR_SUCCESS;
}

ESGC_ERROR ESGenNPModuleServer::DoOpen()
{
    if(NULL != m_pListenSocket)
        return ESGC_ERR_RESOURCE_IN_USE;

    m_pListenSocket = std::make_shared<ESGenNPSocket>();
    return ESGC_ERR_SUCCESS;
}

ESGC_ERROR ESGenNPModuleServer::DoClose()
{
    if(NULL == m_pListenSocket)
        return ESGC_ERR_RESOURCE_IN_USE;

    return ESGC_ERR_SUCCESS;
}

void ESGenNPModuleServer::DoMarkDead()
{
    m_pThread = NULL;
    m_pListenSocket = NULL;
}

bool ESGenNPModuleServer::OnEntry()
{
    std::cout << ">> OnEntry" << std::endl;

    bool bRet = m_pListenSocket->Create(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(false == bRet)
        return false;

    bRet = m_pListenSocket->Bind(INADDR_ANY, DEFAULT_PORT);
    if(false == bRet)
        return false;

    std::cout << "Server Listening..." << std::endl;

    int32_t iResult = m_pListenSocket->Listen();
    if(iResult == SOCKET_ERROR)
        return false;

    ESGENNP_SOCKET hClientSocket = m_pListenSocket->Accept();
    if(NULL == hClientSocket)
        return false;

    m_pClientSocket = std::make_shared<ESGenNPSocket>(hClientSocket);
    std::cout << "New Client Connected!" << std::endl;
    return true;
}

bool ESGenNPModuleServer::OnExecute()
{
    std::cout << ">> OnExecute" << std::endl;
    return true;
}

void ESGenNPModuleServer::OnExit()
{
    std::cout << ">> OnExit" << std::endl;
    //m_pTCPSocket
}

