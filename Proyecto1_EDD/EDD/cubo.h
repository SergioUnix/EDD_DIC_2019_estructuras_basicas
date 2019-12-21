#ifndef CUBO_H_INCLUDED
#define CUBO_H_INCLUDED

#include "listasimple.h"


template<class T>
class Cubo
{

    class Nodo{
        public:
        Nodo(int posx, int posy, T x)
        {
            this->next = 0;
            this->before = 0;
            this->up=0;
            this->down=0;
            this->z_front=0;
            this->z_back=0;
            this->x=posx;
            this->y=posy;
            this->dato = x;
            ///inicializo mi lista
            this->canciones=0;
         }

        Nodo *getNext(){ return next;}
        Nodo *getBefore() {return before;}
        Nodo *getUp() {return up;}
        Nodo *getDown() {return down;}
        Nodo *getZ_front() {return z_front;}
        Nodo *getZ_back() {return z_back;}
        int getX(){return x;}
        int getY(){return y;}

        void setNext(Nodo *n) { next = n;};
        void setBefore(Nodo *n){ before = n;};
        void setUp(Nodo *n){ up = n;};
        void setDown(Nodo *n){ down = n;};
        void setZ_front(Nodo *n){ z_front = n;};
        void setZ_back(Nodo *n){ z_back = n;};
        void setDato(T n){dato =n;};
        void setX(int n){x =n;};
        void setY(int n){y =n;};

        //void setX(int x){ x = x;}
        //void setY(int y){ y = y;}
        T getDato(){ return dato;}

        void setLista(Lista* list){canciones=list;}
        Lista* getLista(){return canciones;}


        void agregarDatosLista(std::string cadena){

            canciones->add_ordenado(cadena);

        }

















     private:
        Nodo *next;    Nodo *before;
        Nodo *up;      Nodo *down;
        Nodo *z_front; Nodo *z_back;
        int x;    int y;
        T dato;
        Lista *canciones;
    };



     public:
         Cubo()
         {
         root= new Nodo(-1,-1,"Root");
         ano=0;
         mes=0;

          }




Lista*  buscar_lista(std::string cadena)
{

        Nodo *iterador = this->root;
        Nodo *iterador2=iterador;
        while(iterador!=0)
        {

                    while(iterador2!=0){

                        if(iterador2->getDato()==cadena){
                            break;
                        }


                        iterador2=iterador2->getDown();


                    }




            iterador = iterador->getNext();
        }

        return iterador2->getLista();

}


void  agregar_alista(std::string cadena,std::string cancion)
{

        Nodo *iterador = this->root;
        Nodo *iterador2=iterador;
        Nodo *solucion;
        while(iterador!=0)
        {

                    while(iterador2!=0){

                        if(iterador2->getDato()==cadena){
                                iterador2=solucion; break;
                        }


                        iterador2=iterador2->getDown();


                    }




            iterador = iterador->getNext();
        }

       solucion->agregarDatosLista(cancion);

}














         Nodo* buscar_fila(int y){
                Nodo *temp = this->root;

                while(temp!=0)
                {
                //    cout<<"en busqueda x: "<<temp->getX()<<" en y: "<<temp->getY();
                if(temp->getY()==y){
                return temp;
                }

                temp = temp->getDown();

                }
                return 0;
                };

         Nodo* buscar_columna(int x){
                Nodo* temp= this->root;
                while(temp!=0){
                      //   cout<<"en busqueda x: "<<temp->getX()<<" en y: "<<temp->getY();
                    if(temp->getX()==x){
                        return temp;
                    }
                temp = temp->getNext();
                }
                return 0;


                };



         Nodo* insertar_ordenado_columna(Nodo *nuevo,Nodo* cabeza_col){

                Nodo*temp=cabeza_col;
                bool bandera=false;
                while(true){
                    if(temp->getX()==nuevo->getX()){
                        temp->setY(nuevo->getY());
                        temp->setDato(nuevo->getDato());
                        return temp;

                    }else if(temp->getX() > nuevo->getX()){
                        bandera=true;
                        break;

                    };
                    if(temp->getNext()!=0){
                        temp=temp->getNext();
                    }else{
                       break;
                    };
                };
                if(bandera==true){
                    nuevo->setNext(temp);
                    temp->getBefore()->setNext(nuevo);
                    nuevo->setBefore(temp->getBefore());
                    temp->setBefore(nuevo);
                }else{
                temp->setNext(nuevo);
                nuevo->setBefore(temp);
                };
                return nuevo;
         };



