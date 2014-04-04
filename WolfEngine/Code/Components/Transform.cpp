#include "Transform.h"
#include <stdio.h>
#include "../Utilities/Debug.h"

void Transform::Start()
{
	//Runs when the component is added to a GameObject
}

void Transform::Move(int x, int y)
{
	position.x += x;
	position.y += y;
}

void Transform::Update()
{
	//Runs every frame
}