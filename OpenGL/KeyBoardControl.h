#pragma once
#include "Planets.h"
#include "Camera.h"


class KeyBoardControl
{
public:
	Planets*mPlanets;
	Camera* mCamera;

	KeyBoardControl();
	KeyBoardControl(Planets* planets, Camera* camera);	
	~KeyBoardControl();
	void ListenToKeys(unsigned char key, int x, int y);
};

