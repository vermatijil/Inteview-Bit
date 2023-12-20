#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// the are the all the four variation of the greater element in the stack
// important these variation are repeated many times in the interview
// one apprach is followed in all the appraoch but dry run all for better understanding

// this is to the left;
vector<int> NextGreatrelementLeft(vector<int> &ans)
{
    vector<int> finalAns;
    stack<int> s;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (s.size() == 0)
            finalAns.push_back(-1);
        else if (s.size() > 0 and s.top() > ans[i])
        {
            finalAns.push_back(s.top());
        }
        else if (s.size() > 0 and s.top() <= ans[i])
        {
            while (s.size() > 0 and s.top() <= ans[i])
            {
                s.pop();
            }
            if (s.size() == 0)
                finalAns.push_back(-1);
            else
            {
                finalAns.push_back(s.top());
            }
        }
        s.push(ans[i]);
    }
    reverse(finalAns.begin(), finalAns.end());
    return finalAns;
}

// this is to the right
vector<int> NextGreatrelementRight(vector<int> &ans)
{
    vector<int> finalAns;
    stack<int> st;
    for (int i = 0; i < ans.size(); i++)
    {
        if (st.empty())
            finalAns.push_back(-1);
        else if (st.size() > 0 and st.top() > ans[i])
        {
            finalAns.push_back(st.top());
        }
        else if (st.size() > 0 and st.top() <= ans[i])
        {
            while (st.size() > 0 and st.top() <= ans[i])
            {
                st.pop();
            }
            if (st.size() == 0)
                finalAns.push_back(-1);
            else
                finalAns.push_back(st.top());
        }
        st.push(ans[i]);
    }
    return finalAns;
}

vector<int> NextSmallerlementRight(vector<int> &ans)
{
    vector<int> finalAns;
    stack<int> st;
    for (int i = 0; i < ans.size(); i++)
    {
        if (st.empty())
            finalAns.push_back(-1);
        else if (st.size() > 0 and st.top() < ans[i])
        {
            finalAns.push_back(st.top());
        }
        else if (st.size() > 0 and st.top() >= ans[i])
        {
            while (st.size() > 0 and st.top() >= ans[i])
            {
                st.pop();
            }
            if (st.size() == 0)
                finalAns.push_back(-1);
            else
                finalAns.push_back(st.top());
        }
        st.push(ans[i]);
    }
    return finalAns;
}

vector<int> NextSmallerelementLeft(vector<int> &ans)
{
    vector<int> finalAns;
    stack<int> s;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (s.size() == 0)
            finalAns.push_back(-1);
        else if (s.size() > 0 and s.top() < ans[i])
        {
            finalAns.push_back(s.top());
        }
        else if (s.size() > 0 and s.top() >= ans[i])
        {
            while (s.size() > 0 and s.top() >= ans[i])
            {
                s.pop();
            }
            if (s.size() == 0)
                finalAns.push_back(-1);
            else
            {
                finalAns.push_back(s.top());
            }
        }
        s.push(ans[i]);
    }
    reverse(finalAns.begin(), finalAns.end());
    return finalAns;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            cin >> ans[i];
        vector<int> finalAns = NextSmallerelementLeft(ans);
        for (auto e : finalAns)
            cout << e << " ";
    }
    return 0;
}