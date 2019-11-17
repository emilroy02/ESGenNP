#ifndef ES_GENNP_MODULE_SERVER_H
#define ES_GENNP_MODULE_SERVER_H

#include "es_gennp_common.h"
#include "es_gennp_module.h"
#include "es_gennp_socket.h"

#include <memory>

class ESGenNPModuleServer: public ESGenNPModule
{
public:
    ESGenNPModuleServer(bool bTCP/*TBD only Temporary*/);
    virtual ~ESGenNPModuleServer();

public:
    virtual std::string GetID () const;

    ESGC_ERROR Start();
    ESGC_ERROR Stop();

protected:
    virtual ESGC_ERROR DoOpen();
    virtual ESGC_ERROR DoClose();
    virtual void DoMarkDead();
    virtual void DoInit();

private:
    std::shared_ptr<ESGenNPSocket> m_TCPSocket;
    bool m_bTCP;

};

#endif // ES_GENNP_MODULE_SERVER_H
