#include<bits/stdc++.h>
using namespace std;

            /****************************************************
                @Author : Alaa Omran
                @object : phone directory based on opened hashing.
            ****************************************************/


int hash_string(string str , int n = 65407){
    long long nn = n;
    long long base = 62;
    long long sum = 0;
    for(int i =0;i < (int)str.size();i++){
        int value = 0;
        if(islower(str[i])){
            value += str[i] - 'a';
        }else if(isupper(str[i])){
            value += str[i] - 'A' + 26;
        }else if(isdigit(str[i])){
            value += str[i] - '0' + 52;
        }
        sum += (sum * base) + value;
        sum %= nn;
    }
    return sum % nn;
}

struct phoneEntry{
    const static int INTERNAL_LIMIT = 65407;
    string number{0};
    string name{""};

    phoneEntry(string name , string number){
        this->name = name;
        this->number = number;
    }

    int hash(){
        return hash_string(name , INTERNAL_LIMIT);
    }

    void print(){
        cout<<"name : "<<name<<" , phone number : "<<number<<"\n";
    }
};


class phoneHashTable{
private:
    int table_size;
    vector<phoneEntry*>table;
    phoneEntry *deleted = new phoneEntry("" , "");
public:
    phoneHashTable(int table_size) : table_size(table_size){
        table.resize(table_size);
    }

    bool put(phoneEntry phone){
        int idx = phone.hash() % table_size;
        for(int i = 0;i < table_size;i++){
            if(!table[idx] or table[idx] == deleted){
                table[idx] = new phoneEntry(phone.name , phone.number);
                return true;
            }else if(table[idx]->name == phone.name){
                table[idx]->number = phone.number;
                return true;
            }
            idx = (idx + 1) % table_size;
        }
        return false;
    }

    bool remove(phoneEntry phone){
        int idx = phone.hash() % table_size;
        for(int i = 0;i < table_size;i++){
            if(!table[idx])
                break;
            if(table[idx] != deleted and table[idx]->name == phone.name){
                delete table[idx];
                table[idx] = deleted;
                return true;
            }
            idx = (idx + 1) % table_size;
        }
        return false;
    }

    bool get(phoneEntry &phone){
        int idx = phone.hash() % table_size;
        for(int i = 0;i < table_size;i++){
            if(!table[idx])
                break;
            if(table[idx] != deleted and table[idx]->name == phone.name){
                phone.number = table[idx]->number;
                return true;
            }
            idx = (idx + 1) % table_size;
        }
        return false;
    }

    void print(){
        for(int i = 0;i < table_size;i++){
            cout<<i<<"\n";
            if(table[i] == deleted)
                cout<<" X \n";
            else if(!table[i])
                cout<<" E \n";
            else
                table[i]->print();
        }
    }
};

void test2(){
    phoneHashTable table(11);
	table.put(phoneEntry("mostafa", "604-401-120"));
	table.put(phoneEntry("mostafa", "604-401-777"));
	table.put(phoneEntry("ali", "604-401-343"));
	table.put(phoneEntry("ziad", "604-401-17"));
	table.put(phoneEntry("hany", "604-401-758"));
	table.put(phoneEntry("belal", "604-401-550"));
	table.put(phoneEntry("john", "604-401-223"));
	table.print();

	cout<<"\n************************************************************\n";

	cout << table.remove(phoneEntry("smith", "")) << "\n"; // 0
	cout << table.remove(phoneEntry("hany", "")) << "\n";  // 1
	cout << table.remove(phoneEntry("john", "")) << "\n";  // 1
	table.print();
}

int main(){
    test2();
}