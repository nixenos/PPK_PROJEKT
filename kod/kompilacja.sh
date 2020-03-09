#!/bin/bash
echo "Wymagany jest pakiet CMake oraz make"
echo "Usuwanie pliku CMakeCache.txt oraz generowanie nowego..."
rm CMakeCache.txt
cmake .
echo "Kompilacja projektu korzystając z make..."
make
echo "Zakończono!"
