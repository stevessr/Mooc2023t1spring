#include <iostream>
#include <set>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int result[26] = {0};
    string str;
    while (getline(cin, str))
    {
        for (auto &i : str)
        {
            if (i <= 'z' && i >= 'a')
            {
                result[i - 'a']++;
            }
        }
    }
    set<int> results;
    for(auto &j:result){
        results.insert(j);
    }
    int minr = max(*results.begin(),1) , maxr = *results.rbegin();
    for(int k=minr;k<=maxr;k++){
        for(int i=0;i<(2*k-1);i++){
            cout<<"#";
        }
        for(int i=2*(maxr-k)-1;i>0;i--)
        cout<<endl;
    }
    return 0;
}