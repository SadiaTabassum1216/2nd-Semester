#include<stdio.h>
#include<string.h>
#include <stdlib.h>

struct encrypt
{
    char a;
    int code[];
};
struct encrypt str[100];
                        /*={{'b',{0}},
                        {'a',{0,1}},
                        {'d',{1,1,0}},
                        {'c',{1,1,1,0}},
                        {'e',{1,1,1,1,0}},
                        {'h',{1,1,1,1,1}}};*/

int main()
{
    char string[1000];
    int i;

    for(i=0;i<100;i++)
    {
        str[i].code=(int*)malloc(sizeof(int)*sizeof(code));
    }
    str[100]={{'b',{0}},
            {'a',{0,1}},
            {'d',{1,1,0}},
            {'c',{1,1,1,0}},
            {'e',{1,1,1,1,0}},
            {'h',{1,1,1,1,1}}};

  }

void EncodedData(char data)
{

}

