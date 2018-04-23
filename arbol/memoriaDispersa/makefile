#   Un pequeño esquema de makefile

arbol.o: arbol.c arbol.h
	gcc -c arbol.c

cola.o: fuenteAuxiliar/cola.c fuenteAuxiliar/cola.h
	gcc -c fuenteAuxiliar/cola.c

pila.o: fuenteAuxiliar/pila.c fuenteAuxiliar/pila.h
	gcc -c fuenteAuxiliar/pila.c

clean:
	rm -rfv *.o
