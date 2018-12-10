#include<stdio.h>
int main()
{
    int num;
    int a1,a2,a3,a5;
    double a4;
    int a4t;
    int sym;
    int N,i;
    bool is[5];
    for(i=0;i<5;++i)
        is[i] = false;
    scanf("%d",&N);
    sym = 1;
    a1=0,a2=0,a3=0,a4=0,a5=0;
    a4t=0;
    for(i=0;i<N;i++)
    {
        scanf("%d",&num);
        is[num%5] = true;
        switch(num%5)
        {
            case 0:
                if(num%2 == 0)
                    a1 += num;
                break;
            case 1:
                a2 += sym * num;
                sym *= -1;
                break;
            case 2:
                a3++;
                break;
            case 3:
                a4 += num;
                a4t++;
                break;
            case 4:
                if(num>a5)
                    a5=num;
                break;
        }
    }
    a4 = a4/a4t;
    if(is[0] == false || a1 == 0)
        printf("N");
    else
        printf("%d", a1);
    putchar(' ');
    if(is[1] == false)
        printf("N");
    else
        printf("%d", a2);
    putchar(' ');
    if(is[2] == false)
        printf("N");
    else
        printf("%d", a3);
    putchar(' ');
    if(is[3] == false)
        printf("N");
    else
        printf("%.1lf", a4);
    putchar(' ');
    if(is[4] == false)
        printf("N");
    else
        printf("%d", a5);
    return 0;
}
