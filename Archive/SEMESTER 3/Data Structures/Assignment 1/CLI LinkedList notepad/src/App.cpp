#include "headers/App.hpp"

App::App() : cursorpos(0), cursor('|') {
    std::ifstream file("text.txt");
    if (!file.is_open()) {
        std::cout << "Failed to open file.\nCreating a new file.\n";
        file.close();
        output.open("text.txt");
    }
    else {
        char c;
        while (file.get(c))
            list.insertAt(cursorpos++, c);
        file.close();
        output.open("text.txt", std::ios::app);
    }
}

void App::print() {
    std::cout << "\x1B[2J\x1B[H";
    for (int i = 0; i < list.getSize(); i++) {
        if (i == cursorpos)
            std::cout << cursor;
        else
            std::cout << list[i];
    }
    std::cout << std::endl;
}

void App::handleInput() {
    char c;
    while (1) {
        c = _getch();
        if (c != -1) {
            if (c == 0 || c == 224) {
                c = _getch();
                switch (c) {
                case 72:
                    if (cursorpos > 0)
                        cursorpos--;
                    break;
                case 80:
                    if (cursorpos < list.getSize())
                        cursorpos++;
                    break;
                case 75:
                    if (cursorpos > 0)
                        cursorpos--;
                    break;
                case 77:
                    if (cursorpos < list.getSize())
                        cursorpos++;
                    break;
                case 8:
                    if (cursorpos > 0) {
                        list.deleteAt(cursorpos);
                        cursorpos--;
                    }
                    break;
                case 27:
                    exit = true;
                    break;
                default:
                    break;
                }
            }
            else
                list.insertAt(cursorpos++, c);
            break;
        }
    }
}

void App::save() {
    for (int i = 0; i < list.getSize(); i++)
        if (i != cursorpos)
            output << list[i];
}

void App::exitPrompt() {
    std::cout << "\n\n\nDo you want to save? (y/n): ";
    char c;
    while (1) {
        c = _getch();
        if (c != -1) {
            if (c == 'y') {
                save();
                std::cout << "File saved.\n";
                break;
            }
            else if (c == 'n') {
                std::cout << "File not saved.\n";
                break;
            }
        }
    }
}

void App::Run() {
    static App app;
    while (1) {
        app.handleInput();
        app.print();
        if (app.exit) {
            app.exitPrompt();
            break;
        }
    }
    app.output.close();
}