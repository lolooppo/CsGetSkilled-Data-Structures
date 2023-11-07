#include <bits/stdc++.h>
using namespace std;

class minHeap{
private:
    int current_idx{-1} , capacity{1000} , *array{nullptr};

    int parent(int child_pos){
        int parent_pos = (child_pos - 1) / 2 ;
        return child_pos ? parent_pos : -1 ;
    }

    int left(int parent_pos){
        int left_child_pos = (2 * parent_pos) + 1 ;
        return left_child_pos <= current_idx ? left_child_pos : -1 ;
    }

    int right(int parent_pos){
        int right_child_pos = (2 * parent_pos) + 2 ;
        return right_child_pos <= current_idx ? right_child_pos : -1 ;
    }

    void heapify_up(int child_pos){
        int parent_pos = parent(child_pos);

        if(!child_pos or array[parent_pos] <= array[child_pos]){
            return;
        }

        swap(array[parent_pos] , array[child_pos]);
        heapify_up(parent_pos);
    }

    void heapify_down(int parent_pos){
        int left_child_pos = left(parent_pos) , right_child_pos = right(parent_pos);
        int target_pos = left_child_pos;

        //leaf node
        if(left_child_pos == -1){
            return;
        }

        //do swap with right instead left
        if(right_child_pos != -1 and array[right_child_pos] < array[left_child_pos]){
            target_pos = right_child_pos;
        }

        //check if target child less than parent to swap
        if(array[target_pos] < array[parent_pos]){
            swap(array[target_pos] , array[parent_pos]);
            heapify_down(target_pos);
        }
    }

    //Floyd heapfiy algorithm(from bottom to up) --> o(n)
    void heapify(){
        for(int i = current_idx / 2 ;i>=0;i--){
            heapify_down(i);
        }
    }

public:
    minHeap(){
        array = new int [capacity];
    }
    minHeap(const vector<int>& v){
        int n = v.size();
        array = new int [capacity];

        assert(n<=capacity);

        for(int i = 0;i<n;i++){
            array[i] = v[i];
        }

        current_idx = n-1;

        heapify();
    }

    void push(const int& data){
        assert(!full());

        array[++current_idx] = data;
        heapify_up(current_idx);
    }

    void pop(){
        assert(!empty());

        swap(array[0] , array[current_idx--]);
        heapify_down(0);
    }

    int top(){
        assert(!empty());
        return array[0];
    }

    void print(){
        if(empty()){
            cout<<"empty";
        }

        for(int i = 0;i<=current_idx;i++){
            cout<<array[i]<<" ";
        }

        cout<<"\n";
    }

    bool empty(){
        return current_idx == -1;
    }

    bool full(){
        return current_idx == capacity - 1;
    }

    bool is_heap(int *arr , int n){

    }

    ~minHeap(){
        delete [] array;
        array = nullptr;
    }
};

class maxHeap{
private:
    minHeap min_max_heap;

    vector<int> neg_v(const vector<int>& v){
        vector<int>res((int)v.size());

        for(int i = 0;i<(int)v.size();i++){
            res[i] = -1 * v[i];
        }

        return res;
    }

public:
    maxHeap(){}

    maxHeap(const vector<int>& v) : min_max_heap(neg_v(v)){

    }

    void push(int data){
        min_max_heap.push(-1 * data);
    }

    void pop(){
        min_max_heap.pop();
    }

    int top(){
        return -1 * min_max_heap.top();
    }

    bool empty(){
        return min_max_heap.empty();
    }

    bool full(){
        return min_max_heap.full();
    }
};
