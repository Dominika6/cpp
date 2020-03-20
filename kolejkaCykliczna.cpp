#include <iostream>
#include <cstdlib>
#include <cstdio>

const int maxlength = 50;
typedef int elementtype;
typedef int position;
class Kolejka
{
protected:
        elementtype Queue[maxlength];
        position Front; // Indeks elementu czołowego
        position Rear; // Indeks ostatniego elementu
public:
        Kolejka(){};
        ~Kolejka(){};
        int AddOne(int i);
        void Init();
        void Enqueue(elementtype x);
        void Dequeue();
        elementtype FrontElem();
        void Makenul();
        bool Empty();
};

/*Tworze kolejke, REAR zaraz za FRONT*/
void Kolejka::Init(){
        Front = 0;
        Rear = maxlength - 1;
}
/*sprawdzam czy kolejka nie jest pusta*/
bool Kolejka::Empty(){
        return (AddOne(Rear) == Front);
}
/*zwieksza o 1*/
int Kolejka::AddOne(int i){
        return ((i + 1) % maxlength);
}
/*aktualizuje pole REAR tak by wskazywalo na piersza wolna
komorke (zamiast na pierwszy element) i wstawiam element*/
void Kolejka::Enqueue(elementtype x){
         /*sprawdzam czy kolejka nie jest pelna*/
        if (AddOne(AddOne(Rear)) != Front){
                Rear = AddOne(Rear);
                Queue[Rear] = x;
        }
}
/*jesli kolejka nie jest pusta to aktualizuje pole FRONT
(czyli wyrzucam to co jest na poczatku kolejki i
wstawiam tam element nastepny w kolejnosci)*/
void Kolejka::Dequeue(){
        if (!Empty()){
                Front = AddOne(Front);
        }
}
/*jesli kolejka nie jest pusta to zwracam element
pierwszy z kolei*/
elementtype Kolejka::FrontElem(){
        if (!Empty())
                return Queue[Front];
}
/*czyszcze kolejke*/
void Kolejka::Makenul(){
        Front = 0;
        Rear = maxlength - 1;
}

int main()
{
        Kolejka *kolejka = new Kolejka();
        kolejka->Init(); /*prawie jak konstruktor*/
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
