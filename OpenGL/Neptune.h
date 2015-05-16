#pragma once
#include "Planet.h"
class Neptune :
	public Planet
{
private:
	GLfloat planetOrbitAngle = 0.0f;
	GLfloat sunOrbitAngle = 0.0f;
public:
	Neptune();
	~Neptune();
	bool Render() override;
};


