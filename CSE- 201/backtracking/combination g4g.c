// Program to print all combination of size r in an array of size n
#include<stdio.h>
#include<string.h>
void combination(char arr[],int n,int r,int index,char data[],int i);

/* arr[] ---> Input Array
n	 ---> Size of input array
r	 ---> Size of a combination to be printed
index ---> Current index in data[]
data[] ---> Temporary array to store current combination
i	 ---> index of current element in arr[]	 */
void combination(char arr[], int n, int r, int index, char data[], int i)
{
	// Current cobination is ready, print it
	if (index == r)
	{
		for (int j=0; j<r; j++)
			printf("%c ",data[j]);
		printf("\n");
		return;
	}

	// When no more elements are there to put in data[]
	if (i >= n)
		return;

	// current is included, put next at next location
	data[index] = arr[i];
	combination(arr, n, r, index+1, data, i+1);

	// current is excluded, replace it with next (Note that
	// i+1 is passed, but index is not changed)
	combination(arr, n, r, index, data, i+1);
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
	combination(str, n, r, 0, data, 0);
	return 0;
}
