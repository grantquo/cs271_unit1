#include "set.h"
#include<iostream>
#include <sstream>
//=================================================
// Set
// Creates an empty Set.
// PARAMS:
// none
// RETURN VALUE:
// none
//=================================================
template <class T>
Set<T> :: Set (void){
    // cout << (head == NULL)<<endl;
    //cout << head->item <<endl;
    head = NULL;
}

//=================================================
// insert
// Inserts an item at the beginning of the set.
// PARAMS:
// const T &item : item of T data type being added.
// RETURN VALUE:
// none
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
        //delete ptr ;
    }
}

//=================================================
// remove
// Removes a specified item from the set.
// PARAMS:
// const T &item : specific item of T data type
// being removed.
// RETURN VALUE:
// none
//=================================================
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

//=================================================
// cardinality
// Finds the number of items in the set.
// PARAMS:
// none
// RETURN VALUE:
// Returns an integer value representing the number
// of items in the set.
//=================================================
template <class T>
int Set<T> :: cardinality (void) const   {
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
//=================================================
// empty
// Checks if the set has no items stored.
// PARAMS:
// none
// RETURN VALUE:
// Returns a boolean true or false for whether the
// set is empty.
//=================================================
template <class T>
bool Set<T> :: empty (void) const   {
    if ( head == NULL ) return true ;
    else return false ;
}

//=================================================
// contains
// Checks if a specified element is inside the set.
// PARAMS:
// const T &item : item of datatype T that will be
// searched within the function.
// RETURN VALUE:
// Returns a boolean true or false for whether the
// item specified in the parameter is in the set.
//=================================================
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

//=================================================
// operator==
// Allows the operator usage of '<=' and compares if two
// sets have the same elements.
// PARAMS:
// const Set<T> & myset : A set being compared to 
// the main set.
// RETURN VALUE:
// Returns a boolean true or false for whether the
// main set and the second set being compared have
// the same elements.
//=================================================
template<class T>
bool Set<T> :: operator== (const Set<T> & myset) {
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
        return false ;
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

//=================================================
// operator<=
// Allows the operator usage of '<=' and finds 
// whether the main set is a subset of a set stated
// in the parameter.
// PARAMS:
// const Set<T> & myset : A set that will be searched
// for subsets.
// RETURN VALUE:
// Returns a boolean true or false for if the main
// set is a subset of the parameter.
//=================================================
template<class T>
bool Set<T> :: operator<= (const Set<T> & myset) {
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
//=================================================
// operator+
// Allows the operator '+' and finds the union
// between two sets.
// PARAMS: 
// const Set<T> & myset : a set that will be searched 
// for unions with the main set.
// RETURN VALUE:
// Returns a new set that is the union between the
// main set and the parameter set.
//=================================================
template<class T>
Set<T> Set<T> :: operator+ (const Set<T> & myset) {
    //Node* ptr_all = new Node ;
    Set<T> st;
    if(head == NULL){
        if(myset.cardinality () ==0 ){
            return st ;
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
            return st ;
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
            return st ;
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
        return stn ;
    }
}
//=================================================
// operator&
// Allows the operator '&' and finds the intersection
// between two sets.
// PARAMS:
// const Set<T> & myset : a set that will searched for
// intersections of the main set.
// RETURN VALUE:
// A new set that is the intersection between the 
// main set and the parameter set.
//=================================================
template<class T>
Set<T> Set<T> :: operator& (const Set<T> & myset) {
    Set<T> ans;
    if(myset.cardinality() ==0 || head == NULL) return ans ;
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
    return ans ;
}
//=================================================
// operator-
// Allow the operator '-' and finds the difference
// between two sets.
// PARAMS:
// const Set<T> & myset : a set that will be used to
// find the difference from the main set.
// RETURN VALUE:
// A new set that is the difference between the main
// set and the parameter set.
//=================================================
template<class T>
Set<T> Set<T> :: operator- (const Set<T> & myset) {
    Set<T> ans;
    if(myset.cardinality() ==0 || head == NULL){
        if(myset.cardinality()==0){
            if(head == NULL) return ans ;
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
    return ans ;
}
//=================================================
// to_string
// Converts the main set into a string and displays
// each of its elements.
// PARAMS:
// none
// RETURN VALUE:
// A string that displays the sets elements, each
// seperated by a whitespace.
//=================================================
template<class T>
string Set<T> :: to_string (void)  const {
    stringstream ss;
    if(head == NULL) return ss.str() ;
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
    return ss.str() ;
}
