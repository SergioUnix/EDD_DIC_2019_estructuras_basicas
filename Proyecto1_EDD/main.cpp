
#include <iostream>
#include <stdlib.h>
#include<string.h>
#include<fstream>
#include "json.hpp"
#include "EDD/listadoble.h"

using json=nlohmann::json;

using namespace std;







// recibe lineas y quita todos los caracteres dejando solo el " y la cadena que esta dentro de ella; que separa las palabras, devuelve lineas
string Cuenta(string s, const char Separadorr) {
    string concatenar;
    string resultante="";
    for (int i = 0; i < s.size(); i++){
        if (s[i] == Separadorr) {

        do{
        concatenar = concatenar + s[i];
        i++;
        }while(s[i]!='"');
        }
        }
resultante = resultante + concatenar;
return resultante;
}

//Crea vector con todos las palabras que estaban entre comillas, recibe un string que trae palabras separadas con un "
vector<string> crear_vector(string cadena){
    //agrego una " al final del texto
    string texto_parseado = cadena + '"';
    vector <string> arreglo;
    string concatenar;
 for (int i = 0; i < texto_parseado.size(); i++){
        if (texto_parseado[i] == '"'&& i!=texto_parseado.size()-1) {

        do{
        i++;
        if(texto_parseado[i]!='"'){
        concatenar = concatenar + texto_parseado[i];
       }
       }while(texto_parseado[i]!='"');

        //cout <<concatenar<<endl;
        i--;
        arreglo.push_back(concatenar);
        } concatenar.clear();
        }
  return arreglo;
}

////propio parser
void parser(){
ifstream archivo;
string texto;
string texto_parseado;
vector<string> parseado;

archivo.open("Library.json", ios:: in); //abrimos el archivo en modo lectura

//
 if(archivo.fail()){
    cout<<"no se puedo abrir el archivo ";
    exit(1);
 }
 while(!archivo.eof()){  //mientras no sea el final del archivo
    getline(archivo, texto);
   texto_parseado = texto_parseado + Cuenta(texto,'"');

 }

//imprimo el texto parseado, listo para mandar a convertirlo a arreglo
//cout << texto_parseado<<endl <<endl; // texto parseado

//mando el string para que sea devuelo como vector donde las posiciones son cada palabra
 parseado = crear_vector(texto_parseado);









//imprimo el ultimo para ver cual es
 //cout << parseado[parseado.size()-1]<<endl<< endl;



//El for lo que hace es lee artistas con sus albums y sus canciones y las guarda
 for (int i = 0; i < parseado.size(); i++)
    {
        if (parseado[i]=="Artist" && parseado[i+1]=="Name"){
        cout << "ArtistaN :"<<parseado[i+2]<<endl;  i++; i++;
                    for (int j = i; i < parseado.size(); j++){
                       if (parseado[j]=="Name" && parseado[j+2]=="Month"){
                            cout <<"AlbumN:"<<parseado[j+1]<<" Month:"<<parseado[j+3]<<" Year:"<<parseado[j+5]<<endl;

                              j++; j++; j++;
                                   for (int k = j; j < parseado.size(); k++){
                                       if (parseado[k]=="Name" && parseado[k+2]=="File"){
                                        cout <<"Name:"<<parseado[k+1]<<" File:"<<parseado[k+3]<<" Rating:"<<parseado[k+5]<<endl;
                                       }
                                       if(parseado[k]=="Name" &&parseado[k+2]=="Month" || k==parseado.size()-1){break;}
                                   }

                       }
                        if(parseado[j]=="Artist" || j==parseado.size()-1){break;}
                    }






        }



 }







 archivo.close(); //cerramos el archivo
}



int main()
{

    int a, b;
    do{
        cout << "1- Leer un archivo \n";
        cout << "2- prueba de artistas \n";
        cout << "3- no asignado \n";
        cout << "4- no asignado \n";
        cout << "5- no asignado \n";
        cout << "6- salir \n \n";


        cin>>a;

        switch (a)
        {
           case 1:
           cout <<" Prueba del archivo json \n \n \n";
            parser();
           break;
           case 2:
           cout <<" prueba del arreglo artista \n \n \n";

           break;
           case 3:
           cout <<" prueba del arreglo artista \n \n \n";

           break;
           case 4:
           cout <<" prueba del arreglo artista \n \n \n";

           break;
           case 6:

                cout <<" Seguro que quieres ...?  SI o NO \n";
                cout <<"\n 1-SI \n";
                cout <<"\n 2-NO \n";
                cin>>b;
                if(b==1)
                {
                    return 0;
                }else{
                    return main();
                }
                break;
           default:
                return main();
                break;
           }
        }
        while (a != 5);
        system("pause");
        return main();

}





