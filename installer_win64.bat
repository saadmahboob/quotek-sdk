@echo OFF

echo "Quotek SDK 2.1 Installer"
echo "========================"

mkdir "C:\Program Files\quotek\sdk"

xcopy doc "C:\Program Files\quotek\sdk\doc\" /e /y
xcopy include "C:\Program Files\quotek\sdk\include\" /e /y
xcopy lib\win64 "C:\Program Files\quotek\sdk\lib\" /e /y

xcopy samples "C:\Program Files\quotek\sdk\samples\" /e /y
xcopy tests "C:\Program Files\quotek\sdk\tests\" /e /y
xcopy helpers "C:\Program Files\quotek\sdk\helpers\" /e /y

xcopy curl\curl "C:\Program Files\quotek\sdk\include\curl\" /e /y
copy curl\libcurl.lib "C:\Program Files\quotek\sdk\lib\"
copy curl\libcurl.dll C:\Windows\System\

echo "Quotek SDK installed succesfully, press any key to continue.."
pause

