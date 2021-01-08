//repマクロ
#define rep(i, n) for (int i = 0; i < n; i++)
#define drep(i, n) for (int i = n - 1; i >= 0; i--)

// ２つのデータを交換する
void swap(
    double *,
    double *);

// ランダムなデータを与える
void data_random(
    int,
    double[]);

// 昇順のデータを与える
void data_ascending(
    int,
    double[]);

// 降順のデータを与える
void data_descending(
    int,
    double[]);

// アルゴリズム 5.1  選択ソート
void selectionsort(
    int,
    double[]);

// アルゴリズム 5.2  挿入ソート
void insertionsort(
    int,
    double[]);

// アルゴリズム 5.5  ヒープソート
void heapsort(
    int,
    double[]);

/*アルゴリズム 6.1  クイックソート
    modeに基準値選択モードを入れる
    1：データ D[left], ..., D[right] の中からランダムに選ぶ
    2：真ん中のデータ D[(left+right)/2] を選ぶ
    3：３つのデータ D[left], D[(left+right)/2], D[right] を大きさの順に並べて中央のデータを選ぶ
    4：左端のデータ D[left] を選ぶ
    5：右端のデータ D[right] を選ぶ */
void quicksort(
    double[],
    int,
    int,
    int mode);

// アルゴリズム 7.3  マージソート
void mergesort(
    int,
    double[],
    int,
    int);

// **** EOF
