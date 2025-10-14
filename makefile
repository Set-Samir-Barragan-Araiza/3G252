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