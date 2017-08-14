#include<bits/stdc++.h>

using namespace std;

//ref - http://www.geeksforgeeks.org/largest-rectangle-under-histogram/

long long findArea(vector<long long> &vec) {
    long long i = 0;
    long long mx = 0;
    stack<long long> stk;
    while(i < vec.size()) {
        if(stk.empty() || vec[i] >= vec[stk.top()]) {
            stk.push(i);
            i++;
        } else {
            while(!stk.empty() && vec[stk.top()] > vec[i]) {
                long long cur = stk.top();
                stk.pop();
                if(stk.empty())
                    mx = max(mx,vec[cur]*(i));
                else
                    mx = max(mx,vec[cur]*(i-stk.top()-1));
            }
        }
    }

    while(!stk.empty()) {
        long long cur = stk.top();
        stk.pop();
        if(stk.empty())
            mx = max(mx,vec[cur]*(i));
        else
            mx = max(mx,vec[cur]*(i-stk.top()-1));
    }

    return mx;
}

int main() {
    long long n;
    cin>>n;

    while(n != 0) {
        vector<long long> vec(n);
        for(int i=0;i<n;i++)
            cin>>vec[i];

        long long res = findArea(vec);
        cout<<res<<endl;
        cin>>n;
    }
}
