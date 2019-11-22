#ifndef ES_GENNP_SYNC_EVENT_H
#define ES_GENNP_SYNC_EVENT_H

#include "es_gennp_common.h"

#include <future>
#include <mutex>

template<typename T> class ESGenNPSyncEvent
{
public:
    ESGenNPSyncEvent();
    virtual ~ESGenNPSyncEvent();

    void SetValue(T &value);
    bool WaitForEventSet(T &value, uint64_t timeout=INFINITE);
    void SetCompleted(const bool value);
    bool WaitForEventSetCompleted();

private:
    std::promise<T> m_EventSetPromise;
    std::future<T> m_EventSetFuture;
    std::promise<bool> m_EventCompletedPromise;
    std::future<bool> m_EventCompletedFuture;
};

#endif // ES_GENNP_SYNC_EVENT_H
