#pragma once
#include "Planet.h"
class Uranus :
	public Planet
{
private:
	GLfloat planetOrbitAngle = 0.0f;
	GLfloat sunOrbitAngle = 0.0f;
public:
	Uranus();
	~Uranus();
	bool Render() override;
};
