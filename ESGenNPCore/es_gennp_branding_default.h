#ifndef ES_GENNP_BRANDING_DEFAULT_H
#define ES_GENNP_BRANDING_DEFAULT_H

#include "es_gennp_branding.h"

class ESGenNPBrandingDefault : public ESGenNPBranding
{
public:
    ESGenNPBrandingDefault ();
    virtual ~ESGenNPBrandingDefault();

    virtual std::string VendorID () const;
    virtual std::string VendorName () const;
    virtual std::string ProductID () const;
    virtual std::string ProductName () const;
    virtual std::string EnvVarLogName () const;
    virtual std::string EnvvarLogLevel () const;

    virtual uint64_t DefaultReceiveTimeout () const;
    virtual uint64_t DefaultSendTimeout () const;
};

#endif // ES_GENNP_BRANDING_DEFAULT_H
