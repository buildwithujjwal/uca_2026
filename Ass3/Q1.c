#include<stdio.h>

void merge(int arr[], int st, int mid, int end, int n, long long *count) {
    int newArray[end - st + 1];

    int p2 = mid + 1;
    for (int p1 = st; p1 <= mid; p1++) {
        while (p2 <= end && (long long)arr[p1] > 2LL * arr[p2]) {
            p2++;
        }
        *count += (p2 - (mid + 1));
    }

    int ptr1 = st;
    int ptr2 = mid + 1;
    int ptr3 = 0;

    while(ptr1 <= mid && ptr2 <= end) {
        if(arr[ptr1] <= arr[ptr2]) {
            newArray[ptr3++] = arr[ptr1++];
        }
        else {
            newArray[ptr3++] = arr[ptr2++];
        }
    }

    while(ptr1 <= mid) newArray[ptr3++] = arr[ptr1++];
    while(ptr2 <= end) newArray[ptr3++] = arr[ptr2++];

    for(int i = st; i <= end; i++){
        arr[i] = newArray[i - st];
    }
}

void sort(int arr[], int st, int end, int n, long long *count){

    if(end <= st) return;

    int mid = st + (end - st)/2;

    sort(arr, st, mid, n, count);
    sort(arr, mid + 1, end, n, count);
    merge(arr, st, mid, end, n, count);
}

int countReversePair(int arr[], int n) {

    long long count = 0;
    sort(arr, 0, n-1, n, &count);

    return (int)count;
}


int main() {

    int n;
    printf("type n : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers : ", n);
    for(int num = 0; num < n; num++) {
        scanf("%d", &arr[num]);
    }

    int count = countReversePair(arr, n);
    printf("%d", count);
}