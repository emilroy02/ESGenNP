#ifndef ES_GENNP_SOCKET_CONTROLLER_WIN_H
#define ES_GENNP_SOCKET_CONTROLLER_WIN_H

#include "es_gennp_common.h"
#include "es_gennp_socket_controller.h"

#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

class ESGenNPSocketControllerWin: public ESGenNPSocketController
{
public:
    ESGenNPSocketControllerWin();
    virtual ~ESGenNPSocketControllerWin();

    virtual bool Create(int32_t protocol);
    virtual bool Connect(uint64_t ipAddress, uint16_t port);

    virtual bool Bind(uint64_t ipAddress, uint16_t port);
    virtual bool SetSocketOpt(int32_t level, int32_t optName, const char *optValue, int32_t optLen);
    virtual bool GetSocketOpt(int32_t level, int32_t optName, const char *optValue, int32_t optLen);

    virtual bool Send(uint8_t *pData, size_t dataSize);
    virtual bool SendTo(uint8_t *pData, size_t dataSize, uint32_t ipAddress, uint16_t port);

private:
    SOCKET m_Socket;

};

#endif // ES_GENNP_SOCKET_CONTROLLER_WIN_H
