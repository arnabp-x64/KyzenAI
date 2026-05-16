// KyzenAI.cpp : This file contains the 'main' function.
//

#include <iostream>
#include <string>
#include "TypeWriter.h"
#include "Database.h" // Include our global database system

int main() {
    // Initialize the global database once at startup
    if (!KyzenDB::load("sensitive_words.txt")) {
        TypeWriter("Warning: Booting without security protocols.\n", 20);
    }

    std::string userInput;
    TypeWriter("Welcome to KyzenAI, your personal AI assistant!\n", 20);

    while (userInput != "exit" && userInput != "quit") {
        std::cout << ">>> ";
        std::getline(std::cin, userInput);


        if (userInput == "exit" || userInput == "quit") {
            break;
        }

        TypeWriter("KyzenAi: ", 20);



        // Use the global database safety check
        if (!KyzenDB::checkSafety(userInput)) {
            TypeWriter("Sorry, I can't help you with that.\n", 20);
        }
        else {
            TypeWriter("You said: " + userInput + "\n", 20);
        }
    }

    TypeWriter("Shutting down KyzenAI. Goodbye!\n", 20);
    return 0;
}