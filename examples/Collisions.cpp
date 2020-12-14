#include "Collisions.h"

bool Collisions::AABBCollision(const RectangleAABB& rectA, const RectangleAABB& rectB) {
	int xMinA = rectA.x;
	int xMaxA = rectA.x + rectA.width;
	int yMinA = rectA.y;
	int yMaxA = rectA.y + rectA.height;
	int xMinB = rectB.x;
	int xMaxB = rectB.x + rectB.width;
	int yMinB = rectB.y;
	int yMaxB = rectB.y + rectB.height;

	return !(xMinA > xMaxB || xMaxA < xMinB || yMinA > yMaxB || yMaxA < yMinB);
}
