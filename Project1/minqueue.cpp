#include <iostream>
#include "minqueue.h"
#include  <sstream>
#include <utility>
#include <stdexcept>

using namespace std; 

template <class T>
MinQueue<T> :: MinQueue (void){
    //head = NULL;
    list = new T[DEFAULT_LIST_CAPACITY];
    capacity = DEFAULT_LIST_CAPACITY;
    size = 0 ;
    
}
template <class T>
MinQueue<T> :: ~MinQueue (void){
    delete []list;
}

template <class T>
MinQueue<T> :: MinQueue ( T*A, int n){
    list = new T[n];
    capacity = n ;
    size = n;
    for(int i =0 ;i<size;i++){
       list[i] = *(A+i);
    }
    build_min_heap();
}


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

template <class T>
 void MinQueue<T> :: heapify (int id){
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
       if (smallest < size ) heapify(smallest);
    }
}

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

template <class T>
T& MinQueue<T>:: operator[] ( int index ){
    if(index >= capacity){
        cout <<"Error"<<endl;
    }
    return *(list+index);
}


template <class T>
void  MinQueue<T>::  build_min_heap( void){
   // cout << size <<endl;
   size = capacity;
  // size = capacity;
   for (int i = size/2 -1;i >= 0;i--){
        heapify(i);
   }
}

template <class T>
T MinQueue<T>::  min( void){
   if( size == 0) return T();
   return list[0];
}


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
    heapify(0);
  }
  return val ;
}

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

template <class T>
void   MinQueue<T>::  sort    (T*A){
    int val = size ;
    //int change = 0 ;
    for(int i = val-1 ;i >0;i--){
        swap(list[0],list[i]);
        size -- ;
        heapify(0);
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

template <class T>
int MinQueue<T>:: len ( void){
    return size ;
}

template<class T> 
string  sliding_window  (T arr[], int len, int window){
    stringstream  ss ; 
    if(len < window||len ==0){
        return ss.str();
    }
    else {
        MinQueue<pair<T,int> > mq;
        for(int i =0 ;i<window;i++){
           // cout << arr[i] <<" "<<i<<endl;
            mq.insert(make_pair(arr[i],i));
        }
        //cout << mq.min().first <<endl;
        ss << mq.min().first;
        for(int i = window  ; i < len;i++){
            mq.insert(make_pair(arr[i],i));
            //cout << mq.min().first << " "<< mq.min().second <<endl;
            while(mq.len()>0&&i- window+1 > mq.min().second){
               int value =  mq.extract_min().second;
            }
            //cout << mq.len() <<endl;
            ss<<" ";
            ss << mq.min().first;
            
        }
        return ss.str();
    }
}

template <class T>
void   MinQueue<T>::  set    (int id , T k){
    if(id >= capacity ){
         throw std::invalid_argument("Index out of range");
    }
    else {
        list[id] = k ;
    }
}
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

template <class T>
int MinQueue<T>:: cap ( void){
    return capacity;
}