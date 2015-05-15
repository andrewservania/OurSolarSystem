#pragma once
#include "glut.h"
#include "freeglut.h"
#include "GL.h"
#include <string>
using namespace std;



class Axes
{
private:
	bool mIsXBeingRendered , mIsYBeingRendered, mIsZBeingRendered;
	bool mIsXGridBeingRendered, mIsYGridBeingRendered, mIsZGridBeingRendered;
	int mLengthOfAxes;
	int depth;
	int squareSizeInGrid;

public:
	Axes();
	~Axes();
	
	bool RenderXAxis();
	bool RenderYAxis();
	bool RenderZAxis();

	bool RenderXAxisGrid();
	bool RenderYAxisGrid();
	bool RenderZAxisGrid();
	void drawText(string text, float x, float y, float z);

};

