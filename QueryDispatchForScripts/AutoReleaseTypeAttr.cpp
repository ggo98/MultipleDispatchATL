#include "pch.h"
#include "AutoReleaseTypeAttr.h"

AutoReleaseTypeAttr::AutoReleaseTypeAttr(ITypeInfo* pTypeInfo, TYPEATTR* pTypeAttr)
{
    m_pTypeInfo = pTypeInfo;
    m_pTypeAttr = pTypeAttr;
}

AutoReleaseTypeAttr::~AutoReleaseTypeAttr()
{
    m_pTypeInfo->ReleaseTypeAttr(m_pTypeAttr);
}

