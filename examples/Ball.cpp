#include "Ball.h"
#include "raylib.h"


Ball::Ball() {
	x = 0;
	y = 0;
	size = 32;

	width = size;
	height = size;

	speedX = 0;
	speedY = 0;

	released = 0;
}

Ball::Ball(int xP, int yP, int heightB, int widthB, int speedB, bool releasedB) : x(xP), y(yP), height(heightB), width(widthB), speedX(speedB), speedY(speedB), released(releasedB) { // Constructor definition outside the class

}

Ball::~Ball() {

}

RectangleAABB Ball::GetRect()
{
	return RectangleAABB{ x, y, width, height };
}

void Ball::HorizontalBounce(int newX) {
	speedX = -speedX;
	x = newX;
}

void Ball::VerticalBounce(int newY) {
	speedY = -speedY;
	y = newY;
}


bool Ball::Released(int releasedB) { //Pressing spacebar to release the ball ONCE
	if (releasedB == 0) {
		if (IsKeyDown(KEY_SPACE)) {
			releasedB = 1;
			return false;
		}
		else return true;
	}
	else return true;
}

void Ball::Update() {
	int screenW = GetScreenWidth();
	int screenH = GetScreenHeight();

	bool released = Released(1);

	if (released) {
		x += speedX;
		y += speedY;

		if (x > screenW - width) {
			HorizontalBounce(screenW - width);
		}

		if (y < 0) {
			VerticalBounce(0);
		}
		if (y > screenH - height) {
			VerticalBounce(screenH - height);
		}
	}
}

int Ball::GetX() const {
	return x;
}

void Ball::SetX(int xP) {
	x = xP;
}

int Ball::GetWidth() const {
	return size;
}

void Ball::Draw() {
	DrawRectangle(x, y, height, width, WHITE);
}
