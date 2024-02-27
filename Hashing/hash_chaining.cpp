#include<bits/stdc++.h>
using namespace std;

            /****************************************************
                @Author : Alaa Omran
                @object : phone directory based on closed hashing.
            ****************************************************/


int hash_string(string str , int n){
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
    const static int INTERNAL_LIMIT = 2147483647;
    string phone_number{0};
    string name{""};

    phoneEntry(string name , string phone_number){
        this->name = name;
        this->phone_number = phone_number;
    }

    void print(){
        cout<<"name : "<<name<<" , phone number : "<<phone_number<<"\n";
    }

    int hash(){
        return hash_string(name , INTERNAL_LIMIT);
    }
};


class phoneHashTable{
private:
    int table_size;
    int total_elements{0};
    double limited_load_factor;
    vector<vector<phoneEntry>>table;
public:
    phoneHashTable(int table_size , double limited_load_factor) : limited_load_factor(limited_load_factor) , table_size(table_size){
        table.resize(table_size);
    }

    void put(phoneEntry phone){
        int idx = phone.hash() % table_size;
        for(int i = 0;i < (int)table[idx].size();i++){
            if(table[idx][i].name == phone.name){
                table[idx][i] = phone;
                return;
            }
        }
        table[idx].push_back(phone);
        total_elements++;
    }

    bool remove(phoneEntry phone){
        int idx = phone.hash() % table_size;
        for(int i = 0;i < (int)table[idx].size();i++){
            if(table[idx][i].name == phone.name){
                swap(table[idx][i] , table[idx].back());
                table[idx].pop_back();
                total_elements--;
                return true;
            }
        }
        return false;
    }

    bool get(phoneEntry &phone){
        int idx = phone.hash() % table_size;
        for(int i = 0;i < (int)table[idx].size();i++){
            if(table[idx][i].name == phone.name){
                phone = table[idx][i];
                return true;
            }
        }
        return false;
    }

    void rehashing(){
        double current_load_factor = (double)total_elements / table_size;
        if(current_load_factor <= limited_load_factor)
            return;
        phoneHashTable newtable(2 * table_size , limited_load_factor);
        for(int idx1 = 0;idx1 < table_size;idx1++){
            if((int)table[idx1].size() == 0)
                continue;
            for(int idx2 = 0;idx2 < (int)table[idx1].size();idx2++)
                newtable.put(table[idx1][idx2]);
        }
        table_size *= 2;
        table = newtable.table;
    }

    void print(){
        for(int idx1 = 0;idx1 < table_size;idx1++){
            if((int)table[idx1].size() == 0)
                continue;
            cout<<"Hash : "<<idx1<<"\n";
            for(int idx2 = 0;idx2 < (int)table[idx1].size();idx2++){
                table[idx1][idx2].print();
            }
            cout<<"\n";
        }
    }
};


void test1(){
    phoneHashTable table(3 , 0.75);

    table.put(phoneEntry("mostafa" , "604-401-120"));
    table.put(phoneEntry("mostafa" , "604-401-777"));
    table.put(phoneEntry("ali" , "604-401-343"));
    table.put(phoneEntry("ziad" , "604-401-17"));
    table.put(phoneEntry("hany" , "604-401-758"));
    table.put(phoneEntry("belal" , "604-401-550"));
    table.put(phoneEntry("john" , "604-401-223"));

    phoneEntry e("mostafa" , "");
    if(table.get(e))
        cout<<e.phone_number<<"\n\n";

    cout<<"All names and phones \n";
    table.print();
}


int main(){

    test1();
}