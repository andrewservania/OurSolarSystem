#pragma once
#include "glut.h"
#include "freeglut.h"
#include "IRenderableObject.h"

#include <string>
#include <windows.h>
class OrbitLane : public IRenderableObject
{
private: 
	GLfloat radius;
public:
	OrbitLane(GLfloat _radius);
	~OrbitLane();
	 virtual void Render() override;
	 virtual void Update() override;
};
