#include <iostream>
using namespace std;

class Alumno{
    private:
        string NombreAlum;
        string Carrera;
        int MateriasAprob;
        float Promedio;
    public:
        friend std::istream & operator>>(std::istream &O, Alumno &x){
            std::cout<<"\n Nombre de Alumno: ";
            O>>x.NombreAlum;
            std::cout<<" Carrera: ";
            O>>x.Carrera;
            std::cout<<" Materias Aprobadas: ";
            O>>x.MateriasAprob;
            std::cout<<" Promedio: ";
            O>>x.Promedio;
            return O;
        }
        friend std::ostream & operator<<(std::ostream &O, Alumno &x){
            O<<"\n Nombre de Alumno: "<<x.NombreAlum;
            O<<"\n Carrera: "<<x.Carrera;
            O<<"\n Materias Aprobadas: "<<x.MateriasAprob;
            O<<"\n Promedio: "<<x.Promedio;
            return O;
        }
};
template<class T>
class Cola;

template<class T>
class node{
private:
    T data;
    node<T>* sig;
public:
    node():sig(nullptr){};
    friend class Cola<T>;
};

template<class T>
class Cola{
private:
    node<T>* lista;
    node<T>* ultimo()const;
    node<T>* primero()const;
    node<T>* anterior(node<T>* pos)const;
    void insertar(node<T>* pos, T elem);
    bool eliminar(node<T>* pos);
public:
    Cola():lista(nullptr){};
    bool vacia()const;
    void imprimir()const;
    void Enqueue(T elem);
    void Dequeue();
    T Front();
};

template<class T>
T Cola<T>::Front(){
    if(!vacia()){
       return primero()->data;
    }
}

template<class T>
void Cola<T>::Dequeue(){
    eliminar(primero());
}

template<class T>
void Cola<T>::Enqueue(T elem){
    insertar(ultimo(),elem);
}

template<class T>
void Cola<T>::imprimir()const{
    node<T>* aux=lista;
    while(aux!=nullptr){
        std::cout<<aux->data<<"\n->->->";
        aux=aux->sig;
    }
}

template<class T>
bool Cola<T>::eliminar(node<T>* pos){
    if(vacia() || pos==nullptr){
        return false;
    }
    if(pos==lista){
        lista=lista->sig;
    }
    else{
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    return true;
}

template<class T>
void Cola<T>::insertar(node<T>* pos, T elem){
    node<T>* aux= new node<T>;
    aux->data=elem;
    if(pos==nullptr){
        aux->sig=lista;
        lista=aux;
    }
    else{
        aux->sig=pos->sig;
        pos->sig=aux;
    }
}

template<class T>
node<T>* Cola<T>::anterior(node<T>* pos)const{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
node<T>* Cola<T>::primero()const{
    if(vacia()){
        return nullptr;
    }
    return lista;
}


template<class T>
node<T>* Cola<T>::ultimo()const{
    if(vacia()){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux->sig!=nullptr){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
bool Cola<T>::vacia()const{
    if(lista==nullptr)
        return true;
    return false;
}

void menuPrincipal(){
    std::cout<<"1. Encolar alumno"<<std::endl;
    std::cout<<"2. Desencolar alumno"<<std::endl;
    std::cout<<"3. Mostrar cola"<<std::endl;
    std::cout<<"4. Salir"<<std::endl;
    std::cout<<"Opcion: ";
}

int main()
{
    Cola<Alumno> micola;
    Alumno alum,x;
    int opt;
    do{
        system("cls");
        menuPrincipal();
        std::cin>>opt;
        switch(opt){
            case 1:
                std::cout<<"\nEncolando nuevo alumno"<<std::endl;
                std::cin>>alum;
                micola.Enqueue(alum);
                std::cout<<"\nAlumno encolado exitosamente.\n"<<std::endl;
                system("pause");
                break;
            case 2:
                if(micola.vacia()){
                    cout<<"\nLa cola se encuentra vacia. . .\n"<<endl;
                }
                else{
                    std::cout<<"\nDesencolando alumno. . ."<<std::endl;
                    x=micola.Front();
                    std::cout<<x<<std::endl<<std::endl;
                    micola.Dequeue();
                    std::cout<<"Alumno desacolado exitosamente.\n"<<std::endl;
                }
                system("pause");
                break;
            case 3:
                if(micola.vacia()){
                    cout<<"\nLa cola se encuentra vacia. . ."<<endl;
                }
                else{
                    std::cout<<"Mostrando cola:"<<std::endl;
                    micola.imprimir();
                }
                cout<<"\n";
                system("pause");
                break;
            default:
                std::cout<<"\nSaliendo. . .\n";
        }
    }
    while(opt!=4);
    return 0;
}
