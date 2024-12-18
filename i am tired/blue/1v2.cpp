#include<iostream>
using namespace std;
int ans=0,a[26],r=0,t=0;
void pd(){
	if(!((a[1]+a[2]+a[3]+a[4]+a[5])%5))return;
	if(!((a[6]+a[7]+a[8]+a[9]+a[10])%5))return;
	if(!((a[11]+a[12]+a[13]+a[14]+a[15])%5))return;
	if(!((a[16]+a[17]+a[18]+a[19]+a[20])%5))return;
	if(!((a[21]+a[22]+a[23]+a[24]+a[25])%5))return;
	if(!((a[1]+a[6]+a[11]+a[16]+a[21])%5))return;
	if(!((a[2]+a[7]+a[12]+a[17]+a[22])%5))return;
	if(!((a[3]+a[8]+a[13]+a[18]+a[23])%5))return;
	if(!((a[4]+a[9]+a[14]+a[19]+a[24])%5))return;
	if(!((a[5]+a[10]+a[15]+a[20]+a[25])%5))return;
	if(!((a[1]+a[7]+a[13]+a[19]+a[25])%5))return;
	if(!((a[5]+a[9]+a[13]+a[17]+a[21])%5))return;
	ans++;
}
void dfs(int k){
	if(k==26){
		pd();
	}
	if(r<=12){
		a[k]=1;
		r++;
		dfs(k+1);
		r--;
	}
	if(t<=11){
		a[k]=0;
		t++;
		dfs(k+1);
		t--;
	}
}
int main(){
	dfs(1);
	cout<<ans;
	return 0;
}