MsgBox "start"

Set obj = CreateObject("MultipleDispatchXO.SimpleObject.1")
MsgBox obj.Method1("VBS")
' add-2nd-interface
MsgBox obj.Method2(3)
'WSCRIPT.QUIT

' add-3rd-interface
' SomeOtherMethod() in ISomeOherInterface is not accessible directly in VBS
' Additional code is required to be able to access ISomeOherInterface (not implement yet)
'obj.SomeOtherMethod()

' add-vbs-support-for-any-IDispatch
' (now we can access ISomeOherInterface with QDHelper)
for i = 1 to 1
    Set QDHelper = CreateObject("QueryDispatchForScripts.QueryDispatchHelper.1")

    'Set ISomeOtherInterface = QDHelper.QueryDispatch(obj, "7bd0ea72-a67b-4908-acde-b3bff166fc01")
    Set ISomeOtherInterface = QDHelper.QueryDispatch(obj, "ISomeOtherInterface")
    ISomeOtherInterface.SomeOtherMethod
    Set ISomeOtherInterface = Nothing
    Set QDHelper = Nothing
next 

Set ISomeOtherInterface = Nothing
Set QDHelper = Nothing
Set obj = Nothing
MsgBox "end of script"

