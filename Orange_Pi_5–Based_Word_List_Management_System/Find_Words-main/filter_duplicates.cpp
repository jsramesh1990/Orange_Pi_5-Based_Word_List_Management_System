#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <set>

// Function to clean text (remove numbers, symbols, etc.)
void clean_text(const std::string &input_file, const std::string &cleaned_file) {
    std::ifstream infile(input_file);
    std::ofstream outfile(cleaned_file);

    if (!infile.is_open() || !outfile.is_open()) {
        std::cerr << "Error: Could not open files.\n";
        return;
    }

    std::string word;
    std::string cleaned_word;

    while (infile >> word) {
        cleaned_word.clear();
        for (char ch : word) {
            if (std::isalpha(static_cast<unsigned char>(ch))) {
                cleaned_word += std::tolower(ch);
            }
        }

        if (!cleaned_word.empty()) {
            outfile << cleaned_word << std::endl;
        }
    }

    infile.close();
    outfile.close();
    std::cout << "✅ Cleaned words saved to " << cleaned_file << "\n";
}

// Function to filter duplicate words from a file
void filter_duplicates(const std::string &cleaned_file, const std::string &filtered_file) {
    std::ifstream infile(cleaned_file);
    std::ofstream outfile(filtered_file);
    std::set<std::string> unique_words;

    if (!infile.is_open() || !outfile.is_open()) {
        std::cerr << "Error: Could not open files.\n";
        return;
    }

    std::string word;
    while (infile >> word) {
        if (unique_words.insert(word).second) {  // Only insert if not already in set
            outfile << word << std::endl;
        }
    }

    infile.close();
    outfile.close();
    std::cout << "✅ Duplicates removed and saved to " << filtered_file << "\n";
}

int main() {
    std::string input_file = "input.txt";
    std::string cleaned_file = "output.txt";
    std::string filtered_file = "filtered.txt";

    clean_text(input_file, cleaned_file);      // Step 1: Clean text
    filter_duplicates(cleaned_file, filtered_file); // Step 2: Remove duplicates

    return 0;
}

