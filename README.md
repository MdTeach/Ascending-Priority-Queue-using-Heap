# Ascending-Priority-Queue-using-Heap
<p>To run the demo: In shell type</p>
```
g++ ./Heap.cpp main.cpp
```
<h3>Public methods:</h3>
```c++
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
```