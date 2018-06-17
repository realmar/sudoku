#pragma once

#include "solver.hpp"
#include "utils.inl"

namespace realmar::sudoku {
    template<typename SizeType, SizeType Size>
    bool increment_counters(SizeType& x, SizeType& y, bool& previous_failed) {
        ++x;
        previous_failed = false;

        if (x >= Size) { x = 0; ++y; }
        return y < Size;
    }

    template<typename SizeType, SizeType Size>
    bool decrement_counters(SizeType& x, SizeType& y, bool& previous_failed) {
        if (x == 0 && y == 0) {
            return false;
        }

        if (x > 0) {
            --x;
        }
        else if (y > 0) {
            --y;
            x = Size - 1;
        }

        previous_failed = true;
        return true;
    }

    SUDOKU_TEMPLATE bool solver<TEMPLATED_TYPES>::solve(sudoku_t<TEMPLATED_TYPES>& sudoku) const {
        if (!_verifier->is_valid(sudoku)) return false;
        if (_verifier->is_filled(sudoku)) return true;

        // make copy for reference
        sudoku_t<TEMPLATED_TYPES> original = sudoku;

        auto previous_failed = false;
        SizeType x = 0, y = 0;
        while (true) {
            auto& original_cell = original.get_cell(x, y);
            if (original_cell.has_value()) {
                if (previous_failed) {
                    decrement_counters<SizeType, Size>(x, y, previous_failed);
                    continue;
                }
                if (!increment_counters<SizeType, Size>(x, y, previous_failed)) break;
                continue;
            }

            auto& cell = sudoku.get_cell(x, y);
            if (!cell.has_value()) {
                cell = 1;
                previous_failed = false;
            }
            else {
                if (_verifier->is_valid(sudoku, x, y) && !previous_failed) {
                    if (!increment_counters<SizeType, Size>(x, y, previous_failed)) break;
                }
                else {
                    ++*cell;
                    previous_failed = false;

                    if (*cell > Size) {
                        cell.reset();
                        if (!decrement_counters<SizeType, Size>(x, y, previous_failed)) {
                            sudoku = original;
                            return false;
                        }
                    }
                }
            }
        }

        auto valid = _verifier->is_valid(sudoku);
        if (!valid) {
            sudoku = original;
            return false;
        }

        return true;
    }
}
