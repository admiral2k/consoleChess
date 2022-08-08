#include "queen.h"

bool Queen::canGo(Pos pos)
{
    int row_now = (m_pos - 1) / 8;
    int row_go = (pos - 1) / 8;

    int column_now = m_pos - row_now * 8;
    int column_go = pos - row_go * 8;
    return (m_pos != pos) && (((row_go == row_now) or (column_go == column_now)) or (abs(row_now - row_go) == abs(column_now - column_go)));
}
