#include<stdio.h>
#include<string.h>
// d is the No of Charcters in the alphabet
#define d 256
 void search(char pat[],char txt[],int q)
{
  int M = strlen(pat);
  int N = strlen(txt);
  int i,j;
  int p = 0;
  int t =0;
  int h = 1;
  // this value of h would be pow(d,M-1)%q
  for(i= 0;i< M-1;i++)
  	h = (h*d)%q;
  for(i=0;i< M;i++)
  {
  	p = (d*p + pat[i])%q;
  	t = (d*t +txt[i])%q;
  }
  for(i=0;i<=N-M;i++){
   if(p==t){
   	for(j=0;j<M;j++){
   		if(txt[i+j] != pat[j])
   			break;
   	}
   	if(j==M)
   		printf("Pattern Found at index %d\n",i);
      }

    if(i<N-M)
    {
    	t = (d*(t-txt[i]*h)+txt[i+M])%q;
    	if(t<0)
    		t = (t+q);
    }
  }
}

int main()
{
	char txt[100],pat[100];
	printf("Enter text String");
	gets(txt);
	printf("Enter Pattern String");
	gets(pat);
	int q = 11;
	search(pat,txt,q);
	return 0;
}
