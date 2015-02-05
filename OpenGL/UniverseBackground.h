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

public:
	UniverseBackground();
	~UniverseBackground();
	bool InitializeUniverseBackground();
	bool Render();
	void RenderWireFrame();
	void RenderUniverseBackground();
	GLuint LoadTexture(Image* image);
};

