#include<bits/stdc++.h>
using namespace std;

int S[] = {5, 10, 12, 13, 15, 18};
int n = 6;
int d = 30;

int solutionCount = 0;

void subsetSum(int index, int sum, vector<int>& subset)
{
    // Target sum found
    if(sum == d)
    {
        solutionCount++;

        cout << "Subset " << solutionCount << " : { ";

        for(int x : subset)
        {
            cout << x << " ";
        }

        cout << "}" << endl;

        return;
    }

    // Stop current branch
    if(index == n || sum > d)
    {
        return;
    }

    // -------- TAKE --------
    subset.push_back(S[index]);

    subsetSum(index + 1,
              sum + S[index],
              subset);

    // -------- BACKTRACK --------,,je elemnt niye desire solution pai ni seta bad dibo jate onno ta diye try kora jay
    subset.pop_back();

    // -------- DON'T TAKE --------
    subsetSum(index + 1,
              sum,
              subset);
}

int main()
{
    vector<int> subset;

    // Print the given set
    cout << "Given Set S = { ";

    for(int i = 0; i < n; i++)
    {
        cout << S[i] << " ";
    }

    cout << "}" << endl;

    // Print target
    cout << "Target Sum d = " << d << endl;

    cout << endl;
    cout << "Subsets whose sum is " << d << ":" << endl;

    // Backtracking -- index,sum,subset
    subsetSum(0, 0, subset);

    cout << endl;
    cout << "Total solutions = " << solutionCount << endl;

    return 0;
}