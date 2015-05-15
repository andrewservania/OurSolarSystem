#include "Planet.h"


Planet::Planet()
{
	mRenderStatus = false;
	mShowOrbitalLanes = true;
	//mColorValue = 0.0f;
	//mVisibility = true;
	mIsImageLoaded = false;
	mPlanetTextureDefaultFolder = "..\\OpenGL\\Resources\\Planets\\";
	mPlanetTextureFileName = "";
	//mCustomValue = 0.0f;
	mSolarSystemRotation = 0;
	//glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
	
}

Planet::~Planet()
{

}



/*Standard render function for all planets.
 All planets get this standard function through inheritance
 Make sure all necessary variables are initialized accordingly
 within the constructor of a planet*/
bool Planet::Render(){

	glPushMatrix();
	//glRotatef(mSolarSystemRotation / mUnknownRotationValue, 0, 0, 0);
	glTranslatef(mPlanetCoordinates.xPosition, mPlanetCoordinates.yPosition, mPlanetCoordinates.zPosition);
	glRotatef( -90.0f, 100.0f, 0.0f, 0.0f);
	CreateTexturedPlanet(mRadius, mSlices, mStacks);


	glPopMatrix();

	return mRenderStatus;
}


/*Standard Orbit drawing function for all planets*/
void Planet::DrawOrbit(GLfloat radius, int numPoints, bool visible, GLfloat customV)
{

	double PI = 3.1415926535897f;


	glBegin(GL_LINE_STRIP);
	glRotatef(-45.0f, 100.0f, 0.0f, 0.0f);
	
	//Standard gray-white color
	glColor4f(1.0f + mColorValue + customV, 1.0f +
		mColorValue + customV, 1.0f +
		mColorValue + customV, 0.0f +
		mColorValue + customV);
	//	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	//glColor3f(r, r, r);

	//TODO: The for-loop below is responsible for rendering the
	//		orbit lanes of planets, however, the orientation is
	//		not being rendered properly. FIX
	for (int i = 0; i < numPoints; i++)
	{
	//	 putting 2.2 instead of 2.0 fixed the LINE issue!! Nice :)
		double Angle = i * (2.2*PI / numPoints);	// use 360 instead of 2.0*PI if
		GLfloat X = (GLfloat)cos(Angle)*radius;			// you use d_cos and d_sin
		GLfloat Y = (GLfloat)sin(Angle)*radius;
		glVertex2f(X, Y);
	}
	glEnd();
}

GLuint Planet::LoadPlanetTexture(Image* image)
{
	GLuint textureId;
	glGenTextures(1, &textureId);				//Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId);	//Tell OpenGL which texture to edit
												//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                 //Always GL_TEXTURE_2D
		0,										//0 for now
		GL_RGB,									//Format OpenGL uses for image
		image->width, image->height,			//Width and height
		0,										//The border of the image
		GL_RGB,									//GL_RGB, because pixels are stored in RGB format
		GL_UNSIGNED_BYTE,						//GL_UNSIGNED_BYTE, because pixels are stored
												//as unsigned numbers
		image->pixels);							//The actual pixel data

	return textureId; //Returns the id of the texture
}

void Planet::LoadPlanetImage(const char* fileName)
{
	if (mIsImageLoaded == false)
	{
		glEnable(GL_DEPTH_TEST);
//	    glEnable(GL_LIGHTING); powerfull lighting effect. Use it wisely!
		glEnable(GL_LIGHT0);
		glEnable(GL_NORMALIZE);
		glEnable(GL_COLOR_MATERIAL);

		mQuadPlanet = gluNewQuadric();
		Image* image = loadBMP(fileName);
		mTextureIDPlanet = LoadPlanetTexture(image);

		delete image;
		mIsImageLoaded = true;
	}
	else{
		mIsImageLoaded = false;
	}
}

void Planet::CreateTexturedPlanet(GLfloat radius, int slices, int stacks)
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, mTextureIDPlanet);
	gluQuadricTexture(mQuadPlanet, 1);
	gluSphere(mQuadPlanet, radius, slices, stacks);
}


GLfloat Planet::GetX()
{
	return mPlanetCoordinates.xPosition;
}

GLfloat Planet::GetY()
{
	return  mPlanetCoordinates.yPosition;
}

GLfloat Planet::GetZ()
{
	return  mPlanetCoordinates.zPosition;
}

Planet::PlanetCoordinates Planet::GetPosition()
{
	return mPlanetCoordinates;
}


void Planet::SetX(GLfloat value)
{
	mPlanetCoordinates.xPosition = value;
	glTranslatef(mPlanetCoordinates.xPosition, mPlanetCoordinates.yPosition, mPlanetCoordinates.zPosition);
}

void Planet::SetY(GLfloat value)
{
	mPlanetCoordinates.yPosition = value;
	glTranslatef(mPlanetCoordinates.xPosition, mPlanetCoordinates.yPosition, mPlanetCoordinates.zPosition);
}

void Planet::SetZ(GLfloat value)
{
	mPlanetCoordinates.zPosition = value;
	glTranslatef(mPlanetCoordinates.xPosition, mPlanetCoordinates.yPosition, mPlanetCoordinates.zPosition);
}


void Planet::SetPosition(GLfloat x, GLfloat y, GLfloat z)
{
	mPlanetCoordinates.xPosition = x;
	mPlanetCoordinates.yPosition = y;
	mPlanetCoordinates.zPosition = z;
}

void Planet::SetPosition(PlanetCoordinates planetCoordinates)
{
	mPlanetCoordinates = planetCoordinates;
}


GLfloat Planet::GetSize()
{
	return mRadius;
}

void Planet::SetSize(GLfloat radius)
{
	mRadius = radius;
	//mOrbitRadius = mRadius*4;
}


