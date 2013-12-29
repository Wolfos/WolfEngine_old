all: main

main: includes.o Models/Map.o Models/Window.o Map/MapLoad.o Game/GameMain.o
	$(CC) -o main.so includes.o Models/Map.o Models/Window.o Map/MapLoad.o Game/GameMain.o -shared -lSDL2 -lSDL2_test -lm
clean:
	rm main.so includes.o Models/Map.o Models/Window.o Map/MapLoad.o Game/GameMain.o