#pragma once

#include <iostream>
#include "utils.hpp"

namespace realmar::sudoku {

    SUDOKU_TEMPLATE void print_sudoku(sudoku_t<TEMPLATED_TYPES> sudoku) {
        for (SizeType i = 0; i < Size; ++i) {
            if (i != 0 && (i - 0) % 3 == 0) std::cout << std::endl;
            for (SizeType j = 0; j < Size; ++j) {
                if (j != 0 && j % 3 == 0) std::cout << " ";

                auto cell = sudoku.get_cell(j, i);
                std::cout << (cell.has_value() ? std::to_string(*cell) : "0");
            }
            std::cout << std::endl;
        }
    }
}
