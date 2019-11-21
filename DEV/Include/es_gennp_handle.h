#ifndef ES_GENNP_HANDLE_H
#define ES_GENNP_HANDLE_H

#include "es_gennp_common.h"
#include "es_gennp_wrap.h"

#include <string>
#include <mutex>
#include <memory>

class ESGenNPHandle
{
public:
    ESGenNPHandle();
    virtual ~ESGenNPHandle()=0;

public:
    virtual std::string GetID() const=0;
    virtual std::string GetSimpleID() const;

    void Init();

    void MarkDead();
    bool IsOpen() const;
    bool IsDead() const;

    void Lock() const;
    void Unlock() const;

protected:
    virtual ESGC_ERROR DoOpen();
    virtual ESGC_ERROR DoClose();
    virtual void DoMarkDead();
    virtual void DoInit();

protected:
    mutable std::recursive_mutex m_Mutex;

private:
    ESGenNPHandle (const ESGenNPHandle&);
    ESGenNPHandle& operator=(const ESGenNPHandle&);

private:
    ESGC_ERROR Open ();
    ESGC_ERROR Close ();
    friend class ESGenNPLibrary;

private:
    bool m_bIsOpen;
    bool m_bIsDead;
    bool m_bInited;
};

typedef void* ESGENNP_HANDLE;

static inline ESGENNP_HANDLE PointerToHandle(const std::shared_ptr<ESGenNPHandle> &p)
{
    return reinterpret_cast<ESGENNP_HANDLE>(p.get());
}

static inline ESGENNP_HANDLE PointerToHandle(ESGenNPHandle *p)
{
    return reinterpret_cast<ESGENNP_HANDLE>(p);
}

#endif // ES_GENNP_HANDLE_H
