@echo off
::  A.Zimmermann, arthur.zimmermann@hwr-berlin.de

REM Laufwerk ermitteln
set LW=%~d0
set AZ_PATH=%LW%\Software\GCCtdm\bin

REM Suchpfad für BS einstellen
set PATH=%AZ_PATH%;%PATH%

REM Umlaute
chcp 1252
REM chcp 65001

REM Eingabeaufforderung
prompt $_$_$D      $T      $P $_$Q$G 

REM Beenden
doskey x=exit

gcc --version
g++ --version

REM =========================
