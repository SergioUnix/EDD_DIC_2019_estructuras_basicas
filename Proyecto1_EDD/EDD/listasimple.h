#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

using namespace std;

class Lista
{
    class Nodo{
    public:
        Nodo(std::string x)
        {
            next = 0;
            dato = x;


        }

        Nodo *getNext(){ return next;}
        void setNext(Nodo *n) { next = n;}
        std::string getDato(){ return dato;}

void print()
{
    //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    std::cout << dato<< "-> ";
}

Nodo *next;

     private:

        std::string dato;

    };
    /////////////////////sigue la lista
     public:
         Lista()
         {
             first = 0;
             size = 0;
         }

         int getSize(){return size;}
         void add_ordenado(std::string dato);
         void add_first(std::string dato);
         void add_last(std::string dato);
         void remove_at(int index);







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


void print()
{
    Nodo *temp=this->first;
    if (this->isEmpty()) {
        cout << "La Lista está vacía " << endl;
    } else {
        while (temp) {
            temp->print();
            if (temp->getNext()==0) cout << "NULL";
                temp = temp->next;
        }
  }
  cout << endl << endl;
}




std::string grafic()
{
        std::string linea1=" digraph G {";
        std::string linea2="nodesep=.02;";
        std::string linea3="rankdir=LR;";
        std::string linea4="node [shape=record,width=.1,height=.1];"   ;
        std::string linea6="node [width =1.5];";
         Nodo *node=this->first;
        int index=1;
        std::string nodos="";
        std::string direccion="";
        while(node!=0){
             nodos=nodos+"node"+std::to_string(index) + "[label = \"{<n>" +node->getDato()+"| <p> }\"];";
             direccion=direccion+"node"+std::to_string(index)+":p -> node"+std::to_string(index+1)+":n;";
             index=index+1;
             node=node->getNext();

        }
           nodos=nodos +"node"+to_string(index) + "[label = \"null\",width=0.5];";
           string lineafinal="}";
           string grafo= linea1+linea2+linea3+linea4+linea6+nodos+direccion+lineafinal;
           return grafo;


}


void generar_txt(){
std::string texto= grafic();
std::ofstream archivo;
archivo.open("listaSimple.txt", std::ios:: out);

archivo<<texto;
archivo.close();

        std::string sentencia="dot -Tpng listaSimple.txt -o listaSimple.png";
        std::string sentencia2="start listaSimple.png";
        system(sentencia.c_str());
        system(sentencia2.c_str());


}




     private:
         bool isEmpty(){return size == 0;}
         int size;
         Nodo *first;
};



void Lista::add_first(std::string dato)
{
    Nodo *n = new Nodo(dato);
    if(this->isEmpty())
    {
        this->first = n;
        this->size++;
    }
    else
    {
        n->setNext(this->first);

        this->first = n;
        this->size++;
    }
}

void Lista::add_ordenado(std::string dato)
{ Nodo *n = new Nodo(dato);
    Nodo *aux=this->first;
    Nodo *aux_ant=0;
    bool bandera=false;
   // bool bandera2=false;

    if(this->isEmpty())
    {
        this->first = n;
        this->size++;
    }
    else
    {

        while(true){

                if(this->comparar(aux->getDato(),n->getDato())>0){
                std::cout<<"comparo  ----------------------------------- "<<this->comparar(aux->getDato(),n->getDato())<<"---"<<aux->getDato()<<"--"<<n->getDato()<<this->getSize()<<std::endl;
                std::cout<<"comparo  ----------------------------------- "<<aux->getDato()<<std::endl;

                bandera=true;

                break;
                }
                if(aux->getNext()==0){break;}

                aux_ant=aux;
               aux=aux->getNext();


        }

        if(aux==this->first&&bandera==true){
        n->setNext(this->first);
        this->first = n;
        this->size++;

         }else if(bandera==true&&this->getSize()>1){

        aux_ant->setNext(n);
        n->setNext(aux);
        this->size++;


    }else{
        aux->setNext(n);
        this->size++;
}


}}








#endif // LISTASIMPLE_H_INCLUDED
