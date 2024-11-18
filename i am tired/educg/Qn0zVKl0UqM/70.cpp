#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class window
{
public:
    int place;
    int x1, y1, x2, y2;
    window(int PL, int X1, int Y1, int X2, int Y2) : place(PL), x1(X1), y1(Y1), x2(X2), y2(Y2) {}
    window() {}
    bool isfallon(int x, int y)
    {
        return ((x >= x1 && x <= x2) || (x <= x1 && x >= x2)) && ((y >= y1 && y <= y2) || (y <= y1 && y >= y2));
    }
};
int main()
{
    int T;
    cin >> T;
    vector<window> winv;
    int PL, x1, y1, x2, y2;
    for (int i = 0; i < T; ++i)
    {
        cin >> PL >> x1 >> y1 >> x2 >> y2;
        winv.push_back(window(PL, x1, y1, x2, y2));
    }
    int clickCount;
    cin >> clickCount;
    int clickX, clickY;
    while (clickCount--)
    {
        cin >> clickX >> clickY;
        for (int i = 0; i < T; i++)
        {
            if (winv[i].isfallon(clickX, clickY))
            {
                window clickedWindow = winv[i];
                winv.erase(winv.begin() + i);
                winv.insert(winv.begin(), clickedWindow);
                break;
            }
        }
    }
    for (int i = 0; i < T; i++)
    {
        cout << winv[i].place << " ";
    }
    cout << endl;

    return 0;
}
