#include<bits/stdc++.h>
using namespace std;

                /***************************************************
                            Object : trie data structure
                            Author : @Alaa Omran
                 ***************************************************/


class trie{
private:
    map<int , trie*>child;
    bool isLeaf{false};

public:
    trie(){

    }

    void insert(string str , int idx = 0){
        if(idx == (int)str.size())
            isLeaf = true;
        else{
            int currentChar = str[idx] - 'a';
            if(child.count(currentChar) == 0)
                child[currentChar] = new trie();

            child[currentChar]->insert(str , idx + 1);
        }
    }

    bool exist(string str , int idx = 0){
        if(idx == (int)str.size())
            return isLeaf;

        int currentChar = str[idx] - 'a';
        if(child.count(currentChar) == 0)
            return false;

        return child[currentChar]->exist(str , idx + 1);
    }

    bool prefix(string str , int idx = 0){
        if(idx == (int)str.size())
            return true;

        int currentChar = str[idx] - 'a';
        if(child.count(currentChar) == 0)
            return false;

        return child[currentChar]->prefix(str , idx + 1);
    }







      /***********************
      *     Home Works 3     *
      ************************/
    //implement the prefix function but the iterative style
    bool prefix_iterative(string str){
        trie* tmp = this;

        for(int idx = 0;idx<(int)str.size();idx++){
            int currentChar = str[idx] - 'a';
            if(tmp->child.count(currentChar) == 0)
                return false;
            tmp = tmp->child[currentChar];
        }
        return true;
    }
};
