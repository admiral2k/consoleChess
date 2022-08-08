#include "chessboard.h"

int main()
{
	Chessboard chess(CLASSIC);
	std::string input1 = "";
	std::string input2 = "";
	while (input1 != "exit" and input2 != "exit")
	{
		system("cls");
		std::cout << chess << "\nchoose piece to move:\n> ";
		std::cin >> input1;
		if (input1 == "exit") break;
		system("cls");
		std::cout << chess << "\nchoose square to go:\n> " << input1 <<" -> ";
		std::cin >> input2;
		if (input2 == "exit") break;

		if (chess.movePossible(str_to_pos(input1), str_to_pos(input2)))
			chess.move(str_to_pos(input1), str_to_pos(input2));
		else
		{
			system("cls");
			std::cout << chess;
			printf("\033[31m\nERROR\nTry again. Type any key to continue\n> \033[0m");
			std::cin >> input1;
		}
	}

	return 0;
}



//char alphabet[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
//	std::cout << alphabet[i - (i - 1) / 8 * 8 - 1] << (i - 1) / 8 + 1 << " = " << piece.canGo((Pos)i) << '\n';
	//chess.add(&piece);
	//Pos pos1 = d8;

	//int counter = 0;
	//int i = 0;
	//std::cout << *(chess[pos1]);
	//for (int column = 7; column >= 0; column--)
	//{
	//	for (int row = 1; row <= 8; row++)
	//	{
	//		i = column * 8 + row;
	//		if ((Pos)i == pos1)
	//			std::cout << "# ";
	//		else
	//			std::cout << chess.movePossible(pos1, (Pos)i) << ' ';
	//		counter++;
	//		if (counter == 8)
	//		{
	//			std::cout << '\n';
	//			counter = 0;
	//		}
	//	}
	//}
	//std::cout << '\n' << chess;

	//for (int column = 7; column >= 0; column--)
	//{
	//	for (int row = 1; row <= 8; row++)
	//	{
	//		i = column * 8 + row;
	//			switch (chess[(Pos)i]->getId())
	//			{
	//			case NONE:
	//				std::cout << "- ";
	//				break;
	//			case PAWN:
	//				std::cout << "I ";
	//				break;
	//			case ROOK:
	//				std::cout << "R ";
	//				break;
	//			case KNIGHT:
	//				std::cout << "@ ";
	//				break;
	//			case BISHOP:
	//				std::cout << "B ";
	//				break;
	//			case QUEEN:
	//				std::cout << "Q ";
	//				break;
	//			case KING:
	//				std::cout << "K ";
	//				break;
	//			}
	//		counter++;
	//		if (counter == 8)
	//		{
	//			std::cout << '\n';
	//			counter = 0;
	//		}
	//	}
	//}
	//std::cout << chess.isWayClear(a1, c3);