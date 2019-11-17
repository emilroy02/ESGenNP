#ifndef ES_GENNP_THREAD_H
#define ES_GENNP_THREAD_H

#include "es_gennp_common.h"
#include <thread>
#include <future>

class ESGenNPThread
{
public:
    ESGenNPThread();
//    virtual ESGenNPThread();

    bool Start();

    ESGenNPThread & operator=(ESGenNPThread && obj)
    {
        m_RequestExit = std::move(obj.m_RequestExit);
        m_IsExitRequested = std::move(obj.m_IsExitRequested);
        return *this;
    }

    void operator()(){Run();}

protected:
    virtual void Run() = 0;

private:
    std::promise<void> m_RequestExit;
    std::future<void> m_IsExitRequested;
};

#endif // ES_GENNP_THREAD_H
