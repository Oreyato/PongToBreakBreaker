#include "Text2.h"

Text2::Text2(int xP, int yP, std::string textP, int fontSizeP, Color colorP) : x(xP), y(yP), text(textP), fontSize(fontSizeP), color(colorP) {

}

Text2::~Text2() {

}

void Text2::Draw() {
	DrawText(text.c_str(), x, y, fontSize, color); //Because the "DrawText" is a C method that doesn't know strings, we have to convert it into a char*
}

void Text2::SetText2(std::string textP) {
	text = textP;
}


