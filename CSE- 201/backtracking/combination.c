// Program to print all combination of size r in an array of size n
#include<stdio.h>
#include<string.h>
void combination(char arr[],int n,int r,char data[]);

/* arr[] ---> Input Array
n	 ---> Size of input array
r	 ---> Size of a combination to be printed
index ---> Current index in data[]
data[] ---> Temporary array to store current combination
i	 ---> index of current element in arr[]	 */
void combination(char arr[], int n, int r, char data[])
{
	int i;
	//for()
}

// Driver program to test above functions
int main()
{
	char str[10];
	int r;
    printf("Enter the string: ");
    gets(str);

    printf("Enter the size: ");
    scanf("%d",&r);

	int n = strlen(str);
	char data[r];
	combination(str, n, r, data);
	return 0;
}
