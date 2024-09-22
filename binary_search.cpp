#include <iostream>
using namespace std;

bool binary_search(int *arr,int size,int value)
{
    int start = 0;
    int end = size;

    while(start < end)
    {
        int mid = (start+end)/2;

        if(value < arr[mid])
        {
            start = start;
            end = mid - 1;
        }

        else if(value>arr[mid])
        {
            start = mid+1;
            end = end;
        }

        else
        {
            return true;
        }
        
    }

    return false;
}

void sort(int *arr,int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=i;j<size;j++)
        {
            if(arr[j]<arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void display(int *arr,int size)
{
    cout<<"[ ";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
}

void input(int *arr,int size)
{
    cout<<"Enter data in array"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<"array["<<i+1<<"]:";
        cin>>arr[i];
    }
}

int main()
{
    int *arr;
    int size;
    int val_to_search;

    cout<<"Enter size of array: ";
    cin>>size;

    arr = new int[size];

    input(arr,size);
    display(arr,size);

    sort(arr,size);
    display(arr,size);

    cout<<"Enter value to search in the sorted array:";
    cin>>val_to_search;

    if(binary_search(arr,size,val_to_search))
    {
        cout<<"The value is in array."<<endl;
    }
    else
    {
        cout<<"The value is not in array."<<endl;
    }

    return 0;
}