#include "es_gennp_runnable_looped.h"

ESGenNPRunnableLooped::ESGenNPRunnableLooped(uint64_t timeoutMS):
    m_TimeoutMS(timeoutMS)
{
}

ESGenNPRunnableLooped::~ESGenNPRunnableLooped()
{
}

void ESGenNPRunnableLooped::Run()
{
    bool bRet = OnEntry();
    if(bRet)
    {
        while(true)
        {
            bool bRet = WaitForExitRequested(0);
            if(true == bRet)
                break;

            OnExecute();

            std::this_thread::sleep_for(std::chrono::milliseconds(m_TimeoutMS));
        }
    }
    OnExit();
}
