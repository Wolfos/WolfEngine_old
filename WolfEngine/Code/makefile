WOLFENGINESOURCE = WolfEngine/Main_SDL.cpp \
WolfEngine/Audio/Sound.cpp \
WolfEngine/Audio/Music.cpp \
WolfEngine/Components/Camera.cpp \
WolfEngine/Components/SpriteRenderer.cpp \
WolfEngine/Components/Transform.cpp \
WolfEngine/ECS/GameObject.cpp \
WolfEngine/ECS/ObjectManager.cpp \
WolfEngine/Input/Input.cpp \
WolfEngine/Models/Point.cpp \
WolfEngine/Rendering/Image.cpp \
WolfEngine/Rendering/Screen.cpp \
WolfEngine/Utilities/Debug.cpp \
WolfEngine/Utilities/Time.cpp 

GAMESOURCE = $(WOLFENGINESOURCE) \ 
GameMain.cpp \
Components/Card.cpp

EXECUTABLE = ../../Debug/WolfEngine

LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

CC = g++

all: $(EXECUTABLE)

$(EXECUTABLE): $(GAMESOURCE)
	$(CC) $(SOURCE) $(LIBS) -o $(EXECUTABLE) -std=gnu++11

clean:
	rm -f $(EXECUTABLE)
