C调用C++编译顺序（注意.c文件中不要include cpp文件，容易报重复定义）:  
gcc -c C_PlusPlus.cpp  
g++ -c C_Main.c  
g++ C_Main.o C_PlusPlus.o  
    
  

C++调用C编译顺序（.cpp文件最好include c文件（可以同时再include .h文件，不会报重复编译），防止找不到函数定义）:  
gcc -c C_Header.c  
g++ -c C_PlusPlusMain.cpp  
g++ C_PlusPlusMain.o C_Header.o

