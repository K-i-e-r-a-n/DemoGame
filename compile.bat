path=K:\MinGW\bin;K:\Programs\Vim\vim74;C:\Windows\System32
cd src
g++ -c Game.cpp Physics.cpp Chunk.cpp World.cpp Entity.cpp -I K:\SFML-2.1\include -I ..\include
cd ..\src
g++ Game.o Physics.o Chunk.o World.o Entity.o -o ..\bin\win32\game -L K:\SFML-2.1\lib -lsfml-graphics -lsfml-window -lsfml-system
pause