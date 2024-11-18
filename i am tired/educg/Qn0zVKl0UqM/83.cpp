#include <iostream>
#include <string>
#include <deque>

using namespace std;

string getMinNumber(string S, int N) {
    deque<char> dq;
    int keep = S.length() - N; 

    for (char c : S) {
        while (!dq.empty() && c < dq.back() && N > 0) {
            dq.pop_back();
            N--;
        }
        dq.push_back(c);
    }
    while (N > 0 && !dq.empty()) {
        dq.pop_back();
        N--;
    }
    string result;
    while (!dq.empty() && keep-- > 0) {
        result.push_back(dq.front());
        dq.pop_front();
    }
    //result.erase(0, result.find_first_not_of('0'));
    return result.empty() ? "0" : result; 
}

int main() {
    string S;
    int N;

    cin >> S >> N;

    cout << getMinNumber(S, N) << endl;

    return 0;
}
