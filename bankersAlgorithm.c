#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,m,i,j,k,flag,ind;
    n=5;
    m=3;
    int alloc[5][3]={
                        {0,1,0},
                        {2,0,0},
                        {3,0,2},
                        {2,1,1},
                        {0,0,2}
                    };
    int max[5][3]={
                        {7,5,3},
                        {3,2,2},
                        {9,0,2},
                        {2,2,2},
                        {4,3,3}
                  };
    int available[3]={3,3,2};
    int f[n],ans[n];
    for(k=0;k<n;++k)
    {
        f[k]=0;//false allocation
    }
    int need[n][m];
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    int y=0;
    for(k=0;k<5;++k)//going for all 5 processes....
    {
        for(i=0;i<n;++i)
        {
            if(f[i]==0)//if finish[i] is false for [***]
            {
                flag=0;
                for(j=0;j<m;++j)
                {
                        if(need[i][j]>available[j])//and this condition also for [***]
                        {
                            flag=1;
                            break;
                        }
                }
                if(flag==0)
                {
                    ans[ind++]=i;
                    for(y=0;y<m;++y)
                    {
                        available[y]+=alloc[i][y];
                    }
                    f[i]=1;
                }
            }
        }
    }
    int check=0;
    for(i=0;i<n;++i)
    {
        if(f[i]==0)
        {
           check++;
        }
    }
    if(check==0)
        printf("safe state");
    else
        printf("unsafe state");
    return 0;
}