:: Run in Visual Studio compiler environment with PEG on PATH (https://www.piumarta.com/software/peg/)
@echo off
setlocal
SET PTH=%~dp0
SET GEN="leg.exe"
SET SRC=%PTH%..\src\
SET BIN=%PTH%..\bin\

:: Build parser
cd %SRC%\core
del grammar.c
%GEN% -o grammar.c grammar.peg

:: Build exe
cd %SRC%
set INPUT=
for /R %%i in (*.cpp) do call set INPUT=%%INPUT%% %%i
cd %BIN%
cl.exe %INPUT% /EHsc
del %BIN%\*.obj
endlocal