#include <iostream>

typedef int  elementtype;

struct celltype {
elementtype element;
celltype * next;
};
typedef celltype  * position;


class Lista{
protected :
        position l; // wskaźnik do głowy listy

public:

        Lista(); //konstruktor
    void Insert(elementtype x, position p);
          void Delete(position p);
    elementtype Retrieve(position p);
          position Locate(elementtype x);
    position First();
    position Next(position p);
    position Previous(position p);
          position END();
     void print();
};

        Lista::Lista(){
                        l = new celltype;
                        l->next = NULL;
        }

        position Lista::First(){
          return l;
        }

        position Lista::Next(position p){
          return p->next;
        }

        void Lista::Insert(elementtype x, position p){
          position tmp = p->next;
          p->next = new celltype;
          p->next->element = x;
          p->next->next = tmp;
        }

        void Lista::Delete(position p){
          position tmp;
          tmp = p->next;
          p->next = p->next->next;
          delete tmp;
        }

        position Lista::Locate(elementtype x){
          position tmp;
          tmp = l;
          while (tmp->next != NULL){
            if (tmp->next->element == x)  return tmp;
            tmp = tmp->next;
          }
          return tmp;

        }
        position Lista::END(){
          position p = l;
          while (p->next != NULL)
            p = p->next;
          return p;
          }

        elementtype Lista::Retrieve(position p){
          if (p->next != NULL)
          return p->next->element;
        }

    void Lista::print(){
      position head = l;

      while(head != END()){
        std::cout << Retrieve(head) << std::endl;
        head = head->next;
      }
      std::cout <<"...."<<std::endl;

    }

int main(){
  Lista *l = new Lista();

  l->Insert(5, l->First());
  l->print();
  l->Insert(2, l->First());
  l->print();
  l->Insert(1, l->Next(l->First()));
  l->print();


  return 0;
}
