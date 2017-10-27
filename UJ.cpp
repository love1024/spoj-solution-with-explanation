#include<bits/stdc++.h>
using namespace std;

//REMOVE COMMENT BEFORE SUBMISSION
//The main idea is to find a^b or multiply a b times
//We divide array a into different parts in array and
//multiply with each part b so as to store large multiplication
//result. for that we use a base here we used 10^15 as base
int main() {

    //Variables to store intermediate values
    long long N,D,arr[555],c,t,i,j,k,m= 1000000000000000LL;

    //Take N and D
    cin>>N>>D;

    //While there is input
    while(N != 0||D!= 0) {

        //Loop over D times
        for(i=0,k=arr[0]=1;i<D;i++,k=j)

            //If there is number left or there is carry
            for(j=0,c=0;j<k || c;j++){

                //Find the current index value after multiplying with n
                //or 0 if it is for carry
                t = ((j<k)?arr[j]:0)*N;

                //Store current value + carry in this array index
                arr[j] = (t+c)%m;

                //Find the carry
                c = (t+c)/m;
            }
        //Starting of result without padding
        cout<<arr[--k];

        //Print rest of the result with padding as 00000 is only 0
        //in intermediate results so we pad with the base of our number
        for(--k;k>=0;k--)cout<<setfill('0')<<setw(15)<<arr[k];
        cout<<endl;

        //Take next number
        cin>>N>>D;
    }
}
