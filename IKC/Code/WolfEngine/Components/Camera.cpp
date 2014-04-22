#include "Camera.h"
#include "../Rendering/Screen.h"

void Camera::Start()
{
	Screen::mainCamera = this;
}

void Camera::Update()
{
	SDL_GetWindowSize(window, &width, &height);
}