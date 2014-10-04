#pragma once
class KeyBoardControl
{
public:
	KeyBoardControl();	
	~KeyBoardControl();
	void ListenToKeys(unsigned char key, int x, int y);
};

