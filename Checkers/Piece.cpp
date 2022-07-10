//
//  Piece.cpp
//  Checkers
//
//  Created by Frank Qiang on 7/9/22.
//

#include "Piece.hpp"

Piece::Piece(Player side, Vec2 location) {
    m_Side = side;
    m_Location = location;
}

Player Piece::getSide() {
    return m_Side;
}

Vec2 Piece::getLocation() { 
    return m_Location;
}
