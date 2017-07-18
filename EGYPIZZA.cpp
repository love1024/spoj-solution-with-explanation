#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    //Take input ratios as string
    vector<string> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];

    //Array for each ratio
    int arr[3] = {0,0,0};

    //Fill array according to ratio
    //arr[0] = 1/4,arr[1]=1/2,arr[2] = 3/4
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        int idx = (vec[i]=="1/4"?0:(vec[i]=="1/2"?1:2));
        arr[idx]++;
    }

    //Now 3/4 each will take one pizza and will leave 1/4
    //so we can subtract the need for 1/4
    cnt += arr[2];
    arr[0] -= arr[2];

    //if 1/4 are negative make them zero
    if(arr[0] < 0)
        arr[0] = 0;

    //Now 1/2 can pair with themselves to make full pizza
    cnt += arr[1]/2;

    //if 1/2 are odd then increment one pizza and add to 1/4
    arr[1] &= 1;
    if(arr[1])
        cnt++,arr[0] -= 2;

    //if 1/4 are now negative make them 0
    if(arr[0] < 0)
        arr[0] = 0;

    //At last if we are left with 1/4 them 4 of them can make 1 pizza
    //Adding 3 is needed if pizza are less than 4
    cnt += ((arr[0]+3)/4);

    //Print final answer
    cout<<cnt+1<<endl;
}
