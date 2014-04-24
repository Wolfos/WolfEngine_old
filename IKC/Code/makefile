SOURCE = WolfEngine/Main_SDL.cpp WolfEngine/Components/Camera.cpp WolfEngine/Components/SpriteRenderer.cpp  WolfEngine/Components/Transform.cpp WolfEngine/ECS/GameObject.cpp WolfEngine/ECS/ObjectManager.cpp WolfEngine/Input/Input.cpp WolfEngine/Models/Point.cpp WolfEngine/Rendering/Image.cpp WolfEngine/Rendering/Screen.cpp WolfEngine/Utilities/Debug.cpp WolfEngine/Utilities/Time.cpp GameMain.cpp Components/Card.cpp

EXECUTABLE = ../../Debug/WolfEngine

LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf

CC = g++

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCE)
	$(CC) $(SOURCE) $(LIBS) -o $(EXECUTABLE) -std=gnu++11

clean: 
	rm -f $(EXECUTABLE)
