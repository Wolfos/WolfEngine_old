#ifndef _MINIGAME_H
#define _MINIGAME_H
///
///	Base class for minigames
///
class MiniGame
{
public:
	/// Calls when the minigame is initialized
	virtual void Start() = 0;
	///	Calls every frame
	virtual void Update() = 0;
};
#endif