#pragma once
#include "piece.h"
class EmptySquare :
    public Piece
{
public:
    EmptySquare(Pos position, Color color) : Piece(position, color, NONE) {};

    bool canGo(Pos) { return false; }
};

