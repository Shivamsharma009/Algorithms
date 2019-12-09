/// write a program to Implement Knuth-Morris-Pratt Algorithm
#include<stdio.h>
#include<stdlib.h>     //Time-Complexity O(m+n)
#include<string.h>    // space Complexity O(m+n)

void ComputeLPSArray(char *pat,int M,int *lps)
{
 int len = 0;
 lps[0] = 0;
 int i =1;
 while(i<M)
 {
 	if(pat[i]==pat[len])
 	{
 		len++;
 		lps[i] = len;
 		i++;
 	}
 	else //(pat[i] != pat[len])
    {
    	if(len!=0)
    	{
    		len= lps[len-1];
    	}
    	else
    	{
    		lps[i] = 0;
    		i++;
    	}
    }
 }
}
void KMPSearch(char *pat,char *txt)
{
 int M = strlen(pat);
 int N = strlen(txt);
 int lps[M];
   ComputeLPSArray(pat,M,lps);
    int i =0;
   int j=0;

   while(i<N)
   {
   	if(pat[j] == txt[i]){
      j++;
      i++;
   	}
   	if(j == M){
   		printf("Found pattern at index %d\n",i - j);
   		j = lps[j  -1];
   	}
   	else if(i<N && pat[j] != txt[i]){
   		if(j!=0)
   			j = lps[j-1];
   		else
   			i++;
   	}
   }
}

int main()
{
	char txt[100], pat[100];
	printf("Enter text String\n");
	scanf("%s",txt);
	printf("Enter pattern String\n");
	scanf("%s",pat);
	KMPSearch(pat,txt);

	return 0;
}
