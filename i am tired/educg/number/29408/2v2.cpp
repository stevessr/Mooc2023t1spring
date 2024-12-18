#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

struct LetterCount {
    char letter;
    int count;
};

bool compare(const LetterCount& a, const LetterCount& b) {
    if (a.count != b.count) 
        return a.count > b.count;
    return a.letter < b.letter;
}

int main() {
    string line, text;
    while (getline(cin, line)) {
        text += line + '\n';
    }

    map<char, int> frequency;
    for (char ch : text) {
        if (islower(ch)) {
            frequency[ch]++;
        }
    }

    vector<LetterCount> counts;
    for (auto& entry : frequency) {
        counts.push_back({entry.first, entry.second});
    }
    sort(counts.begin(), counts.end(), compare);

    if (counts.empty()) {
        return 0;
    }

    int maxHeight = counts[0].count;

    vector<string> chart(maxHeight, string(counts.size(), ' '));
    for (size_t i = 0; i < counts.size(); ++i) {
        for (int j = 0; j < counts[i].count; ++j) {
            chart[maxHeight - 1 - j][i] = '#';
        }
    }

    for (const auto& row : chart) {
        cout << row << endl;
    }

    return 0;
}
