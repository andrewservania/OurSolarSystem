#pragma once
#include "Planet.h"
class Mercury :
	public Planet
{
private:
	GLfloat planetOrbitAngle = 0.0f;
	GLfloat sunOrbitAngle = 0.0f;
public:
	Mercury();
	~Mercury();
	void Render() override;
	void Update() override;
};
