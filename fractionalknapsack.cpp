#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value, weight;
    Item(int value, int weight){
        this->value=value;
        this->weight=weight;
    }
};

bool comp(Item a, Item b){
    double r1 = (double)a.value/(double)a.weight;
    double r2 = (double)b.value/(double)b.weight;
    return (r1>r2);
}

double fractionalKnapsack(int W, Item arr[], int n){
    sort(arr, arr+n, comp);
    double finalValue=0.0;
    for(int i=0; i<n; i++){
        if(arr[i].weight<=W){
            finalValue+=(double)arr[i].value;
            W-=arr[i].weight;
        }
        else{
            finalValue+=arr[i].value * ((double)W/(double)arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main(){
    int W=50;
    Item arr[]={ {60, 10}, {100, 20}, {120, 30}};
    cout<<fractionalKnapsack(W, arr, 3)<<"\n";
    return 0;
}