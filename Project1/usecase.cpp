#include <iostream>
#include  <sstream>
#include "minqueue."

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