#include <iostream>
#include <string>
#include "TypeWriter.h"
#include "Database.h"

int main() {
    // Initialize the built-in protection database layer
    KyzenDB::load();

    std::string userInput = "";
    TypeWriter("Welcome to KyzenAI, your personal AI assistant!", 20);

    while (userInput != "exit" && userInput != "quit") {
        std::cout << "\n>>> ";
        std::getline(std::cin, userInput);

        // Standard exit conditions
        if (userInput == "exit" || userInput == "quit" || userInput.empty()) {
            if (userInput == "exit" || userInput == "quit") break;
            continue;
        }

        TypeWriter("\nKyzenAi: ", 20);

        // Run the input through our global safety check
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