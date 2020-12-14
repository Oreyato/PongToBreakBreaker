#include "Paddle.h"
#include "raylib.h"

Paddle::Paddle() {
	width = 32;
	height = 128;
	speedY = 5;
}

Paddle::Paddle(int xP, int yP, int widthP, int heightP, int speedP) : x(xP), y(yP), width(widthP), height(heightP), speedY(speedP) {

}

Paddle::~Paddle() {

}

RectangleAABB Paddle::GetRect()
{
	return RectangleAABB{ x, y, width, height };
}

void Paddle::Update() {
	int screenH = GetScreenHeight();

	if (IsKeyDown(KEY_UP)) {
		y -= speedY;
		if (y < 0) {
			y = 0;
		}
	}
	if (IsKeyDown(KEY_DOWN)) {
		y += speedY;
		if (y > screenH - height) {
			y = screenH - height;
		}
	}
}

void Paddle::Draw() {
	DrawRectangle(x, y, width, height, WHITE);
}

