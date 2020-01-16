#pragma once
#include<iostream>
#define MAX_SIZE 500

class Node{
    public:
    int priority;
    int data;
};


class Heap{
    public:
    Heap();

    /*
    * Creates new node and adds to the heap
    * @parm string data -> data stored in the node
    * @parm int proriy -> priority to place it in the heap
    */
    void addToHeap(int data, int priority);

    /*
    * Removes the root node and assigns the suitable new root from the heap
    * @reutrns content of the root as string
    */
    int removeFromHeap();
    
    /*
    * @reutrns true if heap is empty
    */
    bool isEmpty();

    /*
    * @reutrns true if heap is full
    */
    bool isFull();

    /*
    * BFS through the elements in the array
    */
    void traverse();

    private:
    //Contains all data as array of nodes
    Node* datas[MAX_SIZE];

    //Index of last item
    int tail;


    //add node to the provided index
    void addToIndex(int index,Node* node);

    //insert to left or right
    void insert(Node* subtree, Node* newNode);

    //get the parents index
    int getParentIndex(int currentIndex);

    //traverse up
    void traverseUp(Node* currentNode, int currentIndex);

};

