:: ---------------------------------------------------------------------------------------
:: http://astyle.sourceforge.net/astyle.html
:: ---------------------------------------------------------------------------------------
set AStyleExe=%~dp0AStyle\AStyle.exe
set AStyleConfigTxt=%~dp0AStyle\AStyleConfig.txt

%AStyleExe% --version

%AStyleExe% --options=%AStyleConfigTxt% --recursive %~dp0..\*.ino
%AStyleExe% --options=%AStyleConfigTxt% --recursive %~dp0..\*.pde
%AStyleExe% --options=%AStyleConfigTxt% --recursive %~dp0..\*.h
%AStyleExe% --options=%AStyleConfigTxt% --recursive %~dp0..\*.c
%AStyleExe% --options=%AStyleConfigTxt% --recursive %~dp0..\*.cpp

:: pause