       Nodo* insertar_ordenado_fila(Nodo *nuevo,Nodo* cabeza_fila){

                Nodo*temp=cabeza_fila;
                bool bandera=false;
                while(true){
                    if(temp->getY()==nuevo->getY()){
                        temp->setX(nuevo->getX());
                        temp->setDato(nuevo->getDato());
                        return temp;

                    }else if(temp->getY() > nuevo->getY()){
                        bandera=true;
                        break;

                    };
                    if(temp->getDown()!=0){
                        temp=temp->getDown();
                    }else{
                       break;
                    };
                };
                if(bandera==true){
                    nuevo->setDown(temp);
                    temp->getUp()->setDown(nuevo);
                    nuevo->setUp(temp->getUp());
                    temp->setUp(nuevo);
                }else{
                temp->setDown(nuevo);
                nuevo->setUp(temp);
                };
                return nuevo;
         };

       Nodo* crear_columna(int x){
           Nodo* cabeza_columna = this->root;
           Nodo* columna = this->insertar_ordenado_columna(new Nodo(x,-1,"COL"), cabeza_columna );

           return columna;
       }

       Nodo* crear_fila(int y){
           std::string mes="";
           if(y==1){mes="Enero";}else if(y==2){mes="Febrero";}else if(y==3){mes="Marzo";}else if(y==4){mes="Abril";}else if(y==5){mes="Mayo";}
           else if(y==6){mes="Junio";}else if(y==7){mes="Julio";}else if(y==8){mes="Agosto";}else if(y==9){mes="Septiembre";}else if(y==10){mes="Octubre";}
           else if(y==11){mes="Noviembre";}else if(y==12){mes="Diciembre";}

           Nodo* cabeza_fila = this->root;
           Nodo* fila = this->insertar_ordenado_fila(new Nodo(-1,y,mes), cabeza_fila );

           return fila;
       }

