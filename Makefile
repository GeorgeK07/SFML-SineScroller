main: main.cpp CharObject.cpp Game.cpp
	g++ -std=c++17 -Wall main.cpp CharObject.cpp Game.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f main