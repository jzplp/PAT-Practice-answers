#include<stdio.h>
int main()
{
    struct student
    {
        char name[12],number[12];
        int score;
    };
    int n,i;
    struct student max1,min1,temp;
    max1.score=-1,min1.score=101;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       scanf("%s %s %d",temp.name,temp.number,&temp.score);
       if(temp.score>max1.score)
       {
           max1=temp;
       }
       if(temp.score<min1.score)
       {
           min1=temp;
       }
    }
    printf("%s %s\n",max1.name,max1.number);
    printf("%s %s",min1.name,min1.number);
    return 0;
}
