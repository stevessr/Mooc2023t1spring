#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, s;
    cin >> n >> s;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    int total;
    for(auto &i:v){
        total+=i.first;
    }
    sort(v.begin(),v.end();
    if(total>s){
        
    }
    return 0;
}