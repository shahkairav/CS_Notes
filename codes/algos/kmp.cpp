#include<bits/stdc++.h>

using namespace std;

vector<int> computelps(string needle){
    vector<int> lps(needle.size(),0);
    
    int i=1, N=needle.size(), len=0;
    while(i<N){
        if(needle[i] == needle[len]){lps[i++] = ++len;}
        else{
            if(len != 0) len = lps[len-1];
            else lps[i++] = 0;
        }
    }
    cout<<"LPS: ";
    for(auto x : lps){cout<<x<<' ';}cout<<endl;
    return lps;
}

void kmp(string haystack, string needle){
    vector<int> lps = computelps(needle);

    int i=0, j=0, N=haystack.size(), M=needle.size();
    while(i<N){
        // cout<<i<<' '<<j<<endl;
        if(j == M){
            cout<<"Match found at "<<i-M<<endl;
            j = lps[j-1];
            i -= (j+1);
        }
        if(haystack[i] == needle[j]){i++;j++;}
        else{
            if(j!=0){
                j = lps[j-1];
            }
            else i++;
        }   
    }
    if(j==M){cout<<"Match found at "<<i-M<<endl;}
}

int main(){
    string haystack, needle;
    cin>>haystack>>needle;
    kmp(haystack,needle);
}