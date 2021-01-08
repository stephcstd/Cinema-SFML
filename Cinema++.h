#ifndef CINEMA++_H
#define CINEMA++_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>

using namespace std;

class Cinema
{
    public:
        void mainmenu();
        void movieChoice();
        void dateChoice();
        void timeChoice();
        void seatChoice();
        void paymentProcess();
        void systemUpdate();
        void viewCustomerData();
        void editCustomerData();
        void deleteCustomerData();

    protected:

    private:
};

#endif // CINEMA++_H
