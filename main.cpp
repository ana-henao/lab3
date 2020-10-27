#include <iostream>
#include<fstream>
#include<math.h>

using namespace std;
string DectoBin(char letra);
string codificar(string grupo);

int main()
{
    string data;

    // Abre el archivo en modo lectura
    ifstream infile;

    // Se pone de manera explicita la ruta relativa donde se encuentra el archivo
    infile.open("../lab3/main/prueba.txt");

    // Se comprueba si el archivo fue abierto exitosamente
    if (!infile.is_open())
    {
      cout << "Error abriendo el archivo" << endl;
      exit(1);
    }

    cout << "Leyendo el archivo" << endl;
    infile >> data;

    // Se escribe el dato en la pantalla
    cout << data << endl;
    cout << "longitud: " << data.length() << endl;

    string palabraBinaria="";

    cout << "Impresion caracter a caracter" << endl;
    for (unsigned int i = 0; i < data.length(); i++) {
        cout << data.at(i) << endl;

        palabraBinaria=palabraBinaria+"|"+DectoBin(data.at(i));
    }

    cout<<palabraBinaria<<endl;

    //for (int i=0; i<palabraBinaria.length()/4; i++){

    //}

    // Se cierra el archivo abierto
    infile.close();

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
