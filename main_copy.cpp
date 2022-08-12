#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <bitset>

using namespace std;

bool compare(char* a, char* b);

char* codimetodo1(char *a,char *b, int s,int t);
char* decometodo1(char *a,char *b, int s,int t);

int main()
{
    char cadena1[15], cadena2[15], cadena3[15];
    string  nombre;

    ifstream fin;               //stream de entrada, lectura
    ofstream fout;              //stream de salida, escritura

    int semilla=4, metodo_compilacion=1;
    int nlen_cadena = 0 ;

    cout<<"Ingrese nombre del archivo: ";
    cin>>nombre;
    //nombre = "datos.txt";

    cout<<"Ingrese semilla: ";
    cin>>semilla;

//    cout<<"Ingrese metodo de compilacion: ";
//    cin>>metodo_compilacion;


    try{


        fin.open(nombre);        //abre el archivo para lectura
        if(!fin.is_open()){
            throw '2';
        }

        fin.getline(cadena3,15);           //lee una linea y la almacena en cadena3
        cout <<cadena3<<endl;
        fin.seekg(0);                   //vuelve al principio del archivo

        int i=0;
        while(fin.good()){              //lee caracter a caracter hasta el fin del archivo
            char temp=fin.get();

            if(fin.good()){
                cadena2[i]=temp;     //Asigna cada caracter leido a la cadena de caracteres
            }
            i++;
        }

        nlen_cadena = strlen (cadena2);

        char aux[strlen(cadena2)*8];
        int size_binario = 0;
        cout << " Texto del archivo en binario " << endl ;
        for (int j = 0; j < nlen_cadena; ++j) {
            bitset<8> bs4(cadena2[j]);      //creo una variable y convierto los caracteres a binario
            //cout << bs4 << " ";
            char a ;
            //binario = binario + bs4.to_string();
            //cout << " tamano " << bs4.size() <<" " ;
            int nta = bs4.size();
            for (int var = 0; var < nta; ++var) {

                cout  << bs4[nta-(var+1)] ;

                a = bs4[nta-(var+1)];
                if(a == 0 ){

                    aux[size_binario] ='0';
                }else{

                aux[size_binario] ='1';
                }
                size_binario++;
                //}
                //cout <<var;

            }
            //cout << endl;
//            cout << aux << endl;
            if (j % 6 == 0 && j != 0)
                cout << endl;
        }
        cout << endl;
        cout << endl;

        //cout <<" aux\t" << aux << endl;

        char binario[size_binario];
        cout <<"codificadar..." << endl;
        codimetodo1(aux,binario,semilla,size_binario);
        cout << binario << endl;

        fin.close();                //Cierra el archivo de lectura.





        cout << endl;
        cout <<"Decodificado..." << endl;
        char binario2[size_binario];
        decometodo1(binario,binario2,semilla,size_binario);
        cout << binario2 << endl;


        string contenido;
        //contenido = "Hola";
        contenido = binario2;
        ofstream fstemp("datos3.txt");
        if(!fstemp) //no se pudo abrir alguno de los 2
          {
            cout << "Error al abrir el archivo!" << endl;

          }

        //modificar linea a linea
        fstemp << contenido << endl;
        fstemp.close();
        cout << endl;
        cout << endl;
        cout << "El archivo ha sido modificado correctamente" << endl;


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

    if(compare(cadena1, cadena2) && compare(cadena1, cadena3)){
        //cout<<"Funciona!!!!\n";
        cout<<endl;
    }else{
        cout<<"Error en la lectura de los datos!!!!\n";
    }

    return 0;
}

bool compare(char* a, char* b){
    unsigned int i;
    bool out = true;
    for(i=0;a[i]!=0 && b[i]!=0;i++){
        if(a[i]!=b[i]){
            out =  false;
        }
    }
    return out;
}

char* codimetodo1(char *a,char *b, int s,int t){
    int n = 0 ;
    int n1 = t/s;
    if (t%s!=0)
        n1++;
    int cantidad_1 = 0,cantidad_0 = 0;
    while (n1>0) {


        if(n==0){
            for (int i = 0; i < s; ++i) {
                if(a[i]=='0'){
                    cantidad_0++;
                   b[i]='1' ;
                }else{
                    cantidad_1++;
                    b[i]='0' ;
                }
            }

        }else{
            if(cantidad_0==cantidad_1){
                cantidad_1 = 0,cantidad_0 = 0;
                for (int i = 0; i < s; ++i) {
                    if(a[n+i]=='0'){
                       cantidad_0++;
                       b[n+i]='1' ;
                    }else{
                        cantidad_1++;
                        b[n+i]='0' ;
                    }
                }
            }else if(cantidad_0>cantidad_1){
                cantidad_1 = 0,cantidad_0 = 0;
                for (int i = 0; i < s; ++i) {
                    if((i+1) % 2 == 0 and i!=0){
                        if(a[n+i]=='0'){
                            cantidad_0++;
                           b[n+i]='1' ;
                        }else{
                            cantidad_1++;
                            b[n+i]='0' ;
                        }
                    }else{
                        if(a[n+i]=='1'){
                            cantidad_1++;
                            b[n+i]='1';
                        }else{
                            cantidad_0++;
                            b[n+i]='0';
                        }

                    }
                }
            }else if(cantidad_1>cantidad_0){
                cantidad_1 = 0,cantidad_0 = 0;
                for (int i = 0; i < s; ++i) {
                    if((i+1) % 3 == 0 and i!=0){
                        if(a[n+i]=='0'){
                            cantidad_0++;
                           b[n+i]='1' ;
                        }else{
                            cantidad_1++;
                            b[n+i]='0' ;
                        }
                    }else{
                        if(a[n+i]=='1'){
                            cantidad_1++;
                            b[n+i]='1' ;
                        }else{
                            cantidad_0++;
                            b[n+i]='0' ;
                        }

                    }
                }
            }

        }
        n=n+s;
        n1--;
    }
    if (t%s==0)
        b[n]='\0' ;
    else
        b[n-1]='\0' ;
    return 0;
}

char* decometodo1(char *a,char *b, int s,int t){
    int n = 0 ;
    int n1 = t/s;
    if (t%s!=0)
        n1++;
    int cantidad_1 = 0,cantidad_0 = 0;
    while (n1>0) {


        if(n==0){
            for (int i = 0; i < s; ++i) {
                if(a[i]=='0'){
                    cantidad_0++;
                   b[i]='1' ;
                }else{
                    cantidad_1++;
                    b[i]='0' ;
                }
            }

        }else{
            if(cantidad_0==cantidad_1){
                cantidad_1 = 0,cantidad_0 = 0;
                for (int i = 0; i < s; ++i) {
                    if(a[n+i]=='0'){
                       cantidad_0++;
                       b[n+i]='1' ;
                    }else{
                        cantidad_1++;
                        b[n+i]='0' ;
                    }
                }
            }else if(cantidad_1>cantidad_0){
                cantidad_1 = 0,cantidad_0 = 0;
                for (int i = 0; i < s; ++i) {
                    if((i+1) % 2 == 0 and i!=0){
                        if(a[n+i]=='0'){
                            cantidad_0++;
                           b[n+i]='1' ;
                        }else{
                            cantidad_1++;
                            b[n+i]='0' ;
                        }
                    }else{
                        if(a[n+i]=='1'){
                            cantidad_1++;
                            b[n+i]='1';
                        }else{
                            cantidad_0++;
                            b[n+i]='0';
                        }

                    }
                }
            }else if(cantidad_0>cantidad_1){
                cantidad_1 = 0,cantidad_0 = 0;
                for (int i = 0; i < s; ++i) {
                    if((i+1) % 2 == 0 and i!=0){
                        if(a[n+i]=='0'){
                            cantidad_0++;
                           b[n+i]='1' ;
                        }else{
                            cantidad_1++;
                            b[n+i]='0' ;
                        }
                    }else{
                        if(a[n+i]=='1'){
                            cantidad_1++;
                            b[n+i]='1' ;
                        }else{
                            cantidad_0++;
                            b[n+i]='0' ;
                        }

                    }
                }
            }

        }
        n=n+s;
        n1--;
    }
    if (t%s==0)
        b[n]='\0' ;
    else
        b[n-1]='\0' ;
    return 0;
}

