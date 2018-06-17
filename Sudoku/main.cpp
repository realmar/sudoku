#include <iostream>
#include <chrono>

#include "verifier.inl"
#include "generator.inl"
#include "solver.inl"
#include "utils.inl"

using namespace realmar::sudoku;

int main()
{
    verifier<> verifier;
    solver<> solver(&verifier);
    generator<> generator(&verifier);

    auto sudoku = generator.generate();

    std::cout << "Sudoku:\n\n";
    print_sudoku(sudoku);

    const auto start = std::chrono::high_resolution_clock::now();
    const auto is_valid = solver.solve(sudoku);
    const auto finish = std::chrono::high_resolution_clock::now();

    if (!is_valid) {
        std::cout << "\nSudoku is not solvable\n";
    }
    else {
        std::cout << "\nSoved Sudoku:\n\n";
        print_sudoku(sudoku);
    }


    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "\nElapsed time: " << elapsed.count() << "s" << std::endl;

    // std::cin.get();

    return 0;
}
