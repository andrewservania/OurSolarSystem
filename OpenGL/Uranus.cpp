#include "Uranus.h"


Uranus::Uranus()
{
	mUnknownRotationValue = 8;

	mPlanetCoordinates.xPosition = 110; //Default: 25 Mercury specific
	mPlanetCoordinates.yPosition = 0;  //Default: 0 Mercury specific
	mPlanetCoordinates.zPosition = 0;  //Default: 0 Mercury specific

	//glTranslatef(mPlanetCoordinates.xPosition, mPlanetCoordinates.yPosition, mPlanetCoordinates.zPosition);
	


	glColor3f(0.4f, 0.4f, 1.0f); // light blue

	mPlanetTextureFileName = "texture_uranus.bmp";

	//createTexturedPlanet parameters:
	mRadius = 4;			//Default: 8  Earth specific
	mSlices = 20;			//Default: 50 Earth specific
	mStacks = 10;			//Default: 50 Earth specific


	//Uranus' rings! Implement render method seperately!
	//glRotatef(90, 1, 0, 0);
	//drawOrbit(6.4f, 20, 1, 1);
	//drawOrbit(6.2f, 20, 1, 1);



	//DrawOrbit parameters:
	mOrbitRadius = 110;		//Default: 50 Earth specific
	mNumberOfPoints = 60;   //Default: 60 Earth specific
	/*including mVisibilty*/
	mCustomValue = 0.4f;    //Default: 1.0f TODO: Figure out this necessary Value!

	LoadPlanetImage((mPlanetTextureDefaultFolder += mPlanetTextureFileName).c_str());
}


Uranus::~Uranus()
{
}
