//
//  test.cpp
//  CS 271 Set Project: Test File
//
//  Created by Grant Gutterman and Dong Tran
//
#include <iostream>
#include <chrono>
#include "set.cpp"

void test_insert() {
    try {
        // int test
        Set<int> s;
        s.insert(0);
        s.insert(1);
        s.insert(2);
        s.insert(-1);
        string set_str = s.to_string();
        if (s.to_string() != "-1 2 1 0") {
            cout << "ERROR: Insert Result [Expected -1 2 1 0 but got : " << set_str << " ]" << endl;
        }

        // char test
        Set<char> t;
        t.insert('t');
        set_str = t.to_string();
        if (t.to_string() != "t") {
            cout << "ERROR: Insert Result [Expected t but got : " << set_str << " ]" << endl;
        }

        // float test
        Set<float> u;
        u.insert(2.3);
        set_str = u.to_string();
        if (u.to_string() != "2.3") {
            cout << "ERROR: Insert Result [Expected 2.3 but got: " << set_str << " ]" << endl;
        }

        // bool test
        Set<bool> v;
        v.insert(true);
        v.insert(false);
        set_str = v.to_string();
        if (v.to_string() != "0 1") {
            cout << "ERROR: Insert Result [Expected 0 1 but got: " << set_str << " ]" << endl;
        }

        // string test
        Set<string> w;
        w.insert("string1");
        w.insert("s s s");
        set_str = w.to_string();
        if (w.to_string() != "s s s string1") {
            cout << "ERROR: Insert Result [Expected s s s string1 but got: " << set_str << " ]" << endl;
        }
    } 
    catch (exception& e) {
    cerr << "Error inserting into set : " << e.what() << endl;
    }
}

void test_remove() {
    try {
        // int test
        Set<int> s;
        s.insert(3);
        s.insert(6);
        s.remove(3);
        string set_str = s.to_string();
        if (s.to_string() != "6") {
            cout << "ERROR: Remove Result [Expected 6 but got: " << set_str << " ]" << endl;
        }

        // char test
        Set<char> t;
        t.insert('2');
        t.insert('g');
        t.remove('2');
        set_str = t.to_string();
        if (t.to_string() != "g") {
            cout << "ERROR: Remove Result [Expected g but got: " << set_str << " ]" << endl;            
        }

        // float test
        Set<float> u;
        u.insert(3.6);
        u.insert(12.34);
        u.remove(12.34);
        set_str = u.to_string();
        if (u.to_string() != "3.6") {
            cout << "ERROR: Remove Result [Expected 3.4 but got: " << set_str << " ]" << endl;
        }

        // bool test
        Set<bool> v;
        v.insert(true);
        v.insert(false);
        v.remove(false);
        set_str = v.to_string();
        if (v.to_string() != "1") {
            cout << "ERROR: Remove Result [Expected 1 but got: " << set_str << " ]" << endl;
        }

        // string test
        Set<string> w;
        w.insert("string1");
        w.insert("string2");
        w.remove("string2");
        set_str = w.to_string();
        if (w.to_string() != "string1") {
            cout << "ERROR: Remove Result [Expected string1 but got: " << set_str << " ]" << endl;
        }
    }
    catch (exception &e) {
        cerr << "Error removing from set : " << e.what() << endl;
    }
}

