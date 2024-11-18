#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    cin >> T;
    vector<int> team, river(T);
    {
        int temp, M = T;
        while (M--)
        {
            cin >> temp;
            team.push_back(temp);
        }
    }
    int cost = 0;
    int todo = T, end = T - 1;
    if (T == 1)
    {
        cout << team[0];
        return 0;
    }
    else if (T == 2)
    {
        cout << max(team[0], team[1]);
        return 0;
    }
    else if (T == 3)
    {
        cout << team[0] + team[1] + team[2];
        return 0;
    }
    while (todo)
    {
        cost+=team[1];
        todo-=2;
        if(todo==0){
            break;
        }
        cost+=team[0];
        todo+=1;
        if(todo==0){
            break;
        }
        cost+=team[end];
        todo-=2;
        if(todo==0){
            break;
        }
        cost+=team[1];
        todo+=1;
        end-=2;
    }
    cout << cost;
    return 0;
}