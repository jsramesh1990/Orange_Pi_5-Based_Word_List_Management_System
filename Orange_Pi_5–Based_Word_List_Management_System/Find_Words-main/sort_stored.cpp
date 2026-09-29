#include <iostream>
#include <fstream>
#include <set>
#include <string>

int main() {
    std::ifstream infile("stored.txt");
    if (!infile.is_open()) {
        std::cerr << "❌ Error: Could not open stored.txt\n";
        return 1;
    }

    std::set<std::string> words_set; // set automatically removes duplicates and sorts
    std::string word;

    // Read all words into set
    while (infile >> word) {
        words_set.insert(word);
    }
    infile.close();

    // Overwrite stored.txt with sorted unique words
    std::ofstream outfile("stored.txt");
    if (!outfile.is_open()) {
        std::cerr << "❌ Error: Could not write to stored.txt\n";
        return 1;
    }

    for (const auto &w : words_set) {
        outfile << w << std::endl;
    }

    outfile.close();

    std::cout << "✅ stored.txt sorted alphabetically and duplicates removed (" 
              << words_set.size() << " words).\n";
    return 0;
}

