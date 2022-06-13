#include "header.h"

int U_CONT::import_u(std::string filename) {
    U_CONT::arr = new USER[U_CONT::size];
    U_CONT::filename = filename;
    label1:
    std::ifstream file(U_CONT::filename);
    std::string line;
    if (file.is_open()) {
        std::cout << "File openend\n";
        while (std::getline(file, line))
        {
            ++U_CONT::tsize;
            if (U_CONT::tsize == U_CONT::size) {
                U_CONT::re_size();
            }
            U_CONT::arr[U_CONT::tsize - 1].ImportUser(line);
        }
        if(U_CONT::tsize == 0) {
            U_CONT::arr[0].CreateAdmin();
            U_CONT::tsize++;
        }    
    }
    else {
        std::cerr << "Could not open file! Do you want to change the path(1) or create a new file(2) or Quit(3) ==> ";
        std::string choice;
        label2:
        std::cin >> choice;
        if (choice == "1") {
            std::cout << "Enter new path: ";
            std::cin >> U_CONT::filename;
            goto label1;
        }
        else if(choice == "2") {
            std::ofstream file(U_CONT::filename);
            file.close();
            goto label1;
        }
        else if(choice == "3") {
            std::cout << "Returnging to menu!" << std::endl;
            return -1;
        }
        else {
            std::cout << "Error!" << std::endl;
            goto label2;
        }
    }
    file.close();
    return 0;
}

void U_CONT::add_user() {
    std::string username;
    std::string password;
    label1:
    std::cout << "Enter username: ";
    std::cin >> username;
    for(int i = 0; i < U_CONT::tsize; i++) {
        if(U_CONT::arr[i].username == username) {
            std::cout << "Username occupied" << std::endl;
            goto label1;
        }
    }
    std::cout << "Enter password: ";
    std::cin >> password;
    if(U_CONT::size == U_CONT::tsize + 1) {
        U_CONT::re_size();
    }
    U_CONT::arr[U_CONT::tsize].CreateUser(username, password, U_CONT::tsize);
    U_CONT::arr[U_CONT::tsize].PrintUser();
    U_CONT::tsize++;
}

void U_CONT::save_file() {
    std::ofstream file(U_CONT::filename);
    for(int i = 0; i < U_CONT::tsize; i++) {
        U_CONT::arr[i].PrintUser();
        file << U_CONT::arr[i].u_id << ';' << U_CONT::arr[i].username << ';' << U_CONT::arr[i].password << '\n';
    }
    file.close();
}

void U_CONT::print_cont() {
    for(int i = 0; i < U_CONT::tsize; i++)
    U_CONT::arr[i].PrintUser();
}

void U_CONT::re_size() {
    U_CONT::size = 2 * U_CONT::tsize;
    USER* temp = new USER[U_CONT::size];
    for(int i = 0; i < U_CONT::tsize; i++) {
        temp[i] = U_CONT::arr[i];
    }
    delete [] U_CONT::arr;
    U_CONT::arr = temp;
}


U_CONT::~U_CONT() {
    delete [] U_CONT::arr;
}