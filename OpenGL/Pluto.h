#pragma once
#include "Planet.h"
class Pluto :
	public Planet
{
private:
	GLfloat planetOrbitAngle = 0.0f;
	GLfloat sunOrbitAngle = 0.0f;
public:
	Pluto();
	~Pluto();
	void Render() override;
	void Update() override;
};

