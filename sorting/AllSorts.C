#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

void generateRandom(int a[], int s){
    int i;
    for (i = 0; i < s; i++) {
        a[i] = rand() % s + 1;
    }
}

void generateAscending(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        a[i] = i;
    }
}

void generateDescending(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
	a[i] = s - i;
    }
}

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void bubbleSort(int a[], int s) {
    int i, j;
    for (i = 0; i < s - 1; i++) {
        for (j = 0; j < s - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a, j, j + 1);
            }
        }
    }
}

void insertionSort(int a[], int s) {
    int i, j, key;
    for (i = 1; i < s; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void selectionSort(int a[], int s) {
    int i, j, minIndex;
    for (i = 0; i < s - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < s; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(a, i, minIndex);
        }
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    int j;
    for (j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a, i, j);
        }
    }
    swap(a, i + 1, high);
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

void merge(int a[], int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int *left = (int *)malloc(n1 * sizeof(int));
    int *right = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        left[i] = a[low + i];
    for (j = 0; j < n2; j++)
        right[j] = a[mid + 1 + j];

    i = 0; j = 0; k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = left[i];
        i++; k++;
    }
    while (j < n2) {
        a[k] = right[j];
        j++; k++;
    }

    free(left);
    free(right);
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void heapify(int a[], int s, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < s && a[left] > a[largest])
        largest = left;
    if (right < s && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        swap(a, i, largest);
        heapify(a, s, largest);
    }
}

void heapSort(int a[], int s) {
    int i;
    for (i = s / 2 - 1; i >= 0; i--)
        heapify(a, s, i);

    for (i = s - 1; i > 0; i--) {
        swap(a, 0, i);
        heapify(a, i, 0);
    }
}

int main() {
    struct timeval te;
    int size = 8000;
    int step = 4000;
    
    int i;
    for (i = 0; i < 8; i++) {
        int a[size];
        generateRandom(a, size);
	//generateAscending(a, size);
	//generateDescending(a, size);

        gettimeofday(&te, NULL);
        long long start = te.tv_sec * 1000LL + te.tv_usec / 1000;

        insertionSort(a, size);

        gettimeofday(&te, NULL);
        long long end = te.tv_sec * 1000LL + te.tv_usec / 1000;

        printf("size=%d time=%lldms\n", size, end - start);

        size += step;
    }

    return 0;
}
