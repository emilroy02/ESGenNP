#include "es_gennp_handle.h"

ESGenNPHandle::ESGenNPHandle():
    m_bIsOpen(false),
    m_bIsDead(false),
    m_bInited(false)
{
}

ESGenNPHandle::~ESGenNPHandle()
{
}

//std::string ESGenNPHandle::GetID() const
//{
//    return "";
//}

std::string ESGenNPHandle::GetSimpleID() const
{
    return GetID();
}

void ESGenNPHandle::Init()
{
    std::lock_guard<std::mutex> lock(m_Mutex);

    if(m_bInited)
        return;

    DoInit();
    m_bInited = true;
}

void ESGenNPHandle::MarkDead()
{
    std::lock_guard<std::mutex> lock(m_Mutex);
    m_bIsDead = false;
    DoMarkDead();
}

ESGC_ERROR ESGenNPHandle::Open()
{
    std::lock_guard<std::mutex> lock(m_Mutex);
    if(false == m_bInited)
        return ESGC_ERR_NOT_INITIALIZED;

    ESGC_ERROR retError = DoOpen();
    if (retError != ESGC_ERR_SUCCESS)
        return retError;

    m_bIsOpen = true;
    return ESGC_ERR_SUCCESS;
}

ESGC_ERROR ESGenNPHandle::Close()
{
    std::lock_guard<std::mutex> lock(m_Mutex);
    m_bIsOpen = false;
    return DoClose();
}

bool ESGenNPHandle::IsOpen() const
{
    std::lock_guard<std::mutex> lock(m_Mutex);
    return m_bIsOpen;
}

bool ESGenNPHandle::IsDead() const
{
    std::lock_guard<std::mutex> lock(m_Mutex);
    return m_bIsDead;
}

void ESGenNPHandle::Lock() const
{
    m_Mutex.lock();
}

void ESGenNPHandle::Unlock() const
{
    m_Mutex.unlock();
}

ESGC_ERROR ESGenNPHandle::DoOpen()
{
    return ESGC_ERR_SUCCESS;
}

ESGC_ERROR ESGenNPHandle::DoClose()
{
    return ESGC_ERR_SUCCESS;
}

void ESGenNPHandle::DoMarkDead()
{
}

void ESGenNPHandle::DoInit()
{
}
