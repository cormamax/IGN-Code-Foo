all: IGNKnights

IGNKnights: Queue.cpp IGNKnights.cpp IGNKnights.h
	g++ -Wall -Werror -O3 IGNKnights.cpp -o IGNKnights
clean:
	rm IGNKnights