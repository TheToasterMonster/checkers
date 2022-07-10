//
//  Vec2.hpp
//  Checkers
//
//  Created by Frank Qiang on 7/9/22.
//

#ifndef Vec2_hpp
#define Vec2_hpp

struct Vec2f {
    float x, y;
};

struct Vec2 {
    int x, y;
    
    Vec2f asVec2f();
};

Vec2 operator+(const Vec2& v1, const Vec2& v2);
Vec2f operator+(const Vec2f& v1, const Vec2f& v2);

#endif /* Vec2_hpp */
