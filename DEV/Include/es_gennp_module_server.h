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
    virtual void DoInit();
    virtual ESGC_ERROR DoOpen();
    virtual ESGC_ERROR DoClose();
    virtual void DoMarkDead();
    //End ESGenNPModule interface

    //ESGenNPRunnableLooped interface
    virtual bool OnEntry();
    virtual bool OnExecute();
    virtual void OnExit();
    //End ESGenNPRunnableLooped interface

//private:
//    void _start();
//    void _stop();

private:
    std::shared_ptr<ESGenNPSocket> m_pClientSocket;
    std::shared_ptr<ESGenNPSocket> m_pListenSocket;
    std::unique_ptr<std::thread> m_pThread;

    std::shared_ptr<ESGenNPEventServerClientConnected> m_pEventClientConnected;
};

#endif // ES_GENNP_MODULE_SERVER_H
