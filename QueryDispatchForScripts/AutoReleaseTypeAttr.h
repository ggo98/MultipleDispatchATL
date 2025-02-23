#pragma once
class AutoReleaseTypeAttr
{
private:
    ITypeInfo* m_pTypeInfo;
    TYPEATTR* m_pTypeAttr;

public:
    AutoReleaseTypeAttr(ITypeInfo *pTypeInfo, TYPEATTR* pTypeAttr);
    ~AutoReleaseTypeAttr();
};

