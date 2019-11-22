#ifndef ES_GENNP_SOCKET_THREADED_H
#define ES_GENNP_SOCKET_THREADED_H

#include "es_gennp_common.h"
#include "es_gennp_socket.h"
#include "es_gennp_runnable.h"

#include "es_gennp_sync_event.h"
#include <thread>

typedef struct ESSocketCreateParam_
{
    int32_t af;
    int32_t type;
    int32_t protocol;

    ESSocketCreateParam_():af(0),type(0), protocol(0){}
    ESSocketCreateParam_(int32_t af, int32_t type, int32_t protocol):
                         af(af),type(type), protocol(protocol){}
} ESSocketCreateParam;

class ESGenNPSocketThreaded: public ESGenNPSocket, public ESGenNPRunnable
{
public:
    ESGenNPSocketThreaded();
    ESGenNPSocketThreaded(ESGENNP_SOCKET hSocket);
    virtual ~ESGenNPSocketThreaded();

    virtual bool Create(int32_t af, int32_t type, int32_t protocol);
//    virtual bool Connect(uint32_t ipAddress, uint16_t port);
//    virtual void Destroy();

public:
    virtual void Run();

private:
    ESGenNPSyncEvent<ESSocketCreateParam> m_CreateEvent;
    std::unique_ptr<std::thread> m_pThread;
};

#endif // ES_GENNP_SOCKET_THREADED_H
