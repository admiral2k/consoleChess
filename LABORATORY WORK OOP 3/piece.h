#pragma once
#include <cmath>
#include <iostream>
#include <string>

//перечисления класса
enum Color
{
	NONE_COLOR = 0,
	WHITE = 1,
	BLACK = 2
};

enum Pos
{
	NONE_POS = 0,
	a1, b1, c1, d1, e1, f1, g1, h1,
	a2, b2, c2, d2, e2, f2, g2, h2,
	a3, b3, c3, d3, e3, f3, g3, h3,
	a4, b4, c4, d4, e4, f4, g4, h4,
	a5, b5, c5, d5, e5, f5, g5, h5,
	a6, b6, c6, d6, e6, f6, g6, h6,
	a7, b7, c7, d7, e7, f7, g7, h7,
	a8, b8, c8, d8, e8, f8, g8, h8
};

enum Id
{
	NONE,
	PAWN,
	ROOK,
	KNIGHT,
	BISHOP,
	QUEEN,
	KING
};

class Piece
{
protected:
	Pos m_pos;
	Color m_color;
	Id m_id;

	//конструкторы в классе Piece пишу в protected, чтобы нельзя было создать объект этого класса. Он базовый.
	// у фигуры должна быть позиция и цвет, поэтому конструктор по умолчанию не создаю.
	Piece(Pos position, Color color, Id id) :m_color(color), m_pos(position), m_id(id) {}
public:
	virtual bool canGo(Pos) = 0;

	//getters
	Pos   getPos()   { return m_pos; }
	Color getColor() { return m_color; }
	Id    getId()    { return m_id; }

	Pos   getPos() const   { return m_pos; }
	Color getColor() const { return m_color; }
	Id    getId() const    { return m_id; }

	//setters
	void setPos(Pos pos) { m_pos = pos; }
	void setColor(Color color) { m_color = color; }
	void setId(Id id) { m_id = id; }

	bool operator== (const Piece& piece);
	bool operator!= (const Piece& piece);

	friend std::ostream& operator<< (std::ostream& out, const Piece& piece);
};
