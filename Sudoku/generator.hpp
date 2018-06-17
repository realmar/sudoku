#pragma once

#include "sudoku.hpp"
#include "verifier.inl"

namespace realmar::sudoku {
    SUDOKU_TEMPLATE_WITH_DEFAULTS class generator {
    private:
        const verifier<TEMPLATED_TYPES>* _verifier;

    public:

        explicit generator(const verifier<TEMPLATED_TYPES>* verifier) : _verifier(verifier) { }
        sudoku_t<TEMPLATED_TYPES> generate() const;
    };
}
