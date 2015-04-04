ALLO=main.o LED.o server.o str.o init_d.o

Yeelink:$(ALLO)
	gcc -o Yeelink $(ALLO) -lwiringPi

main.o:main.c
	gcc -c main.c -o main.o

LED.o:LED.c
	gcc -c  LED.c -o LED.o -lwirongPi

server.o:server.c
	gcc -c server.c -o server.o

str.o:str.c
	gcc -c str.c -o str.o

init_d.o:init_d.c
	gcc -c init_d.c -o init_d.o

clean:
	rm -f *.o

run:
	./Yeelink
