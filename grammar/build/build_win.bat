:: Run in Visual Studio compiler environment
@echo off
setlocal
SET PTH=%~dp0
SET GEN="leg.exe"
SET SRC=%PTH%\"..\src"
SET BIN=%PTH%\"..\bin"

:: Build parser
cd %SRC%
del grammar.c
%GEN% -o grammar.c grammar.peg

:: Build exe
cd %BIN%
cl.exe %SRC%\main.cpp /EHsc
endlocal