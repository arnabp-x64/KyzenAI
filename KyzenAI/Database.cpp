#include "Database.h"
#include <iostream>
#include <algorithm> // Required for std::transform

namespace KyzenDB {

    bool load(const std::string& filename) {
        sensitiveWords.clear();

        // Hardcoded technical hacking database (Zero-file setup)
        sensitiveWords.insert("reverse shell");
        sensitiveWords.insert("cmd.exe");
        sensitiveWords.insert("/bin/sh");
        sensitiveWords.insert("powershell");
        sensitiveWords.insert("malware");
        sensitiveWords.insert("hack");
        sensitiveWords.insert("netcat");
        sensitiveWords.insert("nc -e");
        sensitiveWords.insert("buffer overflow");
        sensitiveWords.insert("sql injection");
        sensitiveWords.insert("xxx"); // Temporary testing key

        std::cout << "[Security]: Built-in protection matrix loaded successfully.\n";
        return true;
    }

    bool checkSafety(const std::string& input) {
        // 1. Create a copy of the string to safely modify
        std::string lowerInput = input;

        // 2. Convert user input to lowercase to prevent capitalization bypasses
        std::transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);

        // 3. Loop through our hash table and scan the string
        for (const auto& badWord : sensitiveWords) {
            if (lowerInput.contains(badWord)) {
                return false; // Malicious term detected!
            }
        }
        return true; // Safe content
    }
}