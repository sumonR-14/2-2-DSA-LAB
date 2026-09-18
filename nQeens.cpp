#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<string>& board,int row,int col, int n){
    //1.check row--horizontal
    for(int i=0; i<n; i++){
        if(board[row][i ]=='Q'){
            return false;
        }
    }
    //check col -- vertical
     for(int i=0; i<row; i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    // left diagonal
     for(int i=row-1,j = col -1; i>=0 && j>=0 ; i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    // right diagonal
    for(int i=row-1,j = col +1; i>=0 && j<n; i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }

    return true;
}


void nQueens(vector<string>& board,int row, int n,vector<vector<string>>& ans){
     if(row == n){
        ans.push_back(board);
        return;
     }
     // try every col
     for(int j=0; j<n; j++){
        if(isSafe(board,row,j,n)){
            board[row][j] = 'Q';
            // go to next row 
            nQueens(board,row+1,n,ans);
            // backtrack
            board[row][j] = '.';
        }
     }
}

vector<vector<string>> solveNqueens(int n){
    vector<string> board(n,string(n,'.'));
    vector<vector<string>> ans;

    nQueens(board,0,n,ans);

    return ans;
}


int main() {
   int n; 
   cout<<"enter the value of n:";
   cin >> n;

   vector<vector<string>> ans = solveNqueens(n);

   cout<<"total solution : " << ans.size() <<endl;
   for(int i=0; i<ans.size();i++){
      cout<<"Solution " <<i+1 <<": " <<endl;
      for(int j=0; j<n; j++){
        cout<<ans[i][j] <<endl;
      }
   }
    return 0;
}