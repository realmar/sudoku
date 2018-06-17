#pragma once

#include "defines.hpp"
#include "sudoku.hpp"

namespace realmar::sudoku {
    SUDOKU_TEMPLATE_WITH_DEFAULTS void print_sudoku(sudoku_t<TEMPLATED_TYPES> sudoku);
}
