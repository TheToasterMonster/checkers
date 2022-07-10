//
//  Piece.hpp
//  Checkers
//
//  Created by Frank Qiang on 7/9/22.
//

#ifndef Piece_hpp
#define Piece_hpp

#include "Vec2.hpp"

enum class Player {
    BLACK = 0,
    WHITE
};

class Piece {
public:
    Piece(Player side, Vec2 location);
    
    Player getSide();
    Vec2 getLocation();
    
private:
    Player m_Side;
    Vec2 m_Location;
};

#endif /* Piece_hpp */
