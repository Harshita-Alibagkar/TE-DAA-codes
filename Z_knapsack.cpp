#include<iostream>
using namespace std;

int knapsack(int weights[], int values[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    // Initialize the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i-1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

// int zknapsack(int weights[], int profits[], int n, int capacity)
// {
//     int dp1[n+1][capacity+1];
//     for(int i = 0; i <= n; i++)
//         for(int j = 0; j <= capacity; j++)
//             if(i == 0|| j == 0)
//             {
//                 dp1[i][j] = 0;
//             }
//             else if(weights[i-1] <= j)
//             {
//                 dp1[i][j] = max(dp1[i-1][j - weights[i-1]]+ profits[i-1], dp1[i-1][j]);
//             }
//             else
//             {
//                 dp1[i][j] = dp1[i-1][j];
//             }
//     return dp1[n][capacity];
// }

int main() {
    int w, v, capacity;
    cout<<"Enter the no. of weights:"<<endl;
    cin>>w;
    int weights[w];
    int values[w];
    cout<<"Enter the weights:"<<endl;
    for(int i = 0; i < w; i++)
    {
        cin>>weights[i];
    }
    cout<<"Enter the profits:"<<endl;
    for(int i = 0; i < w; i++)
    {
        cin>>values[i];
    }
    // int weights[] = {5, 10, 15, 22, 25};
    // int values[] = {30, 40, 45, 77, 90};
    cout<<"Enter the knapsack's capacity:\n";
    cin>>capacity;

    int maxProfit = knapsack(weights, values, w, capacity);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
