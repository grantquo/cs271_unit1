#include <iostream>
#include "minqueue.h"
#include  <sstream>
#include <utility>
#include <stdexcept>

using namespace std;

//======================================================
// MinQueue
// Initialization functiont that creates a new empty queue.
// PARAMS:
//      none
// RETURN VALUES:
//      Doesn't return anything. Creates an empty minimum
//      priority queue.
//======================================================
template <class T>
MinQueue<T> :: MinQueue (void){
    //head = NULL;
    list = new T[DEFAULT_LIST_CAPACITY];
    capacity = DEFAULT_LIST_CAPACITY;
    size = 0 ;

}

//======================================================
// ~MinQueue
// Destructor function that deletes the queue.
// PARAMS:
//      none
// RETURN VALUES:
//      Doesn't return anything. Performs a deletion of
//      the minimum queue, freeing previously stored
//      memory.
//======================================================
template <class T>
MinQueue<T> :: ~MinQueue (void){
    delete []list;
}

//======================================================
// MinQueue (T*A, int n)
// Initializes a new empty minimum priority queue using
// parameters that build its values.
// PARAMS:
//      T *A: A pointer to another minimum priority queue
//      of data type T
//      int n : An integer within the size of *A
// RETURN VALUES:
//      Doesn't return anything. Creates a new minimum
//      priority queue with n values from T *A.
//======================================================
template <class T>
MinQueue<T> :: MinQueue ( T*A, int n){
    list = new T[n];
    capacity = n ;
    size = n;
    for(int i =0 ;i<size;i++){
       list[i] = *(A+i);
    }
    build_heap();
}

//======================================================
// insert
// An insertion function that adds a value into the
// priority queue.
// PARAMS:
//      const T &item: item of data type T that will be
//      added into the queue.
// RETURN VALUES:
//      Doesn't return anything. Adds a new item that is
//      stored inside the queue.
//======================================================
template <class T>
 void MinQueue<T> :: insert (const T&item){
    //int first_time = 0 ;
    if(size < capacity){
    list[size] = item;
    size ++ ;
    }
    else {
        T*newlist;
        newlist = new T[2*capacity];
        capacity *= 2;
        for(int i =0 ;i<size;i++){
            newlist[i] = list[i];
        }
        list = new T[capacity];
        for(int i =0 ;i<size;i++){
            list[i] = newlist[i];
        }
        delete []newlist;
        list[size] = item;
        size ++ ;
    }
    int vl = size-1 ;
    while(vl != 0 && list[vl] < list[(vl-1)/2]){
            //cout << list[vl] <<" "<<list[(vl-1)/2]<<endl;
            swap(list[vl],list[(vl-1)/2]);
            vl = (vl-1)/2;
        }
}

//======================================================
// min_heapify
// Heap function that follows the min-heap property where
// the passed element is organized. Other values
// are arranged in accordance with the property.
// PARAMS:
//      int id: Element that is made the root of the heap
// RETURN VALUES:
//      Doesn't return anything. Instead orders the
//      priority queue and its values by the min-heap
//      property.
//======================================================
template <class T>
 void MinQueue<T> :: min_heapify (int id){
    //cout << size <<endl;
    int l = 2*id +1 ;
    int r = 2*id + 2 ;
    //cout << a[l <<" "<<r<<endl;
    int smallest ;
    if(l < size && list[l] <  list[id]){
        smallest = l ;
    }
    else smallest = id;
    if(r< size && list[r] < list[smallest]){
        smallest = r;
    }
   // cout << list[smallest] <<" "<< list[id]<<endl;
    if(smallest !=id){
        swap(list[id],list[smallest]);
        //cout << size <<endl;
       // cout <<endl;
       if (smallest < size ) min_heapify(smallest);
    }
}

//======================================================
// to_string
// Creates a formatted stringstream that outputs each
// element in the function.
// PARAMS:
//      none
// RETURN VALUES:
//      Returns a stringstream that can be utilized by
//      cout to output and display the queue and its
//      contents.
//======================================================
template<class T>
string MinQueue<T> :: to_string (void)  const {
   stringstream ss ;
  // cout << list[0]<<endl;
  // cout << size <<endl;
   if(size == 0 ) {
        ss.clear();
        return ss.str();
   }
   else if (size == 1){
     ss << list[0];
     return ss.str() ;
   }
   for(int i =0 ;i<size-1 ;i ++){
    ss << list[i];
    ss <<" ";
   }
   ss << list[size-1];
   return ss.str();
}

//======================================================
// operator[]
// Utilizes the [] operator to call indexes in the queue.
// PARAMS:
//      int index: Integer representing the index of a value
//      in the queue.
// RETURN VALUES:
//      Returns the item in the index value within the
//      queue. If the index number given is not in range,
//      an error will be outputted.
//======================================================
template <class T>
T& MinQueue<T>:: operator[] ( int index ){
    if(index >= capacity){
        cout <<"Error"<<endl;
    }
    return *(list+index);
}

