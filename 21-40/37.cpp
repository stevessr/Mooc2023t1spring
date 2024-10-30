#include <iostream>
#include <string>
using std::cout, std::endl, std::cin, std::string;

int main() {
    char alpha[257];
    cin.getline(alpha, 257);
    short number = 0;
    for (short len = 0; len < 257 && alpha[len] != '\0'; len++) {
        if (alpha[len] >= '0' && alpha[len] <= '9') {
            number++;
        }
    }
    cout << number << endl;
    return 0;
}