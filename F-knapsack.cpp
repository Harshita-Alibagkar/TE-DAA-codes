#include<bits/stdc++.h>
using namespace std;

typedef struct Item
{
    int weight, profit;
}Item;

bool compare(Item a, Item b)
{
    double r1 = (double)a.profit/a.weight;
    double r2 = (double)b.profit/b.weight;
    return r1 > r2;
}

int fractional(Item arr[], int w, int n)
{
    //Sorting the arra by reference 
    sort(arr, arr+n, compare);

    int currweight = 0;
    int finalprofit = 0;
    int accepted[n];
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(currweight + arr[i].weight <= w)
        {
            currweight += arr[i].weight;
            finalprofit += arr[i].profit;
            accepted[i] = arr[i].weight;
            count++;
        }
        else
        {
            int remain = w - currweight;
            currweight += remain;
            finalprofit += (arr[i].profit)*remain/arr[i].weight;
            accepted[i] = remain;
            count++;
        }
    }

    cout<<"Weights of the Accepted objects are:\n";
    for(int i = 0; i < count; i++)
    {
        cout<<accepted[i]<<" ";
    }
    cout<<endl;

    cout<<"Maximum profit is: "<<finalprofit;
}

int main()
{
    int n, w;
    cout<<"Enter the capacity of knapsack:\n";
    cin>>w;
    cout<<"Enter the number of objects:\n";
    cin>>n;
    Item arr[n];
    cout<<"Enter the weight and profit of each object:\n";
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i].weight>>arr[i].profit;
    }

    fractional(arr, w, n);
}