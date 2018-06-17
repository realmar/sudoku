#pragma once

#include "sudoku.hpp"
#include <string>

namespace realmar::sudoku {
    SUDOKU_TEMPLATE sudoku_t<TEMPLATED_TYPES>::sudoku_t() {
        static_assert(Size % 3 == 0, "Size must be divisible by 3.");
    }

    SUDOKU_TEMPLATE constexpr SizeType sudoku_t<TEMPLATED_TYPES>::matrix_row_size() {
        return calculate_matrix_row_size<SizeType, Size>();
    }

    SUDOKU_TEMPLATE void sudoku_t<TEMPLATED_TYPES>::set_cell(const SizeType& x, const SizeType& y, const sudoku_cell<T>& value) {
        if (!value.has_value() && value > Size) throw std::invalid_argument("value must be smaller or equal than " + std::to_string(Size));
        _matrix[y][x] = value;
    }

    SUDOKU_TEMPLATE void sudoku_t<TEMPLATED_TYPES>::set_cell(const SizeType& x, const SizeType& y, const T& value) {
        if (value > Size) throw std::invalid_argument("value must be smaller or equal than " + std::to_string(Size));
        _matrix[y][x] = std::make_optional(value);
    }

    SUDOKU_TEMPLATE sudoku_cell<T>& sudoku_t<TEMPLATED_TYPES>::get_cell(const SizeType& x, const SizeType& y) {
        return _matrix[y][x];
    }


    SUDOKU_TEMPLATE sudoku_vector<TEMPLATED_TYPES> sudoku_t<TEMPLATED_TYPES>::get_row(const SizeType& index) const {
        return _matrix[index];
    }

    SUDOKU_TEMPLATE sudoku_vector<TEMPLATED_TYPES> sudoku_t<TEMPLATED_TYPES>::get_column(const SizeType& index) const {
        sudoku_vector<TEMPLATED_TYPES> vec;
        for (auto i = 0; i < Size; i++) vec[i] = _matrix[i][index];

        return vec;
    }
}
