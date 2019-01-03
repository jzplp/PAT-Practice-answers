#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char s1[61];
    char s2[61];
    char s3[61];
    char s4[61];
    scanf("%s",s1);
    scanf("%s",s2);
    scanf("%s",s3);
    scanf("%s",s4);
    int len1 = (strlen(s1)>strlen(s2))?strlen(s2):strlen(s1);
    int len2 = (strlen(s3)>strlen(s4))?strlen(s4):strlen(s3);
    int day=0, h, m;
    int i;
    for(i=0;i<len1;++i)
    {
        if(s1[i] == s2[i])
        {
            if(day == 0 && (s1[i]>='A') && (s1[i]<='G') )
            {
                day = s1[i] - 'A' + 1;
            }
            else if(day != 0)
            {
                if( (s1[i]>='A') && (s1[i]<='N') )
                {
                    h = s1[i] - 'A' + 10;
                    break;
                }
                if( (s1[i]>='0') && (s1[i]<='9') )
                {
                    h = s1[i] - '0';
                    break;
                }
            }
        }
    }
    for(i=0;i<len2;++i)
    {
        if(s3[i] == s4[i] && isalpha(s3[i]))
        {
            m = i;
        }
    }

    char *week[7] = {"MON" , "TUE" ,"WED" ,"THU" ,"FRI" ,"SAT" ,"SUN"};
    printf("%s %02d:%02d", week[day-1], h, m);
    return 0;
}
