#include<bits/stdc++.h>

using namespace std;

//Nikifor will win if he has last turn
//when number are between 1-9
//So do this he must push opponent to give
//him this turn. he can do it easily with any number
//by subtracting and making it equal to multiply of 10
//from multiply of 10 opponent has to subtract something
//So Nikifor can again make it equal to multiple of 10
//And Hence he will win at last
//But at start if number is multiple of 10 Nikifor will lose
//Because opponent will now take moves of Nikifor
int main() {

    //Take the number
    long long int n;
    cin>>n;

    //If number is multiple of 10 Nikifor will lose
    if(n%10 == 0) {
        cout<<2<<endl;
    } else {

        //Else he will win by subtracting remainder of 10 in first move
        cout<<1<<endl;
        cout<<n%10<<endl;
    }
}
