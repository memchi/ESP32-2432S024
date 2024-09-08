@echo off
echo --------------------------------------------------------------------------------
echo %DATE% %TIME% %~nx0 for user: "%USERNAME%" on computer: "%COMPUTERNAME%" starting
echo --------------------------------------------------------------------------------
set WinMergeUExe=%ProgramFiles%\WinMerge\WinMergeU.exe
echo WinMergeUExe=%WinMergeUExe%

:: https://manual.winmerge.org/en/Command_line.html
start "WinMergeU.exe" "%WinMergeUExe%" /r /f "*.ino;*.pde;*.h;*.c;*.cpp" /wr "%CD%" "%USERPROFILE%\Documents\Arduino"

:END
echo --------------------------------------------------------------------------------
echo %DATE% %TIME% %~nx0 for user: "%USERNAME%" on computer: "%COMPUTERNAME%" ended
echo --------------------------------------------------------------------------------
::pause
