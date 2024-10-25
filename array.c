#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p,i,pos,ele,n,ch;
    printf("Enter a no of elements to create array: ");
    scanf("%d",&n);
    p=malloc (n*sizeof(int));
    printf("Dynamic array created: \n");
    printf("enter the %d elements : \n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    while(1)
    {
        printf("\n 1.Insert \n 2.Delete \n 3. Display \n 4. exit \n Enter your choice : \t");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\n Enter pos and ele (0 to %d) to insert \t");
            scanf("%d%d",&pos,&ele);
            realloc(p,(n+1)*sizeof(int));
            n=n+1;
            for(i=n-1;i>=pos;i--)
            {
                p[i]=p[i-1];
            
            }
            p[pos]=ele;
            break;
        
        case 2:
        printf("\n Enter pos and ele (0 to %d) to delete \t",n-1);
        scanf("%d",&pos);
        for(i=pos+1;i<n;i++)
        {
            p[i-1]=p[i];

        }
        n=n-1;
        break;
        case 3:
        printf("\n Enter array elements are: \n");
        for(i=0;i<n;i++)
        {
            printf("%d\t",p[i]);
        
        }
        break;
        case 4:
        exit(0);
         }
    }
    return 0;
}