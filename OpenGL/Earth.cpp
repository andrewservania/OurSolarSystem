#include "Earth.h"


Earth::Earth()
{    
	mSolarSystemRotation = 10;
	 mUnknownRotationValue = 4;

	//glPushMatrix();


	mPlanetCoordinates.xPosition = 50; //Default: 50 Earth specific
	mPlanetCoordinates.yPosition = 0;  //Default: 0 Earth specific
	mPlanetCoordinates.zPosition = 0;  //Default: 0 Earth specific



	mPlanetTextureFileName = "texture_earth_clouds.bmp";
	mOrbitRadius = 50;		//Default: 50 Earth specific
	mNumberOfPoints = 60;   //Default: 60 Earth specific
	mRadius = 8;			//Default: 8  Earth specific
	mSlices = 50;			//Default: 50 Earth specific
	mStacks = 50;			//Default: 50 Earth specific
	mCustomValue = 0.8f;    //Default: 0.8f TODO: Figure out this necessary Value!

	LoadPlanetImage((mPlanetTextureDefaultFolder += mPlanetTextureFileName).c_str());
}


Earth::~Earth()
{
}



