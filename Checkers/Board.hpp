//
//  Board.hpp
//  Checkers
//
//  Created by Frank Qiang on 7/9/22.
//

#ifndef Board_hpp
#define Board_hpp

#include "Piece.hpp"
#include "Vec2.hpp"

class Board {
public:
    Board();
    ~Board();
    
    int getSize() const;
    
private:
    static const int s_Size = 8;

public:
    Piece* squares[s_Size][s_Size];
};

#endif /* Board_hpp */
