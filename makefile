bin/programa : src/main.cpp include/Foco.hpp include/EstadoFoco.hpp
	c++ src/main.cpp -o bin/programa -I include

run : bin/programa
	./bin/programa

bin/memoria : src/memoria.cpp 
	c++ src/memoria.cpp -o bin/programa

runMemoria : bin/memoria
	./bin/memoria

src/ejemplo : src/ejemplo.cpp
	c++ src/ejemplo.cpp -o bin/ejemplo -lftxui-screen -lftxui-dom -lftxui-component

runejemplo : bin/ejemplo
	./bin/ejemplo

run : bin/animacion
	./bin/animacion

bin/animacion : src/animacion.cpp include/*.hpp
	@mkdir -p bin
	g++ -Iinclude -o bin/animacion src/animacion.cpp -lftxui-component -lftxui-dom -lftxui-screen

# New target to build the top-level Animacion.cpp (uppercase) and a convenient build alias
.PHONY: build runAnimacion
build: bin/Animacion

bin/Animacion: Animacion.cpp include/*.hpp
	@mkdir -p bin
	g++ -std=c++20 -Iinclude -o bin/Animacion Animacion.cpp -lftxui-component -lftxui-dom -lftxui-screen -pthread

runAnimacion: bin/Animacion
	./bin/Animacion