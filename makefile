simulation: scheduling.o processes.o
	gcc scheduling.o processes.o -o simulation 
scheduling.o: scheduling.c
	gcc -c scheduling.c
processes.o: processes.c processes.h
	gcc -c processes.c
clean: 
	rm -f *.o simulation