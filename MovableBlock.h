#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
using namespace sf;
using namespace std;

class MovableBlock
{
public:
	MovableBlock();
	~MovableBlock();
	void setBody(RectangleShape body);
	void setImg(vector<Texture> img);
	RectangleShape getBody();
	void limitPos();
	void moveByMouse(RectangleShape obj_pointer);
	void autoAlignToGrid();
private:
	RectangleShape body;
	vector<Texture> img;
	bool select = 0;
};

