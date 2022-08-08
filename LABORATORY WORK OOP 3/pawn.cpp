#include "pawn.h"

bool Pawn::canGo(Pos pos)
{
    int row_now = (m_pos - 1) / 8;
    int row_go = (pos - 1) / 8;

    int column_now = m_pos - row_now * 8;
    int column_go = pos - row_go * 8;

    //std::cout <<  m_pos << " " << pos << " " << row_now << " " << row_go << " " << column_now << " " << column_go << '\n';

    return ((row_now - row_go == ((m_color == WHITE) ? -1 : 1)) && (abs(column_now - column_go) == 1)) && (m_pos != pos);
}