void test_cardinality() {
    try {
        // int test
        Set<int> s;
        int s_card = s.cardinality();
        if (s_card != 0) {
            cout << "ERROR: Incorrect Cardinality Result [Expected 0 but got: " << s_card << " ]" << endl;
        }
        s.insert(1);
        s.insert(2);
        s_card = s.cardinality();
        if (s_card != 2) {
            cout << "ERROR: Incorrect Cardinality Result [Expected 2 but got: " << s_card << " ]" << endl;
        }

        // char test
        Set<char> t;
        int t_card = t.cardinality();
        if (t_card != 0) {
            cout << "ERROR: Incorrect Cardinality Result [Expected 0 but got: " << t_card << " ]" << endl;
        }
        t.insert('a');
        t.insert('b');
        t_card = t.cardinality();
        if (t_card != 2) {
            cout << "ERROR: Incorrect Cardinality Result [Expected 2 but got: " << t_card << " ]" << endl;
        }

        // float test
        Set<float> u;
        int u_card = u.cardinality();
        if (u_card != 0) {
            cout << "ERROR: Incorrect Cardinality Result [Expected 0 but got: " << u_card << " ]" << endl;
        }
        u.insert(2.3);
        u.insert(1.89);
        u_card = u.cardinality();
        if (u_card != 2) {
            cout << "ERROR: Incorrect Cardinality Result [Expected 2 but got: " << u_card << " ]" << endl;    
        } 

        // bool test
        Set<bool> v;
        int v_card = v.cardinality();
        if (v_card != 0) {
            cout << "ERROR: Incorrect Cardinality Result [Expected 0 but got: " << v_card << " ]" << endl;
        }
        v.insert(true);
        v.insert(false);
        v_card = v.cardinality();
        if (v_card != 2) {
            cout << "ERROR: Incorrect Cardinality Result [Expected 2 but got: " << v_card << " ]" << endl;
        }

        // string test
        Set<string> w;
        int w_card = w.cardinality();
        if (w_card != 0) {
            cout << "ERROR: Incorrect Cardinality Result [Expected 0 but got: " << w_card << " ]" << endl;
        }
        w.insert("string1");
        w.insert("string2");
        w_card = w.cardinality();
        if (w_card != 2) {
            cout << "ERROR: Incorrect Cardinality Result [Expected 2 but got: " << w_card << " ]" << endl;
        }
    }
    catch (exception &e) {
        cerr << "Error in determining set cardinality : " << e.what() << endl;
    }
}

void test_empty() {
    try {
        // int test
        Set<int> s;
        if (!s.empty()) {
            cout << "ERROR: Set identified as non-empty" << endl;
        }
        s.insert(1);
        if (s.empty()) {
            cout << "ERROR: Set identified as empty" << endl;
        }

        // char test
        Set<char> t;
        if (!t.empty()) {
            cout << "ERROR: Set identified as non-empty" << endl;
        }
        t.insert('a');
        if (t.empty()) {
            cout << "ERROR: Set identified as empty" << endl;
        }

        // float test
        Set<float> u;
        if (!u.empty()) {
            cout << "ERROR: Set identified as non-empty" << endl;
        }
        u.insert(67.3);
        if (u.empty()) {
            cout << "ERROR: Set identified as empty" << endl;
        }

        // bool test
        Set<bool> v;
        if (!v.empty()) {
            cout << "ERROR: Set identified as non-empty" << endl;
        }
        v.insert(true);
        if (v.empty()) {
            cout << "ERROR: Set identified as empty" << endl;
        }

        // string test
        Set<string> w;
        if (!w.empty()) {
            cout << "ERROR: Set identified as non-empty" << endl;
        }
        w.insert("string1");
        if (w.empty()) {
            cout << "ERROR: Set identified as empty" << endl;
        }
    }
    catch (exception &e) {
        cerr << "Error in determining if set is the empty set : " << e.what() << endl;
    }
}

