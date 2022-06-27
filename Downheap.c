int A[MAX_SIZE], N = #elements;     // MAX_SIZE和#elements都是看題目決定
void buildHeap()
{                   // 假設資料已經存在A[1]~A[N]
    int i;
    for ( i = N / 2 ; i >= 1 ; i-- )// 從最後一個有小孩的點開始向下調整
        downAdjustment(A, i);
}

void downAdjustment(int A[], int idx)
{
    int leftChild = 2 * idx;      // 左邊小孩的index
    int rightChild = 2 * idx + 1; // 右邊小孩的index
    int max;
    if ( leftChild > N ) return;  // 如果左邊沒有小孩，代表右邊也沒也結束

    // 找比較大的小孩
    if ( rightChild > N || (A[leftChild] > A[rightChild]) )
        max = leftChild;          // 如果右邊沒有小孩，或左邊比較大左邊
    else
        max = rightChild;          // 如果右邊比較大右邊

    if ( A[idx] < A[max] )
    {        // 如果比較大的小孩比自己大，交換
        int tmp = A[idx];
        A[idx] = A[max];
        A[max] = tmp;
        downAdjustment(A, max); // 換完後繼續向下調整(新位置: max)
    }
}
