#include "Mercury.h"


Mercury::Mercury()
{
	
	mUnknownRotationValue = 2;
	

	mPlanetCoordinates.xPosition = 25; //Default: 25 Mercury specific
	mPlanetCoordinates.yPosition = 0;  //Default: 0 Mercury specific
	mPlanetCoordinates.zPosition = 0;  //Default: 0 Mercury specific

	//glTranslatef(mPlanetCoordinates.xPosition, mPlanetCoordinates.yPosition, mPlanetCoordinates.zPosition);
	//glColor3f(0.0f, 1.0f, 0.0f); //green

	mPlanetTextureFileName = "texture_mercury.bmp";

	//createTexturedPlanet parameters:
	mRadius = 1;			//Default: 8  Earth specific
	mSlices = 20;			//Default: 50 Earth specific
	mStacks = 10;			//Default: 50 Earth specific

	//DrawOrbit parameters:
	mOrbitRadius = 50;		//Default: 50 Earth specific
	mNumberOfPoints = 60;   //Default: 60 Earth specific
	/*including mVisibilty*/
	mCustomValue = 1.0f;    //Default: 1.0f TODO: Figure out this necessary Value!

	LoadPlanetImage((mPlanetTextureDefaultFolder += mPlanetTextureFileName).c_str());


}


Mercury::~Mercury()
{
}
