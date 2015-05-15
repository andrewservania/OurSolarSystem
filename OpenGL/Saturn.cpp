#include "Saturn.h"


Saturn::Saturn()
{
	
	mUnknownRotationValue = 7;
	
	mPlanetCoordinates.xPosition = 90; //Default: 25 Mercury specific
	mPlanetCoordinates.yPosition = 0;  //Default: 0 Mercury specific
	mPlanetCoordinates.zPosition = 0;  //Default: 0 Mercury specific

	//glTranslatef(mPlanetCoordinates.xPosition, mPlanetCoordinates.yPosition, mPlanetCoordinates.zPosition);
	


	//glColor3f(0.9f, 0.5f, 0.1f); // darker yellow - PROBLEMS WITH THIS LINE HERE! DON'T CALL!
	mPlanetTextureFileName = "texture_saturn.bmp";

	//createTexturedPlanet parameters:
	mRadius = 5;			//Default: 8  Earth specific
	mSlices = 20;			//Default: 50 Earth specific
	mStacks = 10;			//Default: 50 Earth specific






	LoadPlanetImage((mPlanetTextureDefaultFolder += mPlanetTextureFileName).c_str());
}


Saturn::~Saturn()
{
}
