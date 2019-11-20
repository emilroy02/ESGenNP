#ifndef ES_GENNP_THREAD_H
#define ES_GENNP_THREAD_H

#include "es_gennp_common.h"
#include "es_gennp_runnable.h"
#include "es_gennp_branding.h"

#include <thread>
#include <memory>

class ESGenNPThread
{
public:
    ESGenNPThread();
    virtual ~ESGenNPThread();

    bool Start(const std::shared_ptr<ESGenNPRunnable> &task);
//    bool Start(const std::shared_ptr<ESGenNPRunnable> &task);
//    void RequestExit();
//    bool Wait(uint64_t timeOut);

private:
    std::shared_ptr<ESGenNPRunnable> m_pTask;
    std::unique_ptr<std::thread> m_pThread;
};

#endif // ES_GENNP_THREAD_H
