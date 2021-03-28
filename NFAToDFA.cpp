/* Program to convert NFA to DFA*/
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
char nfa[50][50],s[20],st[10][20],eclos[20],input[20];
int x,e,top=0,topd=0,n=0,ns,nos,in;
int checke(char a)
{
int i;
for(i=0;i<e;i++)
{
if(eclos[i]==a)
return i;
}
return -1;
}
int check(char a)
{
int i;
for(i=0;i<in;i++)
{
if(input[i]==a)
return i;
}
return -1;
}
void push(char a)
{
s[top]=a;
top++;
}
char pop()
{
top--;
return s[top];
}
void pushd(char *a)
{
strcpy(st[topd],a);
topd++;
}

char *popd()
{
topd--;
return st[topd];
}
int ctoi(char a)
{
int i=a-48;
return i;
}
char itoc(int a)
{
char i=a+48;
return i;
}
char *eclosure(char *a)
{
int i,j;
char c;
for(i=0;i<strlen(a);i++)
push(a[i]);
e=strlen(a);
strcpy(eclos,a);
while(top!=0)
{
c=pop();
for(j=0;j<ns;j++)
{
if(nfa[ctoi(c)][j]=='e')
{
if(check(itoc(j))==-1)
{
eclos[e]=itoc(j);
push(eclos[e]);
e++;
}
}
}
}
eclos[e]='\0';
return eclos;
}

int main()
{
int i,j,k,count;
char ec[20],a[20],b[20],c[20],dstates[10][10];
cout<<"Enter the number of states"<<endl;
cin>>ns;
for(i=0;i<ns;i++)
{
for(j=0;j<ns;j++)
{
cout<<"Move["<<i<<"]["<<j<<"]";
cin>>nfa[i][j];
if(nfa[i][j]!='-'&&nfa[i][j]!='e')
{
if((check(nfa[i][j]))==-1)
input[in++]=nfa[i][j];
}
}
}
topd=0;
nos=0;
c[0]=itoc(0);
c[1]='\0';
pushd(eclosure(c));
strcpy(dstates[nos],eclosure(c));
for(x=0;x<in;x++)
cout<<"\t"<<input[x];
cout<<"\n";
while(topd>0)
{
strcpy(a,popd());
cout<<a<<"\t";
for(i=0;i<in;i++)
{
int len=0;
for(j=0;j<strlen(a);j++)
{
int x=ctoi(a[j]);
for(k=0;k<ns;k++)
{
if(nfa[x][k]==input[i])
ec[len++]=itoc(k);
}
}
ec[len]='\0';
strcpy(b,eclosure(ec));
count=0;
for(j=0;j<=nos;j++)
{
if(strcmp(dstates[j],b)==0)
count++;
}
if(count==0)
{
if(b[0]!='\0')
{
nos++;
pushd(b);
strcpy(dstates[nos],b);
}
}
cout<<b<<"\t";
}
cout<<endl;
}
return 0;
}



