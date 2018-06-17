#pragma once

#include <unordered_set>
#include "sudoku.inl"
#include "defines.hpp"

namespace realmar::sudoku {
    SUDOKU_TEMPLATE_WITH_DEFAULTS class verifier {
    private:
        bool is_vector_valid(const sudoku_vector<TEMPLATED_TYPES>& vector) const;
        bool is_matrix_valid(const sudoku_matrix<SizeType, calculate_matrix_row_size<SizeType, Size>(), T>& matrix) const {
            std::unordered_set<sudoku_cell<T>> set;
            for (auto&& vec : matrix) {
                for (auto&& item : vec) {
                    if (!item.has_value()) continue;
                    if (set.find(item) != set.end()) return false;
                    set.emplace(item);
                }
            }

            return true;
        }

    public:
        bool is_valid(const sudoku_t<TEMPLATED_TYPES>& sudoku) const;
        bool is_filled(sudoku_t<TEMPLATED_TYPES>& sudoku) const;
    };
}
