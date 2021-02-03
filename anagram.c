#include <stdio.h>

#define SIZE 5

int main(void)
{
    int array_org[SIZE] = {1, 1, 1, 3, 4}; // 오리지널 값
    int array_ang[SIZE] = {2, 1, 1, 3, 1}; // 애너그램 비교할 값
    int i, j;
    int k = 0;


    for(i = 0; i < SIZE; i++)
    {

 
        for(j = 0 ; j < SIZE; j++)
        {
            if(array_ang[i] == array_org[j]) 
            {
                if( i == SIZE-1)           
                {
                    printf("True");
                    k = 1;
                }
                break;
            }
            else                          
            {
                if(j == SIZE -1)          
                {
                    printf("False");
                    k = 1;
                    break;
                }
                continue;
            }
        }
        if(k == 1)
        {
            break;
        }

    }

    return 0;
}
