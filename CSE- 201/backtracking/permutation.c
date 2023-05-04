#include<stdio.h>
#include<string.h>

void permutation(char string[],int l,int r);
void swap(char *x, char *y);


int main()
{
    int l,r;
    char str[10];
    printf("Enter the string: ");
    gets(str);
    l=0;
    r=strlen(str)-1;
    permutation(str,l,r);

    return 0;
}


void permutation(char string[],int l,int r)
{
    int i=l;
if (l == r)
	printf("%s\n", string);
else
    {
    while(i<=r)
        {
        swap(string+l,string+i);
        permutation(string,l+1,r);
        swap(string+l,string+i);
        i++;
        }
    }
}

void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
