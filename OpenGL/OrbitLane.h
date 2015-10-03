#pragma once
#include <string>
#include <windows.h>
#include "glut.h"
#include "freeglut.h"
#include "gl/GL.h"
#include "GL.h"
class OrbitLane
{
public:
	OrbitLane();
	~OrbitLane();
	void Render(GLfloat radius);
};

