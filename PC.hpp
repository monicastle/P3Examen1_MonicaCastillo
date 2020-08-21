#include <iostream>
#include <string>
using namespace std;
class PC{
    string IP, mascara_red, hostname;
public:
    PC(){      
    } // Fin Constructor PC
    PC(string IP, string mascara_red, string hostname){
        this->IP = IP;
        this->mascara_red = mascara_red;
        this->hostname = hostname;
    } // Fin Constructor PC
    ~PC(){
    } // Fin Destructor PC
}; // Fin Class PC