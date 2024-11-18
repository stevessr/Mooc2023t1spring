#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>  // For std::min with initializer list
using namespace std;

int main()
{
    ifstream fin("crossin.txt");
    ofstream fout("crossout.txt");

    string line, word;
    size_t start, end;

    while (getline(fin, line))  // Read each line from input file
    {
        start = 0;
        while (start < line.size())  // Loop through the line
        {
            // Find positions of next space, period, or comma
            size_t end_space = line.find(' ', start);
            size_t end_period = line.find('.', start);
            size_t end_comma = line.find(',', start);

            // Find the nearest delimiter position
            end = min({end_space, end_period, end_comma, line.size()});  // C++11 or later

            // Extract word between start and end (if any characters are found)
            if (end > start)
            {
                word = line.substr(start, end - start);  // Extract word
                fout << word << endl;                    // Write word to output file
                cout << word << endl;                    // Print word to console
            }
            start = end + 1;  // Move start to character after the delimiter
        }
    }

    return 0;
}
