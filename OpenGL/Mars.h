#pragma once
#include "Planet.h"
class Mars :
	public Planet
{
private:
	GLfloat planetOrbitAngle = 0.0f;
	GLfloat sunOrbitAngle = 0.0f;
public:
	Mars();
	~Mars();
	bool Render() override;
};

