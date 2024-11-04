#include <iostream>
#include <string>
#include <vector>
#include "bigint.h"
// download from https://github.com/rgroshanrg/bigint , then extract the zip file, then copy the folder to your project directory, then include the folder in your project.
int main()
{
    bigint M, N;
    char ch;
    std::cin >> M >> ch >> N;
    switch (ch)
    {
    case '+':
        std::cout << M + N;
        break;
    case '-':
        std::cout << M - N;
        break;
    case '*':
        std::cout << M * N;
        break;
    default:
        std::cout << "Unexpected Action!";
    }
    return 0;
}
