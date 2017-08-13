#include<bits/stdc++.h>

using namespace std;

//Array to store temporary intermediate results
int arr[1005][1005];

//Function to get max time we can survive
//The idea here is to every odd step go to air
//To increase both health and armor
//So we can combine this step with other two
//to make only two steps
//Air + water = health-2 , armor - 8
//Air + fire = health-17, armor+7
int getMax(int h,int a,int i) {

    //If health is zero or armor is 0 we cannot add survive
    //this time so return i-1
    if(h <=0 || a <= 0)
        return i-1;

    //Else if this state is already found simple return its result
    else if(arr[h][a] != 0)
        return arr[h][a];

    //Find result of going to air + water
    int f = getMax(h-2,a-8,i+1);

    //Find result of going to air + fire
    int s = getMax(h-17,a+7,i+1);

    //Add max of these into intermediate results
    arr[h][a] = max(f,s);

    //return the max result
    return max(f,s);
}

int main() {

    //Take number of  test cases
    int t,h,a;
    scanf("%d",&t);

    //Loop over all test cases
    while(t--) {

        //Take health and armor
        scanf("%d%d",&h,&a);

        //Initialize intermediate array to 0
        memset(arr,0,sizeof(arr));

        //As we move in pairs so result will be 2*result -1
        //Where 1 is of we start from 1 stage so subtract it.
        printf("%d\n",2*getMax(h,a,1)-1);
    }
}
