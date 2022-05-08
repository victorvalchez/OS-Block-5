
#Jos� Manuel P�rez Lobato
#script para crear la librer�a est�tica y ejecutar el programa de prueba

#creamos los ficheros objeto
gcc -g -c -O cubo.c
gcc -g -c -O cuadrado.c

#creamos la librer�a
ar cru libpotencia.a cubo.o cuadrado.o
ranlib libpotencia.a

#creamos un ejecutable para probar la librer�a
gcc -o usolibreriaestatica usolibreria.c -L. -lpotencia

#ejecutamos el programa de prueba
usolibreriaestatica
