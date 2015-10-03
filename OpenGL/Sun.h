#pragma once
#include "Planet.h"
class Sun :
	public Planet
{
private:
	GLfloat planetOrbitAngle = 0.0f;

public:
	Sun();
	~Sun();
	void Render() override;
	void Update() override;
};
