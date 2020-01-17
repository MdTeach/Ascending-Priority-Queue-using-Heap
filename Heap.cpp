#include<iostream>
#include<math.h>
#include "./Heap.h"

//public functions
Heap::Heap(){
    this->tail = 0;
    std::cout<<"Heap was created\n";
}

void Heap::addToHeap(int data, int priority){
    if(isFull()) throw "Heap Overflow";
    
    Node *node = new Node();
    node->data = data;
    node->priority = priority;

    //Adding the node to end of the tree
    tail+=1; //increment the tail pointer
    addToIndex(tail,node);

    //Traverse up the based on the priority of the node
    traverseUp(node,tail);
}

int Heap::removeFromHeap(){
    //save the head data to be returned
    int data = datas[1]->data;

    //get the last element of the heap
    Node* lastEl = datas[tail];

    //decrease the size of the heap
    tail-=1;

    //inrest the last element of heap to the root
    datas[1] = lastEl;

    //traveser down the heap to arrange the data
    traverseDown(lastEl,1);
    return data;
}

bool Heap::isEmpty(){
    return (tail == 0);
}

bool Heap::isFull(){
    return (tail >= MAX_SIZE);
}

void Heap::traverse(){
    if(isEmpty()) throw "Heap is empty";
    int index = 0;
    while (index < tail){
        index+=1;  
        std::cout<<"Key: "<<datas[index]->priority<<" Data: "<<datas[index]->data<<"\n"; 
    }
    std::cout<<std::endl;
    

}

//private functions
void Heap::addToIndex(int index,Node* node){
    datas[index] = node;
}

//private functions
int Heap::getParentIndex(int currentIndex){
    return floor(currentIndex/2);
}

void Heap::traverseUp(Node* currentNode, int currentIndex){
    int newIndex = getParentIndex(currentIndex);
    if(newIndex >= 1){
        //parent node exists
        if(datas[newIndex]->priority > currentNode->priority){
            //low priority moveup
            //swap the infos
            Node* parentNode = datas[newIndex];
            datas[newIndex] = currentNode;
            datas[currentIndex] = parentNode; 
            //recursively travese up
            traverseUp(currentNode,newIndex);
            
        }
    }
     
}


void Heap::traverseDown(Node* currentNode, int currentIndex){
    //from the given index of the givem node find the index of its 
    //corresponding left and right child
    int leftIndex = 2*currentIndex;
    int rightIndex = 2*currentIndex+1;
    
    if(leftIndex <= tail && rightIndex <= tail){
        //node has both left and right subtree
        
        //compare the priority of the left and right child node and select with greatest priority
        int subTreeWithHighPriority = (datas[leftIndex]->priority <= datas[rightIndex]->priority) ? leftIndex : rightIndex;
        if(datas[subTreeWithHighPriority]->priority < currentNode->priority){
            //swap
            datas[currentIndex] = datas[subTreeWithHighPriority];
            datas[subTreeWithHighPriority] = currentNode;
            
            //recursively travese down
            traverseDown(
                datas[subTreeWithHighPriority],
                subTreeWithHighPriority
            );
            
        }
    }else if(leftIndex <= tail){
        //only left child present
        if(datas[leftIndex]->priority < currentNode->priority){
            //swap
            datas[currentIndex] = datas[leftIndex];
            datas[leftIndex] = currentNode;
            
            //recursively travese down
            traverseDown(
                datas[leftIndex],
                leftIndex
            );
            
        }

    }else if(rightIndex <= tail){
        //only right child present
        if(datas[rightIndex]->priority < currentNode->priority){
            //swap
            datas[currentIndex] = datas[rightIndex];
            datas[rightIndex] = currentNode;
            
            //recursively travese down
            traverseDown(
                datas[rightIndex],
                rightIndex
            );
            
        }
    }

     
}