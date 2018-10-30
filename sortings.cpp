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

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back
#define SIZE(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

void bubble_sort(vector<int>& arr) {
    for (int i = 0; i < SIZE(arr) - 1; ++i) {
        for (int j = 1; j < SIZE(arr) - i; ++j) {
            if (arr[j - 1] > arr[j])
                swap(arr[j - 1], arr[j]);
        }
    }
}

void selection_sort(vector<int>& arr) {
    for (int i = 0; i < SIZE(arr) - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < SIZE(arr); ++j) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        swap(arr[i], arr[min_index]);
    }
}

void insertion_sort(vector<int>& arr) {
    for (int i = 1; i < SIZE(arr); ++i) {
        int temp = arr[i];
        int j;
        for (j = i - 1; j >= 0 && arr[j] > temp; --j)
            arr[j + 1] = arr[j];
        arr[j + 1] = temp;
    }
}

void shell_sort(vector<int>& arr) {
    int gap = SIZE(arr) / 2;
    while (gap > 0) {
        for (int i = gap; i < SIZE(arr); ++i) {
            int temp = arr[i];
            int j;
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
                arr[j + gap] = arr[j];
            arr[j + gap] = temp;
        }
        gap /= 2;
    }
}

void merge_sort(vector<int>& arr) {
    vector<int> tmp(SIZE(arr), 0);
    for (int width = 1; width < SIZE(arr); width <<= 1) {
        for (int start = 0; start < SIZE(arr); start += width * 2) {
            int left = start, middle = min(start + width, SIZE(arr)), right = min(start + width * 2, SIZE(arr));
            int l = left, r = middle;
            for (int i = left; i < right; ++i) {
                if (l < middle && (r >= right || arr[l] <= arr[r])) {
                    tmp[i] = arr[l];
                    ++l;
                } else {
                    tmp[i] = arr[r];
                    ++r;
                }
            }
        }
        swap(arr, tmp);
    }
}

void merge_sort_helper(vector<int>& arr, vector<int>& tmp, int left, int right) {
    if (left >= right)
        return;
    int middle = ((right - left) >> 1) + left;
    merge_sort_helper(arr, tmp, left, middle);
    merge_sort_helper(arr, tmp, middle + 1, right);
    int l = left, r = middle + 1;
    for (int i = left; i <= right; ++i) {
        if (l <= middle && (r > right || arr[l] <= arr[r])) {
            tmp[i] = arr[l];
            ++l;
        } else {
            tmp[i] = arr[r];
            ++r;
        }
    }
    copy(tmp.begin() + left, tmp.begin() + right + 1, arr.begin() + left);
}
void merge_sort2(vector<int>& arr) {
    vector<int> tmp(SIZE(arr), 0);
    merge_sort_helper(arr, tmp, 0, SIZE(arr) - 1);
}

void quick_sort(vector<int>& arr) {
    stack<pii> range_stack;
    range_stack.push(mp(0, SIZE(arr) - 1));
    while (!range_stack.empty()) {
        pii range = range_stack.top();
        range_stack.pop();
        int left = range.first, right = range.second;
        if (left >= right)
            continue;
        int pivot = arr[right];
        int l = left, r = right;
        while (l < r) {
            while (arr[l] < pivot && l < r)
                ++l;
            while (arr[r] >= pivot && l < r)
                --r;
            swap(arr[l], arr[r]);
        }
        swap(arr[l], arr[right]);
        range_stack.push(mp(left, l - 1));
        range_stack.push(mp(l + 1, right));
    }
}

void qsort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;
    int pivot = arr[right];
    int l = left, r = right;
    while (l < r) {
        while (arr[l] < pivot && l < r)
            ++l;
        while (arr[r] >= pivot && l < r)
            --r;
        swap(arr[l], arr[r]);
    }
    swap(arr[l], arr[right]);
    qsort(arr, left, l - 1);
    qsort(arr, l + 1, right);
}
void quick_sort2(vector<int>& arr) {
    qsort(arr, 0, SIZE(arr) - 1);
}

void max_heapify(vector<int>& arr, int left, int right) {
    int parent = left, child = left * 2 + 1;
    while (child <= right) {
        if (child + 1 <= right && arr[child] < arr[child + 1])
            ++child;
        if (arr[parent] > arr[child]) {
            break;
        } else {
            swap(arr[parent], arr[child]);
            parent = child;
            child = child * 2 + 1;
        }
    }
}
void heap_sort(vector<int>& arr) {
    for (int i = SIZE(arr) / 2 - 1; i >= 0; --i)
        max_heapify(arr, i, SIZE(arr) - 1);
    for (int i = SIZE(arr) - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

void counting_sort(vector<int>& arr) {
    if (arr.empty())
        return;

    int minv = *min_element(ALL(arr)), maxv = *max_element(ALL(arr));
    vector<int> b(SIZE(arr), 0);
    vector<int> c(maxv - minv + 1, 0);
    for (int i = 0; i < SIZE(arr); ++i)
        ++c[arr[i] - minv];
    for (int i = 1; i < SIZE(c); ++i)
        c[i] += c[i - 1];
    for (int i = SIZE(arr) - 1; i >= 0; --i) {
        b[c[arr[i] - minv] - 1] = arr[i];
        --c[arr[i] - minv];
    }
    swap(arr, b);
}

void radix_sort(vector<int>& arr, int radix=10) {
    if (arr.empty())
        return;

    int max_bit = int(ceil(log(*max_element(ALL(arr)) + 1) / log(radix)));
    int mask = 1;
    for (int i = 1; i <= max_bit; ++i) {
        vector<vector<int> > bucket(radix, vector<int>());
        for (int val : arr)
            bucket[(val / mask) % radix].pb(val);
        arr.clear();
        for (vector<int> b : bucket)
            arr.insert(arr.end(), ALL(b));
        mask *= radix;
    }
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int a[] = {4,6,2,7,8,1,5,3,9};
    vector<int> arr(a, a + (sizeof a) / (sizeof *a));
    // bubble_sort(arr);
    // selection_sort(arr);
    // insertion_sort(arr);
    // shell_sort(arr);
    // merge_sort(arr);
    // merge_sort2(arr);
    // quick_sort(arr);
    // quick_sort2(arr);
    // heap_sort(arr);
    // counting_sort(arr);
    radix_sort(arr);
    
    for (int i = 0; i < SIZE(arr); ++i)
        cout << arr[i] << ' ';
    cout << endl;

    return 0;
}
