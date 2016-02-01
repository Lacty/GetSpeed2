
main   = debug/main.o
app    = debug/app.o
camera = debug/camera.o
game   = debug/game.o
timer  = debug/timer.o
title  = debug/title.o

program = debug/program.out
objs    = $(main) $(app) $(camera) $(game) $(timer) $(title)

libs = -lglfw -lGL -lAntTweakBar -lX11
opt  = -Wall -std=c++14

$(program): $(objs)
	g++ $(opt) $(libs) $^ -o $@

$(main): src/main.cpp
	g++ $(opt) $(libs) -c $^ -o $@

$(app): src/appNative.cpp
	g++ $(opt) $(libs) -c $^ -o $@

$(camera): src/camera.cpp
	g++ $(opt) $(libs) -c $^ -o $@

$(game): src/game.cpp
	g++ $(opt) $(libs) -c $^ -o $@

$(timer): src/timer.cpp
	g++ $(opt) $(libs) -c $^ -o $@

$(title): src/title.cpp
	g++ $(opt) $(libs) -c $^ -o $@

run: $(program)
	$^

clear:
	rm $(main) $(app) $(camera) $(game) $(timer) $(title) $(program)
