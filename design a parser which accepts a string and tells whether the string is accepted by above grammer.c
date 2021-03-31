/*Consider the following grammar: S->aS, S->Sb, S->ab. Following any suitable parsing technique
(prefer topdown), design a parser which accepts a string and tells whether the string is accepted by
above grammar or not.*/

#include<stdio.h>
#include<string.h>
intcan_be_generated(char *str)
{
intlen=strlen(str);
int flag=1;
inti=0;
    while(1){
        if(((i+2)<=(len-1)) &&(str[i]=='a' &&str[i+1]=='b' &&str[i+2]=='b')){
i=i+3;
            continue;
        }
        else if(((i+1)<=(len-1)) && (str[i]=='a' &&str[i+1]=='b')){
i=i+2;
            continue;
        }
        else if((i<=(len-1)) && (str[i]=='a')){
i=i+1;
            continue;
        }
        else if((i==len)&&(str[i]=='\0')){
            break;
        }
        else{
            flag=0;
            break;
        }
    }
    if(flag==0){
        return 0;
    }
    else
printf("\n accepted \n");
}

int main(){
printf("The grammar is: S->aS, S->Sb, S->ab\n");
	printf("Enter the string to be checked:\n");
	printf("ab");
printf(" %d ",can_be_generated("ab"));

return 0;
}

