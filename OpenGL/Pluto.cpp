#include "Pluto.h"

Pluto::Pluto()
{
	mUnknownRotationValue = 17;
	mPlanetCoordinates.xPosition = 160; //Default: 25 Mercury specific
	mPlanetCoordinates.yPosition = 0;  //Default: 0 Mercury specific
	mPlanetCoordinates.zPosition = 0;  //Default: 0 Mercury specific

	//glTranslatef(mPlanetCoordinates.xPosition, mPlanetCoordinates.yPosition, mPlanetCoordinates.zPosition);

	glColor3f(0.6f, 0.3f, 0.1f); //dark brown

	mPlanetTextureFileName = "texture_pluto_fictional.bmp";

	//createTexturedPlanet parameters:
	mRadius = 4;			//Default: 8  Earth specific
	mSlices = 20;			//Default: 50 Earth specific
	mStacks = 10;			//Default: 50 Earth specific

	//Implement seperately?
	//glRotatef(solarSystemRotation / 10, 0, 0, 1);

	//DrawOrbit parameters:
	mOrbitRadius = 140;		//Default: 50 Earth specific
	mNumberOfPoints = 60;   //Default: 60 Earth specific
	/*including mVisibilty*/
	mCustomValue = 0.3f;    //Default: 1.0f TODO: Figure out this necessary Value!

	LoadPlanetImage((mPlanetTextureDefaultFolder += mPlanetTextureFileName).c_str());
}

Pluto::~Pluto()
{
}