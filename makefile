CC=g++
CF=
CCF=-c

a.out: main.o customer.o food.o restaurant.o util.o order.o system.o
	$(CC) $(CF) main.o customer.o food.o restaurant.o util.o order.o system.o -o a.out;

main.o: main.cpp customer.h food.h restaurant.h util.h order.h system.h
	$(CC) $(CF) $(CCF) main.cpp

customer.o: customer.cpp customer.h util.h order.h
	$(CC) $(CF) $(CCF) customer.cpp

food.o: food.cpp food.h util.h
	$(CC) $(CF) $(CCF) food.cpp

restaurant.o: restaurant.cpp restaurant.h food.h util.h food.h
	$(CC) $(CF) $(CCF) restaurant.cpp

order.o: order.cpp order.h util.h customer.h
	$(CC) $(CF) $(CCF) order.cpp

system.o: system.cpp system.h util.h customer.h restaurant.h
	$(CC) $(CF) $(CCF) system.cpp

util.o: util.cpp util.h
	$(CC) $(CF) $(CCF) util.cpp

test: a.out
	./a.out

clean:
	rm .DS_Store *.o a.out