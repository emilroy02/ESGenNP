#ifndef ES_GENNP_CONFIG_INIT_BRANDING_H
#define ES_GENNP_CONFIG_INIT_BRANDING_H

#include "es_gennp_common.h"
#include "es_gennp_branding.h"
#include "es_gennp_branding_default.h"
#include "es_gennp_config_init.h"

class ESGenNPConfigInitBranding: public ESGenNPConfigInit
{
public:
    ESGenNPConfigInitBranding ():m_InjectedBranding (NULL)
    {
    }

    virtual ~ESGenNPConfigInitBranding()
    {
    }

public:
    static ESGenNPConfigInitBranding *GetInstance()
    {
        static ESGenNPConfigInitBranding *pBranding = new ESGenNPConfigInitBranding ();
        return pBranding;
    }

    static const ESGenNPBranding &GetBranding ()
    {
        const ESGenNPBranding *injected_branding = ESGenNPConfigInitBranding::GetInstance()->GetInjectedBranding();
        if (injected_branding)
        {
            return *injected_branding;
        }

        static ESGenNPBrandingDefault default_branding;
        return default_branding;
    }

    virtual void StartupConfig (const std::shared_ptr<ESGenNPBranding> & brand)
    {
        m_InjectedBranding = brand;
    }

    const ESGenNPBranding *GetInjectedBranding () const
    {
        return m_InjectedBranding.get();
    }

private:
    std::shared_ptr<ESGenNPBranding> m_InjectedBranding;
};

#endif // ES_GENNP_CONFIG_INIT_BRANDING_H
