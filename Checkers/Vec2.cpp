//
//  Vec2.cpp
//  Checkers
//
//  Created by Frank Qiang on 7/9/22.
//

#include "Vec2.hpp"

Vec2f Vec2::asVec2f() { 
    return Vec2f{ (float)x, (float)y };
}

Vec2 operator+(const Vec2& v1, const Vec2& v2) {
    return Vec2{ v1.x + v2.x, v1.y + v2.y };
}

Vec2f operator+(const Vec2f& v1, const Vec2f& v2) {
    return Vec2f{ v1.x + v2.x, v1.y + v2.y };
}
