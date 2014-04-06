#include "CameraMovement.h"
#include "../ECS/GameObject.h"
#include "../Input/Input.h"
#include "../Utilities/Time.h"
void CameraMovement::Start()
{

}

void CameraMovement::Update()
{
	int camspeed = 500;

	int xspeed = 0, yspeed = 0;

	if (Input::keys.ArrowLeft)xspeed = -camspeed;
	if (Input::keys.ArrowRight)xspeed = camspeed;
	if (Input::keys.ArrowUp)yspeed = -camspeed;
	if (Input::keys.ArrowDown)yspeed = camspeed;

	gameObject->transform->Move(xspeed*Time::frameTimeS, yspeed*Time::frameTimeS);
	//gameObject->transform->Move(xspeed, yspeed);
}