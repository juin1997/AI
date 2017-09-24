#include<stdio.h>
#include<math.h>
int a[50],n,t=1;

bool CanPlace(int a[],int num)
{
    int i;
	for(i=1;i<num;i++)
	{
		if(abs(a[i]-a[num])==abs(i-num) || a[i]==a[num])
			return false;
	}
	return true;
}

void Output()
{
    int i,j;
    printf("Solution NO.%d\n",t++);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j==a[i]) 
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
		a[num]=i;
		if(CanPlace(a,num)) 
		{
			if(num==n) 
                Output();
			else  
                Nqueens(num+1);
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