#pragma once
#ifndef INC_01_PONG_COLLISION_H
#define INC_01_PONG_COLLISION_H

#include <raylib.h>
#include "RectangleAABB.h"

class Collisions {
public:
	static bool AABBCollision(const RectangleAABB& rectA, const RectangleAABB& rectB);
};

#endif

