#include<bits/stdc++.h>

using namespace std;

int main() {

    //Get the number
    long long int num;
    cin>>num;

    //check if number is power of 2
    while(num > 1) {
        if(num%2 == 0)
            num = num/2;
        else
            break;
    }

    //if at last number is less than 1 then loop will end
    if(num == 1)
        cout<<"TAK"<<endl;
    else
        cout<<"NIE"<<endl;
    return 0;
}
