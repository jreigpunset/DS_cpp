#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<set>

//Priority Queue tipically impleneted with binary heap
using namespace std;

template<typename T>
class PriorityQueue{
    int heapSize = 0;
    int heapCapacity = 0;
    list<T> heap = null;
    map<T, set<int>> hashtable = new map<T,set<int>>();

public:
    PriorityQueue(){
        this(1);
    }

    PriorityQueue(int sz) {
        heap = new list<>();
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




};