#pragma once

#define SUDOKU_TEMPLATE             \
    template<typename SizeType,     \
             SizeType Size,         \
             typename T>

#define SUDOKU_TEMPLATE_WITH_DEFAULTS           \
    template<typename SizeType = unsigned char, \
             SizeType Size = 9,                 \
             typename T = unsigned char>

#define TEMPLATED_TYPES SizeType, Size, T
