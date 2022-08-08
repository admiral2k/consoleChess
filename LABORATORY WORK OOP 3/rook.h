#pragma once
#include "piece.h"
class Rook :
    public Piece
{
public:
    Rook(Pos position, Color color) : Piece(position, color, ROOK) {};

    bool canGo(Pos pos);
};

