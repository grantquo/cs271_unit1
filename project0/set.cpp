#include "set.h"
#include<iostream>
#include <sstream>
//=================================================
// List
// PARAMETERS:
// none
// RETURN VALUE: none ;
// set the head of the linked list to default NULL
//=================================================
template <class T>
Set<T> :: Set (void){
   // cout << (head == NULL)<<endl;
   //cout << head->item <<endl;
    head = NULL;
}
 //=================================================
// List
// PARAMETERS:
// none
// RETURN VALUE: none ;
// delete the memory leak of pointer
//=================================================
 //=================================================
// append
// PARAMETERS:
// an item
// RETURN VALUE: none
// add a new item that has value value item to the end of linked list
//=================================================
 template <class T>
 void Set<T> :: insert(const T &item ) {
     if(head == NULL){
         head = new Node;
         head->item = item ;
         
         //cout << item<<endl;
         //cout << head->next->item <<endl;
     }
     else {
     Node * ptr = head;
     int exist = 0;
     while(ptr->next){
         if(ptr->item == item){
             exist = 1;
             break;
         }
         ptr = ptr->next;
     }
     
     if(ptr->item == item){
         exist = 1;
     }
     //delete ptr ;
     if(exist == 0){
         Node * ptr1 = new Node;
         ptr1->item = item ;
         ptr1->next = head ;
         head = ptr1;
         //delete ptr1 ;
     }
   //  delete ptr ;
     }
 }
