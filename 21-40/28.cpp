#include <iostream>
#include <vector>
using std::cout, std::endl, std::cin, std::string,std::vector;
int main()
{
    short lenth,result=0;
    cin >> lenth;
    vector<int> test;
    int chart[lenth], target;
    for (int i = 0; i < lenth; i++)
    {
        cin >> chart[i];
        test.push_back(chart[i]);
    }
    cin>>target;
    for (auto i : test ){
        if(i==target){
            result++;
        }
    }
    cout<<result;
    return 0;
}