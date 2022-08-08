#include "piece.h"

bool Piece::operator==(const Piece& piece)
{
	return (this->m_color == piece.getColor() && this->m_pos == piece.getPos() && this->m_id == piece.getId());
}

bool Piece::operator!=(const Piece& piece)
{
	return !(*this == piece);
}

std::ostream& operator<<(std::ostream& out, const Piece& piece)
{
	char alphabet[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	out << (piece.m_color == BLACK ? "Black "
		:  piece.m_color == WHITE ? "White " : "");
	out << (piece.m_id == PAWN ? "pawn"
		: piece.m_id == ROOK ? "rook"
		: piece.m_id == KNIGHT ? "knight"
		: piece.m_id == BISHOP ? "bishop"
		: piece.m_id == QUEEN ? "queen"
		: piece.m_id == KING ? "king"
		: "empty square");
	out << " is on " << alphabet[piece.m_pos - (piece.m_pos - 1) / 8 * 8 - 1] << (piece.m_pos - 1) / 8  + 1<<'\n';
	return out;
}
