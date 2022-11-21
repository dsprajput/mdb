#include <bits/stdc++.h>
using namespace std;

struct job{
    string name;
    int profit;
    int deadline;
};

bool comparision(job a, job b){
    return (a.profit>b.profit);
}

void printJobScheduling(job arr[], int n){
    sort(arr, arr+n, comparision);
    int result[n];
    bool slot[n]={false};
    for(int i=0; i<n; i++){
        for(int j=min(arr[i].deadline, n)-1; j>=0; j--){
            if(slot[j]==false){
                result[j]=i;
                slot[j]=true;
                break;
            }
        }
    }

    for(int i=0; i<n; i++){
        if(slot[i]){
            cout<<arr[result[i]].name<<" ";
        }
    }
}

int main(){
    job arr[]={{"Eat", 100, 2},
            {"Sleep", 27, 1},
            {"Walk", 20, 3},
            {"Talk", 15, 2},
            {"Listen", 10, 1}
    };

    printJobScheduling(arr, 5);
    return 0;
    
}