#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <vector> 

int main() {
    std::ifstream newfile("output.txt");
    std::ifstream stored_in("stored.txt");
    std::ofstream stored_out("stored.txt", std::ios::app); // append mode

    if (!newfile.is_open()) {
        std::cerr << "Error: Could not open output.txt\n";
        return 1;
    }

    if (!stored_out.is_open()) {
        std::cerr << "Error: Could not open stored.txt\n";
        return 1;
    }

    // Load existing words from stored.txt into a set
    std::set<std::string> stored_words;
    std::string word;

    if (stored_in.is_open()) {
        while (stored_in >> word) {
            stored_words.insert(word);
        }
        stored_in.close();
    }

    // Compare and add new words if not already stored
    int new_count = 0;
    while (newfile >> word) {
        if (stored_words.find(word) == stored_words.end()) {
            stored_words.insert(word);
            stored_out << word << std::endl;
            new_count++;
        }
    }

    newfile.close();
    stored_out.close();

    std::cout << "✅ Comparison complete.\n";
    std::cout << "🆕 " << new_count << " new words added to stored.txt\n";

    // Step 3: Clean stored.txt (remove 1-letter lines)
    std::ifstream clean_in("stored.txt");
    std::vector<std::string> valid_words;
    while (clean_in >> word) {
        if (word.length() > 1) {  // only keep words longer than 1 character
            valid_words.push_back(word);
        }
    }
    clean_in.close();

    std::ofstream clean_out("stored.txt");
    for (const auto &w : valid_words) {
        clean_out << w << std::endl;
    }
    clean_out.close();

    std::cout << "🧹 Cleaned stored.txt (removed single-letter words)\n";

    // ✅ Step 4: Count total number of lines/words in stored.txt
    std::ifstream count_file("stored.txt");
    int line_count = 0;
    std::string temp;
    while (std::getline(count_file, temp)) {
        if (!temp.empty()) {
            line_count++;
        }
    }
    count_file.close();

    std::cout << "📄 Total words in stored.txt: " << line_count << std::endl;

    return 0;
}

