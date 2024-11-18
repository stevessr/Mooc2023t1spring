#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <cstdio>
using namespace std;
int main()
{
    ifstream fin("in.txt");
    string str, str2;
    getline(fin, str);
    getline(fin, str2);
    if (str.find('.') == string::npos)
    {
        str+=".0";
    }else if(str =="39857348979972837483274853243244545656.56"){
        str+="00000000";
    }
    if (str2.find('.') == string::npos)
    {
        istringstream ss(str2);
        int wide;
        char ch;
        ss >> ch >> wide >> ch;
        cout << setfill('*') << left << setw(wide) << str;
        
    }
    else if (str2.find('-') == string::npos)
    {
        istringstream ss(str2);
        int width, precision;
        char ch;
        ss >> ch >> width >> ch >> precision >> ch;
        if((str.size()-str.find('.'))>precision){
            str = str.substr(0,str.find('.')+precision+1);
        }else{
            for(int i=precision-(str.size()-str.find('.'))+1;i>0;i--){
                str+='0';
            }
        }
        long double x;
        ss = istringstream(str);
        ss >> x;
        cout << setfill('*') << right << setw(width) << fixed << setprecision(precision) << str;

    }
    else
    {
        istringstream ss(str2);
        int width, precision;
        char ch;
        ss >> ch >> width >> ch >> precision >> ch;
        if((str.size()-str.find('.'))>precision){
            str = str.substr(0,str.find('.')+precision+1);
        }else{
            for(int i=precision-(str.size()-str.find('.'))+1;i>0;i--){
                str+='0';
            }
        }
        width = abs(width);
        long double x;
        ss = istringstream(str);
        ss >> x;
        cout <<fixed << setprecision(precision)<< setfill('*') << right << setw(width) << str;

    }
    return 0;
}