void test_contains() {
    try {
        // int test
        Set<int> s;
        if (s.contains(1)) {
            cout << "ERROR: Incorrectly identified 1 as in the set " << s.to_string() << endl;
        }
        s.insert(1);
        if (s.contains(2)) {
            cout << "ERROR: Incorrectly identified 2 as in the set " << s.to_string() << endl;
        }
        if (!s.contains(1)) {
            cout << "ERROR: Incorrectly identified 1 as NOT in the set " << s.to_string() << endl;
        }

        // char test
        Set<char> t;
        if (t.contains('a')) {
            cout << "ERROR: Incorrectly identified a as in the set " << t.to_string() << endl;
        }
        t.insert('a');
        if (t.contains('b')) {
            cout << "ERROR: Incorrectly identified b as in the set " << t.to_string() << endl;
        }
        if (!t.contains('a')) {
            cout << "ERROR: Incorrectly identified a as NOT in the set " << t.to_string() << endl;
        }

        // float test
        Set<float> u;
        if (u.contains(5.90)) {
            cout << "ERROR: Incorrectly identified 5.90 as in the set " << u.to_string() << endl;
        }
        u.insert(4.67);
        if (u.contains(5.90)) {
            cout << "ERROR: Incorrectly identified 5.90 as in the set " << u.to_string() << endl;
        }
        if (!u.contains(4.67)) {
            cout << "ERROR: Incorrectly identified 4.67 as NOT in the set " << u.to_string() << endl;
        }

        // bool test
        Set<bool> v;
        if (v.contains(true)) {
            cout << "ERROR: Incorrectly identified 1 as in the set " << v.to_string() << endl;
        }
        v.insert(false);
        if (v.contains(true)) {
            cout << "ERROR: Incorrectly identified 1 as in the set " << v.to_string() << endl;
        }
        if (!v.contains(false)) {
            cout << "ERROR: Incorrectly identified 0 as NOT in the set " << v.to_string() << endl;
        }

        // string test
        Set<string> w;
        if (w.contains("string123")) {
            cout << "ERROR: Incorrectly identified string123 as in the set " << w.to_string() << endl;
        }
        w.insert("string321");
        if (w.contains("string123")) {
            cout << "ERROR: Incorrectly identified string123 as in the set " << w.to_string() << endl;
        }
        if (!w.contains("string321")) {
            cout << "ERROR: Incorrectly identified string312 as NOT in the set " << w.to_string() << endl;
        }

    }
    catch (exception &e) {
        cerr << "Error in determining if value contained in set : " << e.what() << endl;
    }
}

void test_equality() {
    try {
        // int test
        Set<int> s1;
        Set<int> s2;
        if (!(s1==s2)) {
            cout << "ERROR: Empty sets should be considered equal" << endl;
        }
        s1.insert(1);
        s2.insert(2);
        if (s1==s2) {
            cout << "ERROR: Incorrectly identified set " << s1.to_string() << " as eqivalent to set " << s2.to_string() << endl;
        }
        s1.insert(2);
        s2.insert(1);
        if (!(s1==s2)) {
            cout << "ERROR: Sets " << s1.to_string() << " and " << s2.to_string() << " should be considered equal" << endl;
        }

        // char test
        Set<char> t1;
        Set<char> t2;
        if (!(t1==t2)) {
            cout << "ERROR: Empty sets should be considered equal" << endl;
        }
        t1.insert('a');
        t2.insert('b');
        if (t1==t2) {
            cout << "ERROR: Incorrectly identified set " << t1.to_string() << " as eqivalent to set " << t2.to_string() << endl;
        }
        t1.insert('b');
        t2.insert('a');
        if (!(t1==t2)) {
            cout << "ERROR: Sets " << t1.to_string() << " and " << t2.to_string() << " should be considered equal" << endl;
        }

        // float test
        Set<float> u1;
        Set<float> u2;
        if (!(u1==u2)) {
            cout << "ERROR: Empty sets should be considered equal" << endl;
        }
        u1.insert(2.34);
        u2.insert(7.89);
        if (u1==u2) {
            cout << "ERROR: Incorrectly identified set " << u1.to_string() << " as eqivalent to set " << u2.to_string() << endl;
        }
        u1.insert(7.89);
        u2.insert(2.34);
        if (!(u1==u2)) {
            cout << "ERROR: Sets " << u1.to_string() << " and " << u2.to_string() << " should be considered equal" << endl;
        }

        // bool test
        Set<bool> v1;
        Set<bool> v2;
        if (!(v1==v2)) {
            cout << "ERROR: Empty sets should be considered equal" << endl;
        }
        v1.insert(true);
        v2.insert(false);
        if (v1==v2) {
            cout << "ERROR: Incorrectly identified set " << v1.to_string() << " as eqivalent to set " << v2.to_string() << endl;
        }
        v1.insert(false);
        v2.insert(true);
        if (!(v1==v2)) {
            cout << "ERROR: Sets " << v1.to_string() << " and " << v2.to_string() << " should be considered equal" << endl;
        }

        // string test
        Set<string> w1;
        Set<string> w2;
        if (!(w1==w2)) {
            cout << "ERROR: Empty sets should be considered equal" << endl;
        }
        w1.insert("string222");
        w2.insert("string111");
        if (w1==w2) {
            cout << "ERROR: Incorrectly identified set " << w1.to_string() << " as eqivalent to set " << w2.to_string() << endl;
        }
        w1.insert("string111");
        w2.insert("string222");
        if (!(w1==w2)) {
            cout << "ERROR: Sets " << w1.to_string() << " and " << w2.to_string() << " should be considered equal" << endl;
        }
    }

    catch (exception &e) {
        cerr << "Error in determining set equality : " << e.what() << endl;
    }
}

