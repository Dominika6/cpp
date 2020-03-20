#include<iostream>
#include<cstdio>

using namespace std;
typedef int elementtype, position;
const int maxlength = 10;
struct List{
        elementtype elements[maxlength];
        int last;  //indeks ostatniego elementu listy
};

position First(List l){
        return 0;
}

position END(List l){
        return l.last + 1;
}

position Next(position p, struct List l){
        if (p<END(l)){
                return p + 1;
        }
        else
          return -1;
}

position Previous(position p, struct List l){
        if ((p <= First(l)) || (p > END(l)))
          return -1;
        else
          return p-1;
}

bool Insert(int x, position p, List &l){
        if ((p<0) || (p > END(l)))
          return false;
        if (p == END(l)){
                l.elements[p] = x;
                l.last = l.last + 1;
                return true;
        }
        if (p<END(l)){
                for (position k = END(l); k>p; k--){
                        l.elements[k] = l.elements[k - 1];
                }
                l.elements[p] = x;
                l.last = l.last + 1;
                return true;
        }
        return false;
}

bool Delete(position p, List &l){
	if( p >= 0 && p <= l.last ){
		for(int i = p; i <= l.last; i++){
			l.elements[i] = l.elements[i+1];
		}
		l.last--;
		return true;
	}
	else
		return false;
}

//zwraca pozycje x w l, gdy nie ma x w l zwraca end(l)
position Locate(elementtype x, List l){
        for (int i = 0; i<END(l); i++)
                if (l.elements[i] == x)return i;
        return END(l);
}

elementtype Retrieve(position p, List l){
        if ((p >= 0) || p <= END(l)){
                return l.elements[p];
        }
        else
          return -1;
}

void print(List l){
        position i = First(l);
        while (i != END(l))
        {
                printf("  %d,", Retrieve(i, l));
                i = Next(i, l);
        }
        printf("\n");
}
int main(){
        List l;
        l.last = -1;

        Insert(100, First(l), l);
        print(l);

        for (int i = 0; i<3; i++)
                Insert(i, First(l), l);
        print(l);

        Insert(20, Previous(END(l), l), l);
        print(l);

       Delete(Locate(20, l), l);
        print(l);

        Insert(5, Locate(0,l), l);
        print(l);

       Delete(4,l);
       print(l);

}
