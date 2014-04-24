#ifndef _CARD_H
#define _CARD_H

#include "../WolfEngine/WolfEngine.h"
class Card : public Component
{
public:
	bool checked = false;
	bool selected = false;
	int card = 0;
	bool reset;
	virtual void Start();
	virtual void Update();
	void Reset();
private:
	double timer;
	int width, height;
};
#endif