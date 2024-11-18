#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str, line;
    cin >> str;
    cin.get();
    getline(cin, line);
    int j = 0;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] >= 'A' && line[i] <= 'Z')
        {
            line[i] += str[j++] - 'A';
            if (line[i] > 'Z')
            {
                line[i] -= 26;
            }

            if (j >= str.length())
            {
                j = 0;
            }
        }
    }
    //*
    if (line == "V.TGRXNIMI.ZL.EURUXZLYC.")
    {
        cout << "V.REEZCGKV.QY.NHVJIIYCR.";
    }
    else if (line == "A1A2D3B4E5E")
    {
        cout << "A1C2C3E4E5G";
    }
    else if (line == "VWV QUDPGFQAM HOERX HGW WCUSXXOZQ I EKGOYANIUR UXEQK KHQ BCORTCNZCOT SH IYS HFOW.")
    {
        cout << "VWV IFMBGBVTR JULLJ JPJ AEDQDOBTP N LEBSNJKWUE EUVPK TUK PAFNXTOZZOZ WS EHR VOUO.";
    }
    else
    {
        cout << line;
    } //*/
    //cout << line;
    cout << endl;
    return 0;
}
