#include <string>
#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    ///*
    // ifstream fin("morse.in");
    // ofstream fout("morse.out");
    ifstream fin("card.in");
    ofstream fout("card.out");
    string str;
    while (getline(fin, str))
    {
        fout << str << "\n";
    }
    // fout<<"?";
    while (getline(fin, str))
    {
        fout << str << "\n";
    } //*/
    // cout<<"10\n1 0 10 10 0\n2 0 20 20 0\n3 0 30 30 0\n4 0 40 40 0\n5 0 50 50 0\n6 0 60 60 0\n7 0 70 70 0\n8 0 80 80 0\n9 0 90 90 0\n10 0 100 100 0\n5\n0 0\n20 20\n10 10\n12 12\n40 40\n\n";
    return 0;
}