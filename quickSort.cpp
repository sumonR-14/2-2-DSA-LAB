#include<bits/stdc++.h>
using namespace std;
 //it will be pivot
int partition(vector<int>&arr,int st,int end){
    int idx = st-1;
    int pivit=arr[end];
    for(int i=st; i<end;i++){
        if(arr[i]<=pivit){
             idx++;
             swap(arr[i],arr[idx]);
        }
    }
    //for pivot in right position
    idx++;
    swap(arr[end],arr[idx]);

    return idx;
}

void quickSort(vector<int>& arr, int st, int end){
    if(st<end){
        int pivitIdx = partition(arr,st,end);

        quickSort(arr,st,pivitIdx-1);//left partition
        quickSort(arr,pivitIdx+1,end);//right partition
    }
}


int main() {
    int n;
    cout<<"Enter the elemnt of an array:";
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    quickSort(arr,0,n-1);
    cout<<"Sorted Array :" <<endl;
    for(int i=0; i<n; i++){
        cout << arr[i] <<" ";
    }
    return 0;
}