void test_subset() {
    try {
        // int test
        Set<int> s1;
        Set<int> s2;
        if(!(s1<=s2)) {
            cout << "ERROR: Set " << s1.to_string() << " should be considered a subset of the set " << s2.to_string() << endl;
        }
        s2.insert(1);
        s2.insert(2);
        if(!(s1<=s2)) {
            cout << "ERROR: Set " << s1.to_string() << " should be considered a subset of the set " << s2.to_string() << endl;
        }
        s1.insert(1);
        s1.insert(2);
        if(!(s1<=s2)) {
            cout << "ERROR: Set " << s1.to_string() << " should be considered a subset of the set " << s2.to_string() << endl;
        }
        s1.insert(3);
        if(s1<=s2) {
            cout << "ERROR: Set " << s1.to_string() << " should NOT be considered a subset of the set " << s2.to_string() << endl;
        }

        // char test
        Set<char> t1;
        Set<char> t2;
        if(!(t1<=t2)) {
            cout << "ERROR: Set " << t1.to_string() << " should be considered a subset of the set " << t2.to_string() << endl;
        }
        t2.insert('a');
        t2.insert('b');
        if(!(t1<=t2)) {
            cout << "ERROR: Set " << t1.to_string() << " should be considered a subset of the set " << t2.to_string() << endl;
        }
        t1.insert('a');
        t1.insert('b');
        if(!(t1<=t2)) {
            cout << "ERROR: Set " << t1.to_string() << " should be considered a subset of the set " << t2.to_string() << endl;
        }
        t1.insert('c');
        if(t1<=t2) {
            cout << "ERROR: Set " << t1.to_string() << " should NOT be considered a subset of the set " << t2.to_string() << endl;
        }        

        // float test
        Set<float> u1;
        Set<float> u2;
        if(!(u1<=u2)) {
            cout << "ERROR: Set " << u1.to_string() << " should be considered a subset of the set " << u2.to_string() << endl;
        }
        u2.insert(1.23);
        u2.insert(5.03);
        if(!(u1<=u2)) {
            cout << "ERROR: Set " << u1.to_string() << " should be considered a subset of the set " << u2.to_string() << endl;
        }
        u1.insert(1.23);
        u1.insert(5.03);
        if(!(u1<=u2)) {
            cout << "ERROR: Set " << u1.to_string() << " should be considered a subset of the set " << u2.to_string() << endl;
        }
        u1.insert(4.55);
        if(u1<=u2) {
            cout << "ERROR: Set " << u1.to_string() << " should NOT be considered a subset of the set " << u2.to_string() << endl;
        }       

        // bool test
        Set<bool> v1;
        Set<bool> v2;
        if(!(v1<=v2)) {
            cout << "ERROR: Set " << v1.to_string() << " should be considered a subset of the set " << v2.to_string() << endl;
        }
        v2.insert(true);
        v2.insert(true);
        if(!(v1<=v2)) {
            cout << "ERROR: Set " << v1.to_string() << " should be considered a subset of the set " << v2.to_string() << endl;
        }
        v1.insert(true);
        v1.insert(true);
        if(!(v1<=v2)) {
            cout << "ERROR: Set " << v1.to_string() << " should be considered a subset of the set " << v2.to_string() << endl;
        }
        v1.insert(false);
        if(v1<=v2) {
            cout << "ERROR: Set " << v1.to_string() << " should NOT be considered a subset of the set " << v2.to_string() << endl;
        }

        // string test
        Set<string> w1;
        Set<string> w2;
        if(!(w1<=w2)) {
            cout << "ERROR: Set " << w1.to_string() << " should be considered a subset of the set " << w2.to_string() << endl;
        }
        w2.insert("string111");
        w2.insert("string222");
        if(!(w1<=w2)) {
            cout << "ERROR: Set " << w1.to_string() << " should be considered a subset of the set " << w2.to_string() << endl;
        }
        w1.insert("string111");
        w1.insert("string222");
        if(!(w1<=w2)) {
            cout << "ERROR: Set " << w1.to_string() << " should be considered a subset of the set " << w2.to_string() << endl;
        }
        w1.insert("random string");
        if(w1<=w2) {
            cout << "ERROR: Set " << w1.to_string() << " should NOT be considered a subset of the set " << w2.to_string() << endl;
        }
    }
    catch (exception& e) {
        cerr << "Error in determining subset : " << e.what() << endl;
    }
}

