#include<iostream>

using  namespace std;

class nodo{
    int dato;
    nodo *anterior;
    nodo *siguiente;
    friend class lista;
};
class lista{
public:
    lista(){
        inicio = new nodo;
        fin = new nodo;
        inicio->siguiente =fin;
        fin->siguiente=inicio;
        inicio->anterior =NULL;
        fin->siguiente =NULL;

    };
    int getFrente(){
        return inicio->siguiente->dato;
    };
    int getAtras(){
        return fin->anterior->dato;
    };
    void add_frente(int _dato){
        nodo *temp =new  nodo;
        temp->dato =_dato;
        temp->anterior =inicio;
        temp->siguiente =inicio->siguiente;

        inicio->siguiente->anterior= temp;
        inicio->siguiente =temp;
    };
    void add_atras(int _dato){
        nodo *temp =new  nodo;
        temp->dato =_dato;
        temp->anterior =fin->anterior;
        temp->siguiente =fin;

        fin->anterior->siguiente= temp;
        fin->anterior =temp;
    };
    void eliminar_frente(){
        nodo *temp = inicio->siguiente->siguiente;
        delete inicio->siguiente;
        inicio->siguiente=temp;
        temp->anterior =inicio;
    };
    void eliminar_atras(){
        nodo *temp = fin->siguiente->siguiente;
        delete fin->anterior;
        fin->anterior=temp;
        temp->siguiente =fin;
    };
    void print_atras(){
        nodo *temp = fin->anterior;
        while(temp !=inicio){
            cout<<temp->dato<<" - ";
            temp = temp->anterior;
        }
    };
    void print_delante(){
        nodo *temp = inicio->siguiente;
        while(temp !=fin ){
            cout<<temp->dato<<" - ";
            temp = temp->siguiente;
        }
    };
private:
    nodo *inicio;
    nodo *fin;
};
int main(){
    lista li;
    li.add_frente(8);
    li.add_frente(8);
    li.add_frente(9);

    li.print_delante();
    return 0;
}
