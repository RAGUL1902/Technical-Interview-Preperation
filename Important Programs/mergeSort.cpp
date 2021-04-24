#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;

    int leftArray[n1], rightArray[n2];
    int i=0,j=0,k=l;

    for(int i=0;i<n1;i++)
        leftArray[i] = arr[l+i];

    for(int i=0;i<n2;i++)
        rightArray[i] = arr[m+1+i];

    while (i<n1 && j<n2)
    {
        if(leftArray[i]<rightArray[j]){
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
        
    }
    
    while(i<n1){
        arr[k] = leftArray[i];
        i++;
        k++; 
    }
    while(j<n2){
        arr[k] = rightArray[j];
        j++;
        k++; 
    }
}

void mergeSort(int arr[], int l, int r){
    int m = l + (r-l)/2;
    if(r>l){
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}