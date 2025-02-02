function show_props(obj, objName)
{
	var result = "";
	for (var i in obj) {
		if (obj[i] == null)
			result += objName + "." + i + " = null\n";
		else
			result += objName + "." + i + " = " + obj[i] + "\n";
	}
	return result;
}

var obj = new ActiveXObject("MultipleDispatchXO.SimpleObject.1");
var QDHelper = new ActiveXObject("QueryDispatchForScripts.QueryDispatchHelper.1");
//obj = QDHelper.QueryDispatch(obj, "7bd0ea72-a67b-4908-acde-b3bff166fc01");
obj = QDHelper.QueryDispatch(obj, "ISimpleObject2");

var s = obj.Method1("JS");
WScript.Echo(s);

var n = obj.Method2(123);
WScript.Echo(n);

var QDHelper = new ActiveXObject("QueryDispatchForScripts.QueryDispatchHelper.1");
var ISomeOtherInterface = QDHelper.QueryDispatch(obj, "7bd0ea72-a67b-4908-acde-b3bff166fc01");
//var ISomeOtherInterface = QDHelper.QueryDispatch(obj, "ISomeOtherInterface");
ISomeOtherInterface.SomeOtherMethod(); // ne semble pas fonctionner