void test_union() {
    try {
        // int test
        Set<int> s1;
        Set<int> s2;
        string set_str = (s1+s2).to_string();
        if (set_str != "") {
            cout << "ERROR: Union of two empty sets should be the empty set. Instead got : " << set_str << endl; 
        }
        s1.insert(1);
        s1.insert(2);
        s2.insert(2);
        s2.insert(1);
        set_str = (s1+s2).to_string();
        if (set_str != "2 1") {
            cout << "ERROR: Union of " << s1.to_string() << " and " << s2.to_string() << " was expected to be 2 1 but instead got : " << set_str << endl;
        }
        s2.insert(18);
        set_str = (s1+s2).to_string();
        if (set_str != "2 1 18") {
            cout << "Union of " << s1.to_string() << " and " << s2.to_string() << " was expected to be 2 1 18 but instead got : " << set_str << endl;
        }

        // char test
        Set<char> t1;
        Set<char> t2;
        set_str = (t1+t2).to_string();
        if (set_str != "") {
            cout << "ERROR: Union of two empty sets should be the empty set. Instead got : " << set_str << endl; 
        }
        t1.insert('a');
        t1.insert('b');
        t2.insert('b');
        t2.insert('a');
        set_str = (t1+t2).to_string();
        if (set_str != "b a") {
            cout << "ERROR: Union of " << t1.to_string() << " and " << t2.to_string() << " was expected to be b a but instead got : " << set_str << endl;
        }
        t2.insert('z');
        set_str = (t1+t2).to_string();
        if (set_str != "b a z") {
            cout << "Union of " << t1.to_string() << " and " << t2.to_string() << " was expected to be b a z but instead got : " << set_str << endl;
        }

        // float test
        Set<float> u1;
        Set<float> u2;
        set_str = (u1+u2).to_string();
        if (set_str != "") {
            cout << "ERROR: Union of two empty sets should be the empty set. Instead got : " << set_str << endl; 
        }
        u1.insert(1.23);
        u1.insert(4.56);
        u2.insert(4.56);
        u2.insert(1.23);
        set_str = (u1+u2).to_string();
        if (set_str != "4.56 1.23") {
            cout << "ERROR: Union of " << u1.to_string() << " and " << u2.to_string() << " was expected to be 4.56 1.23 but instead got : " << set_str << endl;
        }
        u2.insert(1.01);
        set_str = (u1+u2).to_string();
        if (set_str != "4.56 1.23 1.01") {
            cout << "Union of " << u1.to_string() << " and " << u2.to_string() << " was expected to be 4.56 1.23 1.01 but instead got : " << set_str << endl;
        }

        // bool test
        Set<bool> v1;
        Set<bool> v2;
        set_str = (v1+v2).to_string();
        if (set_str != "") {
            cout << "ERROR: Union of two empty sets should be the empty set. Instead got : " << set_str << endl; 
        }
        v1.insert(true);
        v1.insert(false);
        v2.insert(false);
        v2.insert(true);
        set_str = (v1+v2).to_string();
        if (set_str != "0 1") {
            cout << "ERROR: Union of " << v1.to_string() << " and " << v2.to_string() << " was expected to be 0 1 but instead got : " << set_str << endl;
        }
        v2.insert(true);
        set_str = (v1+v2).to_string();
        if (set_str != "0 1") {
            cout << "Union of " << v1.to_string() << " and " << v2.to_string() << " was expected to be 0 1 but instead got : " << set_str << endl;
        }

        // string test
        Set<string> w1;
        Set<string> w2;
        set_str = (w1+w2).to_string();
        if (set_str != "") {
            cout << "ERROR: Union of two empty sets should be the empty set. Instead got : " << set_str << endl; 
        }
        w1.insert("string1");
        w1.insert("string2");
        w2.insert("string2");
        w2.insert("string1");
        set_str = (w1+w2).to_string();
        if (set_str != "string2 string1") {
            cout << "ERROR: Union of " << w1.to_string() << " and " << w2.to_string() << " was expected to be string2 string1 but instead got : " << set_str << endl;
        }
        w2.insert("randstring");
        set_str = (w1+w2).to_string();
        if (set_str != "string2 string1 randstring") {
            cout << "Union of " << w1.to_string() << " and " << w2.to_string() << " was expected to be string2 string1 randstring but instead got : " << set_str << endl;
        }        

    }
    catch (exception& e) {
        cerr << "Error in generating the union set : " << e.what() << endl;
    }
}

