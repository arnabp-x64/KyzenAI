#pragma once
#include <string>
#include <unordered_set> // Used for ultra-fast O(1) hash table lookups

namespace KyzenDB {
    // The global database container stored in RAM
    inline std::unordered_set<std::string> sensitiveWords;

    bool load(const std::string& filename = "");
    bool checkSafety(const std::string& input);
}