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
        int cont = 0, numIP;
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
        string IP_Binaria = "";
        int exp = 0, digito;
        int binario = 0;
        for (int i = 0; i < 4; i++){
            numIP = stoi(numeros_IP[i]);
            while(numIP / 2 != 0){
                digito = numIP % 2;
                binario = binario + digito * pow(10.0,exp);
                exp++;
                numIP = numIP / 2;
            } // Fin While
            binario = binario + numIP * pow(10.0,exp);
            if (i == 3){
                IP_Binaria += to_string(binario);               
            } else {
                IP_Binaria += to_string(binario) + ".";
            } // Fin If
            exp = 0; 
            binario = 0;       
        } // Fin For
        cout << IP_Binaria << endl;
    } // Fin Metodo Ping

    string toString(){
        return IP + " | " + mascara_red + " | " + hostname;
    } // Fin To String

    ~PC(){
    } // Fin Destructor PC

}; // Fin Class PC