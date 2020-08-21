#include <iostream>
#include <string>
#include <vector>
#include <cmath>
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

    string GetIP(){
        return IP;
    } // Fin Get IP

    void SetIP(string IP){
        this->IP = IP;
    } // Fin Set IP

    string GetMascaraRed(){
        return mascara_red;
    } // Fin Get Mascara Red

    void SetMascaraRed(string mascara_red){
        this->mascara_red = mascara_red;
    } // Fin Set Mascara Red

    string GetHostname(){
        return hostname;
    } // Fin Get Mascara Red

    void SetHostname(string hostname){
        this->hostname = hostname;
    } // Fin Set Mascara Red

    void Ping(string IP){
        vector<string> numeros_IP;
        int cont = 0, numID;
        string acum = "";
        for (int i = 0; i < IP.size(); i++){
            if (IP[i] == '.'){
                numeros_IP.push_back(acum);
                acum = "";
            } else {
                acum += IP[i];
                if (i == IP.size() - 1){
                    numeros_IP.push_back(acum);
                    acum = "";                    
                } // Fin If             
            } // Fin If     
        } // Fin For
               cout << "lolis" << endl;
        string IP_Binaria = "";
        int acum1 = 0, acum2 = 0, digito, residuo;
        for (int i = 0; i < 4; i++){
            numID = stoi(numeros_IP[i]);
            acum1 = 0;
            acum2 = 0;
            while(numID != 0){
                digito = numID % 10;
                if (digito == 0 || digito == 1) {
                    int exp = 0, p = 1;
                    p = p + digito * (int) pow(2, exp);
                    exp++;
                    residuo = numID % 10;
                    numID = numID / 10;
                    acum1 = acum1 + p;
                    acum2 --;
                } // Fin If
            } // Fin While 
            IP_Binaria += acum2 + ".";          
        } // Fin For
        cout << IP_Binaria << "IPDOPE";
    } // Fin Metodo Ping

    string toString(){
        return IP + " | " + mascara_red + " | " + hostname;
    } // Fin To String

    ~PC(){
    } // Fin Destructor PC

}; // Fin Class PC