#include<bits/stdc++.h>

using namespace std;

//Storage for bitmap
int bm[185][185];

//Node to store position of bit in map
class Node
{
public:

    //Row and column position of bit
    int r,c;
    Node(int r,int c)
    {
        this->r = r;
        this->c = c;
    }
};

int main()
{

    //Variable to store input
    int t,n,m;

    //Take number of test cases
    cin>>t;

    //Loop over all test cases
    while(t--)
    {
        //Take rows and columns
        cin>>n>>m;

        //Take a queue and string
        queue<Node> que;
        string str;

        //Loop over all rows
        for(int i=0; i<n; i++)
        {
            //Loop over a column
            cin>>str;
            for(int j=0; j<m; j++)
            {
                //If it is 1 then it has already 0 distance else make it max
                bm[i][j] = (str[j]=='0')?INT_MAX:0;

                //If it is 1 put it in queue
                if(bm[i][j] == 0)
                    que.push(Node(i,j));
            }
        }

        //While there are places left in map to fill
        while(!que.empty())
        {

            //Take the position of current bit
            int r = que.front().r, c = que.front().c;
            que.pop();

            //Check all its 8 neighbor to see whether it can update them
            for(int k=-1; k<=1; k++)
            {
                for(int l=-1; l<=1; l++)
                {
                    //If the neighbor position is valid
                    if(r+k >= 0 && r+k < n && c+l >=0 && c+l < m )
                    {

                        //If the current bit can make distance of its neighbor less
                        //than previous distance
                        if(bm[r][c] + abs(k) + abs(l) < bm[r+k][c+l]) {

                            //Update the neighbor and put neighbor in queue
                            //So that it can further update its neighbor
                            bm[r+k][c+l] = bm[r][c] + abs(k) + abs(l);
                            que.push(Node(r+k,c+l));
                        }
                    }
                }
            }
        }

        //Print the result
        for(int i=0; i<n; i++,cout<<endl)
            for(int j=0; j<m; j++)
                cout<<bm[i][j]<<" ";
    }
}
