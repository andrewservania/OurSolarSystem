#include "Mars.h"


Mars::Mars()
{
	//glPushMatrix();
	mUnknownRotationValue = 5;
	

	mPlanetCoordinates.xPosition = 60; //Default: 25 Mercury specific
	mPlanetCoordinates.yPosition = 0;  //Default: 0 Mercury specific
	mPlanetCoordinates.zPosition = 0;  //Default: 0 Mercury specific

	//glTranslatef(mPlanetCoordinates.xPosition, mPlanetCoordinates.yPosition, mPlanetCoordinates.zPosition);
	


	//glColor3f(0.6f, 0.3f, 0.1f); //dark brown
	mPlanetTextureFileName = "texture_mars.bmp";

	//createTexturedPlanet parameters:
	mRadius = 2;			//Default: 8  Earth specific
	mSlices = 20;			//Default: 50 Earth specific
	mStacks = 10;			//Default: 50 Earth specific

	


	LoadPlanetImage((mPlanetTextureDefaultFolder += mPlanetTextureFileName).c_str());
}


Mars::~Mars()
{
}
