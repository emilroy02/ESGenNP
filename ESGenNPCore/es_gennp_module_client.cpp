#include "es_gennp_module_client.h"

ESGenNPModuleClient::ESGenNPModuleClient():
    ESGenNPModule()
{
}

ESGenNPModuleClient::~ESGenNPModuleClient()
{
}

std::string ESGenNPModuleClient::GetID() const
{
    return "TEMP_CLIENT_ID";
}

ESGC_ERROR ESGenNPModuleClient::DoClose()
{
    return ESGC_ERR_SUCCESS;
}

void ESGenNPModuleClient::DoMarkDead()
{
}

void ESGenNPModuleClient::DoInit()
{
}
