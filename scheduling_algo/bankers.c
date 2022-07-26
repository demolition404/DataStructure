#include<stdio.h>
/*
    Bankers algorithms by ayan
    -->we take input of number of processes and resources and availability of each resource
    -->we take the input of max matrix also 
    -->after that we calculate the need matrix
    -->once we do that we see if we could fit in all processes without any dead lock
    -->if dead lock occurs that is at any one instance when no process could be 
        executed becuse resources available is not enough 
    -->we print system is having a deadlock state 
    -->this algo is also called dead lock prevention or dead lock detection
*/
int main()
{
    int n,m,i,j,k;
    scanf("%d%d",&n,&m);
    int alloc[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&alloc[i][j]);
        }
        
    }
    int max[n][m];
    printf("enter the max matrix now\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&max[i][j]);
        }
        
    }
    printf("Enter avilability of all resources:\n");
    int available[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&available[i]);
    }
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
 
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > available[j]){
                        flag = 1;
                         break;
                    }
                }
 
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        available[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
   
    int flag = 1;
       
    for(int i=0;i<n;i++)
    {
      if(f[i]==0)
      {
        flag=0;
         printf("The following system is not safe");
        break;
      }
    }
     
    if(flag==1)
    {
      printf("Following is the SAFE Sequence\n");
      for (i = 0; i < n ; i++)
        printf(" P%d ->", ans[i]);
      
    }
     
 
    return (0);
    

}