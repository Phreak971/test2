#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <chrono>
#include <algorithm> // For std::generate
#include <numeric>   // For std::iota (optional, for filling with sequential numbers)
#include <climits>

int main()
{
    const int SIZE = 100;
    const int NUM_ITERATIONS = 10;

    // Random Number Setup
    std::mt19937 generator(std::random_device{}()); // Better seeding for high-quality randomness
    std::uniform_int_distribution<unsigned int> distribution(0, UINT_MAX);

    // Benchmarking Function (template for flexibility)
    auto benchmark = [&](auto &container, const std::string &name)
    {
        std::cout << "\nBenchmarking " << name << ":\n";
        long long totalDuration = 0;

        for (int i = 0; i < NUM_ITERATIONS; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();

            // Fill with Random Numbers
            std::generate(std::begin(container), std::end(container), [&]()
                          { return distribution(generator); });

            // Optionally: Fill with Sequential Numbers (for comparison)
            // std::iota(std::begin(container), std::end(container), 0);

            auto end = std::chrono::high_resolution_clock::now();
            totalDuration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        }

        double averageDuration = static_cast<double>(totalDuration) / NUM_ITERATIONS;
        std::cout << "Average Time: " << averageDuration << " ns\n";
    };

    // Arrays for Benchmarking
    unsigned int cArray[SIZE];
    std::array<unsigned int, SIZE> stdArray;
    std::vector<unsigned int> stdVector(SIZE); // Preallocate to avoid resizing overhead

    // Run Benchmarks
    benchmark(cArray, "C-style Array");
    benchmark(stdArray, "std::array");
    benchmark(stdVector, "std::vector");

    return 0;
}
