#pragma once

#include "generator.hpp"
// #include <random>

namespace realmar::sudoku {

    SUDOKU_TEMPLATE
        sudoku_t<TEMPLATED_TYPES> generator<TEMPLATED_TYPES>::generate() const {
        /*std::random_device random_device;
        std::mt19937 generator(random_device());
        const std::uniform_int_distribution<> random(1, Size);

        while (true) {
            sudoku_t<TEMPLATED_TYPES> sudoku;

            for (auto i = 0; i < Size; i++) {
                for (auto j = 0; j < Size; j++) {
                    sudoku.set_cell(i, j, random(generator));
                }
            }

            if (_verifier->is_valid(sudoku)) return sudoku;
        }*/

        /*sudoku_t<TEMPLATED_TYPES> sudoku;
        sudoku_vector<TEMPLATED_TYPES> vec;
        for (auto i = 0; i < Size; ++i) vec[i] = i + 1;

        for (auto i = 0; i < Size; ++i) {
            for (auto j = 0; j < Size; ++j) {
                sudoku.set_cell(i, j, vec[j]);
            }

            for (auto j = 0; j < Size; ++j) {
                auto& cell = vec[j];

                cell = *cell + 2;
                if (*cell > Size) cell = *cell - Size;
            }
        }

        auto is_valid = _verifier->is_valid(sudoku);
        return sudoku;*/

        sudoku_t<TEMPLATED_TYPES> sudoku;

        sudoku.set_cell(0, 1, 1);
        sudoku.set_cell(1, 1, 2);
        sudoku.set_cell(1, 2, 3);

        sudoku.set_cell(2, 3, 4);
        sudoku.set_cell(2, 5, 5);

        sudoku.set_cell(2, 6, 6);
        sudoku.set_cell(1, 7, 7);

        sudoku.set_cell(3, 4, 2);

        // --

        sudoku.set_cell(4, 6, 9);
        sudoku.set_cell(4, 8, 5);


        // --

        sudoku.set_cell(8, 1, 4);
        sudoku.set_cell(7, 1, 8);
        sudoku.set_cell(7, 2, 7);

        sudoku.set_cell(6, 3, 6);
        sudoku.set_cell(6, 5, 9);

        sudoku.set_cell(6, 6, 5);
        sudoku.set_cell(7, 7, 2);

        sudoku.set_cell(5, 4, 3);

        return sudoku;
    }
}
