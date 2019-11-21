#include "es_gennp_module_server.h"

#include "WinSock2.h" //TBD only temporary
#define DEFAULT_PORT 4711 //TBD only temporary

#include <iostream> //TBD only temporary

ESGenNPModuleServer::ESGenNPModuleServer():
    ESGenNPModule(),
    ESGenNPRunnableLooped(16),
    m_pClientSocket(NULL),
    m_pListenSocket(NULL),
    m_pEventClientConnected(NULL)
{
}

ESGenNPModuleServer::~ESGenNPModuleServer()
{
    Stop();
}

std::string ESGenNPModuleServer::GetID () const
{
    return "TEMP_SERVER_ID";
}

ESGC_ERROR ESGenNPModuleServer::Start()
{
    std::lock_guard<std::recursive_mutex> lock(GetLock());
    if(NULL != m_pThread)
        return ESGC_ERR_TBD;//TBD

    m_pThread = std::make_unique<std::thread>(&ESGenNPRunnableLooped::Run, this);
    return ESGC_ERR_SUCCESS;
}

ESGC_ERROR ESGenNPModuleServer::Stop()
{
    std::lock_guard<std::recursive_mutex> lock(GetLock());
    if(NULL == m_pThread)
        return ESGC_ERR_TBD;//TBD

    m_pListenSocket->Destroy();
    this->RequestExit();
    m_pThread->join();
    return ESGC_ERR_SUCCESS;
}

void ESGenNPModuleServer::DoInit()
{
    m_pEventClientConnected = std::make_shared<ESGenNPEventServerClientConnected>();
    m_pEventClientConnected->Init();
    AddSupportedEvent(m_pEventClientConnected);
}

ESGC_ERROR ESGenNPModuleServer::DoOpen()
{
    m_pListenSocket = std::make_shared<ESGenNPSocket>();
    return ESGC_ERR_SUCCESS;
}

ESGC_ERROR ESGenNPModuleServer::DoClose()
{
    Stop();
    m_pThread = NULL;
    m_pListenSocket = NULL;
    return ESGC_ERR_SUCCESS;
}

void ESGenNPModuleServer::DoMarkDead()
{
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

    std::cout << "Before Accept!" << std::endl;
    ESGENNP_SOCKET hClientSocket = m_pListenSocket->Accept();
    std::cout << "After Accept!" << std::endl;
    if(NULL == hClientSocket)
        return false;

    std::cout << "New Client Connected!" << std::endl;
    m_pEventClientConnected->AddClientConnectedEvent("Temporary Client ID OK????");
    m_pClientSocket = std::make_shared<ESGenNPSocket>(hClientSocket);

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

//void ESGenNPModuleServer::_start()
//{
//    m_pThread = std::make_unique<std::thread>(&ESGenNPRunnableLooped::Run, this);
//}

//void ESGenNPModuleServer::_stop()
//{
//    m_pListenSocket->Destroy();
//    this->RequestExit();
//    m_pThread->join();
//}

