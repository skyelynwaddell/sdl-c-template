@echo off
echo Creating bin folder...
if not exist bin mkdir bin

echo Compiling...
gcc -Wall -std=c99 src\*.c src\system\*.c src\gameloop\*.c -IC:\dev\SDL2-2.30.8\include -LC:\dev\SDL2-2.30.8\lib\x64 -lSDL2main -lSDL2 -o bin\game.exe

if %errorlevel% neq 0 (
    echo Compilation failed!
    exit /b %errorlevel%
)

echo Compilation successful! Launching game...
start "" bin\game.exe
