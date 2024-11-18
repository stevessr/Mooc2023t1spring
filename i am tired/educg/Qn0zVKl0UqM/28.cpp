#include <iostream>
using namespace std;
int common(int a, int b)
{
    if(a%b==0){
        return b;
    }else{
        return common(b,a%b);
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    int s = common(a, b);
    cout << a / s << " " << b / s;
    return 0;
}