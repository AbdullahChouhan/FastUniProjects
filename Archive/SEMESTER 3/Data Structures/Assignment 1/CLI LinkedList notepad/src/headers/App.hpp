#include <fstream>
#include <iostream>
#include <conio.h>

#include "DoublyLinkedList.hpp"

class App {
    private:
        App();
        char cursor;
        unsigned int cursorpos;
        std::ofstream output;
        DoublyLinkedList list;
        bool exit;
        void exitPrompt();
        void save();
        void print();
        void handleInput();
    public:
        static void Run();
};