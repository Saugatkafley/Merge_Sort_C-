#include <iostream>
using namespace std;

void merge(double arr[], int l,int m,int r)
    {
        int i=l;
        int j=m+1;
        int k=l;
        double temp[1000000] ;
        while(i<=m && j<=r)
        {
            if(arr[i] <=arr[j])
            {
                temp[k] =arr[i];
                i++,k++;
            }
            else
            {
                temp[k] =arr[j];
                j++, k++;
            }
        }
        while (i<=m)
        {
            temp[k] =arr[i];
            i++,k++;
        }
        while(j<=r)
        {
            temp[k] = arr[j];
            j++,k++;
        }
        for(int p=l;p<=r;p++)
        {
            arr[p] = temp[p];
        }
        //return arr;
    }
void MergeSort(double arr[] ,int l , int r)
{

    int m =0;
    if(l<r)
    {
        m= (l+r) /2;
        MergeSort(arr,l,m);
        MergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
void selectionsort(int arr[],int n)
{
    int i,j,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j] < arr[min]) min =j;
        }
        if(min!=i)
        {
            int temp=arr[min];
            arr[min] =arr[i];
            arr[i] =temp;
        }
    }
}

int main()
{
    int c=1000000;
    double a[1000000] ;
    for(int i=0;i<1000000;i++)
    {
       a[i] =c;
       c--;
    }
    cout << "Before Soting ...\n";
    for(int i=0;i<1000000;i++)
    {
        cout << a[i] << " ";
    }
    MergeSort(a,0,999999);
    //selectionsort(a,1000);
    cout << "After sorting ...\n";
    for(int i=0;i<1000000;i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
