#include<bits/stdc++.h>

using namespace std;

int main() {

    //Take number of elements
    int n,k;
    cin>>n;

    //Take elements
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    //Take sliding window size
    cin>>k;

    //Take double ended queue
    deque<int> deq;

    //Loop while there are elements
    //The idea here is to use double ended queue
    //We store the maximum elements in queue starting from largest,then second largest
    //We put element in queue at last
    //First we remove all element that are smaller than current element from front
    //As current element will take their place so there is no need of them
    //Then we start from end removing smallest element for example in case 4 2 1 and current element is 3
    //3 must be after 4 so we remove from last all smaller element
    //Also at each iteration we check if the element that is going outside from sliding window
    //is the largest element if yes then remove the front of queue
    for(int i=0;i<n;i++) {

        //Current element
        int cur = arr[i];

        //If element which is going out of sliding window is largest
        //Then remove this element
        if(i >=k && arr[i-k] == deq.front())
            deq.pop_front();

        //Remove all smaller element from front
        while(!deq.empty() && deq.front() < cur) {
            deq.pop_front();
        }

        //Remove all smaller element from last
        while(!deq.empty() && deq.back() < cur) {
            deq.pop_back();
        }

        //Push current element
        deq.push_back(cur);

        //If it is required sliding window size print answer
        //Which will be front of queue
        if(i >= k-1)
            cout<<deq.front()<<" ";
    }
    return 0;
}