//======================================================
// build_heap
// Builds a heap within the priority queue. This only
// builds the heap and calls min_heapify() to organize it
// by each item.
// PARAMS:
//      none
// RETURN VALUE:
//      Does not return anything. Calls the min_heapify()
//      function to organize the values according to
//      min-heap properties.
//======================================================
template <class T>
void  MinQueue<T>::  build_heap( void){
   // cout << size <<endl;
   size = capacity;
  // size = capacity;
   for (int i = size/2 -1;i >= 0;i--){
        min_heapify(i);
   }
}

//======================================================
// min
// Finds the smallest value in the queue.
// PARAMS:
//      none
// RETURN VALUE:
//      Returns the smallest value in the queue. If the
//      queue is empty, returns an empty queue.
//======================================================
template <class T>
T MinQueue<T>::  min( void){
   if( size == 0) return T();
   return list[0];
}

//======================================================
// extract_min
// Finds and removes the smallest value in the queue.
// PARAMS:
//      none
// RETURN VALUES:
//      Returns the smallest value in the queue. The value
//      is also removed from the queue. If the queue is
//      empty, returns it.
//======================================================
template <class T>
T  MinQueue<T>::  extract_min     (void){
    //if(size == 0) return ;
  T val = list[0];
  if (size == 0){
    return T();
  }
  else if(size == 1){
    size -- ;
  }
  else  {
    list[0] = list[size-1];
    size -- ;
    min_heapify(0);
  }
  return val ;
}

//======================================================
// decrease_key
// Finds a value specified through its index and decreases
// it by a particular number.
// PARAMS:
//      int id: Integer representing the index of a value
//      in the queue.
//      T k: An item with data type T that will be subtracted
//      from the values of the same type in the queue.
// RETURN VALUES:
//      Doesn't return anything. Subtracts from a value
//      in the queue by k.
//======================================================
template <class T>
void   MinQueue<T>::  decrease_key     (int id , T k){
    if(id >= capacity){
            throw std::invalid_argument("Index out of range");
    }
    else {
    if(list[id] > k){
        list[id] = k;
        while(id != 0 && list[id] < list[(id-1)/2]){
            swap(list[id],list[(id-1)/2]);
            id = (id-1)/2;
        }
    }
    }
}

//======================================================
// sort
// Takes an array containing values in a min-heap and
// sorts all of the values in the array in ascending order.
// PARAMS:
//      T *A: An array of values with data type T
// RETURN VALUES:
//      Doesn't return anything. Calls min_heapify() to
//      perform sorting following the min-heap property.
//      Sorts the values in the array A with min-heap values
//      in ascending order.
//======================================================
template <class T>
void   MinQueue<T>::  sort    (T*A){
    int val = size ;
    //int change = 0 ;
    for(int i = val-1 ;i >0;i--){
        swap(list[0],list[i]);
        size -- ;
        min_heapify(0);
    }
    size = val ;
    T*ls = new T[capacity];

    for(int i =0 ;i<size;i++){
        ls[i] =list[size-i-1];
    }
    for(int i =0;i<size;i++){
        *(A+i) = ls[i];
    }
    delete []ls;
   // delete []ls;
}

//======================================================
// len
// Simple function that calls for the size of the queue.
// PARAMS:
//      none
// RETURN VALUES:
//      Returns the size of the queue.
//======================================================
template <class T>
int MinQueue<T>:: len ( void){
    return size ;
}

//======================================================
// set
// Finds a value in a specified index and changes it to
// a different value.
// PARAMS:
//      int id: Integer representing the index of a value
//      in the queue.
//      T k: Item of data type k that will change a value
//      in the queue.
// RETURN VALUES:
//      Doesn't return anything. Changes a value to k in
//      index id.
//======================================================
template <class T>
void   MinQueue<T>::  set    (int id , T k){
    if(id >= capacity ){
         throw std::invalid_argument("Index out of range");
    }
    else {
        list[id] = k ;
    }
}

//======================================================
// allocate
// Allocates more space into the queue by a specified number.
// PARAMS:
//      int n: Integer that adds more spaces for values to
//      be stored in the queue.
// RETURNS:
//      Doesn't return anything. Allocates more space into
//      the queue.
//======================================================
template <class T>
void MinQueue<T> :: allocate (int n){
   // capacity = n ;
    T* newlist = new T[n];
    for(int i =0 ;i<size;i++){
        newlist[i] = list[i];
    }
    list = new T[n];
    capacity = n ;
    for(int i =0 ;i<size;i++){
        list[i] = newlist[i];
    }
    //cout << size <<endl;
   // size = n ;
   delete []newlist;
}

//======================================================
// cap
// Finds the max capacity of the queue.
// PARAMS:
//      none
// RETURN VALUES:
//      Returns an integer of the max capacity of the queue.
//======================================================
template <class T>
int MinQueue<T>:: cap ( void){
    return capacity;
}
