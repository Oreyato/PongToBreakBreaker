#pragma once

#ifndef INC_01_PONG_BALL_H
#define INC_01_PONG_BALL_H

#include "RectangleAABB.h"

class Ball {
public:
	Ball();
	Ball(int xP, int yP, int heightB, int widthB, int speedB); //Constructor declaration
	~Ball(); //Destructor (to free memory, /!\ it is also a binary operator, in a "if" context for example)

	RectangleAABB GetRect();

	void HorizontalBounce(int newX);
	void VerticalBounce(int newY);

	int GetX() const;
	void SetX(int xP);

	int GetWidth() const;

	void Update();
	void Draw();

private:
	int x;
	int y;
	int size;

	int height;
	int width;

	int speedX;
	int speedY;
};

#endif