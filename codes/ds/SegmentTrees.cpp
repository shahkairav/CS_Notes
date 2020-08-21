#include<bits/stdc++.h>

using namespace std;

class SegmentTree {
    private:
        vector<int> tarr;
        vector<int> arr;
        int size;
        int maxSize;

        int build(int i,int j,int idx);
        void print(int i, int j, int idx);
        int query(int tl,int tr,int i,int j,int idx);
        void update(int tl, int tr, int idx, int i, int val);
        
    public:
        SegmentTree(vector<int> inp):maxSize(4*inp.size()),size(inp.size()),tarr(inp){arr.reserve(maxSize);build();}
        int build(){return build(0,size-1,0);}
        int query(int i,int j){return query(0,size-1,i,j,0);}
        void update(int i, int val){update(0,size-1,0,i,val-tarr[i]);tarr[i]=val;}
        int getSize() const{return size;}
        void print(){print(0,size-1,0);}
};

void SegmentTree::update(int tl,int tr, int idx, int i, int val){
    if((i==tl)&&(i==tr)){arr[idx] += val;}
    else if((i<=tr)&&(i>=tl)){
        arr[idx] += val;
        int mid = (tl+tr)/2;
        if((i<=mid)&&(i>=tl)){update(tl,mid,2*idx+1,i,val);}
        if((i>mid)&&(i<=tr)){update(mid+1,tr,2*idx + 2,i, val);}
    }
}

int SegmentTree::query(int tl, int tr, int i, int j, int idx){
    if(i > j){return 0;}
    else if(i > tr){return 0;}
    else if(j < tl){return 0;}
    else if((tl==i)&&(tr==j)){return arr[idx];}
    else {
        int tm = (tl+tr)/2;
        return query(tl,tm,i,min(j,tm),2*idx + 1) + query(tm+1,tr,max(i,tm+1),j,2*idx+2);
    }
}

int SegmentTree::build(int i, int j, int idx){
    if(i==j){arr[idx] = tarr[i];}
    else{
        int mid = (i+j)/2;
        arr[idx] = build(i,mid,2*idx+1) + build(mid+1,j,2*idx + 2); 
    }
    return arr[idx];
}

void SegmentTree::print(int i, int j, int idx){
    if(i==j){cout<<i<<' '<<j<<' '<<arr[idx]<<endl;}
    else{
        int mid = (i+j)/2;
        print(i,mid,2*idx+1);
        print(mid+1,j,2*idx+2);
        cout<<i<<' '<<j<<' '<<arr[idx]<<endl;
    }
}

int main(){
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree ST(arr);
    // ST.print();
    cout<<ST.query(1,5)<<endl;
    ST.update(2,3);
    ST.update(3,3);
    cout<<ST.query(1,5)<<endl;
}