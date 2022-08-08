#include "knight.h"

bool Knight::canGo(Pos pos)
{
    int row_now = (m_pos - 1) / 8;
    int row_go = (pos - 1) / 8;

    int column_now = m_pos - row_now * 8;
    int column_go = pos - row_go * 8;
    return (m_pos != pos) && (((abs(row_now - row_go) == 2) && (abs(column_now - column_go) == 1)) or ((abs(row_now - row_go) == 1) && (abs(column_now - column_go) == 2)));
}
