#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        bool eow;           // End of word
        vector<Node*> vec;  // Stores the children nodes

        /* functions */
        explicit Node():eow(false),vec(26,nullptr){} // Constructor
};

class Trie{
    private:
        Node* head;
        
    public:

        /* functions */
        Trie(){head = new Node;}    // Constructor
        void insert(string str);    // Inserts string into trie
        bool search(string str);    // Searches for the string into trie
};


// Inserts word into the trie ds
void Trie::insert(string str){
    Node* temp = head;

    for(auto x : str){
        // If the indexed element is a null ptr
        // It means no such char were initialized before
        // Therefore initialize it
        if(temp->vec[x-'a'] == nullptr){
            temp->vec[x-'a'] = new Node;
        }

        temp = temp->vec[x-'a'];
    }

    // Last Char Node will be marked as End of the word
    // temp will contain the Node* of the last char
    temp->eow = true;
}

bool Trie::search(string str){
    Node *curr = head;

    for(auto x : str){

        // Returns index of the character Ex. a -> 0, b -> 1
        int idx = (x - 'a');
        Node* next =  curr->vec[idx];

        // If no node has been initialized
        // it means no such word is present
        if(!next) return false;

        curr = next;
    }
    return (curr->eow);
}


int main(){
    Trie T;
    T.insert("rudra");
    T.insert("rude");
    cout<<T.search("rudra")<<endl;
    cout<<T.search("rud")<<endl;
    cout<<T.search("red")<<endl;
    
}