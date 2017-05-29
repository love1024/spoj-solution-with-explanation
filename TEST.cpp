#include<bits/stdc++.h>

using namespace std;

int main() {
	
	//Declare variable to take input in it
    int x;
	
	//Use do while loop as input needs to
	//be taken first before checking for condition
    do {
	
		//take input
        cin>>x;
		
		//if number is not 42 then print that number
        if(x != 42)
            cout<<x<<endl;
			
	//if number is 42 then exit from the loop
    }while(x != 42);
}
