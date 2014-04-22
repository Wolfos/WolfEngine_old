#include "Transform.h"
#include <stdio.h>
#include "../Utilities/Debug.h"

void Transform::Start()
{
	scale.x = 1;
	scale.y = 1;
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