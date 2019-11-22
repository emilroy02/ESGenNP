#ifndef ES_GENNP_RUNNABLE_SOCKET_H
#define ES_GENNP_RUNNABLE_SOCKET_H

#include "es_gennp_runnable.h"
#include "es_gennp_socket.h"

#include "es_gennp_sync_event.h"

typedef struct ESSocketCreateParam_
{
    int32_t af;
    int32_t type;
    int32_t protocol;

    ESSocketCreateParam_():af(0),type(0), protocol(0){}
    ESSocketCreateParam_(int32_t af, int32_t type, int32_t protocol):
                         af(af),type(type), protocol(protocol){}
}ESSocketCreateParam;

typedef struct ESSocketConnectBindParam_
{
    int32_t ipAddress;
    uint16_t port;

    ESSocketConnectBindParam_():ipAddress(0),port(0){}
    ESSocketConnectBindParam_(int32_t ipAddress, uint16_t port):ipAddress(ipAddress),port(port){}
}ESSocketConnectBindParam;

class ESGenNPRunnableSocket:public ESGenNPSocket, public ESGenNPRunnable
{
public:
    ESGenNPRunnableSocket();
    ESGenNPRunnableSocket(ESGENNP_SOCKET hSocket);
    virtual ~ESGenNPRunnableSocket();

    virtual bool Create(int32_t af, int32_t type, int32_t protocol);
    virtual bool Connect(uint32_t ipAddress, uint16_t port);
    virtual bool Bind(uint32_t ipAddress, uint16_t port);
//    virtual void Destroy();

public:
    virtual void Run();

private:
    ESGenNPSyncEvent<ESSocketCreateParam> m_CreateEvent;
    ESGenNPSyncEvent<ESSocketConnectBindParam> m_ConnectEvent;
    ESGenNPSyncEvent<ESSocketConnectBindParam> m_BindEvent;
};

#endif // ES_GENNP_RUNNABLE_SOCKET_H
