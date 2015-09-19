#include "Saturn.h"

Saturn::Saturn()
{
	mUnknownRotationValue = 7;

	mPlanetCoordinates.xPosition = 90; //Default: 25 Mercury specific
	mPlanetCoordinates.yPosition = 0;  //Default: 0 Mercury specific
	mPlanetCoordinates.zPosition = 0;  //Default: 0 Mercury specific

	//glTranslatef(mPlanetCoordinates.xPosition, mPlanetCoordinates.yPosition, mPlanetCoordinates.zPosition);

	glColor3f(0.9f, 0.5f, 0.1f); // darker yellow
	mPlanetTextureFileName = "texture_saturn.bmp";

	//createTexturedPlanet parameters:
	mRadius = 5;			//Default: 8  Earth specific
	mSlices = 20;			//Default: 50 Earth specific
	mStacks = 10;			//Default: 50 Earth specific

	/* Render method has to be seperately implemented for Saturn due to it's
	   rings! */
	//glRotatef(30, 1, 0, 0);
	//drawOrbit(6.2f, 20, 1, 1);
	//drawOrbit(6.5f, 20, 1, 1);
	//drawOrbit(7.1f, 20, 1, 1);
	//drawOrbit(7.6f, 20, 1, 1);
	//drawOrbit(8.0f, 20, 1, 1);
	//drawOrbit(8.2f, 20, 1, 1);
	//drawOrbit(8.4f, 20, 1, 1);
	//drawOrbit(8.6f, 20, 1, 1);
	//drawOrbit(8.8f, 20, 1, 1);
	//drawOrbit(9.0f, 20, 1, 1);
	//drawOrbit(9.2f, 20, 1, 1);

	//DrawOrbit parameters:
	mOrbitRadius = 90;		//Default: 50 Earth specific
	mNumberOfPoints = 60;   //Default: 60 Earth specific
	/*including mVisibilty*/
	mCustomValue = 0.5f;    //Default: 1.0f TODO: Figure out this necessary Value!

	LoadPlanetImage((mPlanetTextureDefaultFolder += mPlanetTextureFileName).c_str());
}

Saturn::~Saturn()
{
}