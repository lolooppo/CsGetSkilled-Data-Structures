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
     *      Home Work  5    *
     ************************/
    //implement a function that prints the tree words
    void get_all_strings(vector<string>& res , string str = ""){
        if(isLeaf)
            res.push_back(str);
        for(int i = 0;i<26;i++){
            if(child.count(i))
                child[i]->get_all_strings(res , str + char('a' + i));
        }
    }
};
