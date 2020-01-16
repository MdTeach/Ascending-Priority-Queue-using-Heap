#include<iostream>
#include "./Heap.h"

int main(){
    Heap h1;
    h1.addToHeap(10,2);
    h1.addToHeap(2,2);
    h1.addToHeap(12,1);
    h1.traverse();
    std::cout<<"DOne :D";
}