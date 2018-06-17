#pragma once

#include <array>
#include <optional>
#include "defines.hpp"

namespace realmar::sudoku {
    template<typename SizeType, SizeType Size>
    constexpr SizeType calculate_matrix_row_size() {
        return Size / 3;
    }

    template<typename T> using sudoku_cell = std::optional<T>;
    SUDOKU_TEMPLATE_WITH_DEFAULTS using sudoku_vector = std::array<sudoku_cell<T>, Size>;
    SUDOKU_TEMPLATE_WITH_DEFAULTS using sudoku_matrix = std::array<sudoku_vector<TEMPLATED_TYPES>, Size>;

    SUDOKU_TEMPLATE_WITH_DEFAULTS class sudoku_t {
    private:
        sudoku_matrix<TEMPLATED_TYPES> _matrix;

    public:
        explicit sudoku_t();
        virtual ~sudoku_t() = default;

        constexpr static SizeType matrix_row_size();

        void set_cell(const SizeType& x, const SizeType& y, const sudoku_cell<T>& value);
        void set_cell(const SizeType& x, const SizeType& y, const T& value);
        sudoku_cell<T>& get_cell(const SizeType& x, const SizeType& y);

        sudoku_vector<TEMPLATED_TYPES> get_row(const SizeType& index) const;
        sudoku_vector<TEMPLATED_TYPES> get_column(const SizeType& index) const;
        sudoku_matrix<SizeType, calculate_matrix_row_size<SizeType, Size>(), T> get_matrix(const SizeType& x, const SizeType& y) const {
            // Requires to be inline because of the function call in the template argument. Otherwise the compiler will not
            // find a declaration for this method.

            const auto size = calculate_matrix_row_size<SizeType, Size>();
            sudoku_matrix<SizeType, size, T> matrix;

            for (auto i = 0; i < size; ++i) {
                for (auto j = 0; j < size; ++j) {
                    matrix[i][j] = _matrix[y * size + i][x * size + j];
                }
            }

            return matrix;
        }
    };
}
