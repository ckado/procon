#include <stdio.h>
int A[999999],W[999999];
long long M(int l,int r){
	if(l+1>=r)return 0;
	if(l+2==r){
		if(A[l]<=A[l+1])return 0;
		int z=A[l];A[l]=A[l+1];A[l+1]=z;
		return 1;
	}
	int m = (l+r)/2,i=l, j=m, k=l;
	long long cl=M(l, m),cr=M(m,r),c=0;
	while(i<m&&j<r){
		if(A[i]<=A[j])W[k++]=A[i++];
		else{
			W[k++]=A[j++];
			c+=m-i;
		}
	}
	while(i<m)W[k++]=A[i++];
	while(j<r)W[k++]=A[j++];
	for(i=l;i<r;i++)A[i]=W[i];
	return cl+cr+c;
}
int main(){
	int T,i,N;
	//PKU2299,aizu0167: バブルソートの交換回数
	//for(;scanf("%d",&N),N;printf("%lld\n",M(0,N)))for(i=0;i<N;i++)scanf("%d",A+i);
	//hackerrank~runningtime,aizuALDS1~5D
	//scanf("%d",&N);for(i=0;i<N;i++)scanf("%d",A+i);printf("%lld\n",M(0,N));
	//spojINVCNT,hackerrank~insertionsort
	//for(scanf("%d",&T);T--;printf("%lld\n",M(0,N)))for(scanf("%d",&N),i=0;i<N;++i)scanf("%d",A+i);
	//codeiq4322: 光線の交差数
	for(N=0;~scanf("%d",A+N);N++);printf("%lld\n",M(0,N));
	//kcs1009KK: Nパズルの可解性
	//for(i=0;~(N=getchar());)if('0'<N&&N<'9')A[i++]=N-'0';
	//puts(M(0,i)%2?"lmpossible":"Possible"); //"l"? lol!
	//atcoderutpc2014F: パリティ
	//for(scanf("%d",&T),getchar();T--;printf("%lld\n",M(0,N)%2))for(N=0;~(A[N]=getchar())&&A[N]!='\n';N++);
	//kcs1031A
	scanf("%d%d",&N,&T);for(i=0;i<N;i++)scanf("%d",A+i);N=M(0,N)-T;printf("%d\n",N>0?N:0);
	return 0;
}