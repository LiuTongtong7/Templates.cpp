// 
// Created by liutongtong on 2018/10/27 00:48
//

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef long long ll;
typedef long double ld;

using namespace std;

#define mp make_pair
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

void bubble_sort(int arr[], int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 1; j < len - i; ++j) {
            if (arr[j - 1] > arr[j])
                swap(arr[j - 1], arr[j]);
        }
    }
}

void selection_sort(int arr[], int len) {
    for (int i = 0; i < len - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        swap(arr[i], arr[min_index]);
    }
}

void insertion_sort(int arr[], int len) {
    for (int i = 1; i < len; ++i) {
        int temp = arr[i];
        int j;
        for (j = i - 1; j >= 0 && arr[j] > temp; --j)
            arr[j + 1] = arr[j];
        arr[j + 1] = temp;
    }
}

void shell_sort(int arr[], int len) {
    int gap = len / 2;
    while (gap > 0) {
        for (int i = gap; i < len; ++i) {
            int temp = arr[i];
            int j;
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
                arr[j + gap] = arr[j];
            arr[j + gap] = temp;
        }
        gap /= 2;
    }
}

void merge_sort(int arr[], int len) {
    int *a = arr;
    int *b = new int[len];
    for (int width = 1; width < len; width <<= 1) {
        for (int start = 0; start < len; start += width * 2) {
            int left = start, middle = min(start + width, len), right = min(start + width * 2, len);
            int l = left, r = middle;
            for (int i = left; i < right; ++i) {
                if (l < middle && (r >= right || a[l] <= a[r])) {
                    b[i] = a[l];
                    ++l;
                } else {
                    b[i] = a[r];
                    ++r;
                }
            }
        }
        swap(a, b);
    }
    if (a != arr) {
        for (int i = 0; i < len; ++i)
            b[i] = a[i];
        b = a;
    }
    delete[] b;
}

void merge_sort_helper(int arr[], int buf[], int left, int right) {
    if (left >= right)
        return;
    int middle = ((right - left) >> 1) + left;
    merge_sort_helper(arr, buf, left, middle);
    merge_sort_helper(arr, buf, middle + 1, right);
    int l = left, r = middle + 1;
    for (int i = left; i <= right; ++i) {
        if (l <= middle && (r > right || arr[l] <= arr[r])) {
            buf[i] = arr[l];
            ++l;
        } else {
            buf[i] = arr[r];
            ++r;
        }
    }
    for (int i = left; i <= right; ++i)
        arr[i] = buf[i];
}
void merge_sort2(int arr[], int len) {
    int *buf = new int[len];
    merge_sort_helper(arr, buf, 0, len - 1);
    delete[] buf;
}

void quick_sort(int arr[], int len) {

}

void qsort(int arr[], int left, int right) {

}
void quick_sort2(int arr[], int len) {

}

void heap_sort(int arr[], int len) {

}

void counting_sort(int arr[], int len) {

}

void radix_sort(int arr[], int len, int radix=10) {

}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int arr[] = {4,6,2,7,8,1,5,3,9};
    int len = (sizeof arr) / (sizeof *arr);
    // bubble_sort(arr, len);
    // selection_sort(arr, len);
    // insertion_sort(arr, len);
    // shell_sort(arr, len);
    // merge_sort(arr, len);
    merge_sort2(arr, len);
    for (int i = 0; i < len; ++i)
        cout << arr[i] << ' ';
    cout << endl;

    return 0;
}
