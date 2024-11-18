#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
bool su(long value)
{
    double v = sqrt(value) + 1;
    for (int i = 2; i < v; i++)
    {
        if (value % i == 0)
        {
            return false;
        }
    }
    return true;
}
int upsidedown(int value)
{
    string str = to_string(value);
    reverse(str.begin(), str.end());
    return stoi(str);
}
bool absolute(int value)
{
    return (su(value) && su(upsidedown(value)));
}
int main(){
    int a,b;
    cin>>a>>b;
    for (;a<=b;a++){
        if(absolute(a)){
            cout<<a<<endl;
        }
    }
    return 0;
}