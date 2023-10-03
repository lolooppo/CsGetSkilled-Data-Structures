template<class T>
class Queue{
private:
    int front,rear,size,added;
    T *arr;
    int next(int idx){
        if(idx == size)
            idx = 0;
        return idx;
    }
public:
    Queue(int size):size(size){
        front = rear = added = 0;
        arr = new T [size];
    }

    bool full(){
        return added == size;
    }

    bool empty(){
        return !added;
    }
    
    T Front(){
        return arr[front];
    }
    
    void push(T val){
        if(full())
            return;

        arr[rear++] = val,added++;
        rear = next(rear);
    }

    void pop(){
        if(empty())
            return;
        front++ , added--;
        front = next(front);
    }

    void print(){
        cout<<"size :: "<<added<<"\n";
        if(empty()){
            cout<<"Empty\n";
            return;
        }
        if(full()){
            cout<<"Full\n";
        }
        for(int curr = front , steps = 0;steps<added;steps++){
            cout<<arr[curr]<<" ";
            curr++;
            curr = next(curr);
        }
        cout<<"\n";
    }

    ~Queue(){
        delete [] arr;
    }

};