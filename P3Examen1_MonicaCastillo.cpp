#include <iostream>
#include <string>
#include <vector>
#include "PC.hpp"
using namespace std;
int main(){
    char respuesta = 's';
    vector<PC *> lista_PCs;
    while (respuesta == 's'){
        int opcion;
        cout << "*******REDES*******" << endl;
        cout << "1. Agregar PC" << endl;
        cout << "2. Ingresar PC" << endl;
        cout << "3. Salida" << endl;
        cout << "********************" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion){
        case 1: {
            string IP, mascara_red, hostname;
            cout << "Ingrese la IP:";
            cin >> IP;
            cout << "Ingrese la Mascara de Red:";
            cin >> mascara_red;
            cout << "Ingrese un Hostname: ";
            cin >> hostname;
            lista_PCs.push_back(new PC(IP, mascara_red, hostname));
            cout << "Computadora agregada con exito!" << endl;
            break; }
        case 2: {
            cout << "*********PCs*********" << endl;
            for (int i = 0; i < lista_PCs.size(); i++) {
                cout << i << ". " << lista_PCs[i]->toString() << endl;
            } // Fin For
            cout << "*********************" << endl;
            int pos_PC;
            cout << "Ingrese la posicion de la PC con la que desea comunicarse: ";
            cin >> pos_PC;
            while (pos_PC < 0 || pos_PC >= lista_PCs.size()) {
                cout << "Posicion no valida!" << endl;
                cout << "Ingrese la posicion de la PC con la que desea comunicarse: ";
                cin >> pos_PC;
            } // Fin While Validacion
            PC pc;
            string comando;
            while (comando != "exit") {
                cout << lista_PCs[pos_PC]->GetHostname() << "#";
                cin >> comando;
                if (comando == "show") {
                    cout << "    IP: " << lista_PCs[pos_PC]->GetIP() << endl;
                    cout << "    Netmask: " << lista_PCs[pos_PC]->GetMascaraRed() << endl;
                } else if (comando == "exit"){
                    return 0;
                } else {
                    string acum_IP = "";
                    for (int i = 0; i < comando.size(); i++){
                        if (i > 4){
                            acum_IP += comando[i];
                        } // Fin If                       
                    } // Fin For
                    bool existeIP = false;
                    for (int i = 0; i < lista_PCs.size(); i++){
                        if (lista_PCs[i]->GetIP() == acum_IP){ 
                            existeIP = true;
                        } // Fin If                        
                    } // Fin For
                    if (existeIP == false){
                        cout << endl << "Pinging to " << acum_IP << " with 32 bytes of data:" << endl;
                        cout << "Request timed out." << endl; 
                        cout << "Request timed out." << endl;
                        cout << "Request timed out." << endl;   
                        cout << "Request timed out." << endl;
                        cout << endl << "Ping statistics for " << acum_IP << ":" << endl;
                        cout << "    Packets: Sent = 4, Received = 0, Lost = 4 (100% loss)" << endl << endl;                        
                    } else {                                               
                        pc.Ping(acum_IP);
                    } // Fin If
                } // Fin If
            } // Fin While Comandos
            break; }
        case 3: {
            // Aqui va la Salida
            respuesta = 'n';
            break; }
        default:
            cout << "¡Entrada no valida!";
        } // Fin Switch
    } // Fin While Respuesta
} // Fin Main