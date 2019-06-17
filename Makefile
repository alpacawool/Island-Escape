output: main.o DisplayMenu.o WorldGrid.o Backpack.o GamePlayer.o GameItem.o Space.o Beach.o Ocean.o Plains.o Forest.o River.o Hut.o
	g++ -std=c++0x main.o DisplayMenu.o WorldGrid.o Backpack.o GamePlayer.o GameItem.o Space.o Beach.o Ocean.o Plains.o Forest.o River.o Hut.o -o island

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

DisplayMenu.o: DisplayMenu.cpp DisplayMenu.hpp
	g++ -std=c++0x -c DisplayMenu.cpp

WorldGrid.o: WorldGrid.cpp WorldGrid.hpp
	g++ -std=c++0x -c WorldGrid.cpp

Backpack.o: Backpack.cpp Backpack.hpp
	g++ -std=c++0x -c Backpack.cpp

GamePlayer.o: GamePlayer.cpp GamePlayer.hpp
	g++ -std=c++0x -c GamePlayer.cpp

GameItem.o: GameItem.cpp GameItem.hpp
	g++ -std=c++0x -c GameItem.cpp

Space.o: Space.cpp Space.hpp
	g++ -std=c++0x -c Space.cpp

Beach.o: Beach.cpp Beach.hpp
	g++ -std=c++0x -c Beach.cpp

Ocean.o: Ocean.cpp Ocean.hpp
	g++ -std=c++0x -c Ocean.cpp

Plains.o: Plains.cpp Plains.hpp
	g++ -std=c++0x -c Plains.cpp

Forest.o: Forest.cpp Forest.hpp
	g++ -std=c++0x -c Forest.cpp

River.o: River.cpp River.hpp
	g++ -std=c++0x -c River.cpp

Hut.o: Hut.cpp Hut.hpp
	g++ -std=c++0x -c Hut.cpp

clean:
	rm *.o island
