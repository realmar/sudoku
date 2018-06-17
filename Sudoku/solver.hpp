#pragma once

#include "sudoku.inl"
#include "verifier.hpp"

namespace realmar::sudoku {
    SUDOKU_TEMPLATE_WITH_DEFAULTS class solver {
    private:
        const verifier<TEMPLATED_TYPES>* _verifier;

    public:
        explicit solver(verifier<TEMPLATED_TYPES>* verifier) : _verifier(verifier) { }
        bool solve(sudoku_t<TEMPLATED_TYPES>& sudoku) const;
    };
}
