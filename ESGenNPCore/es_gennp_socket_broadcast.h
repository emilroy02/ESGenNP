#ifndef ES_GENNP_SOCKET_BROADCAST_H
#define ES_GENNP_SOCKET_BROADCAST_H

#include "es_gennp_common.h"
#include "es_gennp_socket.h"

class ESGenNPSocketBroadcast:public ESGenNPSocket
{
public:
    ESGenNPSocketBroadcast();
    virtual ~ESGenNPSocketBroadcast();

    bool CreateBind(uint32_t ipAddress, uint16_t port);
//    bool SetRouteEnable(bool bEnable); //TBD
//    bool SetTLLValue(bool bEnable);

private:
};

#endif // ES_GENNP_SOCKET_BROADCAST_H
