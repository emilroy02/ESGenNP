#include "es_gennp_runnable_socket.h"

ESGenNPRunnableSocket::ESGenNPRunnableSocket():
    ESGenNPSocket(),
    ESGenNPRunnable()
{
}

ESGenNPRunnableSocket::ESGenNPRunnableSocket(ESGENNP_SOCKET hSocket):
    ESGenNPSocket(hSocket),
    ESGenNPRunnable()
{
}

ESGenNPRunnableSocket::~ESGenNPRunnableSocket()
{
}

bool ESGenNPRunnableSocket::Create(int32_t af, int32_t type, int32_t protocol)
{
    ESSocketCreateParam param(af, type, protocol);
    m_CreateEvent.SetValue(param);
    return m_CreateEvent.WaitForEventSetCompleted();
}

bool ESGenNPRunnableSocket::Connect(uint32_t ipAddress, uint16_t port)
{
    ESSocketConnectBindParam param(ipAddress, port);
    m_ConnectEvent.SetValue(param);
    return m_ConnectEvent.WaitForEventSetCompleted();
}

bool ESGenNPRunnableSocket::Bind(uint32_t ipAddress, uint16_t port)
{
    ESSocketConnectBindParam param(ipAddress, port);
    m_BindEvent.SetValue(param);
    return m_BindEvent.WaitForEventSetCompleted();
}

void ESGenNPRunnableSocket::Run()
{
    while(true)
    {
        bool bRet = WaitForExitRequested(0);
        if(true == bRet)
            break;

        ESSocketCreateParam create;
        bRet = m_CreateEvent.WaitForEventSet(create,0);
        if(bRet)
        {
            bRet = ESGenNPSocket::Create(create.af, create.type, create.protocol);
            m_CreateEvent.SetCompleted(bRet);
        }

        ESSocketConnectBindParam connect;
        bRet = m_ConnectEvent.WaitForEventSet(connect,0);
        if(bRet)
        {
            bRet = ESGenNPSocket::Connect(connect.ipAddress, connect.port);
            m_ConnectEvent.SetCompleted(bRet);
        }

        ESSocketConnectBindParam bind;
        bRet = m_ConnectEvent.WaitForEventSet(bind,0);
        if(bRet)
        {
            bRet = ESGenNPSocket::Bind(bind.ipAddress, bind.port);
            m_ConnectEvent.SetCompleted(bRet);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
