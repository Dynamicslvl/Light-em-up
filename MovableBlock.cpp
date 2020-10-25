#include "MovableBlock.h"
#include "MyFunctions.h"
#include <SFML/Graphics.hpp>

MovableBlock::MovableBlock() 
{
	//Do nothing
}

MovableBlock::~MovableBlock() 
{
	//Do nothing
}

void MovableBlock::setBody(RectangleShape body)
{
	this->body = body;
}

void MovableBlock::setImg(vector<Texture> img)
{
	this->img = img;
}

RectangleShape MovableBlock::getBody()
{
	return body;
}

void MovableBlock::limitPos()
{
	{
		int d = 32;
		if (body.getPosition().x < d) {
			this->body.setPosition(d, body.getPosition().y);
		}
		if (body.getPosition().x > 512 - d) {
			this->body.setPosition(512 - d, body.getPosition().y);
		}
		if (body.getPosition().y < d) {
			this->body.setPosition(body.getPosition().x, d);
		}
		if (body.getPosition().y > 512 - d) {
			this->body.setPosition(body.getPosition().x, 512 - d);
		}
	}
}

void MovableBlock::moveByMouse(RectangleShape obj_pointer)
{
	if (Mouse::isButtonPressed(Mouse::Button::Left)) {
		if (isBoxCollision(obj_pointer.getPosition().x, obj_pointer.getPosition().y, 5, body.getPosition().x, body.getPosition().y, 32)) {
			float x = body.getPosition().x;
			float y = body.getPosition().y;
			float xp = obj_pointer.getPosition().x;
			float yp = obj_pointer.getPosition().y;
			this->body.move((xp - x) / 4, (yp - y) / 4);
			this->select = 1;
		}
		else {
			this->select = 0;
		}
	}
	else {
		this->select = 0;
	}
}

void MovableBlock::autoAlignToGrid() 
{
	float x = body.getPosition().x;
	float y = body.getPosition().y;
	int nx = (x - 32) / 64;
	int ny = (y - 32) / 64;
	if (!select) {
		//X position
		if (x - 32 - 64 * nx < 32) {
			if (abs(x - 32 - 64 * nx) < 8) {
				body.setPosition(64 * nx + 32, y);
			}
			else body.setPosition(x - 4, y);
		}
		else {
			if (abs(64 * nx - x + 32) < 8) {
				body.setPosition(64 * nx + 32, y);
			}
			else body.setPosition(x + 4, y);
		}
		//Reload x, y
		x = body.getPosition().x;
		y = body.getPosition().y;
		nx = (x - 32) / 64;
		ny = (y - 32) / 64;
		//Y Position
		if (y - 32 - 64 * ny < 32) {
			if (abs(y - 32 - 64 * ny) < 8) {
				body.setPosition(x, 64 * ny + 32);
			}
			else body.setPosition(x, y - 4);
		}
		else {
			if (abs(64 * ny - y + 32) < 8) {
				body.setPosition(x, 64 * ny + 32);
			}
			else body.setPosition(x, y + 4);
		}
	}
}