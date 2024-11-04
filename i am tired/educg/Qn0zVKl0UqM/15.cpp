#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;  
    vector<int> sequence(N);
    for (int i = 0; i < N; i++) {
        cin >> sequence[i];
    }

    stack<int> stk;  
    int targetIndex = 0;  

    for (int i = 1; i <= N; i++) {
        stk.push(i);  

        while (!stk.empty() && stk.top() == sequence[targetIndex]) {
            stk.pop();      
            targetIndex++; 
        }
    }
    if (stk.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
