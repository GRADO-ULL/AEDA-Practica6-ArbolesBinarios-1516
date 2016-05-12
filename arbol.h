#include <queue>
#include "nodo.h"

typedef struct
{
    nodo<TDATO>* nd;
    int nivel;
}NODO_T;

template<class TDATO>
class Arbol{
    
    private:
        int num_niveles;
        int num_nodos;
        nodo<TDATO>* raiz;
    public:
        Arbol();
        ~Arbol();
        //int get_niveles(void);

        bool si_vacio(void);

        void insertar(TDATO d);
        void podar(nodo<TDATO>* &nd);
        void insertarRama(nodo<TDATO>* &nd, TDATO d);

        nodo<TDATO>* get_raiz(void);
        bool eshoja(nodo<TDATO>* nd);
        void eliminar(TDATO clave_dada);
        void eliminarRama(nodo<TDATO>* &nd, TDATO clave_dada);
        void sustituye(nodo<TDATO>* &eliminado_, nodo<TDATO>* &sust);


        //BUSCANDO
        nodo<TDATO>* buscar(TDATO x);
        nodo<TDATO>* buscarRama(nodo<TDATO>* nd, TDATO x);
        
        //Imprimiendo arbol
        void imprimir(void);
        void imprimirArbol(nodo<TDATO>* nd);
        
        //Impresión
        //template <class TDATO>
        //friend ostream& operator<<(ostream &salida, const Arbol<TDATO> &arbol_);        
};

template <class TDATO>
nodo<TDATO>* Arbol<TDATO>::buscar(TDATO x)
{
    return buscarRama(raiz, x);
}

template <class TDATO>
nodo<TDATO>* Arbol<TDATO>::buscarRama(nodo<TDATO>* nd, TDATO x)
{
    if(nd == NULL)
        return NULL;
    if(x == nd->get_dato())
        return nd;
    if(x < nd->get_dato())
        return  buscarRama(nd->izq, x);
    return buscarRama(nd->der, x);
}



template <class TDATO>
nodo<TDATO>* Arbol<TDATO>::get_raiz(void)
{
    //cout << "Valor:" << raiz->get_dato() << endl;
    return raiz;
}


template <class TDATO>
Arbol<TDATO>::Arbol()
{
    num_nodos = 0;
    num_niveles = 0;
    raiz = NULL;
}

template <class TDATO>
Arbol<TDATO>::~Arbol()
{
    podar(raiz);
}

template <class TDATO>
bool Arbol<TDATO>::si_vacio(void)
{
    return raiz == NULL;
}

template <class TDATO>
void Arbol<TDATO>::insertar(TDATO d)
{
    insertarRama(raiz,d);
}

template <class TDATO>
void Arbol<TDATO>::insertarRama(nodo<TDATO>* &nd, TDATO d)
{
    if(nd == NULL)
    {
        //cout << "Insertando con arbol vacio" << endl;
        nd = new nodo<TDATO>(d);
        num_nodos++;
    }
    else
    {
        //cout << "Insertando con arbol no vacio" << endl;
        if(d < nd->get_dato())
        {
            //cout << "Inserto el nuevo dato por la izquierda" << endl;
            insertarRama(nd->izq, d);
        }
        else
        {
            //cout << "Inserto el nuevo dato por la derecha" << endl;
            insertarRama(nd->der, d);
        }
    }
}

/*template <class TDATO>
int Arbol<TDATO>::get_niveles(void)
{
    return num_niveles;
}


*/
template <class TDATO>
void Arbol<TDATO>::podar(nodo<TDATO>* &nd)
{
    if(nd == NULL) return;
    podar(nd->izq);
    podar(nd->der);
    delete nd;
    nd = NULL;
}

template <class TDATO>
bool Arbol<TDATO>::eshoja(nodo<TDATO>* nd)
{
    return !nd->der && !nd->izq;
}

template <class TDATO>
void Arbol<TDATO>::eliminar(TDATO clave_dada)
{
    eliminarRama(raiz,clave_dada);
}

