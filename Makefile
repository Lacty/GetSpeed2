
main         = debug/main.o
app          = debug/app.o
camera       = debug/camera.o
timer        = debug/timer.o
scenemanager = debug/scenemanager.o
game         = debug/game.o
title        = debug/title.o
font         = debug/font.o

program = debug/program.out
objs    = $(main) $(app) $(camera) $(scenemanager) $(game) $(timer) $(title) $(font)

libs = -lglfw -lGL -lAntTweakBar -lX11 -lftgl -I/usr/include/freetype2
opt  = -Wall -std=c++14

$(program): $(objs)
	g++ $(opt) $(libs) $^ -o $@

$(main): src/main.cpp
	g++ $(opt) $(libs) -c $^ -o $@

$(app): src/appNative.cpp
	g++ $(opt) $(libs) -c $^ -o $@

$(camera): src/camera.cpp
	g++ $(opt) $(libs) -c $^ -o $@

$(timer): src/timer.cpp
	g++ $(opt) $(libs) -c $^ -o $@

$(scenemanager): src/sceneManager.cpp
	g++ $(opt) $(libs) -c $^ -o $@

$(game): src/game.cpp
	g++ $(opt) $(libs) -c $^ -o $@

$(title): src/title.cpp
	g++ $(opt) $(libs) -c $^ -o $@

$(font): src/font.cpp
	g++ $(opt) $(libs) -c $^ -o $@

run: $(program)
	$^

clear:
	rm $(main) $(app) $(camera) $(timer) $(scenemanager) $(game) $(title) $(program)
