#include "es_gennp_common.h"
#include "es_gennp_branding_restos.h"

ESGenNPBrandingRestos::~ESGenNPBrandingRestos ()
{
}

std::string ESGenNPBrandingRestos::VendorID () const
{
    return "ERVSTUDIOS";
}

std::string ESGenNPBrandingRestos::VendorName () const
{
    return "ERV Studios Inc.";
}

std::string ESGenNPBrandingRestos::ProductID () const
{
    return "RESTOS";
}

std::string ESGenNPBrandingRestos::ProductName () const
{
    return "resTOS";
}

std::string ESGenNPBrandingRestos::EnvVarLogName () const
{
    return "RESTOS_LOG_NAME";
}

std::string ESGenNPBrandingRestos::EnvvarLogLevel () const
{
    return "RESTOS_LOG_LEVEL";
}

uint64_t ESGenNPBrandingRestos::DefaultReceiveTimeout () const
{
    return 1000;
}

uint64_t ESGenNPBrandingRestos::DefaultSendTimeout () const
{
    return 1000;
}
