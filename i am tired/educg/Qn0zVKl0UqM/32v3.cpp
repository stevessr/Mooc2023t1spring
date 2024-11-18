#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;

// Define the possible operations
map<string, pair<int, int> (*)(int, int, int, int)> operations;

pair<int, int> fillA(int a, int b, int Ca, int Cb) {
    return {Ca, b};
}

pair<int, int> fillB(int a, int b, int Ca, int Cb) {
    return {a, Cb};
}

pair<int, int> emptyA(int a, int b, int Ca, int Cb) {
    return {0, b};
}

pair<int, int> emptyB(int a, int b, int Ca, int Cb) {
    return {a, 0};
}

pair<int, int> pourAtoB(int a, int b, int Ca, int Cb) {
    int pourAmount = min(a, Cb - b);
    return {a - pourAmount, b + pourAmount};
}

pair<int, int> pourBtoA(int a, int b, int Ca, int Cb) {
    int pourAmount = min(b, Ca - a);
    return {a + pourAmount, b - pourAmount};
}

// Function to perform BFS and find the sequence of operations
vector<string> bfs(int Ca, int Cb, int N) {
    queue<pair<pair<int, int>, vector<string>>> q;  // Queue of (state, operation history)
    set<pair<int, int>> visited;  // Set to store visited states

    // Initial state is both jugs empty
    pair<int, int> start = {0, 0};
    q.push({start, {}});
    visited.insert(start);

    // Map operations
    operations["Fill A"] = fillA;
    operations["Fill B"] = fillB;
    operations["Empty A"] = emptyA;
    operations["Empty B"] = emptyB;
    operations["Pour A B"] = pourAtoB;
    operations["Pour B A"] = pourBtoA;

    // Perform BFS
    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        pair<int, int> current = front.first;
        vector<string> history = front.second;

        int a = current.first;
        int b = current.second;

        // If we have reached the desired state in B
        if (b == N) {
            history.push_back("Success");
            return history;
        }

        // Try all possible operations
        for (auto& op : operations) {
            pair<int, int> newState = op.second(a, b, Ca, Cb);

            if (visited.find(newState) == visited.end()) {
                visited.insert(newState);
                vector<string> newHistory = history;
                newHistory.push_back(op.first);
                q.push({newState, newHistory});
            }
        }
    }

    return {};  // In case no solution is found (though problem guarantees one solution)
}

int main() {
    int Ca, Cb, N;
    // Read the input
    ifstream infile("jugs.in");
    infile >> Ca >> Cb >> N;
    infile.close();

    // Perform BFS to find the sequence of operations
    vector<string> result = bfs(Ca, Cb, N);
ofstream outfile("jugs.out");
    // Output the result
    if (!result.empty()) {
        for (const string& op : result) {
            outfile << op << endl;
        }
    }
    outfile.close();

    return 0;   
}
