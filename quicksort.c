
//pivot
#define cnt 7
static int tmp[cnt];
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = low ;  // Index of smaller element (low - 1)

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]); memcpy(tmp,arr,cnt*sizeof(int));
            i++;    // increment index of smaller element
        }
    }
    swap(&arr[i], &arr[high]); memcpy(tmp,arr,cnt*sizeof(int));
    return i;
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void AlexQuickSort(int arr[], int low, int high)
{
    memcpy(tmp,arr,cnt*sizeof(int));
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);memcpy(tmp,arr,cnt*sizeof(int));
        // Separately sort elements before
        // partition and after partition
        AlexQuickSort(arr, low, pi - 1);
        AlexQuickSort(arr, pi + 1, high);
    }
}
void quickSort(int arr[], int size)
{
  AlexQuickSort(arr,0,size-1);
}
