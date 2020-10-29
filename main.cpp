#include <iostream>
#include<fstream>
#include<math.h>

using namespace std;
string DectoBin(char letra);
string codificar(string grupo);
void mostrar(string palabra, int b);
string decod(string grupo);
string codificacionpalabra(string data);

int main()
{
    string data;

    // Abre el archivo en modo lectura
    ifstream infile;

    // Se pone de manera explicita la ruta relativa donde se encuentra el archivo
    infile.open("../funcion/BD/Sudo.txt");

    // Se comprueba si el archivo fue abierto exitosamente
    if (!infile.is_open())
    {
      cout << "Error abriendo el archivo" << endl;
      exit(1);
    }

    string user="";
    string contra="";

    while (!infile.eof()){

   // cout << "Leyendo el archivo" << endl;
    infile >> data;

    // Se escribe el dato en la pantalla
   // cout << data << endl;
    //cout << "longitud: " << data.length() << endl;


    bool controlu=false;
    for (int i=0; i<data.length(); i++){
        if (data.at(i)=='u'){
            controlu=true;
            continue;
        }
        if (data.at(i)=='c'){
            controlu=false;
            continue;
        }
        if (controlu){
            user=user+data.at(i);
        }
        else{
            contra=contra+data.at(i);
        }
    }

    // Se cierra el archivo abierto
    }
    infile.close();
    //cout << user<< endl;
    //cout << contra<< endl;
//menu
    int opcion;
    int cedu;
    int clave;
    int saldo;
    int cedula;
    int con;
    int opci;
    cout << "bienvenido al cajero.";
    cout<<"menu: "<< endl;
    cout <<"Desea ingresar como: 1.Administrador   2.Usuario";
    cin >> opcion;
    while (opcion=='1' or opcion=='2'){
        if(opcion=='1'){
            cout << "registro de usuarios: ";
            cout << "Ingrese la cedula del usuario: "<< endl;
            cin >> cedu;
            cout << "Ingrese la clave del usuario: " << endl;
            cin >> clave;
            cout << "Ingrese el saldo del usuario: "<< endl;
            cin >> saldo;

        }
        else if(opcion=='2'){
            cout << "Ingrese al sistema: "<< endl;
            cout << "Ingrese su numero de cedula: ";
            cin >> cedula;
            cout << "Ingrese su clave: "<< endl;
            cin >> con;
            cout << "acceso aceptado.";
            cout << "opciones: 1.Consutar saldo  2.Retirar dinero"<< endl;
            cin >> opci;
            if (opci=='1'){

            }
            else{

            }
        }

    }

    string usuario;
    string contrasena;
    cout <<"ingrese usuario administrador: "<< endl;
    cin >> usuario;
    cout << "ingrese contrasena: "<< endl;
    cin >> contrasena;
    usuario=codificacionpalabra(usuario);
    contrasena=codificacionpalabra(contrasena);

    //cout <<"usuario: "<< codificacionpalabra(usuario)<< endl;
    //cout<<"contraseña: "<<codificacionpalabra(contrasena)<< endl;

    if (user==usuario && contra==contrasena){
           cout << "autenticacion valida."<< endl;
    }
    else{
        cout<<"contrasena o usuario erroneo."<< endl;
    }


    return 0;
}


string DectoBin(char letra){
    int Ascii=letra;
    string binario="";

    for(int i=7; i>=0; i--){//codificar a binario(8 bits 0-7)
        if(pow(2,i)<=Ascii){
            binario=binario+"1";//agrega un uno si en la suma cabe el siguiente numero
            Ascii-=pow(2,i);//se le quita el valor que al que se le agrega el ascii
        }
        else{
            binario=binario+"0";//si no esta, se le agrega el cero
        }
    }
    return binario;
}

string codificar(string grupo){//toma el ultimo dato y lo pone al incicio
    string nuevo=grupo.substr(0,3);//extrae desde la posicion o a la 3
    string nuevoFinal=grupo.at(3)+nuevo;//toma el ultimo valor y lo pone al inicio
    return nuevoFinal;


}

void mostrar(string palabra, int b){

    cout<<endl;
    for(unsigned int i=0; i<palabra.length()/b;i++){

        string palabra_="";
        for (unsigned int j=i*b;j<((i*b)+b);j++){
            palabra_=palabra_+palabra.at(j);
        }
        //string palabra_=palabra.substr(8,16);
        cout<<palabra_<<"|";

        }
}

string decod(string grupo){
    char primer=grupo.at(0);
    string salida=grupo.substr(1,4)+primer;
    return salida;

}

string codificacionpalabra(string data){
    string palabraBinaria="";


    for (unsigned int i = 0; i < data.length(); i++) {
        //cout << data.at(i) << endl;

        palabraBinaria=palabraBinaria+DectoBin(data.at(i));
    }

    //mostrar(palabraBinaria, 8);

     cout << endl;
    string palabraCodificada="";
    for (unsigned int i=0; i<palabraBinaria.length()/4; i++){//la longitud de palabra binaria se divide entre 4, por que se sabe que se van a tomar de a 4 caracteres.para que en la ultima teracion el string tenga las posiciones necesarias para ietrar
        string palabra_="";
        for (unsigned int j=i*4;j<((i*4)+4);j++){
            palabra_=palabra_+palabraBinaria.at(j);
        }
        palabraCodificada=palabraCodificada+codificar(palabra_);
    }

    //mostrar(palabraCodificada, 4);

    return palabraCodificada;
}
