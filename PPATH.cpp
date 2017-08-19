#include<bits/stdc++.h>

using namespace std;

//check if i is prime number till 10000
bool prime[10000+1];

//Node to store value and its distance from
//start node
class Node {
public:
    int val;
    int dis;
    Node(int val,int dis) {
        this->val = val;
        this->dis = dis;
    }
};

//Sieve to find prime number till n
void sieve(int n) {

    //Initialize every number to prime
    memset(prime,true,sizeof(prime));

    //Loop over all numbers
    for(int i=2;i<=n;i++) {

        //Check if current number is prime
        if(prime[i]) {

            //If yes then marks its all multiple
            //as not prime
            int j = i+i;
            while(j <= n) {
                prime[j] = false;
                j += i;
            }
        }
    }
}

//Function to check the difference between digits of two
//Numbers. For e.g. 1234 1237 has difference of 1 as 1 digit
//is different
bool isOneDistance(int n,int m) {
    int cnt = 0;
    while(n > 0) {
        int a= n%10,b = m%10;
        if(a != b)
            cnt++;
        n /=10;
        m /=10;
    }
    return cnt==1;
}

//Function to check in many operations we
//Can reach to required number
//We will apply breadth first search to the
//Number its node will be all numbers it can
//reach and so on
int check(int n,int req) {

    //Take queue for breadth first search
    queue<Node> que;

    //Push the first number and its distance is 0
    que.push(Node(n,0));

    //Take the array which will donate which numbers
    //are already visited and initialize to false
    bool visited[10000];
    memset(visited,false,sizeof(visited));

    //Count will donate the distance from source node
    int cnt = 0;

    //Loop while queue is not empty
    while(!que.empty()) {

        //Take the current node and pop it from queue
        Node cur = que.front();
        que.pop();

        //Take value and distance of current node
        int val = cur.val;
        int dis = cur.dis;

        //If value is equal to given number
        //Return the distance till it
        if(val == req)
            return dis;

        //Else mark it as visited
        visited[val] = true;

        //Traverse all the neighbor it can reach
        for(int i=1000;i<=9999;i++) {

            //If the neighbor is not visited and is prime
            //And the change is of only one digit as we can
            //Only change one digit at a time
            if(!visited[i] && prime[i] && isOneDistance(val,i)) {

                //Push the node and mark it as visited
                que.push(Node(i,dis+1));
                visited[i] = true;
            }
        }
    }
}

int main() {

    //Take number of test cases,number and required number
    int t,n,req;
    cin>>t;

    //Find prime numbers till 10000
    sieve(10000);

    //Loop over all test cases
    while(t--) {

        //Take numbers and print result
        cin>>n>>req;
        cout<<check(n,req)<<endl;
    }
    return 0;
}
