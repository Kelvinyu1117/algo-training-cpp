void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int getMedian(vector<int> &arr, int lo, int mid, int hi)
{
    if ((arr[lo] > arr[mid]) != (arr[lo] > arr[hi]))
        return lo;
    else if ((arr[mid] > arr[lo]) != (arr[mid] > arr[hi]))
        return mid;
    return hi;
}

int partition(vector<int> &arr, int lo, int hi)
{

    swap(arr[getMedian(arr, lo, (hi + lo) / 2, hi)], arr[hi]);

    int pivot = hi;
    int i = lo - 1;

    for (int j = lo; j <= hi - 1; j++)
    {
        if (arr[j] < arr[pivot])
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[pivot]);

    return i + 1;
}

void quickSort(vector<int> &arr, int lo, int hi)
{
    if (lo >= hi)
        return;

    int pivot = partition(arr, lo, hi);

    quickSort(arr, lo, pivot - 1);
    quickSort(arr, pivot + 1, hi);
}

int quickSelect(vector<int> &arr, int lo, int hi, int k)
{
    if (lo == hi)
        return arr[lo];

    int pivot = partition(arr, lo, hi);

    if (pivot == k)
        return arr[pivot];

    if (pivot > k)
        return quickSelect(arr, lo, pivot - 1, k);

    return quickSelect(arr, pivot + 1, hi, k);
}