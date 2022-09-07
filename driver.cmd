@echo off
title FLuffOS
color 02

set DRIVER="%cd%\bin\driver.exe"
set CONFIG="%cd%\config.cfg"

%DRIVER% %CONFIG% %*

pause