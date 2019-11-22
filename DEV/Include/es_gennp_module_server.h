#ifndef ES_GENNP_MODULE_SERVER_H
#define ES_GENNP_MODULE_SERVER_H

#include "es_gennp_common.h"
#include "es_gennp_module.h"

#include <memory>
#include <thread>

class ESGenNPRunnableSocket;
class ESGenNPModuleServer: public ESGenNPModule
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

private:
    std::shared_ptr<ESGenNPRunnableSocket> m_pClientSocket;
    std::shared_ptr<ESGenNPRunnableSocket> m_pListenSocket;
    std::shared_ptr<ESGenNPEventServerClientConnected> m_pEventClientConnected;
    std::unique_ptr<std::thread> m_pThread;
};

//class ESGenNPModuleServer: public ESGenNPModule, public ESGenNPRunnableLooped
//{
//public:
//    ESGenNPModuleServer();
//    virtual ~ESGenNPModuleServer();

//    ESGC_ERROR Start();
//    ESGC_ERROR Stop();

//public:
//    virtual std::string GetID () const;

//protected:
//    //ESGenNPModule interface
//    virtual void DoInit();
//    virtual ESGC_ERROR DoOpen();
//    virtual ESGC_ERROR DoClose();
//    virtual void DoMarkDead();
//    //End ESGenNPModule interface

//    //ESGenNPRunnableLooped interface
//    virtual bool OnEntry();
//    virtual bool OnExecute();
//    virtual void OnExit();
//    //End ESGenNPRunnableLooped interface

//private:
//    std::shared_ptr<ESGenNPSocket> m_pClientSocket;
//    std::shared_ptr<ESGenNPSocket> m_pListenSocket;
//    std::unique_ptr<std::thread> m_pThread;

//    std::shared_ptr<ESGenNPEventServerClientConnected> m_pEventClientConnected;
//};

#endif // ES_GENNP_MODULE_SERVER_H
