#pragma once
#include "Planet.h"
class Saturn :
	public Planet
{
private:
	GLfloat planetOrbitAngle = 0.0f;
	GLfloat sunOrbitAngle = 0.0f;
public:
	Saturn();
	~Saturn();
	void Render() override;
	void Update() override;
};
