#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Given an array A containing N integers.

// You need to find the maximum sum of triplet ( Ai + Aj + Ak ) such that 0 <= i < j < k < N and Ai < Aj < Ak.

// If no such triplet exist return 0.
// A = [2, 5, 3, 1, 4, 9]
// output= 16

int MaximumSumTriplet(vector<int> &A)
{
    int n = A.size();
    vector<int> right(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
            right[i] = A[i];
        else
            right[i] = max(A[i], right[i + 1]);
    }
    int ans = INT_MIN;
    set<int> s;
    s.insert(A[0]);
    for (int i = 1; i < n; i++)
    {
        s.insert(A[i]);
        auto it = s.find(A[i]);
        if (it != s.begin() && A[i] != right[i])
            ans = max(ans, *(--it) + A[i] + right[i]);
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            cin >> ans[i];
        cout << MaximumSumTriplet(ans) << endl;
    }
    return 0;
}