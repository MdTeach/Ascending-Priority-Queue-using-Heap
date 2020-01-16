#include<iostream>
#include<math.h>
#include "./Heap.h"

//public functions
Heap::Heap(){
    this->tail = 1;
    std::cout<<"Heap was created\n";
}

void Heap::addToHeap(int data, int priority){
    if(isFull()) throw "Heap Overflow";
    
    Node *node = new Node();
    node->data = data;
    node->priority = priority;

    //Adding the node to end of the tree
    addToIndex(tail,node);

    //Traverse up the based on the priority of the node
    traverseUp(node,tail);
}

int Heap::removeFromHeap(){
    return datas[1]->data;
}

bool Heap::isEmpty(){
    return (this->datas[1] == NULL);
}

bool Heap::isFull(){
    return (tail >= MAX_SIZE);
}

void Heap::traverse(){
    if(isEmpty()) throw "Heap is empty";
    int index = 1;
    while (index < tail){
        std::cout<<datas[index]->data<<" ";
        index+=1;   
    }
    std::cout<<std::endl;
    

}

//private functions
void Heap::addToIndex(int index,Node* node){
    std::cout<<"Added to"<<index<<"\n";
    datas[index] = node;
    tail+=1;
}

//private functions
int Heap::getParentIndex(int currentIndex){
    return floor(currentIndex/2);
}

void Heap::traverseUp(Node* currentNode, int currentIndex){
    int newIndex = getParentIndex(currentIndex);
    if(newIndex < tail && newIndex >= 1){
        std::cout<<"*** "<<newIndex<<" "<<currentIndex<<"\n";
        //parent node exists
        if(datas[newIndex]->priority > currentNode->priority){
            //low priority moveup
            //swap the infos

            
            Node* parentNode = datas[newIndex];
            
            //std::cout<<"Before"<<datas[newIndex]->data<<" "<<datas[currentIndex]->data<<"\n";
            
            datas[newIndex] = currentNode;
            datas[currentIndex] = datas[newIndex]; 

            //std::cout<<"After"<<parentNode->data<<" "<<datas[currentIndex]->data<<"\n";
            //recursively travese up
            traverseUp(currentNode,newIndex);
        }
    } 
}
