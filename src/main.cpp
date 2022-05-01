#include "Board.h"
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
    std::ifstream stream("test.txt");
    Board board(stream);
    if (board.solve()) {
        std::cout << "\r\nSolution: \r\n";
        board.displayBoard();
    }
    return 0;
}
