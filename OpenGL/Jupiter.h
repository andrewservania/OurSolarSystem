#pragma once
#include "Planet.h"
class Jupiter :
	public Planet
{
private:
	GLfloat planetOrbitAngle = 0.0f;
	GLfloat sunOrbitAngle = 0.0f;
public:
	Jupiter();
	~Jupiter();
	bool Render() override;
};
