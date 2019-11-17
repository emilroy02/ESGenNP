#ifndef ES_GENNP_RUNNABLE_H
#define ES_GENNP_RUNNABLE_H

#include "es_gennp_common.h"
#include <future>

class ESGenNPRunnable
{
public:
    ESGenNPRunnable();
    ESGenNPRunnable(ESGenNPRunnable&& obj);
    virtual ~ESGenNPRunnable();

    virtual void RequestExit();
    bool IsExitRequested();

    ESGenNPRunnable & operator=(ESGenNPRunnable && obj)
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

#endif // ES_GENNP_RUNNABLE_H
