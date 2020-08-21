#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data, height;
        Node *left, *right;

        Node(int val):left(nullptr),right(nullptr),data(val),height(0){}
};

class AVL {
    private:
        Node *root;
        int size;
        
        // Utilities
        Node* findMin(Node *head);
        Node* findMax(Node *head);
        int height(Node* head) {return (head == nullptr) ? 0 : head->height;}

        // Rotations
        Node* RightRotate(Node *head);
        Node* LeftRotate(Node *head);
        Node* LeftRightRotate(Node *head);
        Node* RightLeftRotate(Node *head);

        // Helpers
        Node* insert(Node *head, int val);
        Node* remove(Node *head,int val);
        Node* find(Node *head, int val);
        Node* Balance(Node *head);
        void print(Node *head, bool check);

    public:
        //constructor
        AVL():root(nullptr),size(0){}

        bool find(int val);
        int findMin();
        int findMax();
        void insert(int val);
        void remove(int val);
        void print();
};

Node* AVL::RightRotate(Node *head){
    Node *k1 = head->left;
    Node *k1_right = k1->right;
    head->left = k1_right;
    k1->right = head;
    head->height = max(height(head->left),height(head->right)) + 1;
    k1->height = max(height(k1->right),height(k1->left)) + 1;
    return k1;
}

Node* AVL::LeftRotate(Node *head){
    Node *k2 = head->right;
    Node *k2_left = k2->left;
    head->right = k2_left;
    k2->left = head;
    head->height = max(height(head->left),height(head->right)) + 1;
    k2->height = max(height(k2->right),height(k2->left)) + 1;
    return k2;
}

Node* AVL::LeftRightRotate(Node *head){
    head->left = LeftRotate(head->left);
    head = RightRotate(head);
    return head;
}

Node* AVL::RightLeftRotate(Node *head){
    head->right = RightRotate(head->right);
    head = LeftRotate(head);
    return head;
}

Node* AVL::Balance(Node *head){
    if(head != nullptr){
        if(height(head->left) - height(head->right) > 1){
            if(height(head->left->left) >= height(head->left->right)){
                head = RightRotate(head);
            }
            else{
                head = LeftRightRotate(head);
            }
        }
        else{
            if(height(head->right) - height(head->left) > 1){
                if(height(head->right->right) >= height(head->right->left)){
                    head = LeftRotate(head);
                }
                else{
                    head = RightLeftRotate(head);
                }
            }
        }
        head->height = max(height(head->left),height(head->right)) + 1;
    }
    return head;
}

void AVL::insert(int val){
    root = insert(root, val);
}

Node* AVL::insert(Node *head, int val){
    if(head == nullptr){
        // assign new node as root
        head = new Node(val);
    }
    else if(head->data < val){
            // Go right
            head->right = insert(head->right, val);
        }
    else if(head->data > val){
                // Go left
                head->left = insert(head->left, val);
            }
    else{
                // duplicate
                // do nothing
    }
    return Balance(head);
}

void AVL::remove(int val){
    root = remove(root, val);
}

Node* AVL::remove(Node *head, int val){
    if(head == nullptr){return nullptr;}
    else{
        if(head->data < val){
            head->right = remove(head->right,val);
        }
        else{
            if(head->data > val){
                head->left = remove(head->left,val);
            }
            else{
                if(head->left == nullptr){
                    // Only right child
                    Node* temp = head->right;
                    free(head);
                    head = temp;
                }
                else{
                    if(head->right == nullptr){
                        // Only left child
                        Node* temp = head->left;
                        free(head);
                        head = temp;
                    }
                    else{
                        // Both children
                        Node* rightmin = findMin(head->right);
                        head->data = rightmin->data;
                        remove(head->right, rightmin->data);
                    }
                }
            }
        }
    }
    return Balance(head);
}

bool AVL::find(int val){
    Node* temp = find(root, val);
    return (temp == nullptr) ? false : true;
}

Node* AVL::find(Node* head, int val){
    if(head == nullptr){return nullptr;}
    else if(head->data < val){
        return find(head->right, val);
    }
    else if(head->data > val){
        return find(head->left, val);
    }
    else{
        return head;
    }
}

int AVL::findMin(){
    Node* temp = findMin(root);
    return (temp == nullptr) ? INT_MAX : temp->data;
}

Node* AVL::findMin(Node *head){
    if(head == nullptr){return nullptr;}
    else{
        if(head->left){return findMin(head->left);}
        return head;
    }
}

int AVL::findMax(){
    Node* temp = findMax(root);
    return (temp == nullptr) ? INT_MIN : temp->data;
}

Node* AVL::findMax(Node* head){
    if(head == nullptr){return nullptr;}
    else{
        if(head->right){return findMax(head->right);}
        return head;
    }
}

void AVL::print(){
    print(root,false);
    cout<<endl;
    print(root,true);
    cout<<endl;
}

void AVL::print(Node* head, bool printHeight){
    if(head != nullptr){
        if(printHeight) cout<<head->height<<' ';
        else cout<<head->data<<' ';
        print(head->left, printHeight);
        print(head->right, printHeight);
    }
}

int main(){
    AVL avltree;
    avltree.insert(52);
    avltree.insert(33);
    avltree.insert(40);
    avltree.insert(79);
    avltree.insert(61);
    avltree.insert(86);
    avltree.insert(45);
    avltree.insert(15);
    avltree.insert(22);
    avltree.insert(97);
    avltree.insert(35);
    avltree.print();
    cout<<avltree.findMin()<<' '<<avltree.findMax()<<endl;
    avltree.remove(40);
    avltree.remove(avltree.findMax());
    avltree.print();
    cout<<avltree.findMin()<<' '<<avltree.findMax()<<endl;
    avltree.remove(avltree.findMin());
    avltree.remove(avltree.findMax());
    avltree.print();
}