simulation: scheduling.o processes.o simulate.o
	gcc scheduling.o processes.o simulate.o -o simulation 
simulate.o: simulate.c
	gcc -c simulate.c
scheduling.o: scheduling.c
	gcc -c scheduling.c
processes.o: processes.c processes.h
	gcc -c processes.c
clean: 
	rm -f *.o simulation