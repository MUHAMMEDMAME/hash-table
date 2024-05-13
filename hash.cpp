#include<iostream>
#include<vector>
#define SIZE 10
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class Hash{
private:
    Node **hashTable;
public:
    Hash();
    void insertKey(int key);
    Node * searchKey(int key);
    int hash_function(int key);
};

int Hash::hash_function(int key){
    return key%10;
}
Hash::Hash(){
    hashTable=new Node*[10];
    
    for(int i=0;i<10;i++)
        hashTable[0]=nullptr;
    
    
}

void Hash::insertKey(int key){
    int hIndex=hash_function( key);
    Node *t=new Node;
    t->data=key;
    t->next=nullptr;
    
    if(hashTable[hIndex]==NULL)
        hashTable[hIndex]=t;
    
    else{
        Node *p=hashTable[hIndex];
        while(p->next!=NULL)
        p=p->next;
        
        p->next=t;
        
        
    }
    
}

Node * Hash::searchKey(int key){
    int hIndex=hash_function( key);
    
    Node *p=hashTable[hIndex];
    
    while(p){
        if(p->data==key)
            return p;
        
        p=p->next;
    }
    
    
    return  NULL;
    
    
}
int main() {
    vector<int> arr = {16, 12, 25, 39, 6, 122, 5, 68, 75};
    Hash hash;
    
    for(int i=0;i<arr.size();i++)
        hash.insertKey(arr[i]);
    
    Node *search=hash.searchKey(12);
    

    if(search)
        cout<<"Key is found:"<<search->data<<endl;
    
    else
        cout<<"Key isn't found";
}
