#include<stdio.h>

void merge(int arr[], int idx[], int st, int mid, int end, int answer[]) {
    int size = end - st + 1;
    int newArr[size];
    int newIdx[size];

    int p2 = mid + 1;
    for (int p1 = st; p1 <= mid; p1++) {
        while (p2 <= end && arr[p1] > arr[p2]) {
            p2++;
        }
        answer[idx[p1]] += (p2 - (mid + 1));
    }

    int ptr1 = st;
    int ptr2 = mid + 1;
    int ptr3 = 0;

    while (ptr1 <= mid && ptr2 <= end) {
        if (arr[ptr1] <= arr[ptr2]) {
            newArr[ptr3] = arr[ptr1];
            newIdx[ptr3] = idx[ptr1];
            ptr1++; ptr3++;
        } else {
            newArr[ptr3] = arr[ptr2];
            newIdx[ptr3] = idx[ptr2];
            ptr2++; ptr3++;
        }
    }
    while (ptr1 <= mid) { newArr[ptr3] = arr[ptr1]; newIdx[ptr3] = idx[ptr1]; ptr1++; ptr3++; }
    
    while (ptr2 <= end) { newArr[ptr3] = arr[ptr2]; newIdx[ptr3] = idx[ptr2]; ptr2++; ptr3++; }

    for (int i = st; i <= end; i++) {
        arr[i] = newArr[i - st];
        idx[i] = newIdx[i - st];
    }
}

void sort(int arr[], int idx[], int st, int end, int answer[]) {
    if (end <= st) return;

    int mid = st + (end - st) / 2;

    sort(arr, idx, st, mid, answer);
    sort(arr, idx, mid + 1, end, answer);
    merge(arr, idx, st, mid, end, answer);
}

void countSmaller(int arr[], int n, int answer[]) {
    int idx[n];
    for (int i = 0; i < n; i++) idx[i] = i;
    for (int i = 0; i < n; i++) answer[i] = 0;

    sort(arr, idx, 0, n - 1, answer);
}

int main() {

    int n;
    printf("type n : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers : ", n);
    for (int num = 0; num < n; num++) {
        scanf("%d", &arr[num]);
    }

    int answer[n];
    countSmaller(arr, n, answer);

    for (int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}