#include<iostream>
#include "./Heap.h"

int main(){
    Heap h1;
    h1.addToHeap(10,10);
    h1.addToHeap(22,22);
    h1.addToHeap(21,21);
    h1.addToHeap(5,5);

    h1.addToHeap(1,1);
    std::cout<<"\n:D\n";
    h1.traverse();
    std::cout<<"DOne :D";
}