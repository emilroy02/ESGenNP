#ifndef ES_GENNP_LIBRARY_H
#define ES_GENNP_LIBRARY_H

#include "es_gennp_common.h"
#include "es_gennp_wrap.h"

class ESGenNPLibrary
{
public:
    ESGenNPLibrary();
    virtual ~ESGenNPLibrary();

public:
    //TBD add getinfo
    ESGC_ERROR Initialize();
    ESGC_ERROR Uninitialize();

private:
    ESGenNPLibrary (const ESGenNPLibrary&);
    ESGenNPLibrary& operator=(const ESGenNPLibrary&);
};

#endif // ES_GENNP_LIBRARY_H
