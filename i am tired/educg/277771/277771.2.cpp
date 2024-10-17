#include <iostream>

int main()
{
    long long a, b;
    std::cin >> a >> b;
    if (b > 0)
    {
        std::cout
            << a << "+" << b << "=" << a + b << std::endl
            << a << "*" << b << "=" << a * b << std::endl
            << a << "/" << b << "=" << a / b << std::endl
            << a << "%" << b << "=" << a % b << std::endl;
    }
    else
    {
                std::cout
            << a << "+(" << b << ")=" << a + b << std::endl
            << a << "*(" << b << ")=" << a * b << std::endl
            << a << "/(" << b << ")=" << a / b << std::endl
            << a << "%(" << b << ")=" << a % b << std::endl;
    }
    return 0;
}