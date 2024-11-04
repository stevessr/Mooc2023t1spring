#include<set>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
set<int> s1,s2;
std::vector<int> union_result;
int T,temp;
cin>>T;
while(T--){
    cin>>temp;
    s1.insert(temp);
}
cin>>T;
while(T--){
    cin>>temp;
    s2.insert(temp);
}
set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),back_inserter(union_result));
if(union_result.empty()){
    cout<<"No Answer";
}else{
    for (auto it = union_result.rbegin(); it != union_result.rend(); ++it) {
        std::cout << *it << " ";
    }
}
    return 0;
}