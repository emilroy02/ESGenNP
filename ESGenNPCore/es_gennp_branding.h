#ifndef ES_GENNP_BRANDING_H
#define ES_GENNP_BRANDING_H

#include "es_gennp_common.h"

#include <string>

class ESGenNPBranding
{
public:
    virtual ~ESGenNPBranding () = 0;

    virtual std::string VendorID () const = 0;
    virtual std::string VendorName () const = 0;
    virtual std::string ProductID () const = 0;
    virtual std::string ProductName () const = 0;
    virtual std::string EnvVarLogName () const = 0;
    virtual std::string EnvvarLogLevel () const = 0;

    virtual uint64_t DefaultReceiveTimeout () const = 0;
    virtual uint64_t DefaultSendTimeout () const = 0;
};

inline ESGenNPBranding::~ESGenNPBranding () {}

#endif // ES_GENNP_BRANDING_H
