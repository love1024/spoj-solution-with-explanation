#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

    //Take number of test cases
    int t,m,n;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take row and col
        cin>>m>>n;

        vector<int> row(m-1);
        vector<int> col(n-1);

        for(int i=0;i<m-1;i++)
            cin>>row[i];
        for(int i=0;i<n-1;i++)
            cin>>col[i];


        //Sort row and col
        sort(row.begin(),row.end());
        sort(col.begin(),col.end());

        //Be greedy and always choose the maximum
        //between row and col and divide the chocolate
        //Here c and r represent the cuts in column or row
        int i=m-2,j=n-2,r=1,c=1;
        long long res = 0;
        while(i >= 0 || j >= 0){
            int a,b;
            a = b = 0;
            if(i >= 0)
                a = row[i];
            if(j >= 0)
                b = col[j];
            if(a > b) {
                res += (r*a);
                c++,i--;
            } else {
                res += (c*b);
                r++,j--;
            }
        }

        //Print the result
        cout<<res<<endl;
    }
}
