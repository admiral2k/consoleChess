#pragma once
#include "piece.h"
class Bishop :
    public Piece
{
public:
    Bishop(Pos position, Color color) : Piece(position, color, BISHOP) {};

    bool canGo(Pos pos);
};

