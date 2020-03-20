#include<iostream>

const int maxlength=20;
typedef int elementtype;
typedef int position;

class Stos{
  int S[maxlength] ;
  position Top;//szczyt stosu
public:
  Stos();
  void Push(elementtype x);
  void Pop();
  bool Empty();
  elementtype TopElem();
  void Makenull();
};
////////

Stos::Stos(){
  Top = -1;

}

void Stos::Push(elementtype x){
  if(Top < maxlength -1){
      S[++Top] = x;
  }else
      std::cout << "Stos jest pełny " << std::endl;

}

void Stos::Pop(){
  elementtype x;
  if(Top >= 0){
      Top--;
  }else
  std::cout << "Error" << std::endl;

}

bool Stos::Empty(){
  if(Top == -1){
      return true;
  }else
      return false;
}

elementtype Stos::TopElem(){
  if(Top >= 0){
      elementtype x = S[Top];
      return x;
  }else
      std::cout << "Error" << std::endl;
}

void Stos::Makenull(){
    Top = -1;
}


int main(){
    Stos *s = new Stos();

    if(s->Empty()){
        std::cout << "Stos jest pusty"<< std::endl;
    }else
        std::cout << "nie jest pusty" << std::endl;

    s->Push(1);
    std::cout << "Top element: " << s->TopElem() << std::endl;
    if(s->Empty()){
        std::cout << " Stos jest pusty"<< std::endl;
    }else
        std::cout << "nie jest pusty" << std::endl;


    s->Pop();


if(s->Empty()){
        std::cout << "Stos jest pusty"<< std::endl;
    }else
        std::cout << "nie jest pusty" << std::endl;

s->Push(2);
s->Push(3);

std::cout << "Top element: " << s->TopElem() << std::endl;

s->Makenull();

if(s->Empty()){
        std::cout << " Stos jest pusty"<< std::endl;
    }else
        std::cout << "Nie jest pusty " << std::endl;


    return 0;
}
