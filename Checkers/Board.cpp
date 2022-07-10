//
//  Board.cpp
//  Checkers
//
//  Created by Frank Qiang on 7/9/22.
//

#include "Board.hpp"

Board::Board() {
    // initialize squares
    for (int i = 0; i < s_Size; i++) {
        for (int j = 0; j < s_Size; j++) {
            squares[i][j] = nullptr;
        }
    }
    
    // top 3 and last 3 rows contain pieces
    int rowsWithPieces[6] = { 0, 1, 2, 5, 6, 7 };
    
    // fill board with pieces
    for (int i = 0; i < s_Size; i++) {
        for (int j : rowsWithPieces) {
            if (j > 4 && (i + j) % 2) {
                // white pieces
                squares[i][j] = new Piece(Player::WHITE, Vec2{ i, j });
            } else if (j < 4 && (i + j) % 2) {
                // black pieces
                squares[i][j] = new Piece(Player::BLACK, Vec2{ i, j });
            }
        }
    }
}

Board::~Board() {
}

int Board::getSize() const {
    return s_Size;
}
