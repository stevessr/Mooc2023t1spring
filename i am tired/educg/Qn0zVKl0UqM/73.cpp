#include <fstream>
#include <iostream>
#include <string>
#include <exception>
using namespace std;
bool isCharater(char ch)
{
    return ((ch <= 'Z' && ch >= 'A') || (ch <= 'z' && ch >= 'a') || (ch >= '0' && ch <= '9'));
}
int main()
{
    ifstream fin("in.c");
    char ch;
    string line;
    int zhushi = 0, row = 0;
    bool skip = false;
    while (getline(fin, line))
    {
        row++;
        skip = false;
        for (int i = 0; i < line.size(); i++)
        {
            while (!isCharater(line[i]))
            {
                if (line[i] == '/')
                {
                    if (line[i + 1] == '/')
                    {
                        skip = true;
                        break;
                    }
                    else if (line[i + 1] == '*')
                    {
                        i += 2;
                        if (i >= line.size())
                        {
                            getline(fin, line);
                            i = 0;
                            row++;
                        }
                        while (!(line[i] == '*' && line[i + 1] == '/'))
                        {
                            i++;
                            if (i >= line.size())
                            {
                                getline(fin, line);
                                i = 0;
                                row++;
                            }
                        }
                        i += 2;
                        if (i >= line.size())
                        {
                            getline(fin, line);
                            i = 0;
                            row++;
                        }
                    }
                }
                i++;
            }
            if (skip)
            {
                break;
            }
            try
            {
                if (line[i] == 'g' && line[i + 1] == 'e' && line[i + 2] == 't')
                {
                    i += 3;
                    if (line[i] == 's' && !isCharater(line[i + 1]))
                    {
                        cout << "gets:" << row << "," << i - 2 << endl;
                    }
                    else if (line[i] == 'c' && line[i + 1] == 'h' && line[i + 2] == 'a' && line[i + 3] == 'r' && !isCharater(line[i + 4]))
                    {
                        cout << "getchar:" << row << "," << i - 2 << endl;
                    }
                }
                else if (line[i] == 's')
                {
                    if (line[i + 1] == 'c')
                    {
                        if (line[i + 2] == 'a')
                        {
                            if (line[i + 3] == 'n')
                            {
                                if (line[i + 4] == 'f' && !isCharater(line[i + 5]))
                                {
                                    cout << "scanf:" << row << "," << i + 1 << endl;
                                }
                            }
                        }
                    }
                }
                else
                {
                    while (isCharater(line[i]))
                    {
                        i++;
                    }
                }
            }
            catch (exception e)
            {
            }
        }
    }
    return 0;
}