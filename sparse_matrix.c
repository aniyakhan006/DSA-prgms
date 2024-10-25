  #include<stdio.h>
  #include<stdlib.h>
  #define MAX 100
  struct  term {
    int row;
    int col;
    int value;
  };
  struct term a[MAX],b[MAX];
  void create();
  void transpose();
  void display (int n,struct term m[]);
  int main() {
    int choice;
    while(1){
        printf("\n Menu:\n");
        printf("1.create sparse Matrix\n");
        printf("2.Transpose of sparse Matrix\n");
        printf("3. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            create();
            break;
            case 2:
            transpose();
            break;
            case 3:
            exit(0);
        }
    }
    return 0;
  }
  void create(){
    int i,row,col,n;
    printf("\n Enter number of rows,colums and number of values:");
    scanf("%d%d%d",&row,&col,&n);
    a[0].row = row;
    a[0].col = col;
    a[0].value = n;
    for(i=1;i<=n;i++)
    {
        printf("\n Enter rows,cols and value:");
        scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].value);
    }
    display(n,a);
  }
  void transpose(){
    int i,j,k=1,n;
    n=a[0].value;
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].value=n;
    for(i=0;i<=a[0].col;i++)
    {
        for(j=1;j<=n;j++)
        {
        if (a[j].col==1){
             b[k].row=a[j].col;
             b[k].col=a[j].row;
             b[k].value=a[j].value;
             k++;
             }
    
        }
    }
    
    display(n,b);
  }
  void display(int values,struct term m[]){
    int i;
    printf("\n Rows \tColumns \tvalue \n");
    for(i=0;i<=values;i++){
        printf(" %d\t%d\t%d\n",m[i].row, m[i].col, m[i].value);
    }
  }    
    
  
  
    
  
        
    
