#pragma once
#include "Planets.h"
#include "Camera.h"


class KeyBoardControl
{
public:

	Camera* mCamera;

	KeyBoardControl();
	KeyBoardControl(Camera* camera);	
	~KeyBoardControl();
	void ListenToKeys(unsigned char key, int x, int y);
};

