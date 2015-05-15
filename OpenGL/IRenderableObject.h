#pragma once
class IRenderableObject
{
public:
	IRenderableObject();
	~IRenderableObject();

	int x;
	int y;
	int z;	
	
	int X() const { return x; }
	void X(int val) { x = val; }

	int Y() const { return y; }
	void Y(int val) { y = val; }


	int Z() const { return z; }
	void Z(int val) { z = val; }



};

