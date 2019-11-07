#ifndef ES_GENNP_SOCKET_MESSAGE_H
#define ES_GENNP_SOCKET_MESSAGE_H

#include "es_gennp_common.h"
#include "es_gennp_socket.h"

class ESGenNPSocketMessage: public ESGenNPSocket
{
public:
    ESGenNPSocketMessage();
    virtual ~ESGenNPSocketMessage();

    bool Connect(int protocol, uint64_t ipAddress, uint16_t port);

};

#endif // ES_GENNP_SOCKET_MESSAGE_H
