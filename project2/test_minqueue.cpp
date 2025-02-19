//
//  test_minqueue_example.cpp
//  Priority Queue Project
//
//  Created by Stacey Truex
//
#include <iostream>
#include <chrono>
#include <cstdlib>
#include "minqueue.h"
#include "usecase.cpp"

using namespace std;

void test_minqueue() {

    int* int_data = new int[10];
    for(int i = 0; i < 10; i++){
        int_data[i] = 10-i;
    }

    try {
        //cout << mqq.to_string()<<endl;
        MinQueue<int> empty;
        string mq_str = empty.to_string();

        if(mq_str != "") {
            cout << "Incorrect result from empty constructor. Expected an empty string but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        mq_str = mq.to_string();

        if(mq_str != "1 2 4 3 6 5 8 10 7 9") {
            cout << "Incorrect result from empty constructor. Expected 1 2 4 3 6 5 8 10 7 9 but got : " << mq_str << endl;
        }

    } catch (exception& e) {
        cerr << "Error creating the priority queue : " << e.what() << endl;
    }

    delete[] int_data;
}


void test_insert() {

    int* int_data = new int[10];
    for(int i = 0; i < 10; i++) {
        int_data[i] = 10-i;
    }

    try {
        MinQueue<int> mqq ;
        MinQueue<int> empty;
        empty.insert(0);
        string mq_str = empty.to_string();

        if(mq_str != "0") {
            cout << "Incorrect insert result. Epected 0 but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        mq.insert(25);
        mq.insert(0);
        mq_str = mq.to_string();

        if(mq_str != "0 2 1 3 6 4 8 10 7 9 25 5") {
            cout << "Incorrect insert result. Expected 0 2 1 3 6 4 8 10 7 9 25 5 but got : " << mq_str << endl;
        }
        MinQueue<char> mq1;
        mq1.insert('a');
        mq1.insert('b');
        mq1.insert('z');
        mq1.insert('c');
        mq1.insert('g');
        mq1.insert('e');
        mq1.insert('f');
        mq1.insert('h');
        string str = mq1.to_string();
       // cout << str <<endl;
        if(str!= "a b e c g z f h"){
            cout << "Error"<<endl;
        }
        MinQueue<float> mq2 ;
        mq2.insert(1.1);
        mq2.insert(2.2);
        mq2.insert(3.3);
        mq2.insert(6.6);
        mq2.insert(9.9);
        mq2.insert(8.8);
        mq2.insert(7.7);
        mq2.insert(5.5);
        mq2.insert(4.4);
        mq2.insert(1);
        mq2.insert(0);
        mq2.insert(10);
        string str2 = mq2.to_string();
        if(str2 != "0 1 3.3 4.4 1.1 8.8 7.7 6.6 5.5 9.9 2.2 10"){
            cout << "Error"<<endl;
        }
    } catch (exception& e) {
        cerr << "Error inserting into the priority queue : " << e.what() << endl;
    }

    delete[] int_data;
}

void test_min() {
    int* int_data = new int[10];
    for(int i = 0; i < 10; i++){
        int_data[i] = 10-i;
    }

    try {

        MinQueue<int> empty;
        int min = empty.min();
        if(min != 0) {
            cout << "Incorrect min result. Expect 0 but got : " << min << endl;
        }

        MinQueue<int> mq(int_data, 10);
        min = mq.min();
        if(min != 1) {
            cout << "Incorrect min result. Expect 0 but got : " << min << endl;
        }
    float* float_data = new float[10];
    for(int i = 0; i < 10; i++){
        float_data[i] = 10-i;
    }
       MinQueue<float> mq1(float_data,10);
       mq1.insert(25.5);
       mq1.insert(0);
       int minn = mq1.min();
       if(minn != 0){
        cout <<"Error"<<endl;
       }
    } catch (exception& e) {
        cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    }

    delete[] int_data;
}

void test_extract_min() {

    int* int_data = new int[10];
    for(int i = 0; i < 10; i++){
        int_data[i] = 10-i;
    }

    try {

        MinQueue<int> empty;
        int min = empty.extract_min();
        string mq_str = empty.to_string();

        if(min != 0 || mq_str != "") {
            cout << "Incorrect extract min result. Expected 0 and an empty queue but got : " << min << " and a queue of : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        min = mq.extract_min();
        mq_str = mq.to_string();

        if(min != 1 || mq_str != "2 3 4 7 6 5 8 10 9") {
            cout << "Incorrect extract min result. Expected 0 and the queue 2 3 4 7 6 5 8 10 9 but got : " << min << " and a queue of : " << mq_str << endl;
        }
    MinQueue<float> mq2 ;
        mq2.insert(1.1);
        mq2.insert(2.2);
        mq2.insert(3.3);
        mq2.insert(6.6);
        mq2.insert(9.9);
        mq2.insert(8.8);
        mq2.insert(7.7);
        mq2.insert(5.5);
        mq2.insert(4.4);
        mq2.insert(1);
        mq2.insert(0);
        mq2.insert(10);
        int value = mq2.extract_min();
       // cout << mq2.to_string()<<endl;
        if(value != 0 || mq2.to_string()!= "1 1.1 3.3 4.4 2.2 8.8 7.7 6.6 5.5 9.9 10"){
            cout << "Error"<<endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    }

    delete[] int_data;
}

void test_decrease_key() {

    int* int_data = new int[10];
    for(int i = 0; i < 10; i++){
        int_data[i] = 10-i;
    }

    try {

        MinQueue<int> empty;
        empty.decrease_key(0, 0);
        string mq_str = empty.to_string();

        if (mq_str != "") {
            cout << "Incorrect decrease key result. Expected empty queue but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        mq.decrease_key(0, -6);
        mq.decrease_key(9, -1);
        mq_str = mq.to_string();

        if (mq_str != "-6 -1 4 3 2 5 8 10 7 6") {
            cout << "Incorrect decrease key result. Expected empty queue but got : " << mq_str << endl;
        }

    } catch (exception &e) {
        cerr << "Error in decreasing key : " << e.what() << endl;
    }

    delete[] int_data;
}

void test_min_heapify() {

    int* empty_data = new int[0];

    int* int_data = new int[10];
    for(int i = 0; i < 10; i++){
        int_data[i] = 10-i;
    }

    try {

        MinQueue<int> empty;
        empty.min_heapify(1);
        string mq_str = empty.to_string();

        if(mq_str != "") {
            cout << "Incorrect heapify result. Expected empty string but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        string o_mq_str = mq.to_string();
        mq.set(1, 11);
        mq.min_heapify(1);

        mq_str = mq.to_string();

        if(mq_str != "1 3 4 7 6 5 8 10 11 9") {
            cout << "Incorrect heapify result in heapifying index 1 in the minqueue " << o_mq_str << " after setting to 11. Expected 1 3 4 7 6 5 8 10 11 9 but got : " << mq_str << endl;
        }
        float * float_data = new float[10];
        for(int i = 0; i < 10; i++){
            float_data[i] = 10-i;
        }
        MinQueue<float> mqq(float_data,10);
        mqq.set(1,11.1);
        mqq.min_heapify(1);
     mq_str = mqq.to_string();
        if(mq_str != "1 3 4 7 6 5 8 10 11.1 9") {
            cout << "Incorrect heapify result in heapifying index 1 in the minqueue " << o_mq_str << " after setting to 11. Expected 1 3 4 7 6 5 8 10 11 9 but got : " << mq_str << endl;
        }
    } catch (exception &e) {
        cerr << "Error in min_heapify : " << e.what() << endl;
    }

    delete[] empty_data;
    delete[] int_data;
}

void test_build_heap(){

    int* int_data = new int[10];
    for(int i = 0; i < 10; i++){
        int_data[i] = 10-i;
    }

    try {

        MinQueue<int> mq;
        mq.allocate(10);
        for(int i = 0; i < 10; i++) {
            mq.set(i, int_data[i]);
        }
        string o_mq_str = mq.to_string();

        mq.build_heap();
        string mq_str = mq.to_string();

        if(mq_str != "1 2 4 3 6 5 8 10 7 9") {
            cout << "Incorrect build_heap result from " << o_mq_str << ". Expected 1 2 4 3 6 5 8 10 7 9 but got : " << mq_str << endl;
        }
    } catch (exception &e) {
        cerr << "Error in building min heap : " << e.what() << endl;
    }

    delete[] int_data;
}

void test_heapsort() {

    int* empty_data = new int[0];

    int* int_data = new int[10];
    for(int i = 0; i < 10; i++){
        int_data[i] = 10-i;
    }

    try {

        MinQueue<int> empty;
        empty.sort(empty_data);

        MinQueue<int> heap(int_data, 10);
        heap.sort(int_data);

        string sorted_str = to_string(int_data[0]);

        for(int i = 1; i < 10; i++) {
            sorted_str += (" " + to_string(int_data[i]));
        }

        if(sorted_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect heapsort result. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << sorted_str << endl;
        }
    int* int_data1 = new int[20];
    for(int i = 0; i < 10; i++){
        int_data1[i] = 10-i;
    }
    for(int i = 11; i <20 ; i++){
        int_data1[i-1] = i;
    }
    int_data1[19] = 20 ;
    MinQueue<int> heap1(int_data1, 10);
    heap1.sort(int_data1);
    sorted_str = to_string(int_data1[0]);
     for(int i = 1; i < 20; i++) {
            sorted_str += (" " + to_string(int_data1[i]));
        }
       // cout << sorted_str<<endl;
    if(sorted_str != "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20") {
            cout << "Error"<<endl;
        }
    } catch (exception& e) {
        cerr << "Error in sorting : " << e.what() << endl;
    }

    delete[] empty_data;
    delete[] int_data;
}

void test_sliding_window() {

    int* empty = new int[0];
    int nums[8] = {1,3,-1,-3,5,3,6,7};

    try {

        string window_result = sliding_window(empty, 0, 0);

        if(window_result != "") {
            cout << "Incorrect sliding window result. Expected and empty string but got : " << window_result << endl;
        }
        window_result = sliding_window(nums, 8, 3);
        if(window_result != "-1 -3 -3 -3 3 3") {
            cout << "Incorrect sliding window result. Expected -1 -3 -3 -3 3 3 but got : " << window_result << endl;
        }

        window_result = sliding_window(nums, 1, 1);

        if(window_result != "1") {
            cout << "Incorrect sliding window result. Expected 1 but got : " << window_result << endl;
        }

    } catch(exception &e) {
        cerr << "Error in generating sliding window result : " << e.what() << endl;
    }
    delete[] empty;
}

void time_test() {
    
    MinQueue<int> mq;

    for (int i=0; i<=100000; i++)
        mq.insert(rand()%100000);

    int size = 100000;  // TO-DO: set size of large minqueue
    int total = 0;

    int val = rand()%100000;
    auto begin = std::chrono::high_resolution_clock::now();
    mq.insert(val);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "insert time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    int _ = mq.min();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "min time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    _ = mq.extract_min();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "extract min time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    int last_index = size - 1; // indexing starts at 0
    int new_val = mq.min() - 1; // ensure we're decreasing the key
    begin = std::chrono::high_resolution_clock::now();
    mq.decrease_key(last_index, new_val);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "decrease key time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();
    cout << "Total time: " << total << endl;
}

int main() {

    test_minqueue();
    test_insert();
    test_min();
    test_extract_min();
    test_decrease_key();
    test_min_heapify();
    test_build_heap();
    test_heapsort();

    test_sliding_window();

    time_test();

    cout << "Testing completed" << endl;

    return 0;
}
