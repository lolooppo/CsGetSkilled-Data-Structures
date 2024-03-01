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
    *       Home Works 1   *
    ************************/
    //implement the insert function but the iterative style
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
};

