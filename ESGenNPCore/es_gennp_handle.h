#ifndef ES_GENNP_HANDLE_H
#define ES_GENNP_HANDLE_H

#include "es_gennp_common.h"
#include "es_gennp_wrap.h"

#include <string>
#include <mutex>

class ESGenNPHandle
{
public:
    ESGenNPHandle();
    virtual ~ESGenNPHandle()=0;

public:
    virtual std::string GetID() const = 0;
    virtual std::string GetSimpleID() const;

    void MarkDead();
    bool IsOpen() const;
    bool IsDead() const;

    void Lock() const;
    void Unlock() const;
    void PostConstruct();

protected:
    virtual ESGC_ERROR DoOpen();
    virtual ESGC_ERROR DoClose();
    virtual void DoMarkDead();
    virtual void DoPostConstruct();

private:
    ESGenNPHandle (const ESGenNPHandle&);
    ESGenNPHandle& operator=(const ESGenNPHandle&);

private:
    mutable std::mutex m_Mutex;
    bool m_bIsOpen;
    bool m_bIsDead;
    bool m_bInited;
};

#endif // ES_GENNP_HANDLE_H
