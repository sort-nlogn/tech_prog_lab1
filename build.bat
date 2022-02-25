@echo Compile programm...
@echo off
g++ -g base_queue.cpp -g public_queue.cpp -g private_queue.cpp -g protected_queue.cpp -g .\main.cpp -o .\main.exe
.\main.exe