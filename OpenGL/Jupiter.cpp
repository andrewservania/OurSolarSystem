#include "Jupiter.h"


Jupiter::Jupiter()
{
	//glPushMatrix();
	mUnknownRotationValue = 6;
	mPlanetCoordinates.xPosition = 75; //Default: 25 Mercury specific
	mPlanetCoordinates.yPosition = 0;  //Default: 0 Mercury specific
	mPlanetCoordinates.zPosition = 0;  //Default: 0 Mercury specific

	//glTranslatef(mPlanetCoordinates.xPosition, mPlanetCoordinates.yPosition, mPlanetCoordinates.zPosition);
	


	glColor3f(0.4f, 0.3f, 0.2f); //lime green
	mPlanetTextureFileName = "texture_jupiter.bmp";

	//createTexturedPlanet parameters:
	mRadius = 6;			//Default: 8  Earth specific
	mSlices = 20;			//Default: 50 Earth specific
	mStacks = 10;			//Default: 50 Earth specific

	//DrawOrbit parameters:
	mOrbitRadius = 75;		//Default: 50 Earth specific
	mNumberOfPoints = 60;   //Default: 60 Earth specific
	/*including mVisibilty*/
	mCustomValue = 0.6f;    //Default: 1.0f TODO: Figure out this necessary Value!

	LoadPlanetImage((mPlanetTextureDefaultFolder += mPlanetTextureFileName).c_str());
}


Jupiter::~Jupiter()
{
}
