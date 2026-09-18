#include<bits/stdc++.h>
using namespace std;


int binarySearch(vector<int> &a, int key){
    int st = 0, end = a.size()-1;
    while (st<=end)
    {
        int mid = st + (end -st)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid]<key){
            st = mid+1;
        }
        else{
           end = mid-1;
        }
    }
    return -1;
}
  

int main() {
    int n;
    cout<<"Enter the elemnt of an array:";
    cin>>n;
    vector<int>a(n);
    cout<<"sorted array: " <<endl;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int key;
    cout<<"enter the search element : ";
    cin >> key;

    int result =  binarySearch(a,key);
    if(result != -1){
        cout<<" Key is found in index : " <<result+1 <<endl;
        cout<< a[result];
    }else{
        cout<<"Key is not found " <<endl;
    }
    
    return 0;
}