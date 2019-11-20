#include "es_gennp_thread.h"

ESGenNPThread::ESGenNPThread():
    m_pTask(NULL)
{
}

ESGenNPThread::~ESGenNPThread()
{
}

bool ESGenNPThread::Start(const std::shared_ptr<ESGenNPRunnable> &pTask)
{
    if(NULL == pTask)
        return false;

    m_pThread = std::make_unique<std::thread>(&ESGenNPRunnable::Run, pTask);
    if(NULL == m_pThread)
        return false;
//    m_pTask = pTask;
    return true;
}

//void ESGenNPThread::RequestExit()
//{
//    if(NULL == m_pTask)
//        return;

//    m_pTask->RequestExit();
//}

//bool ESGenNPThread::Wait(uint64_t timeOutMS)
//{
//    if(NULL == m_pTask)
//        return false;

//    return m_pTask->WaitForExit(timeOutMS);
//}
