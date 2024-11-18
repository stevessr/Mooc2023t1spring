#include <stdio.h>
int main()
{
 int i,n,lenofgets,maxOfscanf;
 int gets1[100];
 char line[100],ch;
 
 n=0;
 do{
  scanf("%d",&gets1[n++]);
  ch=getchar();/*get a char by the function getchar()*/
 }while(ch!='\n');
 gets(line);/*gets a line*/
 lenofgets=0;
 while(line[lenofgets]!='\0')
  lenofgets++;
 while((ch=getchar())!=EOF) ;
  i=1;
 maxOfscanf=gets1[0];
 while (i<n)
 {
  if(maxOfscanf<gets1[i])
   maxOfscanf=gets1[i];
 }
 printf("%d\n",maxOfscanf);
 return 0;
}