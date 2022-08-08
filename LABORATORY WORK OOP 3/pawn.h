#pragma once
#include "piece.h"
class Pawn :
    public Piece
{
public:

    Pawn(Pos position, Color color) : Piece(position, color, PAWN) {};

    bool canGo(Pos pos);
};

