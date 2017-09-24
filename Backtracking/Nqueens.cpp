#include<stdio.h>
#include<math.h>
int queen[50],n,t=1;

bool CanPlace(int queen[],int num)//determine if the queen can be placed
{
    int i;
	for(i=1;i<num;i++)
	{
		if(abs(queen[i]-queen[num])==abs(i-num) || queen[i]==queen[num])
			return false;
	}
	return true;
}

void Output()    //output the chessboard
{
    int i,j;
    printf("Solution NO.%d\n",t++);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j==queen[i]) 
                printf("Q ");
            else
                printf("* ");
        }
        printf("\n");
    }
    printf("\n");
}

void Nqueens(int num)
{
    int i;
	for(i=1;i<=n;i++)
	{
		queen[num]=i;
		if(CanPlace(queen,num)) 
		{
			if(num==n) 
                Output();
			else  
                Nqueens(num+1);//use recurrence to backtrack
		}
	}
}

int main()
{
	printf("how many queens?");
	scanf("%d",&n);
    Nqueens(1);
    return 0;
}