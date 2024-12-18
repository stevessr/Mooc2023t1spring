//求差集
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
    set<int> b;
    vector<int> a;
    int temp;
    while(cin>>temp && temp!=-1){
        a.push_back(temp);
    }
    while(cin>>temp && temp!=-1){
        b.insert(temp);
    }
    for(auto &i:a){
        if(b.find(i)==b.end()){
            cout<<i<<" ";
        }
    }
    return 0;
}
