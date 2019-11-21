#include "es_gennp_module.h"

ESGenNPModule::ESGenNPModule():
    ESGenNPHandle(),
    ESGenNPEventSource()
{
}

ESGenNPModule::~ESGenNPModule()
{
}

std::recursive_mutex &ESGenNPModule::GetLock()
{
    return m_Mutex;
}
