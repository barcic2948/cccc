#include "header.h"

void INTERFACE::initialise(U_CONT& tab) {
    
}

void INTERFACE::show_log(U_CONT& tab) {
    std::cout << "Interface inicialised! Choose action." << std::endl;
    std::cout << "1 - Log in" << std::endl;
    std::cout << "2 - Create user" << std::endl;
    std::string choice;
    repeat:
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    if (choice == "1") {
        std::cout << "Choice 1" << std::endl;
        INTERFACE::login(tab);
    }
    else if (choice == "2") {
        std::cout << "Choice 2" << std::endl;
    }
    else {
        std::cerr << "Invalid data type!" << std::endl;
        goto repeat;
    }
}

void INTERFACE::login(U_CONT &tab) {
    std::string username;
    std::string password;
    bool cond = false;
    label1:
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    for(int i = 0; i < tab.tsize; i++) {
        if(tab.arr[i].username == username) {
            if(tab.arr[i].password == password) {
                cond = true;
                break;
            }
        }
    }
    if(cond) {
        std::cout << "Logged in!" << std::endl;
    }
    else {
        std::cout << " Wrong username/password" << std::endl;
        goto label1;
    }
}

