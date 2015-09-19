#pragma once

#include <string>

#include "glut.h"
#include "freeglut.h"
#include "GL.h"

#include "imageloader.h"

using namespace std;
class UniverseBackground
{
private:
	GLuint mTextureId; //The id of the texture
	GLUquadric *mQuad;

	bool mIsUniverseRendering;
	bool mIsUniverseBackgroundInitialized;
	string fileLocationOfUniverses;

	int radius; //Max: 1000, above 1000 will cause your view to display a black hole.
	//Possibly indicating a distance larger than the render distance.

public:
	UniverseBackground(int _radius);
	~UniverseBackground();
	bool InitializeUniverseBackground();
	bool Render();
	void RenderWireFrame();
	void RenderUniverseBackground();
	GLuint LoadTexture(Image* image);
};
