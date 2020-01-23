int partition(int *a, int low, int high)
{
    int e = a[high];
    int pos = low;
    int i, tmp;
    for(i = low; i<high, i++)
    {
        if(a[i]<=e)
        {
            tmp = a[low];
            a[low] = a[i];
            a[i] = tmp;
            low++;
        }
    }
    tmp = a[low];
    a[low] = a[high];
    a[high] = tmp;
    return low;
}

void quick_sort(int *a, int low, int high)
{
    if(low>=high)
        return;
    int mid = partition(a, low, high);
    quick_sort(a, low, mid-1);
    quick_sort(a, mid+1, high);
}
