#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED
#include<string.h>
#include<fstream>

#include "cubo.h"


class ListaDoble
{
    class Nodo{
    public:
        Nodo(std::string x)
        {
            next = 0;
            before = 0;
            dato = x;
            cub= new Cubo<std::string>();


        }

        Nodo *getNext(){ return next;}
        Nodo *getBefore() {return before;}
        void setNext(Nodo *n) { next = n;}
        void setBefore(Nodo *n){ before = n;}
        void setCubo(Cubo <std::string>* dato_cubo){dato_cubo=cub;}
        std::string getDato(){ return dato;}
        Cubo <std::string>* getCubo(){return cub;}



     int mes(std::string mes) {

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


        void setDatosCubo(int ano,std::string mes, std::string disco){
            Cubo <std::string> *aux= new Cubo<std::string>();

            cub->insertar_elemento(ano, this->mes(mes),disco);


        }


     private:
        Nodo *next;
        Nodo *before;
        std::string dato;
        Cubo <std::string> *cub;

    };
    /////////////////////sigue la lista
     public:
         ListaDoble()
         {
             first = 0;
             last = 0;
             size = 0;
         }

         int getSize(){return size;}
         void add_ordenado(std::string dato);
         void add_first(std::string dato);
         void add_last(std::string dato);
         void add_at(std::string dato, int index);
         void remove_at(int index);
        std::string cantidad_artistas();
         std::string grafic();
         void generar_txt();
         std::string get_element_at(int index);



