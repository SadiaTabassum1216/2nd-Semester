#include<stdio.h>
#include<string.h>

void backtracking(char string[],int l,int r);

int shouldSwap(char str[], int start, int curr)
{
    int x=0;
	for (int i = start; i < curr; i++){
		if (str[i] == str[curr])
			x=1;
			break;
	}

	return x;
}


void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
    int l,r;
    char str[10];
    printf("Enter the string: ");
    gets(str);
    l=0;
    r=strlen(str)-1;
    backtracking(str,l,r);

    return 0;
}


void backtracking(char string[],int l,int r)
{
    int i=l;
if (l == r)
	printf("%s\n", string);
else
    {
    while(i<=r)
        {
        int check = shouldSwap(string, 0,i);
		if (check==0) {
        swap(string+l,string+i);
        backtracking(string,l+1,r);
        swap(string+l,string+i);
        i++;}
        }
    }
}

