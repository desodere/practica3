#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bitset>
#include <string.h>


using namespace std;
using std::string;
using std::bitset;
bool compare(char* a, char* b); //Función para comparar si las cadenas de caracteres son iguales.
char* organizar_binario(char c, char *cadena);
int main2()
{
    char cadena1[15], cadena2[15], cadena3[15];
    string binario, aux="";

    ifstream fin;               //stream de entrada, lectura
    ofstream fout;              //stream de salida, escritura

    int semilla, metodo_compilacion;

    int decimal = 0;

    cout<<"Ingrese semilla: ";
    cin>>semilla;

    cout<<"Ingrese metodo de compilacion: ";
    cin>>metodo_compilacion;

    //cin.getline(cadena1, sizeof(cadena1));      //lee una cadena con espacios

    try{
        /*
        fout.open("datos.txt");       //abre el archivo para escritura
        if(!fout.is_open()){
            throw '1';
        }
        fout<<cadena1;                     //escribe la palabra
        fout.close();                   //cierra el archivo
        */
        fin.open("datos.txt");        //abre el archivo para lectura
        if(!fin.is_open()){
            throw '2';
        }



        fin.getline(cadena3,15);           //lee una linea y la almacena en cadena3

        fin.seekg(0);                   //vuelve al principio del archivo

        int i=0;
        while(fin.good()){              //lee caracter a caracter hasta el fin del archivo
            char temp=fin.get();

            if(fin.good()){
                cadena2[i]=temp;     //Asigna cada caracter leido a la cadena de caracteres
            }
            i++;
        }
        cout<<cadena2<<endl;
        for (int j = 0; j < strlen (cadena2); ++j) {
            bitset<8> bs4(cadena2[j]);
            cout << bs4 << " ";
            binario = binario + bs4.to_string();
//            cout << " tamano " << bs4.size() <<" " ;
//            for (int var = 0; var < 8; ++var) {
//                cout <<" var " <<var<<"  " << bs4[var] ;
//                //cout <<var;

//            }
//            cout << endl;
//            if (j % 6 == 0 && j != 0)
//                cout << endl;
        }
        cout<<binario<<endl;

        int nlen=binario.size();

        char nc[nlen];
        for (int j = 0; j < semilla; ++j) {
            if(binario[j]==0){
                aux[j]='1';
            }else{
                aux[j]='0';
            }
            cout << j <<endl;
            cout << binario[j] <<endl;
        }
        cout << aux<< endl;
//        cout <<h.at(o-1)<<endl;
        fin.close();                //Cierra el archivo de lectura.



    }
    catch (char c){
        cout<<"Error # "<<c<<": ";
        if(c=='1'){
            cout<<"Error al abrir el archivo para escritura.\n";
        }
        else if(c=='2'){
            cout<<"Error al abrir el archivo para lectura.\n";
        }
    }
    catch (...){
        cout<<"Error no definido\n";
    }

    if(compare(cadena1, cadena2) && compare(cadena1, cadena3))
        cout<<"Funciona!!!!\n";
    else
        cout<<"Error en la lectura de los datos!!!!\n";


    return 0;
}

//bool compare(char* a, char* b){
//    unsigned int i;
//    bool out = true;
//    for(i=0;a[i]!=0 && b[i]!=0;i++){
//        if(a[i]!=b[i]){
//            out =  false;
//        }
//    }
//    return out;
//}

//char* organizar_binario(char c, char *cadena)
//{
//    char cadenaTemporal[2];
//    cadenaTemporal[0] = c;
//    cadenaTemporal[1] = '\0';
//    strcat(cadena, cadenaTemporal);
//    return strcat(cadena, cadenaTemporal);
//}



