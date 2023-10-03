#include<bits/stdc++.h>
using namespace std;

/***********************************************************/
/*                 Author : Alaa Omran                     */
/* Object : array-based stack and some applications of it  */
/***********************************************************/

template<class T>
class Stack{
private:
    int size{0},capacity{5},idx{-1};
    T *arr{nullptr};

    //double the reserved capacity to the double
    void expand(){
        capacity*=2;
        T *arr2 = new T [capacity];
        for(int i = 0;i<size;i++)arr2[i] = arr[i];
        swap(arr,arr2);
        delete [] arr2;
        arr2 = nullptr;
        return;
    }

public:
    //constructor
    Stack(){
        //default
        arr = new T [capacity];
    }
    Stack(int size,T val = 0):size(size){
        //parameterized
        capacity = (2*size);
        arr = new T [capacity];
        for(int i = 0;i<size;i++)arr[i] = val;
        idx = size-1;    //position at the last element
    }
    //add to last
    void push(T val){
        if(size==capacity)
            expand();
        arr[++idx] = val;
        size++;
    }
    //get the last element
    T top(){
        int res = 0;
        if(size)
            res = arr[idx];
        return res;
    }
    //delete the last element
    void pop(){
        if(!size)
            return;
        idx--,size--;
    }
    //peak
    T peak(){
        T x = top();
        pop();
        return x;
    }
    //get the actual size
    int Size(){
        return size;
    }
    //check if empty
    bool empty(){
        return !size;
    }
    //display the content
    void print(){
        if(!size)
            return;

        for(int i = idx;i>=0;i--)cout<<arr[i]<<" ";
        cout<<"\n";
    }

    //destructor
    ~Stack(){
        //freeing the reserved heap memory
        delete [] arr;
        arr = nullptr;
    }

};
//reverse sub-words of the original word
string reverse_subwords(string& line){
    string new_line{""};
    line+=" ";
    Stack<char>st;
    for(int i = 0;i<line.size();i++){
        if(line[i]==' '){
            while(!st.empty()){
                new_line+=st.top();
                st.pop();
            }
            new_line+=" ";
        }
        else{
            st.push(line[i]);
        }
    }
    return new_line;
}
//reverse number deigits
int reverse_num(int &num){
    int res{0},tens{1};
    Stack<int>st;
    while(num){
        st.push(num%10);
        num/=10;
    }

    while(!st.empty()){
        res+=(st.top()*tens);
        st.pop();
        tens*=10;
    }

    return res;
}
//infix to postfix
int precedence(char c){
    if(c=='+' or c=='-')
        return 1;
    else if(c=='*' or c=='/')
        return 2;

    return 0;
}
string infixTOpostfix(string& infix){
    Stack<char>operators{};
    string postfix{""};
    //to get ride of making another loop to get the remainder on the stack
    infix+='-';
    //to get ride of checking if the stack is empty
    operators.push('#');
    //run
    for(int i = 0;i<infix.size();i++){
        if(isdigit(infix[i])){
            postfix+=infix[i];
        }
        else if(infix[i]=='('){
            operators.push(infix[i]);
        }
        else if(infix[i]==')'){
            while(operators.top()!='('){
                    postfix+=operators.peak();
            }
            operators.pop();//remove (
        }
        else{
            while(precedence(infix[i])<=precedence(operators.top())){
                    postfix+=operators.peak();
            }
            operators.push(infix[i]);
        }
    }
    //return
    return postfix;
}
int main(){

    string s{"2+3-((5+2)*3)"};
    cout<<infixTOpostfix(s);

}