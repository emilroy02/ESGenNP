#ifndef ES_GENNP_THREAD_BASE_H
#define ES_GENNP_THREAD_BASE_H

#include "es_gennp_common.h"

#include <memory>
#include <thread>

class ESGenNPThreadBase
{
public:
    ESGenNPThreadBase ();
    virtual ~ESGenNPThreadBase ();

public:
    bool Create(void *pParam, int priority);
    void RequestExit();
    int  Wait();

protected:
    virtual void OnRun()=0;
    virtual void OnStartUp(){}
    virtual void OnExit(){}

private:

private:
     std::unique_ptr<std::thread>m_pThread;

private:
    /* No copy or assignment! */
    ESGenNPThreadBase (const ESGenNPThreadBase&); /* No implementation! */
    ESGenNPThreadBase& operator=(const ESGenNPThreadBase&); /* No implementation! */
};

#endif // ES_GENNP_THREAD_BASE_H
