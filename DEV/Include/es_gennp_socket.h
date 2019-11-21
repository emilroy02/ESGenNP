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
    bool Create(int32_t af, int32_t type, int32_t protocol);
    bool Connect(uint32_t ipAddress, uint16_t port);
    bool Bind(uint32_t ipAddress, uint16_t port);
    void Destroy();

    ESGENNP_SOCKET Accept();//TBD add socket info???
    int32_t Listen(); //TBD add backlog parameter

private:
    std::shared_ptr<ESGenNPSocketController> m_pController;
    mutable std::mutex m_Mutex;
    ESGENNP_SOCKET m_hSocket;
};

#endif // ES_GENNP_SOCKET_H
