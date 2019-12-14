#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED
#include<fstream>
#include <iostream>
#include <stdlib.h>
#include<string.h>
class Operacion
{ public:

         std::string Cuenta(std::string s, const char Separadorr);
         std::vector<std::string> crear_vector(std::string cadena);
         void parser();

     private:

};


// recibe lineas y quita todos los caracteres dejando solo el " y la cadena que esta dentro de ella; que separa las palabras, devuelve lineas
std::string Operacion::Cuenta(std::string s, const char Separadorr) {
    std::string concatenar;
    std::string resultante="";
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
std::vector<std::string> Operacion::crear_vector(std::string cadena){
    //agrego una " al final del texto
    std::string texto_parseado = cadena + '"';
    std::vector <std::string> arreglo;
    std::string concatenar;
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




void Operacion::parser(){
std::ifstream archivo;
std::string texto;
std::string texto_parseado;
std::vector<std::string> parseado;

archivo.open("Library.json", std::ios:: in); //abrimos el archivo en modo lectura

//
 if(archivo.fail()){
    std::cout<<"no se puedo abrir el archivo ";
    exit(1);
 }
 while(!archivo.eof()){  //mientras no sea el final del archivo
    getline(archivo, texto);
   texto_parseado = texto_parseado + Cuenta(texto,'"');

 }

//imprimo el texto parseado, listo para mandar a convertirlo a arreglo
 std::cout << texto_parseado<<std::endl <<std::endl; // texto parseado

//mando el string para que sea devuelo como vector donde las posiciones son cada palabra
 parseado = crear_vector(texto_parseado);









//imprimo el ultimo para ver cual es
 std::cout << parseado[parseado.size()-1]<<std::endl<< std::endl;



//El for lo que hace es lee artistas con sus albums y sus canciones y las guarda
 for (int i = 0; i < parseado.size(); i++)
    {
        if (parseado[i]=="Artist" && parseado[i+1]=="Name"){
        std::cout << "ArtistaN :"<<parseado[i+2]<<std::endl;  i++; i++;
                    for (int j = i; i < parseado.size(); j++){
                       if (parseado[j]=="Name" && parseado[j+2]=="Month"){
                            std::cout <<"AlbumN: "<<parseado[j+1]<<"Month "<<parseado[j+3]<<std::endl; j++; j++; j++;
                                   for (int k = j; j < parseado.size(); k++){
                                       if (parseado[k]=="Name" && parseado[k+2]=="File"){
                                        std::cout <<"Name: "<<parseado[k+1]<<"File:  "<<parseado[k+3]<<std::endl;
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





#endif // BIBLIOTECA_H_INCLUDED
