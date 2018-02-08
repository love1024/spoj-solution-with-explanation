#include<bits/stdc++.h>


using namespace std;

//Merge sort to find inversion count
long long inv = 0;
void mergeArray(int arr[],int s,int m,int e) {
    int i = s,j = m+1,k=0;
    int temp[e-s+1];

    while(i <= m && j <= e) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
            //Add all elements to inversion as its smaller than all remaining
            inv += (m-i+1);
        }
        k++;
    }
    while(i <= m) {
        temp[k] = arr[i];
        i++,k++;
    }
    while(j <= e) {
        temp[k] = arr[j];
        j++,k++;
    }
    for(int i=0;i<=e-s;i++) {
        arr[i+s] = temp[i];
    }

}

void mergeSort(int arr[],int i,int j) {
    if(i >= j)
        return;
    int m = (i+j)/2;
    mergeSort(arr,i,m);
    mergeSort(arr,m+1,j);
    mergeArray(arr,i,m,j);
}

int main() {
    int t,n;
    cin>>t;

    while(t--) {

        //Insert all second line worlds in map and
        //Thus create an array of positions which can
        //be used to find inversion count
        cin>>n;
        vector<string> words(n);
        map<string,int> mp;
        string str;
        inv = 0;
        int vec[n];

        for(int i=0;i<n;i++) {
            cin>>words[i];
        }

        for(int i=0;i<n;i++) {
            cin>>str;
            mp[str] = i;
        }

        for(int i=0;i<n;i++) {
            vec[i] = mp[words[i]];
        }

        mergeSort(vec,0,n-1);
        cout<<inv<<endl;
    }
}
