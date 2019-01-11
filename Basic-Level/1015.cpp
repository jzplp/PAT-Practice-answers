#include<stdio.h>
#include<stdlib.h>
struct stu
{
    int num;
    int de;
    int cai;
};

int comp(const void *ss1,const void *ss2)
{

    const struct stu * s1 = (const struct stu *)ss1;
    const struct stu * s2 = (const struct stu *)ss2;
    int zong1 = s1->de+s1->cai;
    int zong2 = s2->de+s2->cai;
    if( zong1!= zong2)
        return zong1<zong2;
    if(s1->de!=s2->de)
        return s1->de<s2->de;
    return s1->num>s2->num;
}
int main()
{
    int N,L,H;
    scanf("%d %d %d",&N,&L,&H);
    struct stu v[N];

    int i,j;

    for(i=0,j=0;i<N;++i)
    {
        stu s;
        scanf("%d %d %d",&s.num,&s.de,&s.cai);
        if(s.de<L || s.cai<L)
            continue;
        v[j++]=s;
    }
    struct stu v1[j];
    struct stu v2[j];
    struct stu v3[j];
    struct stu v4[j];
    int j1=0,j2=0,j3=0,j4=0;
    for(i=0;i<j;++i)
    {
        if(v[i].de>=H && v[i].cai>=H)
        {
            v1[j1++]=v[i];
            continue;
        }
        if(v[i].de>=H)
        {
            v2[j2++]=v[i];
            continue;
        }
        if(v[i].de>= v[i].cai)
        {
            v3[j3++]=v[i];
            continue;
        }
        v4[j4++]=v[i];
    }
    qsort(v1,j1,sizeof(struct stu),comp);
    qsort(v2,j2,sizeof(struct stu),comp);
    qsort(v3,j3,sizeof(struct stu),comp);
    qsort(v4,j4,sizeof(struct stu),comp);
    printf("%d\n",j);

    for(i=0;i<j1;++i)
        printf("%d %d %d\n",v1[i].num,v1[i].de,v1[i].cai);
    for(i=0;i<j2;++i)
        printf("%d %d %d\n",v2[i].num,v2[i].de,v2[i].cai);
    for(i=0;i<j3;++i)
        printf("%d %d %d\n",v3[i].num,v3[i].de,v3[i].cai);
    for(i=0;i<j4;++i)
        printf("%d %d %d\n",v4[i].num,v4[i].de,v4[i].cai);
    return 0;
}
