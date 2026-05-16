#pragma once
#include <string>
#include <unordered_set> 

namespace KyzenDB {
    // The global database container
    inline std::unordered_set<std::string> sensitiveWords;

    bool load(const std::string& filename);
    bool checkSafety(const std::string& input);
}