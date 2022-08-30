mybin: main.o mytest.o
		gcc $^ -o $@

main.o:main.c
	gcc -c main.c

mytest.o:mytest.c
	gcc -c mytest.c


.PHONY:clean
clean:
	rm -f mybin  
