#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string defiline, useline;
    getline(cin, defiline); 
    getline(cin, useline); 
    
    unordered_set<string> defi;      
    vector<string> defOrder;
    
    for (int i = 0, itemp; i < defiline.size();) {
        while (i < defiline.size() && !(isalpha(defiline[i]) || defiline[i] == '_')) i++;
        if (i >= defiline.size()) break;

        itemp = i;

        while (i < defiline.size() && (isalnum(defiline[i]) || defiline[i] == '_')) i++;

        string var = defiline.substr(itemp, i - itemp);
        defi.insert(var);
        defOrder.push_back(var);
    }

    unordered_set<string> used; 
    vector<string> result; 

    for (int i = 0, itemp; i < useline.size();) {
        while (i < useline.size() && !(isalpha(useline[i]) || useline[i] == '_')) i++;
        if (i >= useline.size()) break;

        itemp = i;

        while (i < useline.size() && (isalnum(useline[i]) || useline[i] == '_')) i++;

        string var = useline.substr(itemp, i - itemp);

        if (defi.count(var) && used.count(var) == 0) {
            used.insert(var);
            result.push_back(var);
        }
    }
    set<string> resultSet(result.begin(), result.end());
    for(auto i=defOrder.begin();i!=defOrder.end();i++){
        if(resultSet.find(*i)!=resultSet.end()){
            cout<<*i<<" ";
        }
    }
    cout << endl;

    return 0;
}
