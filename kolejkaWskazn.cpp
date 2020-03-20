#include <cstdio>
#include <cstdlib>
#include <iostream>

typedef int elementtype;
struct celltype{
        elementtype element;
        celltype * next;
};
typedef celltype * position;
class Queue
{
protected:
        position Front; // wskaźnik do głowy listy
        position Rear; // wskaźnik do ostatniegoelementu
public:
        Queue(); //konstruktor
        ~Queue(); //destruktor
        void Enqueue(elementtype x);
        void Dequeue();
        elementtype FrontElem();
        bool Empty();
};


/*tworzy obiekt, glowe i aktualizuje wartosci FRONT i REAR*/
Queue::Queue( ) {
        Front = new celltype;
        Rear = Front;
        Front->next = NULL;
}
/*sprawdzam czy kolejka nie jest pusta*/
bool Queue::Empty() {
        return (Front->next == NULL);
}
/*tworzy nowa komorke, wstawia ja na koniec kolejki
oraz aktualizuje REAR tak by wskazywal na ta komorke*/
void Queue::Enqueue(elementtype x) {
        position p = new celltype;
        p->element = x;
        p->next = NULL;
        Rear->next = p;
        Rear = p;
}
/*jesli kolejka nie jest pusta to zapamietuje glowe
w zmiennej p, zmieniam pole FRONT tak by wskazywalo
element kolejny jako glowe i usuwamp */
void Queue::Dequeue(){
        if (!Empty()){
                position p = Front;
                Front = Front->next;
                delete p;
        }
}
/*jesli kolejka nie jest pusta to zwracam pierwszy element*/
elementtype Queue::FrontElem(){
        if (!Empty())
                return Front->next->element;
}
Queue::~Queue( ){
        position tmp;
        while (Front->next != NULL){
                tmp = Front;
                Front = Front->next;
                delete tmp;
        }
        delete Front;
}

int main()
{
        Queue *kolejka = new Queue();
        std::cout << "Sprawdzam czy kolejka jest pusta: ";
        if (kolejka->Empty()) std::cout << "kolejka pusta" << std::endl;
        else  std::cout << "w kolejce cos jest!" << std::endl;
        std::cout << "Wstawiam elementy: 5,6,1,2,4 na KONIEC kolejki" << std::endl;
        kolejka->Enqueue(5);
        kolejka->Enqueue(6);
        kolejka->Enqueue(8);
        kolejka->Enqueue(2);
        kolejka->Enqueue(4);

        std::cout << "Sprawdzam co ma na pozycji FRONT (powinno byc 5)" << std::endl;
        std::cout << kolejka->FrontElem() << std::endl;
        std::cout << "Usuwam pierwszy element " << std::endl;
        kolejka->Dequeue();
        std::cout << "Sprawdzam co ma na pozycji FRONT (powinno byc 6)" << std::endl;
        std::cout << kolejka->FrontElem() << std::endl;

        std::cout << "Usuwam 3 elementy z poczatku kolejki " << std::endl;
        kolejka->Dequeue();
        kolejka->Dequeue();
        kolejka->Dequeue();
        std::cout << "Sprawdzam co ma na pozycji FRONT (powinno byc 4)" << std::endl;
        std::cout << kolejka->FrontElem() << std::endl;

        std::cout << "Usuwam ostatni element z kolejki " << std::endl;
        kolejka->Dequeue();

        std::cout << "Sprawdzam czy kolejka jest pusta: ";
        if (kolejka->Empty()) std::cout << "kolejka pusta" << std::endl;
        else  std::cout << "w kolejce cos jest!" << std::endl;


        getchar();

}
