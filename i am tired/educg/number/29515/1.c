#include <stdio.h>
#include <stdbool.h>
int main()
{
    char buff[255], ch;
    
    FILE * fin = fopen("trans.in","r+"),*fout = fopen("trans.out","w+");
    fgets(buff,255, fin);
    int j = -1;
    int num[40] = {0};
    bool isfirstnumber = true;
    for (int i = 0; buff[i] != '\0'; i++)
    {
        ch = buff[i];
        if (ch <= '9' && ch >= '0')
        {
            if (isfirstnumber == true)
            {
                isfirstnumber = false;
                j++;
                num[j] = ch - '0';
            }
            else
            {
                num[j] = num[j] * 10 + ch - '0';
            }
        }
        else
        {
            isfirstnumber = true;
            continue;
        }
    }
    fprintf(fout,"%d\n", j+1);
    for(int i=0;i<=j;i++){
        fprintf(fout,"%d ",num[i]);
    }
    return 0;
}