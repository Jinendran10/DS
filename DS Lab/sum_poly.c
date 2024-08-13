#include<stdio.h>
struct poly
{ 
	int  coeff;
	int exp;
};
void main()
{
	int row1,row2,i=0,j=0,k=0,r;
	printf("Enter the degree of the polynomial 1:");
	scanf("%d",&row1);
	printf("Enter the degree of the polynomial:");
	scanf("%d",&row2);
	struct poly A[row1],B[row2],sum[r];
	for(i=row1;i>=0;i--)
	{
		printf("Enter the coefficient of X^%d of polynomial 1:",i);
		scanf("%d",&A[i].coeff);
		A[i].exp=i;
	}
	for(i=row2;i>=0;i--)
	{
		printf("Enter the coefficient of X^%d of polynomial 2:",i);
		scanf("%d",&B[i].coeff);
		B[i].exp=i;
	}
	while(i<row1 && j<row2)
	{
		if(A[i].exp==B[j].exp)
		{
			sum[k].coeff=A[i].coeff+B[j].coeff;
			sum[k].exp=A[i].exp;
			i++;
			j++;
			k++;
		}
		else if(A[i].exp>B[j].exp)
		{
			sum[k].coeff=A[i].coeff;
			i++;
			k++;
		}
		else
		{
			sum[k].coeff=B[j].coeff;
			j++;
			k++;
		}
	}
	while(i<r)
	{
		printf("%dX^%d",sum[i].coeff,sum[i].exp);
		i++;
	}			
}
