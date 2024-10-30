#include <iostream>
#include <algorithm>
using namespace std;
class square
{
public:
    short x1, x2, y1, y2;
    square(short x1i, short x2i, short y1i, short y2i)
    {
        this->x1 = x1i, this->x2 = x2i, this->y1 = y1i, this->y2 = y2i;
    }
    square() {}
    short left(short y, short left)
    {
        if (y < y2 && y >= y1)
        {
            if (x1 < left)
            {
                return x1;
            }
            else
            {
                return left;
            }
        }
        else
        {
            return left;
        }
    }
    short right(short y, short right)
    {
        if (y < y2 && y >= y1)
        {
            if (x2 > right)
            {
                return x2;
            }
            else
            {
                return right;
            }
        }
        else
        {
            return right;
        }
    }
    long heresize(short left, short right, short y)
    {
        if (y < y2 && y >= y1)
        {
        }
        else
        {
            return 0;
        }
    }
    void update (bool * line,short y){
        if(y<y2 && y>=y1){
            for(int i = x1;i<x2;i++){
                *(line+i)= 1;
            }
        }
    }
};
int main()
{
    short T;
    long size = 0;
    cin >> T;
    square sqset[T];
    short Y[2 * T], X[2 * T];
    short x1, x2, y1, y2,y;
    {
        
        for (short i = 0; i < T; i++)
        {
            cin >> x1 >> y1 >> x2 >> y2;
            sqset[i] = square(x1, x2, y1, y2);
            X[i] = x1, X[T + i] = x2, Y[i] = y1, Y[T + i] = y2;
        }
        sort(X, X + 2 * T);
        sort(Y, Y + 2 * T);
    }
    {
        long addsize;
        bool line[101];
        for (short i = 0; i < 2 * T; i++)
        {
            for (short j = 0; j < T; j++)
            {
                y2=sqset[j].y2,y1=sqset[j].y1,x2=sqset[j].x2,x1=sqset[j].x1;y=Y[i];
                if(y<y2 && y>=y1){
            for(int i = x1;i<x2;i++){
                *(line+i)= 1;
            }
        }
            }
            short add = Y[i+1]-Y[i];
            for (short j = 0;j<101;j++){
                if(line[j]){
                    size+=add;
                    
                }line[j] = 0;
            }
        }
    }
    cout << size;
    return 0;
}