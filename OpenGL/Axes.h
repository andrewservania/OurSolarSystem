#pragma once
#include "glut.h"
#include "freeglut.h"
#include "GL.h"

using namespace std;



class Axes
{
private:
	bool mIsXBeingRendered , mIsYBeingRendered, mIsZBeingRendered;
	bool mIsXGridBeingRendered, mIsYGridBeingRendered, mIsZGridBeingRendered;

public:
	Axes();
	~Axes();
	
	bool RenderXAxis();
	bool RenderYAxis();
	bool RenderZAxis();

	bool RenderXAxisGrid();
	bool RenderYAxisGrid();
	bool RenderZAxisGrid();


};

