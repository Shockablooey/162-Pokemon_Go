CC = g++ -g
exe = wow
$(exe): trainer.o error.o go.o location.o event.o empty.o world.o cave.o spawnpoint.o pokestop.o geodude.o larvitar.o pidgey.o dratini.o abra.o slowpoke.o
	$(CC) trainer.o error.o go.o location.o event.o empty.o world.o cave.o spawnpoint.o pokestop.o geodude.o larvitar.o pidgey.o dratini.o abra.o slowpoke.o -o $(exe)
debug: 
	$(CC) trainer.cpp error.cpp go.cpp location.cpp event.cpp empty.cpp world.cpp cave.cpp spawnpoint.cpp pokestop.cpp geodude.cpp larvitar.cpp pidgey.cpp dratini.cpp abra.cpp slowpoke.cpp -D DEBUG -o $(exe)
trainer.o: trainer.cpp
	$(CC) -c trainer.cpp
error.o: error.cpp
	$(CC) -c error.cpp
go.o: go.cpp
	$(CC) -c go.cpp
location.o: location.cpp
	$(CC) -c location.cpp
event.o: event.cpp
	$(CC) -c event.cpp
empty.o: empty.cpp
	$(CC) -c empty.cpp
world.o: world.cpp
	$(CC) -c world.cpp
cave.o: cave.cpp
	$(CC) -c cave.cpp
spawnpoint.o: spawnpoint.cpp
	$(CC) -c spawnpoint.cpp
pokestop.o: pokestop.cpp
	$(CC) -c pokestop.cpp
geodude.o: geodude.cpp
	$(CC) -c geodude.cpp
larvitar.o: larvitar.cpp
	$(CC) -c larvitar.cpp
pidgey.o: pidgey.cpp
	$(CC) -c pidgey.cpp
dratini.o: dratini.cpp
	$(CC) -c dratini.cpp
abra.o: abra.cpp
	$(CC) -c abra.cpp
slowpoke.o: slowpoke.cpp
	$(CC) -c slowpoke.cpp
clean:
	rm -f *.out *.o $(exe)