template <class T>
 void Set<T> :: remove(const T &item ) {
     if(head){
         if(!head->next){
             if(head->item == item){
                 head = NULL;
             }
         }
         else {
        Node *ptr = head ;
        if(ptr->item == item){
            Node *ptr1 = head ;
            ptr1 = ptr1 ->next ;
            head = ptr1 ;
        }
        else {
        while(ptr->next->next){
            if(ptr->next->item == item){
                ptr->next = ptr->next->next;
                break;
            }
            ptr = ptr->next;
        }
    if(ptr->next->item == item){
        ptr->next = NULL ;
    }
        }
        //delete ptr;
         }
     }
 }

 template <class T>
 int  Set<T> :: cardinality (void) const   {
     if(head == NULL){
         return 0;
     }
     else {
         Node *ptr = head;
         int len = 0;
         while(ptr){
             len ++;
              ptr = ptr->next;
         }
         //delete ptr ;
         return len ;
     }
 }


 template <class T>
 bool   Set<T> :: empty (void) const   {
     if ( head == NULL ) return true ;
     else return false ;
 }

 template <class T>
 bool Set<T> :: contains (const T &item){
     if(head == NULL){
         return false ;
     }
     Node *ptr = head ;
     while(ptr){
         if(ptr->item == item){
             return true ;
         }
         ptr = ptr ->next;
     }
     //delete ptr ;
     return false ;
 }

 template<class T>
 bool Set<T>  :: operator== (const Set<T> & myset) {
     if(head == NULL){
         if(myset.cardinality() == 0) return true ;
         return false ;
     }
     else {
         if(myset.cardinality() ==0){
             return false ;
         }
         else {
     Node *ptr = head ;
     //Node * ptr = st2 ;
     int len = 0 ;
     Node *ptr1 = head ;
     while(ptr1){
         len ++ ;
         ptr1 =ptr1->next;
     }
     if(len !=myset.cardinality()){
         return false;
     }
     while(ptr){
         Node*ptr1 = myset.head ;
         int exist  = 0;
         while(ptr1){
             if(ptr->item == ptr1->item){
                    exist = 1;
                    break;
             }
             ptr1 = ptr1->next;
         }
         if(exist == 0) return false;
         ptr = ptr->next;
     }
     return true ;
         }
     }
 }

 template<class T>
 bool Set<T>  :: operator<= (const Set<T> & myset) {
     int len = 0 ;
     if(head ==NULL){
         return true ;
     }
     else {
         if(myset.cardinality() ==0){
             return false ;
         }
     Node*ptr = head ;
     while(ptr){
         len ++;
         ptr = ptr->next;
     }
     if(len > myset.cardinality()){
         return false ;
     }
     else {
         Node*ptr = head ;
         //Node*ptr1 = myset.head;
        while(ptr){
            int exist = 0;
            Node*ptr1 = myset.head;
            while(ptr1){
                if(ptr->item == ptr1->item){
                    exist = 1;
                    break;
                }
                ptr1 = ptr1->next ;
            }
            if(exist == 0){
                return false ;
            }
            ptr = ptr->next;
        }
        return true ;
     }
     }
 }

 template<class T>
 Set<T>  Set<T>  :: operator+ (const Set<T> & myset) {
     //Node* ptr_all = new Node ;
     Set<T> st;
     if(head == NULL){
         if(myset.cardinality () ==0 ){
             return st;
         }
         else {
             st.head = new Node;
             Node *ptr = st.head ;
             Node*ptr1 = myset.head ;
             while(ptr1->next){
                 ptr->item = ptr1->item ;
                 ptr->next = new Node;
                 ptr1 = ptr1->next;
                 ptr = ptr->next;
             }
             ptr->item = ptr1->item ;
             return st;
         }
     }
     else {
         Node *ptr = head ;
         st.head = new Node ;
         Node *ptr1 = st.head ;
         while(ptr->next){
            ptr1->item = ptr->item ;
            ptr1->next = new Node;
            ptr1 = ptr1->next;
            ptr = ptr->next;
         }
         ptr1->item = ptr->item;
         if(myset.cardinality() ==0){
             return st;
         }
         else {
             Node *ptr2 = myset.head;
             //ptr1->next = new Node;
             while(ptr2){
                 int exist = 0;
                 Node *ptr3 = head ;
                 while(ptr3){
                     if(ptr3->item == ptr2->item){
                         exist = 1;
                         break;
                     }
                     ptr3 = ptr3->next;
                 }
                 if(exist == 0){
                     ptr1->next = new Node;
                     ptr1= ptr1->next;
                     ptr1->item = ptr2->item ;
                 }
                 ptr2= ptr2->next;
             }
         }
         return st;
     }
 }

 template<class T>
 Set<T>  Set<T>  :: operator& (const Set<T> & myset) {
     Set<T> ans;
     if(myset.cardinality() ==0 || head == NULL) return ans;
     Node *ptr =  head ;
     //Node *ptr1 = myset.head;
     while(ptr){
         int exist = 0;
         Node *ptr1 = myset.head ;
         while(ptr1){
             if(ptr1->item == ptr->item){
                 exist = 1;
                 break;
             }
             ptr1 = ptr1->next;
         }
         if(exist ==1){
             ans.insert(ptr->item);
         }
         ptr = ptr->next ;
     }
     return ans;
 }

 template<class T>
 Set<T>  Set<T>  :: operator- (const Set<T> & myset) {
    Set<T> ans;
     if(myset.cardinality() ==0 || head == NULL){
         if(myset.cardinality()==0){
             if(head == NULL) return ans;
             Node *ptr = head;
             //cout << ptr->item <<endl;
             while(ptr){
                 ans.insert(ptr->item );
                 ptr = ptr->next;
             }
             return ans ;
         }
         else {
             return ans ;
         }
     }
     Node *ptr =  head ;
     //Node *ptr1 = myset.head;
     while(ptr){
         int exist = 0;
         Node *ptr1 = myset.head ;
         while(ptr1){
             if(ptr1->item == ptr->item){
                 exist = 1;
                 break;
             }
             ptr1 = ptr1->next;
         }
         if(exist ==0){
             ans.insert(ptr->item);
         }
         ptr = ptr->next ;
     }
     return ans;
 }

 template<class T>
 string   Set<T>  :: to_string (void)  const {
           stringstream ss;
     if(head == NULL) return ss.str();
     Node *ptr = head ;
     //cout << ptr->item <<endl;
     while(ptr->next){
        // cout << ptr->item <<" ";
         ss << ptr->item ;
         ss <<" ";
         //ans += " ";
         ptr = ptr->next;
     }
     //cout <<endl;
     //cout << ans<<endl;
     ss << ptr->item ;
     return ss.str();
 }
