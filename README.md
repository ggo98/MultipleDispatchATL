# MultipleDispatchATL

## Points à voir pour l'ajout de la 2ème interface
### MultipleDispatchATL/MultipleDispatchATL.idl
...
```cpp
interface ISimpleObject2 : ISimpleObject
{
	//[id(1)] HRESULT Method2([in] int n, [out, retval] int* ret);
	// add-2nd-interface (changed the id because 1 is already used by ISimpleObject::Method1())
	[id(2)] HRESULT Method2([in] int n, [out, retval] int* ret); // id(2)
};
```
...
```cpp
	coclass SimpleObjectXO
	{
		//[default] interface ISimpleObject;
		// add-2nd-interface
		[default] interface ISimpleObject2;
		interface ISimpleObject;
	};
```
...
### SimpleOjectXO.h
...
```cpp
class ATL_NO_VTABLE CSimpleObjectXO :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSimpleObjectXO, &CLSID_SimpleObjectXO>,
	public ISupportErrorInfo,
	//public IDispatchImpl<ISimpleObject, &IID_ISimpleObject, &LIBID_MultipleDispatchATLLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	// add-2nd-interface
	public IDispatchImpl<ISimpleObject2, &IID_ISimpleObject2, &LIBID_MultipleDispatchATLLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
```
...
```cpp
BEGIN_COM_MAP(CSimpleObjectXO)
	COM_INTERFACE_ENTRY(ISimpleObject)

	//COM_INTERFACE_ENTRY(IDispatch)
	// add-2nd-interface
	COM_INTERFACE_ENTRY(ISimpleObject2)
	COM_INTERFACE_ENTRY2(IDispatch, ISimpleObject2)

	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

```
...
```cpp
	// add-2nd-interface
	STDMETHOD(Method2)(int n, int* ret);
```
...
## Divers
### MultipleDispatchATL/__VBS/test.VBS
mini script qui utilise SimpleObjectXO
### MFCClient/MFCClientDlg.cpp
...

```cpp
void CMFCClientDlg::OnBnClickedOk()
{
	try
	{
		//MultipleDispatchATLLib::ISimpleObjectPtr I(__uuidof(MultipleDispatchATLLib::SimpleObjectXO));
		// add-2nd-interface
		MultipleDispatchATLLib::ISimpleObject2Ptr I(__uuidof(MultipleDispatchATLLib::SimpleObjectXO));

		//for (int i = 0; i < 100000; i++)
		//	I->Method1("MFC");
		AfxMessageBox(I->Method1("MFC"));

		CString s;
		s.Format(L"%d", I->Method2(10));
		AfxMessageBox(s);
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description() + L";" + e.ErrorMessage());
	}

	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
}
```

### MFCClient/MFCClient.cpp
...

```cpp
static void SetOANoCache()
{
	typedef void (WINAPI* SETOANOCACHE)();
	HINSTANCE hDLL = LoadLibrary(_T("oleaut32.dll"));
	//if (!hDLL)
	//	throw Exception(“Unable to load oleaut32.dll”);

	SETOANOCACHE SetOaNoCachePtr = (SETOANOCACHE)GetProcAddress(hDLL, "SetOaNoCache");
	if (!SetOaNoCachePtr)
	{
		//throw Exception(“Unable to get SetOaNoCache”);
		int a = 123;
	}
	SetOaNoCachePtr();
}
```
...
```cpp
	// pour mettre en évidence plus rapidement les erreurs de gestion (mémoire) des chaine OLE (BSTR), genre plusieurs free sur le même BSTR
	/* par exemple: dans ISimpleObject::Method1(), faire 
	* *ret = bstrt;
	* alors qu'il faut faire
	* *ret = bstrt.Detach();
	*/
	SetOANoCache();
```
...
