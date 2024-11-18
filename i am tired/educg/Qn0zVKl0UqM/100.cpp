#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("card.in");
    ofstream fout("card.out");
    int T, A[100] = {0}, target = 0, differ[100] = {0};
    fin >> T;
    for (int i = 0; i < T; i++)
    {
        fin >> A[i];
        target += A[i];
    }
    target = target / T;
    for (int i = 0; i < T; i++)
    {
        differ[i] = target - A[i];
    }
    int j=0;
    for(int i = 0; i < T; i++){
        if(differ[i]!=0){
            differ[i+1]+=differ[i];
            differ[i]=0;
            j++;
        }
    }
    if(j==0){
        return 0;
    }
    fout<<j;
    return 0;
}