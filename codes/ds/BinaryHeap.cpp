#include<bits/stdc++.h>

using namespace std;

class BinaryHeap{
    private:
        vector<int> arr;
        int maxSize, size;

        // Imp declaration
        // Here , we are assuming index starts from 0;
        inline int left(int idx){return 2*idx+1;}
        inline int right(int idx){return 2*idx + 2;}
        inline int parent(int idx){return (idx-1)/2;}

        // Utils
        void swap(int idx1, int idx2);
        int find(int idx,int val);

        // Imp Funcs
        void percolateUp(int idx);
        void percolateDown(int idx);

        
    public:
        BinaryHeap(int n):maxSize(n),size(0){arr.resize(n);}
        void insert(int val);
        int findMin(){return (size == 0)? INT_MAX : arr[0];}
        int deleteMin();
        void increaseKey(int key, int val);
        void decreaseKey(int key, int val);
        void print();
};

void BinaryHeap::swap(int idx1, int idx2){
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int BinaryHeap::find(int idx, int val){
    if(idx>=size){return -1;}
    else if(arr[idx] == val){return idx;}
    else{
        int one = -1;
        if(arr[left(idx)]<=val){one = find(left(idx),val);}
        if(one == -1){
            if(arr[right(idx)]<=val){one = find(right(idx),val);}
        }
        return one;
    }
}

void BinaryHeap::percolateUp(int idx){
    if(arr[idx] < arr[parent(idx)]){
        swap(idx,parent(idx));
        percolateUp(parent(idx));
    }
}

void BinaryHeap::percolateDown(int idx){
    int replace = -1;
    if(left(idx) < size){
        replace = left(idx);
    }
    if(right(idx) < size){
        if(arr[left(idx)] > arr[right(idx)]){replace = right(idx);}
    }
    if(replace != -1){
        if(arr[replace] < arr[idx]){
            swap(replace,idx);
            percolateDown(replace);
        }
    }

}
void BinaryHeap::insert(int val){
    if(size == maxSize){
        throw length_error("Size already maximum");
    }
    else{
        arr[size++] = val;
        percolateUp(size-1);
    }
}

int BinaryHeap::deleteMin(){
    if(size > 0){
        int ret = findMin();
        arr[0] = arr[--size];
        percolateDown(0);
        return ret;
    }
    else{
        return INT_MAX;
    }
}

void BinaryHeap::increaseKey(int key, int val){
    int idx = find(0,key);
    if(idx != -1){
        arr[idx] += val;
        percolateDown(idx);
    }
    else{
        throw runtime_error("Key not found!");
    }
}

void BinaryHeap::decreaseKey(int key, int val){
    int idx = find(0,key);
    if(idx != -1){
        arr[idx] -= val;
        percolateUp(idx);
    }
    else{
        throw runtime_error("Key not found!");
    }
}

void BinaryHeap::print(){
    for(int i=0;i<size;i++){cout<<arr[i]<<' ';}
    cout<<endl;
}

int main(){
    BinaryHeap H(6);
    H.insert(3);
    H.insert(5);
    H.insert(1);
    H.insert(2);
    H.insert(4);
    H.print();
    cout<<H.findMin()<<endl;
    cout<<H.deleteMin()<<endl;
    H.print();
    H.increaseKey(2,5);
    H.decreaseKey(5,3);
    // H.insert(6);
    H.print();
    cout<<H.findMin()<<endl;
    cout<<H.deleteMin()<<endl;
    H.print();
}