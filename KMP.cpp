#include <stdio.h>
#include <string.h>
char t[105],p[101];
int next[105];
void prefixNext()
{
	next[0]=0;
	int k = 0,i=1;
	while (i<strlen(p))
	{
		while (k>0&&p[k]!=p[i])
			k=next[k-1];
		if(p[k] == p[i])//说明p[0...k-1]共k个都匹配了
			k=k+1;
		next[i]=k;
		++i;
	}
}
void KMP()
{
	int pPoint=0;
	for (int i=0;i<=strlen(t)-strlen(p);++i)
	{
		while (pPoint!=0 && t[i]!=p[pPoint])
			pPoint = next[pPoint-1];
		if(t[i]==p[pPoint])
		{
			pPoint++;
			if (pPoint == strlen(p))
			{
				printf("%d\n",i-pPoint+1);
				//pPoint = 0;//上一个在s匹配的字符串,不能成为下一个匹配字符串的一部分
				pPoint = next[pPoint-1];//上一个在s匹配的字符串,也能成为下一个匹配字符串的一部分
			}
		}
	}
}
int main()
{
	//scanf("%s%s",t,p);
	strcpy(t,"ababacababababababbaabbababaabaababacabababababbcababbabababcababba");
	strcpy(p,"ababacab");
	prefixNext();
	KMP();
	return 0;
}