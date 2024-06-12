#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <chrono>

int main() {
    // Start time measurement
    auto start = std::chrono::high_resolution_clock::now();

    // Open the file for reading
    std::ifstream infile("1000mb (copy).txt");
    if (!infile.is_open()) {
        std::cerr << "Error opening file for reading" << std::endl;
        return 1;
    }

    // Read the file content into a string
    std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
    infile.close();

    // Convert the content to uppercase
    std::transform(content.begin(), content.end(), content.begin(), ::toupper);

    // Open the file for writing
    std::ofstream outfile("1000mb (copy).txt");
    if (!outfile.is_open()) {
        std::cerr << "Error opening file for writing" << std::endl;
        return 1;
    }

    // Write the modified content back to the file
    outfile << content;
    outfile.close();

    // End time measurement
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    // Print the elapsed time
    std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
