#include <iostream>
#include "CDecode.h"
#include "CRegister.h"

#pragma once

class CExecute
{
    public:
        CExecute() { }
        virtual ~CExecute() { }
};


class CT1ExecuteTinyUnit: public CExecute
{
    public:
        CT1ExecuteTinyUnit( CT1DecodeDirectFetch& decode,
                            C16RegisterFile& regs)
            : m_decode_unit(decode), m_regs(regs) { }
        virtual ~CT1ExecuteTinyUnit() { }

        bool do_execute();

    private:
        CT1DecodeDirectFetch& m_decode_unit;
        C16RegisterFile&      m_regs;
};
