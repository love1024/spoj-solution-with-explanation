#include<bits/stdc++.h>

using namespace std;

void print(int num) {

    //Print result for base numbers
    if(num == 3) {
        cout<<"2+2(0)";
        return;
    }if(num == 2) {
        cout<<"2";
        return;
    }
    if(num == 1) {
        cout<<"2(0)";
        return;
    };
    if(num == 0)
        return;

    //Else find the nearest power of 2 and that number
    int n = 1,c = 0;
    while(true) {
        if(n<<1 > num)
            break;
        n<<=1;
        c++;
    }

    //Call with that power of 2 further expand
    cout<<"2(";
    print(c);
    cout<<")";

    //Subtract from total number the nearest power of 2
    //and call again with that number
    num -= n;
    if(num != 0)
        cout<<"+";

    print(num);

}

int main() {

    //Main program
    int arr[] = {137, 1315, 73, 136, 255, 1384, 16385};
    for(int i=0;i<7;i++){
        cout<<arr[i]<<"=";
        print(arr[i]);
        cout<<endl;
    }
}
