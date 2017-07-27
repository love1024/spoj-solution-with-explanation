#include<bits/stdc++.h>

using namespace std;

int main() {

    //Number of elements
    int n,m;

    //Loop while there are element
    cin>>n;
    while(n != 0) {

        //Take first array
        vector<int> first(n);
        for(int i=0;i<n;i++)
            cin>>first[i];

        //Take second array
        cin>>m;
        vector<int> second(m);
        for(int i=0;i<m;i++)
            cin>>second[i];

        //Loop while there are element in one of array
        int i=0,j=0;
        long long s1=0,s2=0;
        while(i<n || j<m) {

            //If there are element left in both array and are equals
            //Then this is intersection choose the max among previous sum
            if(i < n && j < m && first[i] == second[j]) {
                s1 += first[i];
                s2 += second[j];
                s1 = s2 = max(s1,s2);
                i++,j++;
            } else if(i >= n) {

                //if there are no element in first array
                s2 += second[j];
                j++;
            } else if(j >= m) {

                //if there are no element in second array
                s1 += first[i];
                i++;
            } else if(first[i] < second[j]) {

                //if first element is small then increase it to reach second
                s1 += first[i];
                i++;
            } else if(first[i] > second[j]){

                //if second element is small then increase it to reach first
                s2 += second[j];
                j++;
            }
        }

        //Print the maximum of sum
        cout<<max(s1,s2)<<endl;

        //Take next input
        cin>>n;
    }
}
