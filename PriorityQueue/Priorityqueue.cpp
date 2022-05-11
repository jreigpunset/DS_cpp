#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<set>

//Priority Queue tipically implemented with binary heap
using namespace std;

template<typename T>
class PriorityQueue {
    int heapSize = 0;
    int heapCapacity = 0;
    list<T> heap = null;
    map<T, set<int>> hashtable = new map<T,set<int>>();

public:
    PriorityQueue() {
        this(1);
    }

    PriorityQueue(int sz) {
        heap = new list<T>();
    }
    //construct a priority queue using heapify in 0(n)
    PriorityQueue(T[] elems) {
        heapSize = heapCapacity = elems.size();
        heap = new list<T>(heapCapacity);
        //place all elements in heap
        for(int i = 0; i < heapSize; i++) {
            hashtable.insert({elems[i], i});
            heap.insert(elems[i]);
        }
        // heapify process
        for(int i = max(0, (heapSize/2) - 1); i >= 0; i--)
            sink(i);
    }
    //priority queue construction , 0(nlog(n))
    PriorityQueue(Collection<T> elems) {
        this(elems.size());
        for(T elem : elems) add(elem);
    }

    bool isEmpty(){
        return heapSize == 0;
    }
    // clear everything inside the heap 0(n)
    void clear() {
        for ( int i = 0; i < heapCapacity; i++) {
            heap.clear(i,NULL);
        }
        heapSize= 0;
        hashtable.clear();
    }

    /* peek Returns the value of the element with the lowest
     * priority in this priority queue. If the priority
     * queue is empty null is returned. 
     */

    int peek() {
        if(isEmpty()) return NULL;

         return heap[0];
    }
    //poll Removes the root of the heap, 0(log (n))
    T poll() {
        return removeAt(0);
    }

    //contains Test if an element is in heap 0(n)
    bool contains(T elem) {
        //Linear scan to check containment
        list<T>::iterator it;
        for(it = heap.begin(); it !=heap.end(); it++) {
            if(it == elem) return true;
            return false;
        }
    }
    //Add
    // Adds an element to the priority queue, the
    // element must not be null, O(log(n))


    // less 
    // Tests if the value of node i <= node j
    // This method assumes i & j are valid indices, O(1)

    //swim Perform bottom up node swim, O(log(n))

    // Top down node sink, O(log(n))
    //private void sink(int k) {

    // Swap two nodes. Assumes i & j are valid, O(1)
    // private void swap(int i, int j) {

    // Removes a node at particular index, O(log(n))
    // private T removeAt(int i) {

  // Recursively checks if this heap is a min heap
  // This method is just for testing purposes to make
  // sure the heap invariant is still being maintained
  // Called this method with k=0 to start at the root
  //public boolean isMinHeap(int k) {




};