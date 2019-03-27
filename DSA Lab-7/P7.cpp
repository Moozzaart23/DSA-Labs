#include<stdio.h>
int a[100005];
int Merge(int a[],int left[],int right[],int nL,int nR)
{
	int i,j,k,inv=0;
	while(i<nL && j<nR)
	{
		if(left[i]<=right[j])
		{
			a[k++]=left[i++];
		}
		else
		{
			a[k++]=right[j++];
			inv+=(nL-i);
		}
	}
	while(i<nL)
	{
		a[k++]=left[i++];
	}
	while(j<nR)
	{
		a[k++]=right[j++];
	}
	return inv;
}
int MergeSort(int arr[],int n)
{
	if(n<2)
		return 0;
	int mid=n/2;
	int nL=mid;
	int nR=(n-mid);
	int left[nL];
	int right[nR];
	for(int i=0;i<nL;i++)
		left[i]=arr[i];
	for(int i=nL;i<n;i++)
		right[i-mid]=arr[i];
	int x=MergeSort(left,nL);
	int y=MergeSort(right,nR);
	int z=Merge(arr,left,right,nL,nR);
	return x+y+z;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int z=MergeSort(a,n);
	printf("%d",z);
	return 0;
}
