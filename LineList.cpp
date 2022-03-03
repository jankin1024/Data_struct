#include <iostream>
using namespace std;

#define N 102


struct Node
{
    int key;
    int value;
};

struct Linelist{
    Node list[N];
    int len;
    Linelist();
    int length();
    int getvalue(int p);
    int find(int x);
    void insert(int p, int x);
    void del(int p);
};

Linelist::Linelist(){
    for (int i = 0; i < N; i++){
        Linelist::list[i].key = 0;
        Linelist::list[i].value = 0;
    }
    Linelist::len = 0;
}

int Linelist::length(){
    return Linelist::len;
}

int Linelist::getvalue(int p){
    if(p>0 && p<=Linelist::len){
        return Linelist::list[p].value;
    }
    else{
        cerr << "p is out of range" << endl;
        return -1;
    }
}

int Linelist::find(int x){
    for (int i = 1; i <= Linelist::len; i++){
        if(Linelist::list[i].value == x){
            return i;
        }
    }
    cerr << "x is not find" << endl;
    return -1;
}

void Linelist::insert(int p, int x){
    Linelist::len++;
    for (int i = Linelist::len; i > p; i--)
    {
        
    }
}

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
