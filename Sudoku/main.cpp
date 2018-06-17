#include <iostream>
#include <chrono>

#include "verifier.inl"
#include "generator.inl"
#include "solver.inl"
#include "utils.inl"

using namespace realmar::sudoku;
using namespace std::chrono;

SUDOKU_TEMPLATE_WITH_DEFAULTS duration<double> do_samples(const unsigned int& sample_count)
{
    verifier<TEMPLATED_TYPES> verifier;
    solver<TEMPLATED_TYPES> solver(&verifier);
    generator<TEMPLATED_TYPES> generator(&verifier);

    duration<double> average_time{};

    for (unsigned int i = 0; i < sample_count; ++i) {
        auto sudoku = generator.generate();

        const auto start = high_resolution_clock::now();
        const auto is_valid = solver.solve(sudoku);
        const auto finish = high_resolution_clock::now();

        if (!is_valid) {
            std::cout << "\nSudoku is not solvable\n";
        }


        duration<double> elapsed = finish - start;
        average_time += elapsed;
    }

    return average_time / sample_count;
}

SUDOKU_TEMPLATE_WITH_DEFAULTS duration<double> do_single(sudoku_t<TEMPLATED_TYPES>& sudoku) {
    verifier<TEMPLATED_TYPES> verifier;
    solver<TEMPLATED_TYPES> solver(&verifier);


    const auto start = high_resolution_clock::now();
    const auto is_valid = solver.solve(sudoku);
    const auto finish = high_resolution_clock::now();

    if (!is_valid) {
        std::cout << "\nSudoku is not solvable\n";
    }


    return finish - start;
}

void main_single() {
    verifier<> verifier;
    generator<> generator(&verifier);

    auto sudoku = generator.generate();

    std::cout << "Sudoku:" << std::endl << std::endl;
    print_sudoku(sudoku);

    auto duration = do_single(sudoku);

    std::cout << std::endl << "Solved Sudoku:" << std::endl << std::endl;
    print_sudoku(sudoku);

    std::cout << std::endl << "Elapsed time: " << duration.count() << "s" << std::endl;
}

void main_samples(const unsigned int& sample_cout) {
    auto avg_duration = do_samples(sample_cout);
    std::cout << "Average elapsed time: " << avg_duration.count() << "s" << std::endl;
}

int main()
{
    std::cout << "Solving single sudoku ..." << std::endl << std::endl;
    main_single();

    const unsigned int sample_cout = 200;
    std::cout << std::endl << "Measuring performance using " << sample_cout << " samples ..." << std::endl << std::endl;
    main_samples(sample_cout);

    std::cin.get();

    return 0;
}
