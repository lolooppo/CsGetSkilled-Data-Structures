#include <bits/stdc++.h>
using namespace std;

class maxHeap{
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


        if(!child_pos or array[child_pos] < array[parent_pos]){
            return;
        }

        swap(array[child_pos] , array[parent_pos]);
        heapify_up(parent_pos);
    }

    void heapify_down(int parent_pos){
        int left_child_pos = left(parent_pos) , right_child_pos = right(parent_pos);
        int target_pos = left_child_pos;

        if(left_child_pos == -1){
            return;
        }

        if(right_child_pos != -1 and array[right_child_pos] > array[left_child_pos]){
            target_pos = right_child_pos;
        }

        if(array[parent_pos] < array[target_pos]){
            swap(array[parent_pos] , array[target_pos]);
            heapify_down(target_pos);
        }
    }

    void heapify(){
        for(int i = current_idx / 2;i>=0;i--){
            heapify_down(i);
        }
    }

public:
    maxHeap(){
        array = new int [capacity];
    }

    maxHeap(const vector<int>& v){
        int n = v.size();
        assert(n <= capacity);

        array = new int [capacity];

        for(int i = 0;i<n;i++){
            array[i] = v[i];
        }

        current_idx = n-1;

        //fix the hole array
        heapify();
    }

    void push(int data){
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

        for(int i = 0;i <= current_idx;i++){
            cout<<array[i]<<" ";
        }

        cout<<"\n";
    }

    bool empty(){
        return current_idx == -1;
    }

    bool full(){
        return current_idx == (capacity - 1);
    }

    ~maxHeap(){
        delete [] array;
        array = nullptr;
    }
};
