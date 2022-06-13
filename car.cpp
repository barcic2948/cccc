#include "header.h"

void CAR::ImportCar(std::string line) {
    std::stringstream ss(line);
    std::string tab[4];
    int i = 0;
    while(ss.good()) {
        std::getline(ss, tab[i], ';');
        i++;
    }
    CAR::car_id = stoi(tab[0]);
    CAR::name = tab[1];
    CAR::gar = stoi(tab[2]);
    CAR::user_id = stoi(tab[3]);
}

void CAR::CreateCar(std::string name, int c_id) {
    CAR::name = name;
    CAR::car_id = c_id;
    CAR::gar = true;
    CAR::user_id = 0;
}

void CAR::rent(int u_id) {
    CAR::gar = true;
    CAR::user_id = u_id;
}

void CAR::give_b() {
    CAR::gar = false;
    CAR::user_id = false;
}

void CAR::PrintCar() {
    std::cout << "Name: " << CAR::name << " | Id: " << CAR::car_id << " | Rented: " << CAR::gar << " | By: " << CAR::user_id << std::endl;
}