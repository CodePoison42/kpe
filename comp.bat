g++ src/*.cpp include/KPE/*.cpp -o main.exe -O2 -g -std=c++17 -Iinclude/ -Iinclude/KPE/include -Llibs/ -lraylib -lopengl32 -lgdi32 -lwinmm -static -mwindows
REM C:\Users\20122677\Documents\mingw64\bin\gdb main.exe
REM pause
.\main.exe