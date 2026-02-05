#include <stdio.h>

int nResult[40], firstResult[40], secondResult[40], remain = 0, skip;
long n;
void main()
{
    printf("Enter the positive integer n: ");
    scanf("%d", &n);
    while(n <= 0)
    {
        printf("Please re-enter n:");
        scanf("%d", &n);
    }
    for(int i = 0; i<40; i++)
    {
        nResult[i] = 0;
        firstResult[i] = 0;
        secondResult[i] = 0;
    }
    secondResult[0] = 1;
    printf("Thu tu\tGia tri\n");
    if(n>0)
    {
        printf("1 -\t0\n");
    }
    if(n>1)
    {
        printf("2 -\t1\n");
    }
    if(n>2)
    {
        for(int i = 3; i <= n; i++)
        {
            printf("%d -\t", i);
            for(int i = 0; i < 40; i++)
            {
                nResult[i] = firstResult[i] + secondResult[i] + remain;
                if(nResult[i] > 9)
                {
                    nResult[i] = nResult[i]%10;
                    remain = 1;
                }
                else remain = 0;
            }
            for(int i = 39; i>= 0; i--)
            {
                if(nResult[i] != 0)
                {
                    skip = i;
                    break;
                }
            }
            for(int i = skip; i >= 0; i--)
            {
                printf("%d", nResult[i]);
            }
            for(int i = 0; i < 40; i++)
            {
                firstResult[i] = secondResult[i];
                secondResult[i] = nResult[i];
            }
            printf("\n");
        }
    }
}