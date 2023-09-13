class Vector{
private:

    int *arr{nullptr},idx{-1},Size{0},capacity{100};
    void expand_capacity(){
        capacity*=2;

        //create new array with the doubled capacity
        int *new_arr = new int[capacity];

        //moving old items into the new one
        for(int i = 0;i<Size;i++)
            new_arr[i] = arr[i];

        //make our (arr) variable points to the sized array
        swap(arr,new_arr);

        //deleting the new crated array
        delete [] new_arr;
        new_arr = nullptr;
        return;
    }
    
    //left rotate
    void left_rotate(){
        int first = arr[0];
        for(int i = 0;i<idx;i++){
            arr[i] = arr[i+1];
        }
        arr[idx] = first;
    }
    
    //right rotate
    void right_rotate(){
        int last = arr[idx];
        for(int i = idx;i>0;i--){
            arr[i] = arr[i-1];
        }
        arr[0] = last;
    }
    
public:

    //constructor
    Vector(int sz = 0,int val = 0){
        Size = sz;
        arr = new int[capacity];
        for(int i = 0;i<Size;i++)
            arr[i] = 0;
        idx = Size-1;
    }

    //add to the end
    void push_back(int val){
        //check if we gonna out of capacity
        if(Size==capacity){
            expand_capacity();
        }
        arr[++idx] = val;
        Size++;
    }

    //add to specific index
    void insert(int index,int val){
        assert(index>=0 and index<=idx);

        if(Size==capacity){
            expand_capacity();
        }
        Size++,idx++;

        //right shift all elements by one till the given index
        for(int i = idx;i>index;i--){
            arr[i] = arr[i-1];
        }

        arr[index] = val;
        return;
    }

    //deleting the last element
    void pop_back(){
        assert(Size);
        idx--,Size--;
    }

    //deleting at specific index;
    void erase(int index){
        assert(index>=0 and index<=idx);
        //left shift starting from given index
        for(int i = index;i<Size;i++){
            arr[i] = arr[i+1];
        }
        idx--,Size--;
    }

    //get the first element
    int front(){
        assert(Size);
        return arr[0];
    }

    //get the last element
    int back(){
        assert(Size);
        return arr[idx];
    }

    //search for index
    int find(int &val){
        for(int i = 0;i<=idx;i++){
            if(arr[i]==val)
                return i;
        }
        return -1;
    }

    //get element at specific position
    int at(int &pos){
        assert(pos>0 and pos<Size);
        return arr[pos-1];
    }

    //optimized search
    int find_transposition(int pos){
        pos--;
        assert(Size);
        assert(pos>=0 and pos<=idx);
        //check if position not the first element
        if(pos){
            //swap the target with its prior ->(position = 4) 3,4,5,6 became 3,5,4,6
            swap(arr[pos],arr[pos-1]);
            //as we swapped it with its prior
            pos--;
        }
        return arr[pos];
    }

    //get actual size
    int size(){
        return Size;
    }

    //check if empty
    bool empty(){
        return !Size;
    }

    //print elements
    void print(){
        for(int i = 0;i<=idx;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    //left rotate
    void left_rotate(int t){
        if(!Size)
            return;

        t%=Size;
        while(t--){
            left_rotate();
        }
        return;
    }

    //right rotate
    void right_rotate(int t){
        if(!Size)
            return;

        t%=Size;
        while(t--){
            left_rotate();
        }
        return;
    }

    //destructor
    ~Vector(){
        delete [] arr;
        arr = nullptr;
    }
};