#pragma once

#ifndef INC_01_PONG_TEXT2_H
#define INC_01_PONG_TEXT2_H

#include <raylib.h>
#include <string>

class Text2 {
public:
	Text2() = delete;
	Text2(int xP, int yP, std::string textP, int fontSizeP, Color colorP);
	~Text2();

	void Draw();

	void SetText2(std::string textP);

private:
	int x;
	int y;
	std::string text;
	int fontSize;
	Color color;
};


#endif // !INC_01_PONG_TEXT2_H