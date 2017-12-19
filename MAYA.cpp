#include<bits/stdc++.h>

using namespace std;

//Number of maya calender
int arr[] = {1,20,360,7200,144000,2880000,57600000};

int main() {

    //Take input
    int n,k,cnt;
    long long sum;
    cin>>n;
    cin.ignore();

    //While there is input
    while(n != 0) {
        string str;

        //Print the output
        k = n-1,sum=0;
        for(int i=0;i<n;i++) {
            getline(cin,str);
            cnt = 0;
            for(int j=0;j<str.length();j++) {
                if(str[j] == '.')
                    cnt++;
                else if(str[j] == '-')
                    cnt += 5;
            }
            sum += cnt*arr[k];
            k--;
        }
        cout<<sum<<endl;

        cin>>n;
        cin.ignore();
    }
}
