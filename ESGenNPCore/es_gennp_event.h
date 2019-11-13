#ifndef ESGENNPEVENT_H
#define ESGENNPEVENT_H

#include "es_gennp_common.h"
#include "es_gennp_wrap.h"
#include <deque>
#include <condition_variable>

template<typename T> class ESGenNPEvent
{
public:
    ESGenNPEvent();
    virtual ~ESGenNPEvent();

    ESGC_ERROR GetData(void *buffer, size_t *psize, uint64_t timeout);
    ESGC_ERROR Kill();

protected:
    bool AddEventData(const T &eventData);

protected:
    virtual ESGC_ERROR DoGetData(const T &eventData, void *pBuffer, size_t *pBufferSize) = 0;

private:
    typedef std::deque<T> EventDataQueueType;
    EventDataQueueType m_EventDataQueue;

    std::condition_variable m_QueueNotEmpty;
    mutable std::mutex m_Mutex;
    mutable bool m_bAborted;
};

#endif // ESGENNPEVENT_H
