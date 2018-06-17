#pragma once

#include "verifier.hpp"

namespace realmar::sudoku {
    SUDOKU_TEMPLATE bool verifier<TEMPLATED_TYPES>::is_vector_valid(const sudoku_vector<TEMPLATED_TYPES>& vector) const {
        std::unordered_set<sudoku_cell<T>> set;
        for (auto&& item : vector) {
            if (!item.has_value()) continue;
            if (set.find(item) != set.end()) return false;
            set.emplace(item);
        }

        return true;
    }

    SUDOKU_TEMPLATE bool verifier<TEMPLATED_TYPES>::is_valid(const sudoku_t<TEMPLATED_TYPES>& sudoku) const {
        for (auto i = 0; i < Size; i++) {
            if (!is_vector_valid(sudoku.get_row(i))) return false;
            if (!is_vector_valid(sudoku.get_column(i))) return false;
        }

        const auto row_size = sudoku.matrix_row_size();
        for (auto i = 0; i < row_size; i++) {
            for (auto j = 0; j < row_size; j++) {
                if (!is_matrix_valid(sudoku.get_matrix(i, j))) return false;
            }
        }

        return true;
    }


    SUDOKU_TEMPLATE bool verifier<TEMPLATED_TYPES>::is_filled(sudoku_t<TEMPLATED_TYPES>& sudoku) const {
        for (auto i = 0; i < Size; i++) {
            for (auto j = 0; j < Size; j++) {
                sudoku_cell<T>& cell = sudoku.get_cell(i, j);
                if (!cell.has_value()) return false;
            }
        }

        return true;
    }
}
