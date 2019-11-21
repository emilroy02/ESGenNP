#ifndef ES_GENNP_MODULE_CLIENT_H
#define ES_GENNP_MODULE_CLIENT_H

#include "es_gennp_common.h"
#include "es_gennp_module.h"
#include "es_gennp_socket.h"

#include <memory>
#include <thread>

class ESGenNPModuleClient: public ESGenNPModule
{
public:
    ESGenNPModuleClient();
    virtual ~ESGenNPModuleClient();

public:
    virtual std::string GetID () const;

    ESGC_ERROR Connect(const std::string &ipAddress, const uint16_t port);

protected:
    virtual ESGC_ERROR DoOpen();
    virtual ESGC_ERROR DoClose();
    virtual void DoMarkDead();
    virtual void DoInit();

private:
    std::shared_ptr<ESGenNPSocket> m_pDiscoverySocket;
    std::shared_ptr<ESGenNPSocket> m_pConnectSocket;
};

#endif // ES_GENNP_MODULE_CLIENT_H