void test_intersection() {
    try {
        // int test
        Set<int> s1;
        Set<int> s2;
        string set_str = (s1&s2).to_string();
        if (set_str != "") {
            cout << "ERROR: Intersection of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        s1.insert(1);
        s1.insert(2);
        s2.insert(100);
        set_str = (s1&s2).to_string();
        if (set_str != "") {
            cout << "ERROR: Intersection of " << s1.to_string() << " and " << s2.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
        }
        s2.insert(2);
        s2.insert(1);
        set_str = (s1&s2).to_string();
        if (set_str != "1 2") {
            cout << "ERROR: Intersection of " << s1.to_string() << " and " << s2.to_string() << " was expected to be 1 2 but instead got : " << set_str << endl; 
        }

        // char test
        Set<char> t1;
        Set<char> t2;
        set_str = (t1&t2).to_string();
        if (set_str != "") {
            cout << "ERROR: Intersection of the empty sets should be the empty set. Instead got : " << set_str << endl; 
        }
        t1.insert('a');
        t1.insert('b');
        t2.insert('z');
        set_str = (t1&t2).to_string();
        if (set_str != "") {
            cout << "ERROR: Intersection of " << t1.to_string() << " and " << t2.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
        }
        t2.insert('b');
        t2.insert('a');
        set_str = (t1&t2).to_string();
        if (set_str != "a b") {
            cout << "ERROR: Intersection of " << t1.to_string() << " and " << t2.to_string() << " was expected to be a b but instead got : " << set_str << endl;
        }

        // float test
        Set<float> u1;
        Set<float> u2;
        set_str = (u1&u2).to_string();
        if (set_str != "") {
            cout << "ERROR: Intersection of the empty sets should be the empty set. Instead got : " << set_str << endl; 
        }
        u1.insert(1.2);
        u1.insert(3.4);
        u2.insert(9.9);
        set_str = (u1&u2).to_string();
        if (set_str != "") {
            cout << "ERROR: Intersection of " << u1.to_string() << " and " << u2.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
        }
        u2.insert(3.4);
        u2.insert(1.2);
        set_str = (u1&u2).to_string();
        if (set_str != "1.2 3.4") {
            cout << "ERROR: Intersection of " << u1.to_string() << " and " << u2.to_string() << " was expected to be 1.2 3.4 but instead got : " << set_str << endl;
        }

        // bool test
        Set<bool> v1;
        Set<bool> v2;
        set_str = (v1&v2).to_string();
        if (set_str != "") {
            cout << "ERROR: Intersection of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        v1.insert(true);
        v1.insert(false);
        v2.insert(false);
        set_str = (v1&v2).to_string();
        if (set_str != "0") {
            cout << "ERROR: Intersection of " << v1.to_string() << " and " << v2.to_string() << " was expected to be 0 but instead got : " << set_str << endl;
        }

        // string test
        Set<string> w1;
        Set<string> w2;
        set_str = (w1&w2).to_string();
        if (set_str != "") {
            cout << "ERROR: Intersection of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        w1.insert("string111");
        w1.insert("string222");
        w2.insert("STRING999");
        set_str = (w1&w2).to_string();
        if (set_str != "") {
            cout << "ERROR: Intersection of " << w1.to_string() << " and " << w2.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
        }
        w2.insert("string222");
        w2.insert("string111");
        set_str = (w1&w2).to_string();
        if (set_str != "string111 string222") {
            cout << "ERROR: Intersection of " << w1.to_string() << " and " << w2.to_string() << " was expected to be string111 string222 but instead got : " << set_str << endl;
        }
    }

    catch (exception& e) {
        cerr << "Error in generating the intersection set : " << e.what() << endl;
    }
}

void test_diff() {
    try {
        // int test
        Set<int> s1;
        Set<int> s2;
        string set_str = (s1-s2).to_string();
        if (set_str != "") {
            cout << "ERROR: Difference of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        s1.insert(1);
        s1.insert(2);
        s2.insert(100);
        set_str = (s1-s2).to_string();
        if (set_str != "1 2") {
            cout << "ERROR: Set " << s1.to_string() << " \\ Set " << s2.to_string() << " was expected to be 1 2 but instead got : " << set_str << endl;
        }
        s2.insert(2);
        s2.insert(1);
        set_str = (s1-s2).to_string();
        if (set_str != "") {
            cout << "ERROR: Set " << s1.to_string() << " \\ Set " << s2.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
        }

        // char test
        Set<char> t1;
        Set<char> t2;
        set_str = (t1-t2).to_string();
        if (set_str != "") {
            cout << "ERROR: Difference of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        t1.insert('a');
        t1.insert('b');
        t2.insert('z');
        set_str = (t1-t2).to_string();
        if (set_str != "a b") {
            cout << "ERROR: Set " << t1.to_string() << " \\ Set " << t2.to_string() << " was expected to be a b but instead got : " << set_str << endl;
        }
        t2.insert('b');
        t2.insert('a');
        set_str = (t1-t2).to_string();
        if (set_str != "") {
            cout << "ERROR: Set " << t1.to_string() << " \\ Set " << t2.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
        }

        // float test
        Set<float> u1;
        Set<float> u2;
        set_str = (u1-u2).to_string();
        if (set_str != "") {
            cout << "ERROR: Difference of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        u1.insert(1.2);
        u1.insert(3.4);
        u2.insert(9.9);
        set_str = (u1-u2).to_string();
        if (set_str != "1.2 3.4") {
            cout << "ERROR: Set " << u1.to_string() << " \\ Set " << u2.to_string() << " was expected to be 1.2 3.4 but instead got : " << set_str << endl;
        }
        u2.insert(3.4);
        u2.insert(1.2);
        set_str = (u1-u2).to_string();
        if (set_str != "") {
            cout << "ERROR: Set " << u1.to_string() << " \\ Set " << u2.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
        }

        // bool test
        Set<bool> v1;
        Set<bool> v2;
        set_str = (v1-v2).to_string();
        if (set_str != "") {
            cout << "ERROR: Difference of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        v1.insert(true);
        v1.insert(false);
        v2.insert(false);
        set_str = (v1-v2).to_string();
        if (set_str != "1") {
            cout << "ERROR: Set " << v1.to_string() << "  \\ Set " << v2.to_string() << " was expected to be 1 but instead got : " << set_str << endl;
        }

        // string test
        Set<string> w1;
        Set<string> w2;
        set_str = (w1-w2).to_string();
        if (set_str != "") {
            cout << "ERROR: Difference of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        w1.insert("string111");
        w1.insert("string222");
        w2.insert("STRING999");
        set_str = (w1-w2).to_string();
        if (set_str != "string111 string222") {
            cout << "Set " << w1.to_string() << " \\ Set " << w2.to_string() << " was expected to be string11 string222 but instead got : " << set_str << endl;
        }
        w2.insert("string222");
        w2.insert("string111");
        set_str = (w1-w2).to_string();
        if (set_str != "") {
            cout << "Set " << w1.to_string() << " \\ Set " << w2.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
        }
    }
    catch (exception& e) {
        cerr << "Error in generating the difference set : " << e.what() << endl;
    }
}

void time_test() {
    Set<int> s1;
    int limit = 100000, s1_increments = 2, s2_increments = 3;
    for (int i = 0; i < limit; i+=s1_increments)
        s1.insert(i);

    Set<int> s2;
    for (int i = 0; i < limit; i+=s2_increments)
        s2.insert(i);
    int total = 0;

    // int val = rand()%100000;
    // auto begin = std::chrono::high_resolution_clock::now();
    // s1.insert(val);
    // auto end = std::chrono::high_resolution_clock::now();
    // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cout << "insert time test took " << elapsed.count() << " nanoseconds" << endl;
    // total+=elapsed.count();

    // begin = std::chrono::high_resolution_clock::now();
    // s1.remove(val);
    // end = std::chrono::high_resolution_clock::now();
    // elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cout << "remove time test took " << elapsed.count() << " nanoseconds" << endl;
    // total+=elapsed.count();

    // begin = std::chrono::high_resolution_clock::now();
    // s1.cardinality();
    // end = std::chrono::high_resolution_clock::now();
    // elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cout << "cardinality time test took " << elapsed.count() << " nanoseconds" << endl;
    // total+=elapsed.count();


    // begin = std::chrono::high_resolution_clock::now();
    // s1.empty();
    // end = std::chrono::high_resolution_clock::now();
    // elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cout << "empty time test took " << elapsed.count() << " nanoseconds" << endl;
    // total+=elapsed.count();

    // val = rand()%100000;
    // begin = std::chrono::high_resolution_clock::now();
    // bool r = s1.contains(val);
    // end = std::chrono::high_resolution_clock::now();
    // elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cout << "contains time test took " << elapsed.count() << " nanoseconds" << endl;
    // total+=elapsed.count();


    // begin = std::chrono::high_resolution_clock::now();
    // r = (s1==s2);
    // end = std::chrono::high_resolution_clock::now();
    // elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cout << "equality time test took " << elapsed.count() << " nanoseconds" << endl;
    // total+=elapsed.count();


    // begin = std::chrono::high_resolution_clock::now();
    // r = (s1<=s2);
    // end = std::chrono::high_resolution_clock::now();
    // elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cout << "subset time test took " << elapsed.count() << " nanoseconds" << endl;
    // total+=elapsed.count();


    // begin = std::chrono::high_resolution_clock::now();
    // Set<int> U = (s1+s2);
    // end = std::chrono::high_resolution_clock::now();
    // elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cout << "union time test took " << elapsed.count() << " nanoseconds" << endl;
    // total+=elapsed.count();


    // begin = std::chrono::high_resolution_clock::now();
    // U = (s1&s2);
    // end = std::chrono::high_resolution_clock::now();
    // elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cout << "intersection time test took " << elapsed.count() << " nanoseconds" << endl;
    // total+=elapsed.count();


    // begin = std::chrono::high_resolution_clock::now();
    // U = (s1-s2);
    // end = std::chrono::high_resolution_clock::now();
    // elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cout << "difference time test took " << elapsed.count() << " nanoseconds" << endl;
    // total+=elapsed.count();
    // cout << "Total time: " << total << endl;
}

int main() {
    test_insert();
    test_remove();
    test_cardinality();
    test_empty();
    test_contains();
    test_equality();
    test_subset();
    test_union();
    test_intersection();
    test_diff();

    // time_test();
    
    cout << "Testing completed!" << endl;
    
    return 0;
}



