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

ESGenNPSocket::~ESGenNPSocket()
{
}

bool ESGenNPSocket::Create(int32_t af, int32_t type, int32_t protocol)
{
    std::lock_guard<std::mutex> scopeLock(m_Mutex);
    if(NULL != m_hSocket)
        return false;

    m_hSocket = m_pController->Create(af, type, protocol);
    if(NULL == m_hSocket)
        return false;

    return true;
}

bool ESGenNPSocket::Bind(uint32_t ipAddress, uint16_t port)
{
    std::lock_guard<std::mutex> scopeLock(m_Mutex);

    if(NULL == m_hSocket)
        return false;

    bool bRet = m_pController->Bind(m_hSocket, ipAddress, port);
    if(false == bRet)
        return false;

    return true;
}

void ESGenNPSocket::Destroy()
{
    std::lock_guard<std::mutex> scopeLock(m_Mutex);

    if(NULL == m_hSocket)
        return;

    m_pController->Destroy(m_hSocket);
}
