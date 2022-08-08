#pragma once

#include <iostream>
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "emptySquare.h"

enum Fill
{
	EMPTY,
	CLASSIC
};

Pos str_to_pos(std::string str);

class Chessboard
{
	Piece* m_array[65]{ nullptr };

	EmptySquare* m_emptySquare  = new EmptySquare(NONE_POS, NONE_COLOR);
	Color m_currentMoveColor = WHITE;

	bool isWayClear(Pos pos1, Pos pos2);
public:

	Chessboard(Fill fill = EMPTY);

	void add(Piece* piece);
	void remove(Pos pos);
	void move(Pos pos1, Pos pos2);
	bool movePossible(Pos pos1, Pos pos2);

	Piece* operator[] (const Pos index);
	Piece* operator[] (const Pos index) const;

	friend std::ostream& operator<< (std::ostream& out, const Chessboard& chess);
};

