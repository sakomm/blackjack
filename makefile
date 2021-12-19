all: blackjack.c
	gcc -g -Wall -o blackjack blackjack.c
	./blackjack

clean:
	rm blackjack

