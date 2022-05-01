#include "Board.h"
#include <iostream>

bool Board::loadBoard(std::ifstream & _content) {
    int number = 0;
    int i = 0;
    int j = 0;

    _content >> number;
    size_ = number;
    board_.push_back({});

    while (_content >> number) {
        if (j == size_) {
            board_.push_back({});
            j = 0;
            i++;
        }

        board_.at(i).push_back(number);
        j++;
        if (j == size_ && i == size_ -1) {
            i++;
        }
    }

    return i == j && i == size_;
}

bool Board::emptySlotExists(int & _i, int & _j) {
    for (_i = 0; _i < size_; _i++) {
        for (_j = 0; _j < size_; _j++) {
            if (board_.at(_i).at(_j) == 0) {
                return true;
            }
        }
    }

    return false;
}

bool Board::isUsedInRow(int const& _row, int const& _value) {
    for (int col = 0; col < size_; col++) {
        if (board_.at(_row).at(col) == _value) {
            return true;
        }
    }

    return false;
}

bool Board::isUsedInColumn(int const& _col, int const& _value) {
    for (int row = 0; row < size_; row++) {
        if (board_.at(row).at(_col) == _value) {
            return true;
        }
    }

    return false;
}

bool Board::isUsedInSquare(int const& _startRow, int const& _startColumn, int const& _value) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board_.at(_startRow + row).at(_startColumn + col) == _value) {
                return true;
            }
        }
    }

    return false;
}

bool Board::isSafeEntry(int const& _row, int const& _col, int const& _value) {
    return !isUsedInRow(_row, _value) && !isUsedInColumn(_col, _value) && !isUsedInSquare(_row - _row % 3, _col - _col % 3, _value);
}

bool Board::solve() {
    int i;
    int j;

    if (!emptySlotExists(i, j)) {
        return true;
    }

    for (int num = 1; num <= size_; num++) {
        if (isSafeEntry(i, j, num)) {
            board_.at(i).at(j) = num;
            if (solve()) {
                return true;
            }
            board_.at(i).at(j) = 0;
        }
    }

    return false;
}

void Board::displayBoard() {
    for (auto const& vec : board_) {
        for (auto const& item : vec) {
            std::cout << " " << item;
        }
        std::cout << "\r\n";
    }
}
