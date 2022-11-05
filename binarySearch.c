#include "stdio.h"

int main() {
    int arr[] = {1, 4, 9, 12, 222, 433, 900, 1000};
    int key = 9;
    int first = 0;
    size_t last = sizeof(arr) / sizeof(int) - 1;
    while (first <= last) {
        int mid = ((unsigned)first + (unsigned)last) / 2;
        int midVal = arr[mid];
        if(key < midVal) {
            last = mid - 1;
        } else if (key > midVal) {
            first = mid + 1;
        } else {
            printf("Найдено: %d", midVal);
            return 1;
        }
    }
    printf("Не найдено");
    return 0;
}