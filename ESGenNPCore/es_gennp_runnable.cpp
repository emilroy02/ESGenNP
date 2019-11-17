#include "es_gennp_runnable.h"

ESGenNPRunnable::ESGenNPRunnable()
{
    m_IsExitRequested = m_RequestExit.get_future();
}

ESGenNPRunnable::ESGenNPRunnable(ESGenNPRunnable&& obj)
{
    m_RequestExit = std::move(obj.m_RequestExit);
    m_IsExitRequested = std::move(obj.m_IsExitRequested);
}

ESGenNPRunnable::~ESGenNPRunnable()
{
    RequestExit();
}

void ESGenNPRunnable::RequestExit()
{
    m_RequestExit.set_value();
}

bool ESGenNPRunnable::IsExitRequested()
{
    if (m_IsExitRequested.wait_for(std::chrono::milliseconds(0)) == std::future_status::timeout)
        return false;

    return true;
}
