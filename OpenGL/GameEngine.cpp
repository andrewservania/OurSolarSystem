#include "GameEngine.h"



using namespace std;

vector<shared_ptr<IRenderableObject>> GameEngine::renderableObjects;


GameEngine::GameEngine()
{



}

GameEngine::~GameEngine()
{
}

void GameEngine::Update()
{
	for (shared_ptr<IRenderableObject> obj : renderableObjects)
		obj->Update();
}

void GameEngine::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	Update();

	gluLookAt(	0, 80, -336,	//eye
				0, 80, 336,		//center
				0, 1, 0);

	

	glPushMatrix();
	glLineWidth(2.0);						// Width of ALL Lines in the 3D environment
	glPopMatrix();

	for (shared_ptr<IRenderableObject> obj : renderableObjects)	obj->Render();


	glutSwapBuffers();
	Sleep(1000 / framesPerSecond);
}

void GameEngine::GatherKeyboardInput(unsigned char key, int x, int y)
{

}

void GameEngine::GatherKeyboardArrowPadInput(int key, int x, int y)
{

}

void GameEngine::GatherMouseClickInput(int button, int state, int x, int y)
{

}

void GameEngine::GatherMouseMotionInput(int x, int y)
{

}

void GameEngine::GatherMouseScrollWheelInput(int button, int dir, int x, int y)
{

}

void GameEngine::Reshape(GLint width, GLint height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(90, width / (float)height, 1, 2000);
	glMatrixMode(GL_MODELVIEW);
}

void GameEngine::IdleFunction()
{

}

//GLuint GameEngine::LoadTexture(Image* image)
//{
//
//	GLuint textureId;
//	glGenTextures(1, &textureId);				//Make room for our texture
//	glBindTexture(GL_TEXTURE_2D, textureId);	//Tell OpenGL which texture to edit
//	//Map the image to the texture
//	glTexImage2D(GL_TEXTURE_2D,                 //Always GL_TEXTURE_2D
//		0,										//0 for now
//		GL_RGB,									//Format OpenGL uses for image
//		image->width, image->height,			//Width and height
//		0,										//The border of the image
//		GL_RGB,									//GL_RGB, because pixels are stored in RGB format
//		GL_UNSIGNED_BYTE,						//GL_UNSIGNED_BYTE, because pixels are stored
//		//as unsigned numbers
//		image->pixels);							//The actual pixel data
//
//	return textureId; //Returns the id of the texture
//
//}

void GameEngine::AddRenderableObject(std::shared_ptr<IRenderableObject> object)
{
	renderableObjects.push_back(object);
}

