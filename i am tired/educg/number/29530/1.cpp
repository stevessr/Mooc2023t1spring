#include <iostream>
using namespace std;
int main()
{
    int m, n, M[11][11];
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> M[i][j];
        }
    }
    cout<<n<<" "<<m<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = m-1; j >=0; j--)
        {
            cout << M[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}