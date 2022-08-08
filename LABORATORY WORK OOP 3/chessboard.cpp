#include "chessboard.h"

//проверяет, есть ли преграды на пути
bool Chessboard::isWayClear(Pos pos1, Pos pos2)
{
	int row_now = (pos1 - 1) / 8;
	int row_go = (pos2 - 1) / 8;

	int column_now = pos1 - row_now * 8;
	int column_go = pos2 - row_go * 8;

	if (column_now == column_go)
	{
		if (abs(row_go - row_now) == 1) return true;
		if (row_go > row_now)
		{
			for (int i = row_now + 1; i < row_go; i++)
			{
				if (m_array[i * 8 + column_go] != m_emptySquare) return false;
			}
			return true;
		}
		if (row_go < row_now)
		{
			for (int i = row_go + 1; i < row_now; i++)
			{
				if (m_array[i * 8 + column_go] != m_emptySquare) return false;
			}
			return true;
		}
		return false;
	}

	if (row_now == row_go)
	{
		if (abs(column_go - column_now) == 1) return true;
		if (column_go > column_now)
		{
			for (int i = column_now + 1; i < column_go; i++)
			{
				if (m_array[row_now * 8 + i] != m_emptySquare) return false;
			}
			return true;
		}
		if (column_go < column_now)
		{
			for (int i = column_go + 1; i < column_now; i++)
			{
				if (m_array[row_now * 8 + i] != m_emptySquare) return false;
			}
			return true;
		}
		return false;
	}
	if ((abs(row_now - row_go) == 1) && (abs(column_now - column_go) == 1)) return true;
	if (column_now > column_go )
	{
		int temp_col = column_now - column_go - 1;
		if (row_now > row_go)
		{
			for (int i = 1; i <= temp_col; i++)
			{
				if (m_array[(row_now - i) * 8 + column_now + i] != m_emptySquare) return false;
			}
			return true;
		}
		if (row_now < row_go)
		{
			for (int i = 1; i <= temp_col; i++)
			{
				if (m_array[(row_now + i) * 8 + column_now + i] != m_emptySquare) return false;
			}
			return true;
		}
	}

	if (column_now < column_go)
	{
		int temp_col = column_go - column_now - 1;
		if (row_now > row_go)
		{
			for (int i = 1; i <= temp_col; i++)
			{
				if (m_array[(row_now - i) * 8 + column_now - i] != m_emptySquare) return false;
			}
			return true;
		}
		if (row_now < row_go)
		{
			for (int i = 1; i <= temp_col; i++)
			{
				if (m_array[(row_now + i) * 8 + column_now - i] != m_emptySquare) return false;
			}
			return true;
		}
	}
}

Chessboard::Chessboard(Fill fill)
{
	if (fill == EMPTY)
	{
		for (int i = 0; i < 64; i++)
		{
			m_array[i] = m_emptySquare;
		}
	}
	else if (fill == CLASSIC)
	{
		//white pieces
		
		m_array[a1] = new Rook(a1, WHITE);
		m_array[b1] = new Knight(b1, WHITE);
		m_array[c1] = new Bishop(c1, WHITE);
		m_array[d1] = new Queen(d1, WHITE);
		m_array[e1] = new King(e1, WHITE);
		m_array[f1] = new Bishop(f1, WHITE);
		m_array[g1] = new Knight(g1, WHITE);
		m_array[h1] = new Rook(h1, WHITE);
		for (int i = a2; i < a3; i++)
			m_array[i] = new Pawn((Pos)i, WHITE);

		//empty space of deck
		for (int i = a3; i < a7; i++)
			m_array[i] = m_emptySquare;

		//black pieces
		for (int i = a7; i < a8; i++)
			m_array[i] = new Pawn((Pos)i, BLACK);

		m_array[a8] = new Rook(a8, BLACK);
		m_array[b8] = new Knight(b8, BLACK);
		m_array[c8] = new Bishop(c8, BLACK);
		m_array[d8] = new Queen(d8, BLACK);
		m_array[e8] = new King(e8, BLACK);
		m_array[f8] = new Bishop(f8, BLACK);
		m_array[g8] = new Knight(g8, BLACK);
		m_array[h8] = new Rook(h8, BLACK);
	}
}

//добавление фигуры
void Chessboard::add(Piece* piece)
{
	// если клетка не пустая, ошибка
	if (m_array[piece->getPos()] != m_emptySquare) abort();
	m_array[piece->getPos()] = piece;
}

