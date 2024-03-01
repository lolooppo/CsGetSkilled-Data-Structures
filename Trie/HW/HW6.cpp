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
      *     Home Work 6      *
      ************************/
    //implement an auto complete function
    void auto_complete_v1(vector<string>& res ,const string& word , string str = "" , int idx = 0){
        if(isLeaf and idx >= (int)word.size())
            res.push_back(str);
        for(int i = 0;i<26;i++){
            if(  child.count(i) and (idx >= (int)word.size()    or    word[idx] == (char)('a' + i))  )
                child[i]->auto_complete_v1(res , word , str + (char)('a' + i) , idx + 1);
        }
    }
    //another version of problem 6
    void auto_complete_v2(vector<string>& res ,const string& word){
        trie* tmp = this;
        for(int i = 0;i<(int)word.size();i++){
            int currentChild = word[i] - 'a';
            if(tmp->child.count(currentChild) == 0)
                return;
            tmp = tmp->child[currentChild];
        }
        tmp->get_all_strings(res , word);
    }

};
