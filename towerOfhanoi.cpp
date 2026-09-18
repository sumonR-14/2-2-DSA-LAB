#include<bits/stdc++.h>
using namespace std;

int cnt =0;
void towerOfHanoi(int n, char source,char helper,char destination){
    if(n==1){
        cout<<"Move disk 1 from " <<source <<" to "
        <<destination <<endl;  
        cnt++;
        return;
    }

    // move n-1 disk from source to helper 
    towerOfHanoi(n-1,source,destination,helper);
    // move largest disk from source to destination
    cout<<"Move disk " <<n <<" from "
    <<source <<" to " <<destination <<endl;

    cnt++;

    // move n-1 disk from helper to destination using source as a helper
    towerOfHanoi(n-1,helper,source,destination);
}

int main() {
    int n;
    cout<<"Enter the number of disks: ";
    cin>> n;
    towerOfHanoi(n,'A','B','C');
    cout<<"Total moves : " <<cnt <<endl;
    return 0;
}