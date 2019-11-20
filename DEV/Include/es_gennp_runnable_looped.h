#ifndef ES_GENNP_RUNNABLE_LOOPED_H
#define ES_GENNP_RUNNABLE_LOOPED_H

#include "es_gennp_common.h"
#include "es_gennp_runnable.h"

class ESGenNPRunnableLooped: public ESGenNPRunnable
{
public:
    ESGenNPRunnableLooped(uint64_t timeoutMS);
    virtual ~ESGenNPRunnableLooped();

public:
    virtual bool OnEntry() = 0;
    virtual bool OnExecute() = 0;
    virtual void OnExit() = 0;

public:
    virtual void Run();

private:
    uint64_t m_TimeoutMS;
};

#endif // ES_GENNP_RUNNABLE_LOOPED_H
