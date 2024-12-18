#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(){
    int goup[3]={0,0,0};//" ","\t","\n"
    string str;
    while(getline(cin,str)){
        for(auto &i:str){
            switch (i)
            {
            case ' ':
                goup[0]++;
                break;
            case '\t':
                goup[1]++;
                break;
            case '\n':
                goup[2]++;
                break;
            default:
                break;
            }
        }
        goup[2]++;
    }
    cout<<goup[0]<<" "<<goup[1]<<" "<<goup[2]-1;
    return 0;

}