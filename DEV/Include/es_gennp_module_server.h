#ifndef ES_GENNP_MODULE_SERVER_H
#define ES_GENNP_MODULE_SERVER_H

#include "es_gennp_common.h"
#include "es_gennp_module.h"
#include "es_gennp_runnable_looped.h"
#include "es_gennp_socket.h"

#include <memory>
#include <thread>

class ESGenNPModuleServer: public ESGenNPModule, public ESGenNPRunnableLooped
{
public:
    ESGenNPModuleServer();
    virtual ~ESGenNPModuleServer();

    ESGC_ERROR Start();
    ESGC_ERROR Stop();

public:
    virtual std::string GetID () const;

protected:
    //ESGenNPModule interface
    virtual ESGC_ERROR DoOpen();
    virtual ESGC_ERROR DoClose();
    virtual void DoMarkDead();
//    virtual void DoInit();
    //End ESGenNPModule interface

    //ESGenNPRunnableLooped interface
    virtual bool OnEntry();
    virtual bool OnExecute();
    virtual void OnExit();
    //End ESGenNPRunnableLooped interface

private:
    std::shared_ptr<ESGenNPSocket> m_pClientSocket;
    std::shared_ptr<ESGenNPSocket> m_pListenSocket;
    std::unique_ptr<std::thread> m_pThread;
};

#endif // ES_GENNP_MODULE_SERVER_H
