#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

int main() {
    std::ifstream infile("input.txt");
    std::ofstream outfile("output.txt");

    if (!infile.is_open()) {
        std::cerr << "Error: Could not open input.txt\n";
        return 1;
    }

    if (!outfile.is_open()) {
        std::cerr << "Error: Could not open output.txt\n";
        return 1;
    }

    std::string word;
    std::string cleaned_word;

    while (infile >> word) {  // Read each word
        cleaned_word.clear();
        for (char ch : word) {
            if (std::isalpha(static_cast<unsigned char>(ch))) {
                cleaned_word += std::tolower(ch); // keep only alphabets
            }
        }

        if (!cleaned_word.empty()) {
            outfile << cleaned_word << std::endl;  // write to file
        }
    }

    infile.close();
    outfile.close();

    std::cout << "✅ Cleaned words written to output.txt\n";
    return 0;
}

