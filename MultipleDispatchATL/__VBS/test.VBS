Set obj = CreateObject("MultipleDispatchXO.SimpleObject.1")
MsgBox obj.Method1("VBS")
' add-2nd-interface
MsgBox obj.Method2(3)

' add-3rd-interface
' SomeOtherMethod() in ISomeOherInterface is not accessible directly in VBS
' Additional code is required to be able to access ISomeOherInterface (not implement yet)
'obj.SomeOtherMethod()

