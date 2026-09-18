#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&a,int st,int mid,int end){
    vector<int>temp;
    int i= st,j=mid+1;
    while (i<=mid && j<=end)
    {
        if(a[i]<a[j]){
            temp.push_back(a[i]);
             i++;
        }
        else{
            temp.push_back(a[j]);
           j++;
        }
    }

    while (i<=mid)
    {
        temp.push_back(a[i]);
        i++;
    }
    while (j<=end)
    {
        temp.push_back(a[j]);
        j++;
    }
    
    for(int i=0; i<temp.size();i++){
        a[i+st] = temp[i];
    }
    
}

void mergeSort(vector<int>&a,int st,int end){
    if(st>=end) return;
    int mid = st+(end-st)/2;
    
    // left divide
    mergeSort(a,st,mid);
    // right 
    mergeSort(a,mid+1,end);

    merge(a,st,mid,end);
}

int main() {
    int n;
    cout<<"Enter the elemnt of an array:";
    cin>>n;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    mergeSort(a,0,n-1);
    cout<<"Sorted Array :" <<endl;
    for(int i=0; i<n; i++){
        cout << a[i] <<" ";
    }
    return 0;
}