#ifndef BOARD_H
#define BOARD_H

#include <cstddef>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

class Board {
    private:
        int size_;
        std::vector<std::vector<int>> board_{};

        bool loadBoard(std::ifstream & _content);
        bool emptySlotExists(int & _i, int & _j);
        bool isUsedInRow(int const& _row, int const& _value);
        bool isUsedInColumn(int const& _column, int const& _value);
        bool isUsedInSquare(int const& _startRow, int const& _startColumn, int const& _value);
        bool isSafeEntry(int const& _row, int const& _col, int const& _value);

    public:
        Board(std::ifstream &_content) {
            if(!loadBoard(_content)) {
                ::exit(1);
            };
            displayBoard();
        }

        bool solve();
        void displayBoard();
};

#endif
