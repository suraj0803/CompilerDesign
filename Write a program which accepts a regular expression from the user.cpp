/*Write a program which accepts a regular expression from the user
and generates a regular grammar which is equivalent to the R.E.
entered by user. The grammar will be printed to a text file, with
only one production rule in each line. Also, make sure that all
production rules are
displayed in compact forms e.g. the production rules: S--&gt; aB, S--
&gt; cd S- -&gt; PQ Should be written as S--&gt; aB | cd | PQ And not as
three different production rules. Also, there should not be any
repetition of production rules.*/

#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main() {
    string str[50];
    string s[50];
intn,i,j,k,index;
int a [26]={0};
cout<<"\n How many production rule you want to enter? "<<endl;
cin>>n;

cout<<"Enter production :"<<endl;
     k=-1;

    for(i=0;i<n;i++)
    {
        if(i==0) getline(cin,str[i]);

cout<<"["<<i+1<<"] : ";
getline(cin,str[i]);
if(int(str[i][0])<65 || int(str[i][0])>91)
        {
cout<<"variables cannot be smallcase "<<endl;
            return 0;
        }
        a[int(str[i][0]) -65]++;

        if(a[int(str[i][0]) -65]>1)
        {
            j=0;
           for(j=0;j<=k;j++)
            {
                if(s[j][0]== str[i][0])
                {
                    index=j;
                    break;
                }
            }
            if(s[index].find(str[i].substr(2))== string::npos)
            {
                string st = str[i].substr(2);
                s[index] += '/' + st;
            }
        }
        else
        {
++k;
            s[k] = str[i];
        }
    }
cout<<"Input you entered"<<endl;
     for(i=0;i<n;i++)
    {
cout<<"["<<i+1<<"] ";
cout<<str[i]<<endl;
    }
cout<<"Output: "<<endl;
    n=k;
     for(k=0;k<=n;k++)
    {
cout<<"["<<k+1<<"] ";
cout<<s[k]<<endl;
    }
return 0;
}



