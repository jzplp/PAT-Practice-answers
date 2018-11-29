#include<stdio.h>
int main()
{
    int i=20000;
    int i1,i2;
    while(2 == scanf("%d%d",&i1,&i2))
    {
        if(i2 == 0)
            break;
        if(i != 20000)
            printf(" ");
        i1 = i1*i2;
        i2 = i2-1;
        printf("%d %d",i1, i2);
        i = i2;
    }
    if(i == 20000) printf("0 0");
    return 0;
}
