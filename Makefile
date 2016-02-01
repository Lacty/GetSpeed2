
main   = debug/main.o
app    = debug/app.o
camera = debug/camera.o

program = debug/program.out
objs    = $(main) $(app) $(camera)

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

run: $(program)
	$^

clear:
	rm $(main) $(app) $(program)
