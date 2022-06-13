#include "header.h"


int main() {
    std::string filename = "C:\\Users\\barci\\Desktop\\porjecyt\\data\\users.txt";
    std::string filename2 = "C:\\Users\\barci\\Desktop\\porjecyt\\data\\cars.txt";
    C_CONT tab;
    std::cout << tab.import_c(filename2) << std::endl;
    tab.add_car();
    tab.print_cont();
    tab.save_file();
    //U_CONT tab(filename);
    //std::cout << "Hello, world!\n";
    //INTERFACE interface;
    //interface.show_log(tab);
    //tab.add_user();
    //tab.save_file();
}
