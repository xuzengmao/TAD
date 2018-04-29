#   Un pequeño esquema de makefile

grafo.o: grafo.c grafo.h
	gcc -c grafo.c

fuenteAuxiliar/cola.o: fuenteAuxiliar/cola.c fuenteAuxiliar/cola.h
	gcc -c fuenteAuxiliar/cola.c -o fuenteAuxiliar/cola.o

fuenteAuxiliar/pila.o: fuenteAuxiliar/pila.c fuenteAuxiliar/pila.h
	gcc -g -c fuenteAuxiliar/pila.c -o fuenteAuxiliar/pila.o

fuenteAuxiliar/monticulo.o: fuenteAuxiliar/monticulo.c fuenteAuxiliar/monticulo.h
	gcc -g -c fuenteAuxiliar/monticulo.c -o fuenteAuxiliar/monticulo.o

clean:
	rm -rfv *.o */*.o
