#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

class CAR {
    public:
        bool gar = false;
        std::string name;
        int user_id;
        int car_id;
        void ImportCar(std::string line);
        void PrintCar();
        void CreateCar(std::string name, int c_id);
        void rent(int u_id);
        void give_b();
};


class USER {
    public:
        std::string password;
        std::string username;
        int u_id;
        void CreateUser(std::string username, std::string password, int u_id);
        void ImportUser(std::string line);
        void CreateAdmin();
        void PrintUser();
};

class C_CONT {
    public:
        int size = 8;
        int tsize = 0;
        CAR* arr;
        std::string filename;
        int import_c(std::string filename);
        void add_car();
        void save_file();
        void re_size();
        void print_cont();
        void print_avi();
        void rent_c();
        ~C_CONT();

};

class U_CONT {
    public:
        int size = 8;
        int tsize = 0;
        USER* arr;
        std::string filename;
        int import_u(std::string filename);
        void add_user();
        void save_file();
        void re_size();
        void print_cont();
        ~U_CONT();
};

class INTERFACE {
    public:
        void initialise(U_CONT& tab);
        void show_log(U_CONT& tab);
        void login(U_CONT& tab);
        void cuser();
};

#endif 