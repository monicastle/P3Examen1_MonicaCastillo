#include <iostream>
#include <string>
using namespace std;
int main(){
    char respuesta = 's';
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
            
            break; }
        case 2: {

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