template <class TDATO>
void Arbol<TDATO>::sustituye(nodo<TDATO>* &eliminado_, nodo<TDATO>* &sust)
{
    if(sust->der != NULL)
        sustituye(eliminado_, sust->der);
    else
    {
        //eliminado_->Info = sust->Info;
        eliminado_->dato = sust->get_dato();
        eliminado_ = sust;
        sust = sust->izq;
    }
}

template <class TDATO>
void Arbol<TDATO>::eliminarRama(nodo<TDATO>* &nd, TDATO clave_dada)
{
    if(nd == NULL) //return NULL;
    {}
    if(clave_dada < nd->get_dato())
        eliminarRama(nd->izq, clave_dada);
    else if(clave_dada > nd->get_dato())
        {
            eliminarRama(nd->der, clave_dada);
        }
    else
    {
        nodo<TDATO>* eliminado = nd;
        if(nd->der == NULL)
            nd = nd->izq;
        else if(nd->izq == NULL)
        {
            nd = nd->izq;
        }
        else
        {
            sustituye(eliminado, nd->izq);
        }
        delete eliminado;
    }
}

template <class TDATO>
void Arbol<TDATO>::imprimir(void)
{
    cout << "Imprimiendo arbol:" << endl;
    if(si_vacio())
    {
        cout << "Arbol vacio" << endl;
    }
    else
    {
        //cout << "Arbol no vacio" << endl;
        imprimirArbol(raiz);
    }
    cout << endl;
}


template <class TDATO>
void Arbol<TDATO>::imprimirArbol(nodo<TDATO>* nd)
{
    cin.get();
    cout << "Numero de nodos del arbol:" << num_nodos << endl;
    queue<NODO_T> Q;
    
    
    NODO_T raiz_;

    int nivel = 0;
    int nivel_actual = 0;
    
    raiz_.nd = raiz;
    raiz_.nivel = 0;
    Q.push(raiz_);
    cout << "Nivel " << nivel_actual << ":\t";
    while(!Q.empty())
    {
        NODO_T nodo_actual;
        nodo_actual.nd = NULL;
        nodo_actual.nivel = 0;
        
        nodo_actual = Q.front();
        Q.pop();

        if(nodo_actual.nivel > nivel_actual)
        {
            //cout << "Nivel del nodo actual:" << nodo_actual.nivel << ", Nivel actual:" << nivel_actual << endl;
            nivel_actual = nodo_actual.nivel;   
            cout << endl;
            cout << "Nivel " << nivel_actual << ":\t";
        }
        
        if(nodo_actual.nd != NULL)
        {
            //Hago la impresion del nodo actual
            cout << (nodo_actual.nd)->get_dato() << "\t";

            NODO_T hijo_izquierdo;
            NODO_T hijo_derecho;
            
            //Inserto nuevos valores en la cola
            if((nodo_actual.nd)->izq != NULL)
            {
                hijo_izquierdo.nd = (nodo_actual.nd)->izq;
                hijo_izquierdo.nivel = nodo_actual.nivel+1;
                Q.push(hijo_izquierdo);
            }
            else
            {
                hijo_izquierdo.nd = NULL;
                hijo_izquierdo.nivel = nodo_actual.nivel+1;
                Q.push(hijo_izquierdo);
            }
            if((nodo_actual.nd)->der != NULL)
            {
                hijo_derecho.nd = (nodo_actual.nd)->der;
                hijo_derecho.nivel = nodo_actual.nivel+1;    
                Q.push(hijo_derecho);
            }
            else
            {
                hijo_derecho.nd = NULL;
                hijo_derecho.nivel = nodo_actual.nivel+1;
                Q.push(hijo_derecho);
            }
        }
        else
        {
            //Subárbol vacío
            cout << "[.]" << "\t";
        }
    }
    
}

/*
//Impresión
template <class TDATO>
ostream& operator<<(ostream &salida,const Arbol<TDATO> &arbol_)
{
    arbol_.imprimirArbol(arbol_.get_raiz(), salida);
    return salida;
}
*/