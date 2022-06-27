
void upAdjustment(int A[], int idx){
    int parent = idx / 2;             // parent的index
    if ( parent < 1 ) return;         // 如果沒有parent了(最小是1)，					 // 代表是root，結束。

    if ( A[idx] > A[parent] ){        // 如果自己比parent大，交換
        int tmp = A[idx];
        A[idx] = A[parent];
        A[parent] = tmp;
        upAdjustment(A, parent);   // 換完後繼續向上調整(新位置: parent)
    }
}

void addAElement(int ele){
    A[N++] = ele;                 // 放在最後
    upAdjustment(A, N);           // 做向上調整
}

