#include<stdlib.h>
#include<stdio.h>
 
// Gop hai mang con arr[l...m] và arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* Tao các mang tam */
    int L[n1], R[n2];
 
    /* Copy du lieu sang các mang tam */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Gop hai mang tam vua roi vào mang arr*/
    i = 0; // Khoi tao chi so bat đau cua mang con đau tiên
    j = 0; // Khoi tao chi so bat đau cua mang con thu hai
    k = l; // Khoi tao chi so bat đau cua mang luu ket qua
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy các phan tu còn lai cua mang L vào arr neu có */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy các phan tu còn lai cua mang R vào arr neu có */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l là chi so trái và r là chi so phai cua mang con đuoc sap xep */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Tuong tu (l+r)/2, nhung cách này tránh tràn so khi l và r lon
        int m = l+(r-l)/2;
 
        // Goi hàm đe quy tiep tuc chia đôi tung nua mang
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
 
 
/* Hàm xuat mang */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
 
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
 