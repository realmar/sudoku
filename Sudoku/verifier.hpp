#pragma once

#include "sudoku.inl"
#include "defines.hpp"

namespace realmar::sudoku {
    SUDOKU_TEMPLATE_WITH_DEFAULTS class verifier {
    private:
        bool is_vector_valid(const sudoku_vector<TEMPLATED_TYPES>& vector) const;
        bool is_matrix_valid(const sudoku_matrix<SizeType, calculate_matrix_row_size<SizeType, Size>(), T>& matrix) const {
            std::array<bool, Size> occupied{};
            for (auto&& vector : matrix) {
                for (auto& item : vector) {
                    if (!item.has_value()) continue;
                    if (occupied[item.value() - 1]) return false;
                    occupied[item.value() - 1] = true;
                }
            }
            return true;
        }

    public:
        bool is_valid(const sudoku_t<TEMPLATED_TYPES>& sudoku) const;
        bool is_filled(sudoku_t<TEMPLATED_TYPES>& sudoku) const;
    };
}
