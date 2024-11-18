#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <cctype> // for ispunct and isdigit
#include <algorithm> // for any_of
using namespace std;

// Helper function to remove punctuation from a word
string removePunctuation(const string &word) {
    string cleaned_word;
    for (char c : word) {
        if (!ispunct(c)) { // Only add non-punctuation characters
            cleaned_word += c;
        }
    }
    return cleaned_word;
}

// Helper function to check if a word contains any digits
bool containsDigit(const string &word) {
    return any_of(word.begin(), word.end(), ::isdigit);
}

int main()
{
    ifstream file("crossin.txt");
    string line;
    
    // Unordered map to store word positions
    unordered_map<string, vector<string>> word_positions;
    // Vector to maintain the order of words as they appear
    vector<string> word_order;

    int line_number = 0;
    while (getline(file, line))
    {
        line_number++;
        int word_position = 1;
        stringstream ss(line);
        string word;
        
        // Process each word in the line
        while (ss >> word)
        {
            // Clean the word by removing punctuation
            string cleaned_word = removePunctuation(word);

            // Skip empty words or words containing digits
            if (cleaned_word.empty() || containsDigit(cleaned_word)) continue;

            // If this is the first time we encounter this word, add it to the order list
            if (word_positions.find(cleaned_word) == word_positions.end()) {
                word_order.push_back(cleaned_word);
            }

            // Format position as "(line_number,word_position)"
            string position = "(" + to_string(line_number) + "," + to_string(word_position) + ")";
            word_positions[cleaned_word].push_back(position);
            word_position++;
        }
    }

    // Output words in the order they first appeared in the text
    for (const auto &word : word_order)
    {
        cout << word << ": ";
        for (const auto &pos : word_positions[word])
        {
            cout << pos << ",";
        }
        cout << "\b " << endl; // Remove the trailing comma and add a space
    }

    return 0;
}
