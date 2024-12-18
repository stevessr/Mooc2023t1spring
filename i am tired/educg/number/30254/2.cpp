// 阶乘和数（正序）
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int number;
    cin >> number;
    string str = to_string(number);
    vector<short> num;
    for (auto &i : str)
    {
        num.push_back(i-'0');
    }
    int cover=0;
    int jie[]={1,1,2,6,24,120,720,5040,40320,362880};
    cout<<number<<",";
    bool first = true;
    for(auto &j:num){
        cover+=jie[j];
        if(first){
            first = false;
        }else{
            cout<<"+";
        }
        cout<<j<<"!";
    }
    cout<<"="<<cover<<endl;
    if(cover == number){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}