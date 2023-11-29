simulation: simulate.o scheduling.o processes.o timeControl.o
	gcc simulate.o scheduling.o processes.o timeControl.o -o simulation 
simulate.o: simulate.c mylib.h
	gcc -c simulate.c
scheduling.o: scheduling.c scheduling.h mylib.h
	gcc -c scheduling.c
processes.o: processes.c processes.h mylib.h
	gcc -c processes.c
timeControl.o: timeControl.c timeControl.h mylib.h
	gcc -c timeControl.c
clean: 
	rm -f *.o simulation