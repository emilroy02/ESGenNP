#include "es_gennp_socket_controller_win.h"

ESGenNPSocketControllerWin::ESGenNPSocketControllerWin():
    m_Socket(INVALID_SOCKET)
{
    WSADATA wsaData;
    int ret = WSAStartup(MAKEWORD(2,2), &wsaData);
}

ESGenNPSocketControllerWin::~ESGenNPSocketControllerWin()
{
}

bool ESGenNPSocketControllerWin::Create(int32_t protocol)
{
    if(INVALID_SOCKET != m_Socket)
        return false;

    m_Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(m_Socket == INVALID_SOCKET)
        return false;

    return true;
}

bool ESGenNPSocketControllerWin::Connect(uint64_t ipAddress, uint16_t port)
{
    if(INVALID_SOCKET == m_Socket)
        return false;

    sockaddr_in TargetAddress;
    TargetAddress.sin_family = AF_INET;
    TargetAddress.sin_port = htons(port);
    TargetAddress.sin_addr.S_un.S_addr	= inet_addr("127.0.0.1");

    int error = bind(m_Socket, (struct sockaddr *)&TargetAddress, sizeof(TargetAddress));
    if (SOCKET_ERROR == error)
        return false;

    return true;
}

void ESGenNPSocketControllerWin::Destroy()
{
    if(INVALID_SOCKET != m_Socket)
        return;

    //TBD add traces
    shutdown(m_Socket, SD_BOTH);
    closesocket(m_Socket);

    m_Socket = INVALID_SOCKET;
}

bool ESGenNPSocketControllerWin::Bind(uint64_t ipAddress, uint16_t port)
{
    return false;
}

bool ESGenNPSocketControllerWin::SetSocketOpt(int32_t level, int32_t optName, const char *optValue, int32_t optLen)
{
    return false;
}

bool ESGenNPSocketControllerWin::GetSocketOpt(int32_t level, int32_t optName, const char *optValue, int32_t optLen)
{
    return false;
}


bool ESGenNPSocketControllerWin::SendTo(uint8_t *pData, size_t dataSize, uint32_t ipAddress, uint16_t port)
{
    return false;
}

bool ESGenNPSocketControllerWin::Send(uint8_t *pData, size_t dataSize)
{
    char *pSendPositionCurrent = (char *)pData;
    size_t countByteSent = 0;

    while(countByteSent < dataSize)
    {
        size_t countByteSentPartial = send(m_Socket, pSendPositionCurrent, dataSize - countByteSent, 0);
        if (SOCKET_ERROR == countByteSentPartial)
            return false;

        if(0 == countByteSentPartial)
            return false;

        countByteSent += countByteSentPartial;
        pSendPositionCurrent += countByteSentPartial;
    }

    return true;
}
