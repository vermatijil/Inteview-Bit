#include <iostream>
#include <vector>

using namespace std;

vector<int> Add(vector<int> &ans, vector<int> &bns)
{
    int i = ans.size() - 1;
    int j = bns.size() - 1;
    int carry = 0;
    vector<int> finalAns;
    while (i >= 0 || j >= 0 || carry)
    {
        int num1 = i >= 0 ? ans[i] : 0;
        int num2 = j >= 0 ? bns[j] : 0;
        int sum = num1 + num2 + carry;
        finalAns.push_back(sum % 10);
        carry = sum / 10;
        i--;
        j--;
    }
    return finalAns;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> ans(n), bns(m);
        for (int i = 0; i < n; i++)
            cin >> ans[i];
        for (int i = 0; i < m; i++)
            cin >> bns[i];
        vector<int> finalAns = Add(ans, bns);
        for (auto e : finalAns)
            cout << e << " ";
    }
    return 0;
}