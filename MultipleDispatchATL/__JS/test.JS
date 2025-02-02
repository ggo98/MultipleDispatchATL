var obj = new ActiveXObject("MultipleDispatchXO.SimpleObject.1");
//var QDHelper = new ActiveXObject("QueryDispatchForScripts.QueryDispatchHelper.1");
//obj = QDHelper.QueryDispatch(obj, "ISimpleObject2");

var s = obj.Method1("JS");
WScript.Echo(s);

var n = obj.Method2(123);
WScript.Echo(n);

var QDHelper = new ActiveXObject("QueryDispatchForScripts.QueryDispatchHelper.1");
//var ISomeOtherInterface = QDHelper.QueryDispatch(obj, "7bd0ea72-a67b-4908-acde-b3bff166fc01");
var ISomeOtherInterface = QDHelper.QueryDispatch(obj, "ISomeOtherInterface");

// �a appelle la Method2() qui est dans l'interface ISimpleObject
// => en fait en javascript, on peut apparemment pas obtenir un autre IDispatch
// que celui par d�faut, en tout cas pas "facilement".
// (�a marche en VBS)
// une solution pour JS possiblement est d'avoir une interface Dispatch 
// qui contient toutes les m�thodes dont on a besoin.
// mais �a semble lourd car il faut impl�menter soi-m�me IDispatch apparemment...
// (FIN des tests avec jscript).
var n = ISomeOtherInterface.Method2(33);
WScript.Echo(n);

// comme en fait on a un ISimpleObject2, l'appel au m�thodes SomeOtherMethodX() ne fonctionne forc�ment pas.
//ISomeOtherInterface.SomeOtherMethod(); // ne semble pas fonctionner
var s = ISomeOtherInterface.SomeOtherMethod2("js"); // ne semble pas fonctionner
WScript.Echo(s);


