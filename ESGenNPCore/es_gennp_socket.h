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
    virtual ~ESGenNPSocket();

public:
    bool Create(int32_t af, int32_t type, int32_t protocol);
    bool Bind(uint32_t ipAddress, uint16_t port);
    void Destroy();

protected:
//    virtual void OnCreate();???


private:
    std::shared_ptr<ESGenNPSocketController> m_pController;
    mutable std::mutex m_Mutex;
    ESGENNP_SOCKET m_hSocket;
};

#endif // ES_GENNP_SOCKET_H
