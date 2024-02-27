#include<bits/stdc++.h>
using namespace std;

class trie{
private:
    map<int , trie*>child;
    bool isLeaf{false};

public:
    trie(){

    }

    void insert_iterative(string str){
        trie* tmp = this;

        for(int idx = 0 ;idx < (int)str.size(); idx++){
            int currentChar = str[idx] - 'a';
            if(tmp->child.count(currentChar) == 0)
                tmp->child[currentChar] = new trie();
            tmp = tmp->child[currentChar];
        }
        tmp->isLeaf = true;
    }

    void get_all_strings(vector<string>& res , string str = ""){
        if(isLeaf)
            res.push_back(str);
        for(int i = 0;i<26;i++){
            if(child.count(i))
                child[i]->get_all_strings(res , str + char('a' + i));
        }
    }
};

void unique_substrings_trie(const string &str , vector<string>& res){
    trie tree;
    int n = (int)str.size();
    for(int start = 0;start < n;start++){
        for(int end = start;end < n;end++){
            tree.insert_iterative(str.substr(start , end - start + 1));
        }
    }
    tree.get_all_strings(res);
}

void test1(){
    int cnt{0};

    string str1{"aaab"};
    string str2{"aa"};

    vector<string>res1 , res2;

    unique_substrings_trie(str1 , res1);
    unique_substrings_trie(str2 , res2);

    unordered_map<string , bool>mp;

    for(auto& x : res1){
        mp[x] = true;
    }
    for(auto& x : res2){
        if(mp.count(x)){
            cnt++;
        }
    }
    cout<<cnt<<"\n";
}

void test2(){
    int cnt{0};

    string str1{"aaab"};
    string str2{"ab"};

    vector<string>res1 , res2;

    unique_substrings_trie(str1 , res1);
    unique_substrings_trie(str2 , res2);

    unordered_map<string , bool>mp;

    for(auto& x : res1){
        mp[x] = true;
    }
    for(auto& x : res2){
        if(mp.count(x)){
            cnt++;
        }
    }
    cout<<cnt<<"\n";
}

void test3(){
    int cnt{0};

    string str1{"aaaaa"};
    string str2{"xy"};

    vector<string>res1 , res2;

    unique_substrings_trie(str1 , res1);
    unique_substrings_trie(str2 , res2);

    unordered_map<string , bool>mp;

    for(auto& x : res1){
        mp[x] = true;
    }
    for(auto& x : res2){
        if(mp.count(x)){
            cnt++;
        }
    }
    cout<<cnt<<"\n";
}

void test4(){
    int cnt{0};

    string str1{"aaaaa"};
    string str2{"aaaaa"};

    vector<string>res1 , res2;

    unique_substrings_trie(str1 , res1);
    unique_substrings_trie(str2 , res2);

    unordered_map<string , bool>mp;

    for(auto& x : res1){
        mp[x] = true;
    }
    for(auto& x : res2){
        if(mp.count(x)){
            cnt++;
        }
    }
    cout<<cnt<<"\n";
}

int main(){
    test1();        //2  [a , aa]
    test2();        //3  [a , b , aa]
    test3();        //0
    test4();        //5  [a , aa , aaa , aaaa , aaaaa]
}
