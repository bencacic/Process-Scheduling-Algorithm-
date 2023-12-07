simulation: simulate.o scheduling.o processes.o timeControl.o output.o stat_table.o main_helper.o
	gcc simulate.o scheduling.o processes.o timeControl.o output.o stat_table.o main_helper.o -o simulation 
simulate.o: simulate.c mylib.h
	gcc -c simulate.c
scheduling.o: scheduling.c scheduling.h mylib.h
	gcc -c scheduling.c
processes.o: processes.c processes.h mylib.h
	gcc -c processes.c
timeControl.o: timeControl.c timeControl.h mylib.h
	gcc -c timeControl.c
output.o: output.c output.h mylib.h 
	gcc -c output.c
stat_table.o: stat_table.c stat_table.h mylib.h
	gcc -c stat_table.c
main_helper.o: main_helper.c main_helper.h mylib.h
	gcc -c main_helper.c
clean: 
	rm -f *.o simulation