#include "Venus.h"


Venus::Venus()
{

	mUnknownRotationValue = 3;

	mPlanetCoordinates.xPosition = 40; //Default: 40 Venus specific
	mPlanetCoordinates.yPosition = 0;  //Default: 0 Mercury specific
	mPlanetCoordinates.zPosition = 0;  //Default: 0 Mercury specific

	//glTranslatef(mPlanetCoordinates.xPosition, mPlanetCoordinates.yPosition, mPlanetCoordinates.zPosition);
	
	//glColor3f(0.7f, 0.6f, 0.0f); //brown
	mPlanetTextureFileName = "texture_venus.bmp";

	//createTexturedPlanet parameters:
	mRadius = 2;			//Default: 8  Earth specific
	mSlices = 20;			//Default: 50 Earth specific
	mStacks = 10;			//Default: 50 Earth specific

	//DrawOrbit parameters:
	mOrbitRadius = mRadius;		//Default: 50 Earth specific
	mNumberOfPoints = 60;   //Default: 60 Earth specific
	/*including mVisibilty*/
	mCustomValue = 0.9f;    //Default: 1.0f TODO: Figure out this necessary Value!

	LoadPlanetImage((mPlanetTextureDefaultFolder += mPlanetTextureFileName).c_str());



}


Venus::~Venus()
{
}