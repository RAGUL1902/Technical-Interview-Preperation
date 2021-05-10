#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n, m;
    cin>>n>>m;
    long long int arr[n];
    for(int i=0;i<n;i++){
        arr[i] = 0;
    }
    for(int i = 0;i<m;i++){
        long long int a,b,c;
        cin>>a>>b>>c;
        arr[a-1] += c;
        arr[b] -= c;
    }
    int maxi = 0;
    int val = 0;
    for(int i=0;i<n;i++){
        val += arr[i];
        if(val > maxi)
            maxi = val;
    }
    cout<<maxi;
}