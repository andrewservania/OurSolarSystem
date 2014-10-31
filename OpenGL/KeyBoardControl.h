#pragma once
#include "Planets.h"
class KeyBoardControl
{
public:
	Planets*mPlanets;
	KeyBoardControl();
	KeyBoardControl(Planets* planets);	
	~KeyBoardControl();
	void ListenToKeys(unsigned char key, int x, int y);
};

