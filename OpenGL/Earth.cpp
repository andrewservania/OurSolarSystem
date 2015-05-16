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
	glRotatef(sunOrbitAngle, 0.0f, 1.0f, 0.0f); //responsible for creating an orbit lane for the planet
	sunOrbitAngle += 0.7f;
  
	glPushMatrix();

	glTranslatef(mPlanetCoordinates.xPosition, mPlanetCoordinates.yPosition, mPlanetCoordinates.zPosition);

	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Default angle of a planet. If you don't want Earth's texture to look upside down, keep this one as it is.


	glRotatef(planetOrbitAngle, 0.0f, 0.0f, 1.0f);
	planetOrbitAngle += 0.2f; 
	CreateTexturedPlanet(mRadius, mSlices, mStacks);
	

	glPopMatrix();
	glPopMatrix();


	return mRenderStatus;
}




