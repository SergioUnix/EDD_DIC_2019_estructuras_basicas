
#include <iostream>
#include <stdlib.h>
#include<string.h>
#include<fstream>
#include "json.hpp"
#include "EDD/listadoble.h"
#include "Clases/artista.h"
#include "EDD/cubo.h"
#include <conio.h>



using json=nlohmann::json;

using namespace std;

//devuelve -1 a va antes que b, 1 si a va despues de b, y 0 si son iguales
int comparar(string a,string b) {
    int n1 = a.length();
    int n2 = b.length();
    // declaring character array
    char char_a[n1 + 1];
    char char_b[n2 + 1];
    // copying the contents of the
    // string to char array
    strcpy(char_a, a.c_str());
    strcpy(char_b, b.c_str());
    return strcmp(char_a,char_b);
}


int mes(string mes) {

if(mes=="ENERO"|| mes=="enero"){  return 1;
}else if(mes=="Febrero"|| mes=="febrero"){ return 2;
}else if(mes=="Marzo"|| mes=="marzo"){ return 3;
}else if(mes=="Abril"|| mes=="abril"){ return 4;
}else if(mes=="Mayo"|| mes=="mayo"){   return 5;
}else if(mes=="Junio"|| mes=="junio"){ return 6;
}else if(mes=="Julio"|| mes=="julio"){ return 7;
}else if(mes=="Agosto"|| mes=="agosto"){return 8;
}else if(mes=="Septiembre"|| mes=="septiembre"){ return 9;
}else if(mes=="Octubre"|| mes=="octubre"){ return 10;
}else if(mes=="Noviembre"|| mes=="noviembre"){ return 11;
}else if(mes=="Diciembre"|| mes=="diciembre"){ return 12;
}else{return 13;}

}

void cmd(){
    while (true){
        string sentencia="dot -Tpng graf.txt -o graf.png";
        string sentencia2="start graf.png";
        cout <<"Escriba exit para salir: ";
        string comando;
        getline(cin,comando);
        system(sentencia.c_str());
        system(sentencia2.c_str());

        if(comando=="exit"|| comando=="EXIT") break;


    }}


//genero el .txt, y el contenido de graphviz dentro del archivo y lo mando a compilar en consola
void generar_txt(string nombre, string dot){

ofstream archivo;
archivo.open(nombre+".txt", ios:: out);

archivo<<dot;
archivo.close();

        string sentencia="dot -Tpng "+nombre+".txt -o "+nombre+".png";
        string sentencia2="start "+nombre+".png";
        system(sentencia.c_str());
        system(sentencia2.c_str());


}






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
ListaDoble *lista_artistas= new ListaDoble();




archivo.open("Library.json", ios:: in); //abrimos el archivo en modo lectura


 if(archivo.fail()){
    cout<<"no se puedo abrir el archivo ";
    exit(1);}


 while(!archivo.eof()){  //mientras no sea el final del archivo
    getline(archivo, texto);
   texto_parseado = texto_parseado + Cuenta(texto,'"'); }

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
        cout << "ArtistaN :"<<parseado[i+2]<<endl;  lista_artistas->add_ordenado(parseado[i+2]);  i++; i++;
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
}}}  //termina el for



 archivo.close(); //cerramos el archivo
cout<<lista_artistas->grafic();
generar_txt("listaDoble",lista_artistas->grafic());
    //Artista *persona = lista_artistas->get_element_at(0);
    //persona->imprimir();


 }






int main()
{
/////////  Objeto tipo Artista
    Artista *jod= new Artista("Eduardo");
    jod->imprimir();

//////// Objeto tipo Cubo
Cubo <string> *cub= new Cubo<string>();
cub->insertar_elemento(20,8,"Anio1");
cub->insertar_elemento(30,8,"Anio1");
cub->insertar_elemento(30,9,"Anio2");
cub->insertar_elemento(40,10,"Anio3");
cub->insertar_elemento(50,11,"Anio4");
//cout << cub->grafic();
//cub->generar_txt();










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
           cout <<" Ejecutar un comando \n \n \n";
           cmd();



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





