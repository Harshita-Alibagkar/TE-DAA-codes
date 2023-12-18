#include<iostream>
#include<vector>
using namespace std;

bool flag = false;

void Subset(int i, int n, int ts, int set[], vector<int> subset)
{
    if(ts == 0)
    {
        flag = true;
        cout << "[ ";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i] << " ";
        }
        cout << "]" << endl;
        return;
    }

    if(i == n)
        return;

    Subset(i+1, n, ts, set, subset);

    cout<<"Including"<<set[i]<<endl;
    subset.push_back(set[i]);
    Subset(i+1, n, ts - set[i], set, subset);
    subset.pop_back();
}

int main()
{
    int n, ts;
    cout<<"Enter set elements number:\n";
    cin>>n;
    int set[n];
    for(int i = 0; i < n; i++)
    {
        cin>>set[i];
    }
    cout<<"Target sum:\n";
    cin>>ts;

    vector<int> subset;
    cout<<"Output:\n";
    Subset(0,n,ts,set,subset);

    if(!flag)
        cout<<"No subset\n";

    return 0;
}