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
    for(auto &k:results){
        for(int i=0;i<k;i++){
            cout<<"#";
        }
        cout<<endl;
    }
    return 0;
}