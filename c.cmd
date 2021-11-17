@echo off
::  A.Zimmermann, arthur.zimmermann@hwr-berlin.de

if %1.==. goto ERR
set X=%~x1
set N=%~n1
set E=

::  set default extension as C
if %X%.==.        set X=.c
::  choose the compiler
if /I %X%.==.c.   set E=gcc
if /I %X%.==.cpp. set E=g++
if %E%.==. goto ERR

%E% %N%%X% -o %N%.exe
if NOT ERRORLEVEL 1 %N%.exe
goto FIN

:ERR
echo Parameter fehlt oder fehlerhaft

:FIN
set N=
del /q *.exe *.o 2 > nul

::::::::::::::: EOF
