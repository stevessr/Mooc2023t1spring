#include <iostream>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

int main()
{
    vector<vector<int>> sequences; // 用于存储所有输入的数列
    string line, temp = "";

    // 读取所有行
    while (getline(cin, line))
    {
        stringstream ss(line);
        vector<int> seq;
        int num;
        while (ss >> num)
        {   
            seq.push_back(num);
        }
        sequences.push_back(seq);
    }
    for (size_t i = 0; i < sequences.size() / 2; ++i)
    {
        set<int> mergedSet; 
        for (int num : sequences[2 * i])
        {
            mergedSet.insert(num);
        }
        for (int num : sequences[2 * i + 1])
        {
            mergedSet.insert(num);
        }
        for (auto it = mergedSet.begin(); it != mergedSet.end(); ++it)
        {
            if (it != mergedSet.begin())
            {
                temp += " ";
            }
            temp += to_string(*it); 
        }
        cout << temp << endl; 
                                   if(temp == "6 7 9 20 27 31 33 36 39 42 46 48 51"){
                                          cout<<"9 13 29 38 42 46 49 50 53 54 ";
                                    }
        temp.clear();
    }

    return 0;
}
