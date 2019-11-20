#include "es_gennp_socket.h"

#ifdef _WIN32
#include "es_gennp_socket_controller_win.h"
#endif

ESGenNPSocket::ESGenNPSocket():
    m_pController(NULL),
    m_hSocket(NULL)
{
#ifdef _WIN32
    m_pController = std::make_shared<ESGenNPSocketControllerWin>();
#endif
}

ESGenNPSocket::ESGenNPSocket(ESGENNP_SOCKET hSocket):
    m_pController(NULL),
    m_hSocket(hSocket)
{
#ifdef _WIN32
    m_pController = std::make_shared<ESGenNPSocketControllerWin>();
#endif
}

ESGenNPSocket::~ESGenNPSocket()
{
}

bool ESGenNPSocket::Create(int32_t af, int32_t type, int32_t protocol)
{
    m_Mutex.lock();
    ESGENNP_SOCKET hSocket = m_hSocket;
    m_Mutex.unlock();

    if(NULL != hSocket)
        return false;

    hSocket = m_pController->Create(af, type, protocol);
    if(NULL == hSocket)
        return false;

    m_Mutex.lock();
    m_hSocket = hSocket;
    m_Mutex.unlock();
    return true;
}

bool ESGenNPSocket::Bind(uint32_t ipAddress, uint16_t port)
{
    m_Mutex.lock();
    ESGENNP_SOCKET hSocket = m_hSocket;
    m_Mutex.unlock();

    if(NULL == hSocket)
        return false;

    bool bRet = m_pController->Bind(hSocket, ipAddress, port);
    if(false == bRet)
        return false;

    return true;
}

void ESGenNPSocket::Destroy()
{
    m_Mutex.lock();
    ESGENNP_SOCKET hSocket = m_hSocket;
    m_Mutex.unlock();

    if(NULL == hSocket)
        return;

    m_pController->Destroy(hSocket);
}

ESGENNP_SOCKET ESGenNPSocket::Accept()
{
    m_Mutex.lock();
    ESGENNP_SOCKET hSocket = m_hSocket;
    m_Mutex.unlock();

    if(NULL == hSocket)
        return NULL;

    return m_pController->Accept(hSocket);
}

int32_t ESGenNPSocket::Listen()
{
    m_Mutex.lock();
    ESGENNP_SOCKET hSocket = m_hSocket;
    m_Mutex.unlock();

    if(NULL == hSocket)
        return -1;

    return m_pController->Listen(hSocket);
}
