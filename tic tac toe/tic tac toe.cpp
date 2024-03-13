#include <iostream>
#include <vector>
#include <string>

// Размер игрового поля
const int ROWS = 3;
const int COLS = 3;

std::vector<std::vector<char>> board(ROWS, std::vector<char>(COLS, '-'));

void DispayBoard() {
	std::cout << "  0 1 2\n";
	for (int i = 0; i < ROWS; ++i) {
		std::cout << i << " ";
		for (int j = 0; j < COLS; ++j) {
			std::cout << board[i][j] << " ";
		}
		std::cout << "\n";
	}
}

bool checkWin(char player) {
	for (int i = 0; i < ROWS; ++i) {
		if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
			return true;
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
			return true;
	}
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
		return true;
	if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
		return true;
	return false;
}

// ход игрока
void makeMove(char player) {
	int row, col;
	std::cout << "Ход игрока " << player << ". Введите строку и столбец от 0 до 2";
	std::cin >> row >> col;
	if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == '-') {
		board[row][col] = player;
	}
	else {
		std::cout << "Некорректный ход! Попробуйте еще раз.\n";
		makeMove(player);
	}
}

int main() {
	char currentPlayer = 'X';
	int moves = 0;

	std::cout << "Добро пожаловать в игру крестики нолики.\n";
	std::cout << "Игровок поле.\n";
	DispayBoard();

	while (moves < ROWS * COLS) {
		makeMove(currentPlayer);
		++moves;
		DispayBoard();
		if (checkWin(currentPlayer)) {
			std::cout << "Игрок " << currentPlayer << " победил\n";
			return 0;
		}
		currentPlayer = (currentPlayer == 'X') ? '0' : 'X';
	}

	std::cout << "Ничья\n";
	return 0;
}