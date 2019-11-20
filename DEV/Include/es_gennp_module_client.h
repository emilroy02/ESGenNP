#ifndef ES_GENNP_MODULE_CLIENT_H
#define ES_GENNP_MODULE_CLIENT_H

#include "es_gennp_common.h"
#include "es_gennp_module.h"
#include "es_gennp_socket.h"

#include <memory>

class ESGenNPModuleClient: public ESGenNPModule
{
public:
    ESGenNPModuleClient();
    virtual ~ESGenNPModuleClient();

public:
    virtual std::string GetID () const;

//    ESGC_ERROR UpdateServerList();
//    ESGC_ERROR ConnectToServer(std::string serverIP, uint16_t port, uint8_t *connectPacket);

protected:
    virtual ESGC_ERROR DoClose();
    virtual void DoMarkDead();
    virtual void DoInit();

private:
    std::shared_ptr<ESGenNPSocket> m_ServerDiscoverySocket;
};

#endif // ES_GENNP_MODULE_CLIENT_H
