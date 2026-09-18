#include<bits/stdc++.h>
using namespace std;

void computeLPS(string pattern,vector<int>& lps){
    int len =0;
    int i =1;

    lps[0] =0;
    while (i<pattern.length())
    {
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len !=0){
                len = lps[len - 1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    
}


void KMP(string text, string pattern){
    int n = text.length();
    int m = pattern.length();

    vector<int>lps(m);

    computeLPS(pattern,lps);
    int i=0;
    int j=0;
    while (i<n)
    {
        if(text[i] == pattern[j]){
            i++;
            j++;
        }
        if(j==m){
            cout<<"Pattern is found at index : " 
            <<i-j <<endl;

            j = lps[j-1];
        }
        else if(i<n && text[i] != pattern[j]){
            if(j != 0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    

}

int main() {
    ifstream file("text.txt");

    if(!file){
        cout<<"File could not be opened." <<endl;
        return 0;
    } 
    string text;
    getline(file,text);

    cout<<text <<endl;
    
    file.close();

    string pattern;
    cout<<"Enter pattern: ";
    cin >> pattern;

    KMP(text,pattern);

    return 0;
}