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

	mRadius = 8;			//Default: 8  Earth specific
	mSlices = 50;			//Default: 50 Earth specific
	mStacks = 50;			//Default: 50 Earth specific


	LoadPlanetImage((mPlanetTextureDefaultFolder += mPlanetTextureFileName).c_str());
}


Earth::~Earth()
{
}

bool Earth::Render()
{
	glPushMatrix();
	//glRotatef(mSolarSystemRotation / mUnknownRotationValue, 0, 0, 0);
	glTranslatef(mPlanetCoordinates.xPosition, mPlanetCoordinates.yPosition, mPlanetCoordinates.zPosition);
	glRotatef(-90.0f, 100.0f, 0.0f, 0.0f);
	CreateTexturedPlanet(mRadius, mSlices, mStacks);


	glPopMatrix();

	return mRenderStatus;
}




