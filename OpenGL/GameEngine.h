#pragma once
#include "IRenderableObject.h"
#include "glut.h"
#include "imageloader.h"

#include <vector>
#include <memory>
#include <string>

class GameEngine
{
private:
	// A vector to include all objects to be rendered 
	static std::vector<std::shared_ptr<IRenderableObject>> renderableObjects;
	static const int framesPerSecond = 60;
	void UpdateObjects();
	void RenderObjects();



public:
	GameEngine();
	~GameEngine();
	// Required GLUT callback functions
	static void Update();
	static void Render();
	static void GatherKeyboardInput(unsigned char key, int x, int y);
	static void GatherKeyboardArrowPadInput(int key, int x, int y);
	static void GatherMouseClickInput(int button, int state, int x, int y);
	static void GatherMouseMotionInput(int x, int y);
	static void GatherMouseScrollWheelInput(int button, int dir, int x, int y);
	static void Reshape(GLint width, GLint height);
	static void IdleFunction();

	//static GLuint LoadTexture(Image* image);
	static void AddRenderableObject(std::shared_ptr<IRenderableObject> object);

	// Make the game engine a singleton as there will be only one

};