     int mes(std::string mes) {

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


   int comparar(std::string a,std::string b) {
    int n1 = a.length();
    int n2 = b.length();
    // declaring character arrayCubo <std::string> *cub;

    char char_a[n1 + 1];
    char char_b[n2 + 1];
    // copying the contents of the
    // string to char array
    strcpy(char_a, a.c_str());
    strcpy(char_b, b.c_str());
    return strcmp(char_a,char_b);
}

void  buscar_cubo_agregarCancion(std::string cadena,std::string cancion)
{
Cubo<std::string>* cub= new Cubo<std::string>();
        Nodo *iterador = this->first;
        int x = 0;
        while(iterador!=0)
        {
            if(cadena == iterador->getDato()){cub= iterador->getCubo();}
            iterador = iterador->getNext();
            x++;
        }

}





Cubo <std::string>*  buscar_cubo(std::string cadena)
{

        Nodo *iterador = this->first;
        int x = 0;
        while(iterador!=0)
        {
            if(cadena == iterador->getDato()){return iterador->getCubo();}
            iterador = iterador->getNext();
            x++;
        }

}
void datos_aCubo(std::string disco,std::string mes,int ano,std::string artista)
{
        Nodo *iterador = this->first;
        int x = 0;
        while(iterador!=0)
        {
            if(artista == iterador->getDato()){   iterador->setDatosCubo(ano,mes,disco);}
            iterador = iterador->getNext();
            x++;
        }


}

     private:
         bool isEmpty(){return size == 0;}
         int size;
         Nodo *first;
         Nodo *last;
};


void ListaDoble::add_ordenado(std::string dato)
{

    Nodo *n = new Nodo(dato);
    Nodo *aux=this->first;
    bool bandera=false;

    if(this->isEmpty())
    {
        this->first = n;
        this->last = n;
        this->size++;
    }
    else
    {

        while(true){
                if(this->comparar(aux->getDato(),n->getDato())>0){
                //std::cout<<"comparo  ----------------------------------- "<<this->comparar(aux->getDato(),n->getDato())<<"---"<<aux->getDato()<<"--"<<n->getDato()<<this->getSize()<<std::endl;
                //std::cout<<"comparo  ----------------------------------- "<<aux->getDato()<<std::endl;

                bandera=true;
                break;
                }
                if(aux->getNext()==0){break;}
               aux=aux->getNext();


        }

        if(aux==this->first&&bandera==true&&this->getSize()==1){
        n->setNext(this->first);
        this->first->setBefore(n);
        this->first = n;
        this->size++;


        }else if(aux==this->last&&bandera==false&&this->getSize()==1){
        this->last->setNext(n);
        n->setBefore(this->last);
        this->last = n;
        this->size++;

        }
        else if(aux==this->last&&bandera==true&&this->getSize()>1){
        n->setNext(aux);
        n->setBefore(aux->getBefore());
        aux->getBefore()->setNext(n);
        aux->setBefore(n);
        this->size++;


        }else if(aux==this->last&&bandera==false&&this->getSize()>1){
        this->last->setNext(n);
        n->setBefore(this->last);
        this->last = n;
        this->size++;

        }else if(aux==this->first&&bandera==true&&this->getSize()>1){

        n->setNext(this->first);
        this->first->setBefore(n);
        this->first = n;
        this->size++;
        }else if(bandera==true&&this->getSize()>1){
          n->setNext(aux);
         n->setBefore(aux->getBefore());
         aux->getBefore()->setNext(n);
        aux->setBefore(n);
        this->size++;

    }else{
}


}}

void ListaDoble::add_first(std::string dato)
{
    Nodo *n = new Nodo(dato);
    if(this->isEmpty())
    {
        this->first = n;
        this->last = n;
        this->size++;
    }
    else
    {
        n->setNext(this->first);
        this->first->setBefore(n);

        this->first = n;
        this->size++;
    }
}

void ListaDoble::add_last(std::string dato)
{
    if(this->isEmpty())
    {
        this->add_first(dato);
    }
    else
    {
        Nodo *n = new Nodo(dato);
        this->last->setNext(n);
        n->setBefore(this->last);
        this->last = n;
        this->size++;
    }
}

void ListaDoble::add_at(std::string dato, int index)
{
    if(index >= 0 && index <= this->size)
    {
        if(index == 0){ this->add_first(dato); return;}
        if(index == this->size) {this->add_last(dato); return;}
        Nodo *aux = this->first;
        int x = 0;
        while(aux!=0)
        {
            if(x == index){break;}
            aux = aux->getNext();
            x++;
        }
        Nodo *n = new Nodo(dato);
        aux->getBefore()->setNext(n);
        n->setBefore(aux->getBefore());
        n->setNext(aux);
        aux->setBefore(n);
        this->size++;
    }
}

std::string ListaDoble::get_element_at(int index)
{
    if(index >= 0 && index < size)
    {
        Nodo *iterador = this->first;
        int x = 0;
        while(iterador!=0)
        {
            if(index == x){return iterador->getDato();}
            iterador = iterador->getNext();
            x++;
        }
    }
    return 0;
}


std::string ListaDoble::cantidad_artistas()
{
    string result;

        Nodo *iterador = this->first;
        int x = 1;
        while(iterador!=0)
        {
            result = result +std::to_string(x)+ "."+iterador->getDato()+" \n";
            iterador = iterador->getNext();
            x++;
        }

    return result;
}





void ListaDoble::remove_at(int index)
{
        if(index >= 0 && index < this->size)
    {
        if(index == 0){Nodo *aux = this->first->getNext();  aux->setBefore(0); this->first =aux;       this->size--;    return;}
        if(index == this->size-1) {Nodo *aux = this->last->getBefore();  aux->setNext(0);        this->size--;             return;}
        Nodo *aux = this->first;
        int x = 0;
        while(aux!=0)
        {
            if(x == index){break;}
            aux = aux->getNext();
            x++;
        }

        aux->getBefore()->setNext(aux->getNext());
        aux->getNext()->setBefore(aux->getBefore());
        this->size--;
    }

    // return 0;
}

std::string ListaDoble::grafic()
{
        std::string linea1=" digraph G {";
       std:: string linea2="nodesep=.02;";
        std::string linea3="rankdir=LR;";
        std::string linea4="node [shape=record,width=.1,height=.1];";
        std::string linea5="node0 [label = \"null\"];";
        std::string linea6="node [width =1.5];";

        Nodo *node = this->first;
        //node =self.head
        int index=1;
        std::string nodos="";
        std::string direccion="";

        while(node!=0){
         nodos=nodos+ "node"+std::to_string(index) +"[label = \"{<n> |" + node->getDato() +"| <p> }\"];";
         direccion=direccion+"node" + std::to_string(index)+":n -> node"+std::to_string(index-1)+":p;";
         direccion=direccion+"node"+std::to_string(index)+":p -> node"+std::to_string(index+1)+":n;" ;
         index=index+ 1;
         node=node->getNext();
        }
        nodos =nodos+"node"+std::to_string(index) + "[label = \"null\",width=0.5];";
        std::string lineafinal="}";
        std::string grafo= linea1+linea2+linea3+linea4+linea5+linea6+nodos+direccion+lineafinal;
        return grafo;

}







#endif // LISTADOBLE_H_INCLUDED
