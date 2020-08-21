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

    void Ping(string IP, string IP_Usuario, string mascara_Usuario){
        // INICIO PING INGRESADO
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
        string IP_Binaria_Final = "", acumnumeritos = "";
        int contn = 0, cantnumeros;
        for (int i = 0; i < IP_Binaria.size(); i++){
            if (IP_Binaria[i] == '.'){
                cantnumeros = 8 - contn; 
                for (int j = 0; j < 8; j++){
                    if (j < cantnumeros) {
                        IP_Binaria_Final += "0";
                    } // Fin If                  
                } // Fin For          
                IP_Binaria_Final += acumnumeritos + ".";
                acumnumeritos = "";
                contn = 0;
            } else {
                contn++;
                acumnumeritos += IP_Binaria[i];
                if(i == IP_Binaria.size() - 1){
                    cantnumeros = 8 - contn; 
                    for (int j = 0; j < 8; j++){
                        if (j < cantnumeros) {
                            IP_Binaria_Final += "0";
                        } // Fin If                  
                    } // Fin For 
                    IP_Binaria_Final += acumnumeritos;                    
                } // Fin If 
            } // Fin If  
        } // Fin For
        // FINAL PING INGRESADO
        //
        // INICIO PING USUARIO
        vector<string> numeros_IP2;
        int cont2 = 0, numIP2;
        string acum2 = "";
        for (int i = 0; i < IP_Usuario.size(); i++){
            if (IP_Usuario[i] == '.'){
                numeros_IP2.push_back(acum2);
                acum2 = "";
            } else {
                acum2 += IP_Usuario[i];
                if (i == IP_Usuario.size() - 1){
                    numeros_IP2.push_back(acum2);
                    acum2 = "";                    
                } // Fin If             
            } // Fin If     
        } // Fin For
        string IP_Binaria2 = "";
        int exp2 = 0, digito2;
        int binario2 = 0;
        for (int i = 0; i < 4; i++){
            numIP2 = stoi(numeros_IP2[i]);
            while(numIP2 / 2 != 0){
                digito2 = numIP2 % 2;
                binario2 = binario2 + digito2 * pow(10.0,exp2);
                exp2++;
                numIP2 = numIP2 / 2;
            } // Fin While
            binario2 = binario2 + numIP2 * pow(10.0,exp2);
            if (i == 3){
                IP_Binaria2 += to_string(binario2);               
            } else {
                IP_Binaria2 += to_string(binario2) + ".";
            } // Fin If
            exp2 = 0; 
            binario2 = 0; 
        } // Fin For
        string IP_Binaria_Final2 = "", acumnumeritos2 = "";
        int contn2 = 0, cantnumeros2;
        for (int i = 0; i < IP_Binaria2.size(); i++){
            if (IP_Binaria2[i] == '.'){
                cantnumeros2 = 8 - contn2; 
                for (int j = 0; j < 8; j++){
                    if (j < cantnumeros2) {
                        IP_Binaria_Final2 += "0";
                    } // Fin If                  
                } // Fin For          
                IP_Binaria_Final2 += acumnumeritos2 + ".";
                acumnumeritos2 = "";
                contn2 = 0;
            } else {
                contn2++;
                acumnumeritos2 += IP_Binaria2[i];
                if(i == IP_Binaria2.size() - 1){
                    cantnumeros2 = 8 - contn2; 
                    for (int j = 0; j < 8; j++){
                        if (j < cantnumeros2) {
                            IP_Binaria_Final2 += "0";
                        } // Fin If                  
                    } // Fin For                     
                    IP_Binaria_Final2 += acumnumeritos2;                    
                } // Fin If 
            } // Fin If  
        } // Fin For
        // FINAL PING USUARIO
        //
        //INICIO MASCARA DE RED USUARIO
        vector<string> mascara_US;
        int cont3 = 0, num_Masc;
        string acum3 = "";
        for (int i = 0; i < mascara_Usuario.size(); i++){
            if (mascara_Usuario[i] == '.'){
                mascara_US.push_back(acum3);
                acum3 = "";
            } else {
                acum3 += mascara_Usuario[i];
                if (i == mascara_Usuario.size() - 1){
                    mascara_US.push_back(acum3);
                    acum3 = "";                    
                } // Fin If             
            } // Fin If     
        } // Fin For
        string Mascara_Binaria = "";
        int exp3 = 0, digito3;
        int binario3 = 0;
        for (int i = 0; i < 4; i++){
            num_Masc = stoi(mascara_US[i]);
            while(num_Masc / 2 != 0){
                digito3 = num_Masc % 2;
                binario3 = binario3 + digito3 * pow(10.0,exp3);
                exp3++;
                num_Masc = num_Masc / 2;
            } // Fin While
            binario3 = binario3 + num_Masc * pow(10.0,exp3);
            if (i == 3){
                Mascara_Binaria += to_string(binario3);               
            } else {
                Mascara_Binaria += to_string(binario3) + ".";
            } // Fin If
            exp3 = 0; 
            binario3 = 0; 
        } // Fin For
        string Mascara_Binaria_Final = "", acumnumeritos3 = "";
        int contn3 = 0, cantnumeros3;
        for (int i = 0; i < Mascara_Binaria.size(); i++){
            if (Mascara_Binaria[i] == '.'){
                cantnumeros3 = 8 - contn3; 
                for (int j = 0; j < 8; j++){
                    if (j < cantnumeros3) {
                        Mascara_Binaria_Final += "0";
                    } // Fin If                  
                } // Fin For          
                Mascara_Binaria_Final += acumnumeritos3 + ".";
                acumnumeritos3 = "";
                contn3 = 0;
            } else {
                contn3++;
                acumnumeritos3 += Mascara_Binaria[i];
                if(i == Mascara_Binaria.size() - 1){
                    cantnumeros3 = 8 - contn3; 
                    for (int j = 0; j < 8; j++){
                        if (j < cantnumeros3) {
                            Mascara_Binaria_Final += "0";
                        } // Fin If                  
                    } // Fin For 
                    Mascara_Binaria_Final += acumnumeritos3;                    
                } // Fin If 
            } // Fin If  
        } // Fin For
        // FINAL MASCARA DE RED USUARIO
        //
        // INICIO PROCESO DE COMPARACION
        int cont_unos = 0;
        string acumnumeros_IP1, acumnumeros_IP2, final_IP1, final_IP2;
        for (int i = 0; i < Mascara_Binaria_Final.size(); i++){
            if (Mascara_Binaria_Final[i] == '1'){
                cont_unos++;
            } // Fin If
        } // Fin For
        for (int i = 0; i < IP_Binaria_Final.size(); i++){
            if (IP_Binaria_Final[i] != '.'){
                acumnumeros_IP1 += IP_Binaria_Final[i];
            } // Fin If
        } // Fin For
        for (int i = 0; i < IP_Binaria_Final2.size(); i++){
            if (IP_Binaria_Final2[i] != '.'){
                acumnumeros_IP2 += IP_Binaria_Final2[i];
            } // Fin If
        } // Fin For
        final_IP1 = acumnumeros_IP1.substr(0, cont_unos);
        final_IP2 = acumnumeros_IP2.substr(0, cont_unos);
        if (final_IP1 == final_IP2) {
            cout << endl << "Pinging to " << IP << " with 32 bytes of data:" << endl;
            cout << "Reply from " << IP << ": bytes=32 time=37ms TTL=46" << endl; 
            cout << "Reply from " << IP << ": bytes=32 time=37ms TTL=46" << endl; 
            cout << "Reply from " << IP << ": bytes=32 time=37ms TTL=46" << endl; 
            cout << "Reply from " << IP << ": bytes=32 time=37ms TTL=46" << endl << endl;                 
            cout << endl << "Ping statistics for " << IP << ":" << endl;
            cout << "    Packets: Sent = 4, Received = 4, Lost = 0 (0% loss)" << endl << endl;         
        } else {
            cout << endl << "Pinging to " << IP << " with 32 bytes of data:" << endl;
            cout << "Reply from " << IP << ": Destination host unreachable" << endl; 
            cout << "Reply from " << IP << ": Destination host unreachable" << endl; 
            cout << "Reply from " << IP << ": Destination host unreachable" << endl; 
            cout << "Reply from " << IP << ": Destination host unreachable" << endl << endl;                 
            cout << endl << "Ping statistics for " << IP << ":" << endl;
            cout << "    Packets: Sent = 4, Received = 4, Lost = 0 (0% loss)" << endl << endl; 
        } // Fin If
        // FINAL PROCESO DE COMPARACION
    } // Fin Metodo Ping

    string toString(){
        return IP + " | " + mascara_red + " | " + hostname;
    } // Fin To String

    ~PC(){
    } // Fin Destructor PC

}; // Fin Class PC