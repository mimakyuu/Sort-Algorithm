#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for clock()
#include "sort.h"

// データの個数(初期値)
#define N 10000

// 1回ごとに増やすデータ数
#define DIFF 10000

// 正確な計算時間を得るための反復回数
#define REP 20

/*実行するソート
0 or 51 SelectionSort
1 or 52 InsertionSort
2 or 55 HeapSort
3 or 61 QuickSort
4 or 73 MergeSort
*/

#define SORT 51

// データ
double A[N * 5];

double _time[5];

// ********
// Main
// ********

int n;

char sortName[5][100] = {"5.1 SelectionSort", "5.2 InsertionSort", "5.5 HeapSort", "6.1 QuickSort", "7.3 MergeSort"};
char dataType[3][100] = {"Random", "Ascending", "Descending"};

int disp = 0;
void main(void)
{

    rep(data, 3)
    {

        rep(i, 5)
        {
            n = N + DIFF * i;
            clock_t time_all, time_start, time_end;

            // 計算時間の合計
            time_all = 0;

            // 正確な計算時間を得るための反復
            rep(k, REP)
            {
                // データの入力
                switch (data)
                {
                case 0:
                    data_random(n, A);
                    break;
                case 1:
                    data_ascending(n, A);
                    break;
                case 2:
                    data_descending(n, A);
                    break;
                }

                // 計算時間の計測開始
                time_start = clock();

                // ソート
                switch (SORT)
                {
                case 0:
                case 51:
                    selectionsort(n, A);
                    disp = 0;
                    break;
                case 1:
                case 52:
                    insertionsort(n, A);
                    disp = 1;
                    break;
                case 2:
                case 55:
                    heapsort(n, A);
                    disp = 2;
                    break;
                case 3:
                case 61:
                    quicksort(A, 0, n - 1, 1);
                    disp = 3;
                    break;
                case 4:
                case 73:
                    mergesort(n, A, 0, n - 1);
                    disp = 4;
                    break;
                }

                // 計算時間の計測終了
                time_end = clock();

                // 計算時間の合計
                time_all += (time_end - time_start);

            }

            // 計算時間（平均）
            _time[i] = ((double)time_all / (double)REP) / (double)CLOCKS_PER_SEC;
        }

        printf("\n%s: %s\n", sortName[disp], dataType[data]);
        rep(i, 5)
        {
            printf("size: %d  ", N + DIFF * i);
            printf("time: %lf sec.\n", _time[i]);
        }
    }
}

// **** EOF
