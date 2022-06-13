#include "header.h"


void USER::ImportUser(std::string line) {
    std::stringstream ss(line);
    std::string tab[3];
    int i = 0;
    while(ss.good()) {
        std::getline(ss, tab[i], ';');
        i++;
    }
    USER::u_id = stoi(tab[0]);
    USER::username = tab[1];
    USER::password = tab[2];
}

void USER::CreateAdmin() {
    USER::u_id = 0;
    USER::username = "admin";
    USER::password = "1234";
}


void USER::CreateUser(std::string username, std::string password, int u_id) {
    USER::username = username;
    USER::password = password;
    USER::u_id = u_id;
}

void USER::PrintUser(){
    std::cout << "Username: " << USER::username << " | Password: " << USER::password << " | ID: " << USER::u_id << std::endl;
}