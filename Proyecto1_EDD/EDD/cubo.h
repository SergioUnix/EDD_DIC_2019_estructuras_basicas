#ifndef CUBO_H_INCLUDED
#define CUBO_H_INCLUDED



template<class T>
class Cubo
{
    class Nodo{
    public:
        Nodo(T x)
        {
            next = 0;
            before = 0;
            up=0;
            down=0;
            z_front=0;
            z_back=0;

            dato = x;
        }

        Nodo *getNext(){ return next;}
        Nodo *getBefore() {return before;}
        Nodo *getUp() {return up;}
        Nodo *getDown() {return down;}
        Nodo *getZ_front() {return z_front;}
        Nodo *getZ_back() {return z_back;}

        void setNext(Nodo *n) { next = n;}
        void setBefore(Nodo *n){ before = n;}
        void setUp(Nodo *n){ up = n;}
        void setDown(Nodo *n){ down = n;}
        void setZ_front(Nodo *n){ z_front = n;}
        void setZ_back(Nodo *n){ z_back = n;}


        T getDato(){ return dato;}

     private:
        Nodo *next;
        Nodo *before;
        Nodo *up;
        Nodo *down;
        Nodo *z_front;
        Nodo *z_back;
        T dato;
    };
     public:
         Cubo()
         {
             first = 0;
             last = 0;
             size = 0;
         }

         int getSize(){return size;}
         void add_first(T dato);
         void add_last(T dato);
         void add_at(T dato, int index);
         void remove_at(int index);

         T get_element_at(int index);

     private:
         bool isEmpty(){return size == 0;}
         int ano_x;
         int mes_y;
         int size_x;
         int size_y;
         int size_z;
         Nodo *first_x;
         Nodo *first_y;
         Nodo *first_z;

         Nodo *last_x;
         Nodo *last_y;
         Nodo *last_z;
};

template<class T>
void ListaDoble<T>::add_first(T dato)
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

template<class T>
void ListaDoble<T>::add_last(T dato)
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

template<class T>
void ListaDoble<T>::add_at(T dato, int index)
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

template<class T>
T ListaDoble<T>::get_element_at(int index)
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

template<class T>
void ListaDoble<T>::remove_at(int index)
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

#endif // CUBO_H_INCLUDED
