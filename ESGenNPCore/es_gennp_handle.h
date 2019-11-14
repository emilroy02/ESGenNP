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
    virtual std::string GetID() const;
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
    mutable std::mutex m_Mutex;

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

#endif // ES_GENNP_HANDLE_H
