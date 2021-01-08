#include <stdlib.h>
#include "sort.h"

// ********
// 5.1 SelectionSort
// ********
void selectionsort(
    int n,     // データの個数
    double D[] // データ D[0], ..., D[n-1]
)
{
    int i, j, max_index;
    double max;

    for (i = n - 1; i > 0; i--)
    {
        max = D[0];
        max_index = 0;
        for (j = 1; j <= i; j++)
        {
            if (D[j] >= max)
            {
                max = D[j];
                max_index = j;
            }
        }
        swap(&(D[max_index]), &(D[i]));
    }
}

// ********
// 5.2 InsertionSort
// ********
void insertionsort(
    int n,     // データの個数
    double D[] // データ D[0], ..., D[n-1]
)
{
    for (int i = 1; i < n; i++)
    {
        double x = D[i];
        int j = i;
        while ((D[j - 1] > x && j > 0))
        {
            D[j] = D[j - 1];
            j--;
        }
        D[j] = x;
    }
}

// ********
// 5.5 HeapSort
// ********
int size;

void push_heap(double *, double);
double delete_maximum(double *);

void heapsort(
    int n,     // データの個数
    double D[] // データ D[0], ..., D[n-1]
)
{
    double T[n];
    size = 0;
    rep(i, n)
    {
        push_heap(T, D[i]);
    }
    drep(i, n)
    {
        D[i] = delete_maximum(T);
    }
}

void push_heap(double T[], double x)
{
    size++;
    T[size] = x;
    int k = size;
    while (T[k] > T[k / 2] && k > 1)
    {
        swap(&T[k], &T[k / 2]);
        k /= 2;
    }
}

double delete_maximum(double T[])
{
    double res;
    if (size > 0)
    {
        res = T[1];
    }
    else
    {
        res = 0.0;
    }
    T[1] = T[size];
    size--;
    int k = 1;
    while (2 * k <= size)
    {
        if (2 * k == size)
        {
            if (T[k] < T[2 * k])
            {
                swap(&T[k], &T[2 * k]);
                k *= 2;
            }
            else
            {
                break;
            }
        }
        else
        {
            int big;
            if (T[2 * k] > T[2 * k + 1])
            {
                big = 2 * k;
            }
            else
            {
                big = 2 * k + 1;
            }

            if (T[k] < T[big])
            {
                swap(&T[k], &T[big]);
                k = big;
            }
            else
            {
                break;
            }
        }
    }
    return res;
}

// ********
// 6.1 QuickSort
// ********

int partition(double D[], int left, int right, int mode);

int setBase(double D[], int l, int r, int mode);

/*modeに基準値選択モードを入れる
    0：データ D[left], ..., D[right] の中からランダムに選ぶ
    1：真ん中のデータ D[(left+right)/2] を選ぶ
    2：３つのデータ D[left], D[(left+right)/2], D[right] を大きさの順に並べて中央のデータを選ぶ
    3：左端のデータ D[left] を選ぶ
    4：右端のデータ D[right] を選ぶ */
void quicksort(
    double D[], // データ D[left], ..., D[right]
    int left,   // ソートの対象とする配列 D の左端の位置
    int right,  // ソートの対象とする配列 D の右端の位置
    int mode)
{
    int pivot_index;

    if (left < right)
    {
        pivot_index = partition(D, left, right, mode);
        quicksort(D, left, pivot_index - 1, mode);
        quicksort(D, pivot_index + 1, right, mode);
    }
}

int partition(double D[], int left, int right, int mode)
{

    int k = setBase(D, left, right, mode);

    swap(&D[k], &D[right]);

    int i = left;
    int j = right - 1;

    while (i <= j)
    {
        while (D[i] < D[right])
        {
            i++;
        }

        while ((D[j] >= D[right]) && (j >= i))
        {
            j--;
        }

        if (i < j)
        {
            swap(&D[i], &D[j]);
        }
    }

    swap(&D[i], &D[right]);

    return i;
}

int setBase(double D[], int l, int r, int mode)
{
    int c = (l + r) / 2;
    int res;

    switch (mode)
    {
    case 0:
    default:
        res = (rand() % (r - l + 1)) + l;
        break;

    case 1:
        res = c;
        break;
        
    case 2:
        if ((D[l] < D[r] && D[r] < D[c]) || (D[c] < D[r] && D[r] < D[l]))
        {
            res = r;
        }
        else if ((D[r] < D[l] && D[l] < D[c]) || (D[c] < D[l] && D[l] < D[r]))
        {
            res = l;
        }
        else
        {
            res = c;
        }
        break;

    case 3:
        res = l;
        break;

    case 4:
        res = r;
        break;
    }

    return res;
}

// ********
// 7.3 MergeSort
// ********
void merge(int n, double D[], int left, int mid, int right);

void mergesort(
    int n,
    double D[], // データ D[left], ..., D[right]
    int left,   // ソートの対象とする配列 D の左端の位置
    int right   // ソートの対象とする配列 D の右端の位置
)
{
    int mid;

    mid = (left + right) / 2;

    if (left < mid)
    {
        mergesort(n, D, left, mid);
    }

    if (mid + 1 < right)
    {
        mergesort(n, D, mid + 1, right);
    }

    merge(n, D, left, mid, right);
}

void merge(int n, double D[], int left, int mid, int right)
{
    int x, y, i;
    double M[n];

    x = left;
    y = mid + 1;

    for (i = left; i <= right; i++)
    {
        if (x == mid + 1)
        {
            M[i] = D[y];
            y++;
        }
        else if (y == right + 1)
        {
            M[i] = D[x];
            x++;
        }
        else if (D[x] <= D[y])
        {
            M[i] = D[x];
            x++;
        }
        else
        {
            M[i] = D[y];
            y++;
        }
    }

    for (i = 0; i <= right - left; i++)
    {
        D[left + i] = M[i];
    }
}

// **** EOF