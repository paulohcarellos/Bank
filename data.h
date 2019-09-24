#ifndef DATA.H
#define DATA.H

#include <ctime>
#include <iostream>
#include <string>


using namespace std;
class Data{

        private :
                string _Data;
        public :
                void Obter_Data();
                ~Data();
                string Get_data();
};


#endif // DATA
