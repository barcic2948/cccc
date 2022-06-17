#include "header.h"

int C_CONT::import_c(std::string filename) {
    C_CONT::arr = new CAR[C_CONT::size];
    C_CONT::filename = filename;
    label1:
    std::ifstream file(C_CONT::filename);
    std::string line;
    if (file.is_open()) {
        std::cout << "File openend\n";
        while (std::getline(file, line))
        {
            if (line.size() > 4) {
               ++C_CONT::tsize;
                if (C_CONT::tsize == C_CONT::size) {
                    C_CONT::re_size();
                }
                C_CONT::arr[C_CONT::tsize - 1].ImportCar(line); 
            }
        }
    }
    else {
        std::cerr << "Could not open file! Do you want to change the path(1) or create a new file(2) or Quit(3) ==> ";
        std::string choice;
        label2:
        std::cin >> choice;
        if (choice == "1") {
            std::cout << "Enter new path: ";
            std::cin >> C_CONT::filename;
            goto label1;
        }
        else if(choice == "2") {
            std::ofstream file(C_CONT::filename);
            file.close();
            goto label1;
        }
        else if(choice == "3") {
            std::cout << "Returnging to menu!" << std::endl;\
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

void C_CONT::print_cont() {
    for(int i = 0; i < C_CONT::tsize; i++) {
        C_CONT::arr[i].PrintCar();
    }
}

void C_CONT::print_avi() {
    for(int i = 0; i < C_CONT::tsize; i++) {
        if(!C_CONT::arr[i].gar) {
            C_CONT::arr[i].PrintCar();
        }
    }
}

void C_CONT::add_car() {
    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;
    if(C_CONT::size == C_CONT::tsize + 1) {
        C_CONT::re_size();
    }
    C_CONT::arr[C_CONT::tsize].CreateCar(name, C_CONT::tsize);
    C_CONT::tsize++;
}

void C_CONT::rent_c() {
    
}

void C_CONT::save_file() {
    std::ofstream file(C_CONT::filename);
    for(int i = 0; i < C_CONT::tsize; i++) {
        file << C_CONT::arr[i].car_id << ';' << C_CONT::arr[i].name << ';' << C_CONT::arr[i].gar << ';' << C_CONT::arr[i].user_id << '\n';
    }
    file.close();
}

void C_CONT::re_size() {
    C_CONT::size = 2 * C_CONT::tsize;
    CAR* temp = new CAR[C_CONT::size];
    for(int i = 0; i < C_CONT::tsize; i++) {
        temp[i] = C_CONT::arr[i];
    }
    delete [] C_CONT::arr;
    C_CONT::arr = temp;
}

C_CONT::~C_CONT() {
    delete [] C_CONT::arr;
}