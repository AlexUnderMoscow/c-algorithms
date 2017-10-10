
//в целях отладки размер статического масссива для его просмотра
#define cnt 7
//статический массив
static int tmp[cnt];
//деление подмассива на части с меньшими и большими элементами
//отностительно центрального, который избирается последним в списке
//выталкивание бОльших элементов вперед подобно пузырьковой сортировке
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // избираем центральный элемент
    int i = low ;  //индекс минимального - low
    //цикл продвижения больших элементов вперед
    for (int j = low; j <= high- 1; j++)
    {
       //если элемент менее центрального, то минимальный
        //элемент меняется местами с текущим
        if (arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]); memcpy(tmp,arr,cnt*sizeof(int));
            i++;
        }
    }
    //обмен максимального элемента с последним
    swap(&arr[i], &arr[high]); memcpy(tmp,arr,cnt*sizeof(int));
    //возврат центрального элемента
    return i;
}

void AlexQuickSort(int arr[], int low, int high)
{
    memcpy(tmp,arr,cnt*sizeof(int));
    if (low < high)
    {
        //определение центрального элемента, виталкивание больших
        //вперед и сортировка
        int pi = partition(arr, low, high);memcpy(tmp,arr,cnt*sizeof(int));
        //рекурсивный вызов сортировки для подмассивов левого и правого
        AlexQuickSort(arr, low, pi - 1);
        AlexQuickSort(arr, pi + 1, high);
    }
}
void quickSort(int arr[], int size)
{
  AlexQuickSort(arr,0,size-1);
}
