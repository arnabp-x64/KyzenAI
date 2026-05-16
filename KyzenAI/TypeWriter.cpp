#include "TypeWriter.h"
#include <iostream>
#include <thread>
#include <chrono>

void TypeWriter(const std::string& text, int delay) {
    for (char c : text) {
        std::cout << c << std::flush; // Print character immediately
        std::this_thread::sleep_for(std::chrono::milliseconds(delay)); // Pause
    }
    std::cout << std::endl; // Move to next line when finished
}