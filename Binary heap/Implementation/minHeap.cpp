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

    //check if heap
    bool _is_heap(int _parent_pos = 0){
        bool is = true;

        //go back if leaf
        if(_parent_pos == -1)
            return is;

        int left_child = left(_parent_pos) , right_child = right(_parent_pos);

        if(left_child != -1 and array[left_child] < array[_parent_pos]){
            is = false;
        }
        if(right_child != -1 and array[right_child] < array[_parent_pos]){
            is = false;
        }

        //to stop immediately if not a heap
        if(!is)
            return false;

        return _is_heap(left_child) and _is_heap(right_child);
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

    bool is_heap(int *p , int n){
        int *old_array = array , old_idx = current_idx;
        array = p , current_idx = n-1;

        assert(current_idx > -1);

        bool is = _is_heap();

        array = old_array , current_idx = old_idx;

        return is;
    }

    //heap sort
    void heap_sort(int* p , int n){
        int last_idx = current_idx , *old_array = array , old_idx = current_idx;
        array = p , current_idx = n-1;

        //build the heap first
        heapify();
        
        //act as deleting the top and fix
        while(current_idx != 0){
            swap(array[0] , array[current_idx--]);
            heapify_down(0);
        }

        //reverse
        for(int i = 0;i < n/2;i++){
            swap(array[i] , array[n-i-1]);
        }

        array = old_array , current_idx = old_idx;
    }

    void print_less_than(int val , int _parent_pos = 0){
        //check if we out of bound or the current value is not <
        if(_parent_pos > current_idx or array[_parent_pos] >= val){
            return;
        }

        //otherwise
        cout<<array[_parent_pos]<<" ";

        int left_child = left(_parent_pos) , right_child = right(_parent_pos);

        print_less_than(val , left_child);
        print_less_than(val , right_child);
    }

    ~minHeap(){
        delete [] array;
        array = nullptr;
    }
};