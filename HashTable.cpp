#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    
};

//insert each Node inside hashing table by NULL
void insert_hashing_tableToNull(Node **&hashing_table)
{
    
    for(int i=0;i<10;i++)
        hashing_table[i]=NULL;
}

int hash_funtion(int key){
    return key%10;
}

//insert hashing table by Node
void insertKey(Node **&hashing_table,int key){
    int hIndex=hash_funtion( key);
    Node *t=new Node;
    t->data=key;
    t->next=nullptr;
    
    if(hashing_table[hIndex]==NULL)
        hashing_table[hIndex]=t;
    
    else{
        Node *p=hashing_table[hIndex];
        while(p->next!=nullptr)
            p=p->next;
        
        p->next=t;
        
    }
    
}

//search for element 
Node * searchKey(Node **&hashing_table,int key){
    int hIndex=hash_funtion( key);
    
    Node *p=hashing_table[hIndex];
    
    while(p){
        if(p->data==key)
            return p;
        
    }
    
    return NULL;
}
int main(){
    
    vector<int> arr={5,12,22,6,7,75,28,27,99};
    
    Node **hashing_table;
    hashing_table=new Node*[10];
    
    insert_hashing_tableToNull(hashing_table);
    
    
    
    
    for(int i=0;i<arr.size();i++)
        insertKey(hashing_table, arr[i]);
    
    Node *search=searchKey(hashing_table,  6121);
    
    if(search)
        cout<<"key is found:"<<search->data<<endl;
    
    else
        cout<<"key isn't found!"<<endl;
    
    
    
    
    
}