   void insertar_Z(Nodo *nuevo,int x,int y){


         Nodo* raiz = this->root;
         Nodo* obtenido =0;
         Nodo* encontrado=0 ;


                while(true){
                    if(raiz->getY()==y){
                        obtenido=raiz;

                        while(true){
                    if(raiz->getX()==x){
                        raiz=obtenido;
                        raiz=nuevo;
                        break;
                    }
                    obtenido = obtenido->getNext();
                    }

                      break;
                    }
                    raiz =raiz->getDown();
                    }








         };




void  insertar_elemento(int x, int y, std::string dato){
        Nodo * nuevo= new Nodo(x,y,dato);
        Nodo* NodoColumna = this->buscar_columna(x);
        Nodo* NodoFila =this->buscar_fila(y);

        if(NodoColumna == 0 && NodoFila == 0){
         std::cout<< "Caso1"<<std::endl;
         NodoColumna= this->crear_columna(x);
         //cout << NodoColumna->getX()<<" "<<NodoColumna->getX()<<endl;
         NodoFila = this->crear_fila(y);
         //cout << NodoFila->getX()<<" "<<NodoFila->getX()<<endl;
         nuevo = this->insertar_ordenado_columna(nuevo,NodoFila);
         nuevo = this->insertar_ordenado_fila(nuevo, NodoColumna);
         return;

         }else if(NodoColumna == 0 && NodoFila != 0){
         std::cout<< "Caso2"<<std::endl;
         NodoColumna= this->crear_columna(x);
         nuevo = this->insertar_ordenado_columna(nuevo,NodoFila);
         nuevo = this->insertar_ordenado_fila(nuevo, NodoColumna);
         return;

         }else if(NodoColumna != 0 && NodoFila == 0){
         std::cout<< "Caso3"<<std::endl;
         NodoFila = this->crear_fila(y);
         nuevo = this->insertar_ordenado_columna(nuevo,NodoFila);
         nuevo = this->insertar_ordenado_fila(nuevo, NodoColumna);
         return;

         }else if(NodoColumna != 0 && NodoFila != 0){
         std::cout<< "Caso4"<<std::endl;
         //cout << NodoColumna->getX()<<" "<<NodoColumna->getDown()->getY()<<"  "<<NodoColumna->getDown()->getX()<<NodoFila->getDown()->getDato() <<endl;
         //cout << NodoFila->getY()<<" "<<NodoFila->getNext()->getX()<<"  "<<NodoFila->getNext()->getY()<<NodoFila->getNext()->getDato()<<endl;

         //insertar_Z(nuevo,x,y);
         nuevo = this->insertar_ordenado_columna(nuevo,NodoFila);
         nuevo = this->insertar_ordenado_fila(nuevo, NodoColumna);

         return;

         }


}

std::string grafic(){
    std::string linea1="digraph Sparce_Matrix { \n";
    std::string linea2="node [shape=box]  \n";
    std::string linea3="Mt[ label = \"Matrix\", width = 1.5, style = filled, fillcolor = firebrick1, group = 1 ];  \n";
    std::string linea4="/*nodos vacíos, necesarios para anular la ubicación de nodo predeterminada de graphiz  */ \n e0[ shape = point, width = 0 ];  \n";
    std::string linea5="e1[ shape = point, width = 0 ];   \n";


    /// aca se grafica el eje Y
      Nodo *temp1 = this->root->getDown();
     int j=0;
     int comodin2=-1;
     std::string primeroY="";
     std::string linea6="";
     std::string linea7=""; ///links de Y
     /// me ayuda  a recorrer en forma horizontal
     Nodo *recoX=this->root->getDown();
     /// Nodos fila
     std::string filas="";
     std::string punteros_fila="";
     std::string same="";

      int comodin_fila=-1;
     /// recorre en el plano Z
     std::string Z="";
     std::string punteros_Z="";
     std::string sameZ="";
     Nodo *recoXZ;
     int comodin_filaZ=-1;

                while(temp1!=0)
                {
                    recoX= temp1->getNext();
                    while(recoX!=0){
                        if(comodin_fila<0){   punteros_fila=punteros_fila+ "U"+std::to_string(temp1->getY())+ "-> N"+std::to_string(recoX->getX())+std::to_string(recoX->getY())+"; \n";  same=same+ "U"+std::to_string(temp1->getY())+";";     comodin_fila +=1;}

                        if(recoX!=0){
                               filas= filas + "N"+ std::to_string(recoX->getX())+std::to_string(recoX->getY())+" [label = \""+recoX->getDato()+"\" width = 1.5, group ="+ std::to_string(recoX->getX()) +" ];  \n";
                                  same=same+ "N"+ std::to_string(recoX->getX())+std::to_string(recoX->getY())+";";
                                            if(recoX->getUp()->getY()==-1){ //si es cabecera la de arriba hace esto
                                            punteros_fila=punteros_fila + "A"+ std::to_string(recoX->getUp()->getX())+ "-> N"+std::to_string(recoX->getX())+std::to_string(recoX->getY()) +"; \n";
                                            }else{ //cuando no es cabecera ejecuta esto
                                            punteros_fila=punteros_fila + "N"+ std::to_string(recoX->getX())+std::to_string(recoX->getY())+ "-> N"+std::to_string(recoX->getUp()->getX())+std::to_string(recoX->getUp()->getY()) +"; \n";
                                             punteros_fila=punteros_fila + "N"+ std::to_string(recoX->getUp()->getX())+std::to_string(recoX->getUp()->getY())+ "-> N"+std::to_string(recoX->getX())+std::to_string(recoX->getY()) +"; \n";
                                           }
                  //////////////////////////////capto los nodos en z
                                    recoXZ=recoX->getZ_back();
                                    while(recoXZ!=0){
                                        if(comodin_filaZ<0){   punteros_Z=punteros_Z+ "N"+std::to_string(recoX->getX())+std::to_string(recoX->getY())+"-> Z"+std::to_string(recoX->getX())+std::to_string(recoX->getY())+"; \n";      comodin_filaZ +=1;}



                                         Z= Z + "Z"+ std::to_string(recoXZ->getX())+std::to_string(recoXZ->getY())+" [label = \""+recoXZ->getDato()+"\" width = 1.5 ];  \n";



                                         punteros_Z=punteros_Z +"Z"+std::to_string(recoXZ->getX())+std::to_string(recoXZ->getY())+ "-> Z"+std::to_string(recoXZ->getNext()->getX())+std::to_string(recoXZ->getNext()->getY())+"; \n" +"N"+std::to_string(recoXZ->getNext()->getX())+std::to_string(recoXZ->getNext()->getY())+ "-> N"+std::to_string(recoXZ->getX())+std::to_string(recoXZ->getY())+"; \n";



                                     recoXZ= recoXZ->getZ_back();
                                    }
                                       /////////////////////////

                                  if(recoX->getNext()!=0){
                                   punteros_fila=punteros_fila +"N"+std::to_string(recoX->getX())+std::to_string(recoX->getY())+ "-> N"+std::to_string(recoX->getNext()->getX())+std::to_string(recoX->getNext()->getY())+"; \n" +"N"+std::to_string(recoX->getNext()->getX())+std::to_string(recoX->getNext()->getY())+ "-> N"+std::to_string(recoX->getX())+std::to_string(recoX->getY())+"; \n";

                                   }
                        }else{break;}


                        recoX= recoX->getNext();
                    }
                    punteros_fila=punteros_fila + "{ rank = same; "+same+"} \n";
                    same="";



                     if(comodin2<0){
                    primeroY="U"+ std::to_string(temp1->getY());
                    comodin2 +=1;

                    }

                linea6 = linea6 + "U"+ std::to_string(temp1->getY()) + "[label = \""+  temp1->getDato() +"\" width = 1.5 style = filled, fillcolor = bisque1, group ="+ "1" +"];  \n";
                if(temp1->getDown()!=0){
                linea7=linea7 +"U"+std::to_string(temp1->getY())+ "-> U"+std::to_string(temp1->getDown()->getY())+"; \n" +"U"+std::to_string(temp1->getDown()->getY())+ "-> U"+std::to_string(temp1->getY())+"; \n";

                }


                j += 1;
                temp1 = temp1->getDown();

                comodin_fila=-1;

                }
    std::string same_completo="{ rank = same; "+same+"} \n";



     Nodo *temp = this->root->getNext();
     int i=0;
     int comodin=-1;
     std::string primeroX="";
     std::string linea8="";
     std::string linea9="";
     std::string para_linea11="";
     /// Nodos fila
     std::string columnas="";
     std::string punteros_columna="";
     int comodin_columna=-1;
                while(temp!=0)
                {

                    if(comodin<0){
                            primeroX="A"+ std::to_string(temp->getX());
                    comodin +=1;

                    }

                linea8 = linea8 + "A"+ std::to_string(temp->getX()) + "[label = \""+ std::to_string(temp->getX()) +"\" width = 1.5 style = filled, fillcolor = lightskyblue, group ="+ std::to_string(temp->getX()) +"];  \n";
                if(temp->getNext()!=0){
                linea9=linea9 +"A"+std::to_string(temp->getX())+ "-> A"+std::to_string(temp->getNext()->getX())+"; \n" +"A"+std::to_string(temp->getNext()->getX())+ "-> A"+std::to_string(temp->getX())+"; \n";}
                para_linea11=para_linea11 + "A"+ std::to_string(temp->getX())+"; ";
                i += 1;
                temp = temp->getNext();
                 comodin_columna=-1;

                }


    std::string linea10="Mt -> "+primeroY+"; Mt -> "+primeroX+"; \n";
    std::string linea11="{ rank = same; Mt;"+ para_linea11 +"} \n";



                std::string total=linea1+linea2+linea3+linea4+linea5+linea6+linea7+linea8+linea9+linea10+linea11+filas+punteros_fila+Z+punteros_Z+"}";
                return total;
                 }

void generar_txt(){
std::string texto= grafic();
std::ofstream archivo;
archivo.open("cubo.txt", std::ios:: out);

archivo<<texto;
archivo.close();

        std::string sentencia="dot -Tpng cubo.txt -o cubo.png";
        std::string sentencia2="start cubo.png";
        system(sentencia.c_str());
        system(sentencia2.c_str());


}




     private:
         int ano;
         int mes;

         Nodo * root;


};









#endif // CUBO_H_INCLUDED
