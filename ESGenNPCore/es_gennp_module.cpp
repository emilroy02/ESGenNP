#include "es_gennp_module.h"

ESGenNPModule::ESGenNPModule():
    ESGenNPHandle(),
    ESGenNPEventSource()
{
}

ESGenNPModule::~ESGenNPModule()
{
}

std::mutex &ESGenNPModule::GetLock()
{
    return m_Mutex;
}
