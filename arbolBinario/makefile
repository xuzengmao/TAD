#   Un pequeño esquema de makefile

arbol.o: arbol.c arbol.h
	gcc -c arbol.c

fuenteAuxiliar/cola.o: fuenteAuxiliar/cola.c fuenteAuxiliar/cola.h
	gcc -c fuenteAuxiliar/cola.c -o fuenteAuxiliar/cola.o

fuenteAuxiliar/pila.o: fuenteAuxiliar/pila.c fuenteAuxiliar/pila.h
	gcc -c fuenteAuxiliar/pila.c -o fuenteAuxiliar/pila.o

clean:
	rm -rfv *.o */*.o