//удаление фигуры
void Chessboard::remove(Pos pos)
{
	if (m_array[pos] == m_emptySquare) abort();
	delete m_array[pos];
	m_array[pos] = m_emptySquare;
}

void Chessboard::move(Pos pos1, Pos pos2)
{

	if (m_array[pos2] != m_emptySquare) this->remove(pos2);

	m_array[pos2] = m_array[pos1];
	m_array[pos1] = m_emptySquare;
	m_array[pos2]->setPos(pos2);

	if (m_currentMoveColor == WHITE)
		m_currentMoveColor = BLACK;
	else
		m_currentMoveColor = WHITE;
	return;

}

//проверка возможности хода
bool Chessboard::movePossible(Pos pos1, Pos pos2)
{
	//проверка цвета
	if (m_array[pos1]->getColor() != m_currentMoveColor) return 0;

	//т.к. у пешки сложный ход
	if (m_array[pos1]->getId() == PAWN)
	{
		if (*m_array[pos2] == *m_emptySquare)
		{
			int row_now = (pos1 - 1) / 8;
			int row_go = (pos2 - 1) / 8;
			int column_now = pos1 - row_now * 8;
			int column_go = pos2 - row_go * 8;
			bool canGo;
			//std::cout << row_now << std::endl;
			//std::cout << row_go << std::endl;
			//std::cout << column_now << std::endl;
			//std::cout << column_go << std::endl;
			if (m_array[pos1]->getColor() == WHITE)
			{
				canGo = (column_now == column_go) && (((row_now == 1) && (row_go - row_now <= 2) && (row_go - row_now > 0)) or (row_go - row_now == 1));

			}
			if (m_array[pos1]->getColor() == BLACK)
			{
				 canGo = (column_now == column_go) && (((row_now == 6) && (row_now - row_go <= 2) && (row_now - row_go > 0)) or (row_now - row_go == 1));

			}
			
			return canGo && isWayClear(pos1, pos2);
		}
	}
	return (m_array[pos1]->canGo(pos2)) && ((*m_array[pos2] == *m_emptySquare) or ((int)m_array[pos1]->getColor() + (int)m_array[pos2]->getColor() == 3)) && (m_array[pos1]->getId() == KNIGHT ? 1 : this->isWayClear(pos1, pos2));
}

Piece* Chessboard::operator[](const Pos index)
{
	return m_array[index];
}

Piece* Chessboard::operator[](const Pos index) const
{
	return m_array[index];
}

Pos str_to_pos(std::string str)
{
	int column = 0;
	char alphabet[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	for (int i = 0; i < 8; i++)
		if (str[0] == alphabet[i]) column = i + 1;
	
	if (!column) abort();
	return (Pos)(column + ((int)(str[1] - '0') - 1) * 8);
}

std::ostream& operator<<(std::ostream& out, const Chessboard& chess)
{
	std::string info[8]{ "I - pawn", "R - rook", "@ - knight", "B - bishop", "Q - queen", "K - king", "", "Type \"exit\" to leave"};
	int counter = 0, i = 0, counter2 = 0;
	for (int column = 7; column >= 0; column--)
	{
		for (int row = 1; row <= 8; row++)
		{
			i = column * 8 + row;
			switch (chess[(Pos)i]->getColor())
			{
			case BLACK:
				printf("\033[90m");
				break;
			case WHITE:
				printf("\x1B[93m");
				break;
			case NONE_COLOR:
				printf("\x1B[37m");
				break;
			}
			switch (chess[(Pos)i]->getId())
			{
			case NONE:
				out << "- ";
				break;
			case PAWN:
				out << "I ";
				break;
			case ROOK:
				out << "R ";
				break;
			case KNIGHT:
				out << "@ ";
				break;
			case BISHOP:
				out << "B ";
				break;
			case QUEEN:
				out << "Q ";
				break;
			case KING:
				out << "K ";
				break;
			}
			printf("\x1B[0m");
			counter++;
			if (counter == 8)
			{
				out  << '\t' << (counter2 < 8 ? info[counter2] : "");
				counter2++;
				out << '\n';
				counter = 0;
			}
		}
	}	
	out << "current color: " << (chess.m_currentMoveColor == WHITE ? "WHITE" : "BLACK");
	return out;
}
