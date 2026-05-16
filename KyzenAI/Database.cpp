#include "Database.h"
#include <fstream>
#include <iostream>
#include <filesystem>

namespace KyzenDB {

    bool load(const std::string& filename) {
        std::string finalPath = filename;

        // Smart filesystem checks we added earlier
        if (!std::filesystem::exists(finalPath)) {
            finalPath = "../" + filename;
        }
        if (!std::filesystem::exists(finalPath)) {
            finalPath = "../../" + filename;
        }

        std::ifstream file(finalPath);
        if (!file.is_open()) {
            std::cerr << "[Global DB Error]: Could not find " << filename << "\n";
            return false;
        }

        sensitiveWords.clear(); // Empty the set before loading
        std::string word;
        while (std::getline(file, word)) {
            if (!word.empty()) {
                sensitiveWords.insert(word); // Correct function for unordered_set
            }
        }
        file.close();
        return true;
    }

    bool checkSafety(const std::string& input) {
        // Since we are checking if the user's input sentence CONTAINS a bad word, 
        // we loop through our set of bad words and use C++23 .contains()
        for (const auto& badWord : sensitiveWords) {
            if (input.contains(badWord)) {
                return false; // Dangerous word found!
            }
        }
        return true; // Input is safe
    }
}