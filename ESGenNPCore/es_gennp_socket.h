#ifndef ES_GENNP_SOCKET_H
#define ES_GENNP_SOCKET_H

#include "es_gennp_common.h"
#include "es_gennp_socket_controller.h"

#include <memory>
#include <mutex>

class ESGenNPSocket
{
public:
    ESGenNPSocket();
    ESGenNPSocket(ESGENNP_SOCKET hSocket);
    virtual ~ESGenNPSocket();

public:
    virtual bool Create(int32_t af, int32_t type, int32_t protocol);
    virtual bool Connect(uint32_t ipAddress, uint16_t port);
    virtual bool Bind(uint32_t ipAddress, uint16_t port);
    virtual void Destroy();

    virtual ESGENNP_SOCKET Accept();//TBD add socket info???
    virtual int32_t Listen(); //TBD add backlog parameter

private:
    std::shared_ptr<ESGenNPSocketController> m_pController;
    mutable std::recursive_mutex m_Mutex;
    ESGENNP_SOCKET m_hSocket;
};

#endif // ES_GENNP_SOCKET_H
