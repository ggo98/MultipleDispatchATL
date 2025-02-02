Il semble que ce composant crée quelques memory leaks (pas à chaque fois qu'on l'utilise)
dans un script VBS ou JS 
(de tout façon l'interface retournée par QueryDispatch() ne semble pas utilisable en JS).
Pas de memory leak apparent dans le client C++ MFC, ni dans le client .NET. 
(pas d'explication trouvée)
