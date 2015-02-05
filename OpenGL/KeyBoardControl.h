#pragma once
#include "Planets.h"
#include "UniverseCameraParameters.h"


class KeyBoardControl
{
public:
	Planets*mPlanets;
	UniverseCameraParameters* mCamera;

	KeyBoardControl();
	KeyBoardControl(Planets* planets, UniverseCameraParameters* camera);	
	~KeyBoardControl();
	void ListenToKeys(unsigned char key, int x, int y);
};

