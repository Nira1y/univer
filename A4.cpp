#include <fstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

void quick_sort(vector<string>& arr, int left, int right) {
    if (left >= right) return;

    int pivot_index = left + (right - left) / 2;
    string pivot = arr[pivot_index];

    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    quick_sort(arr, left, j);
    quick_sort(arr, i, right);
}

void quick_sort(vector<string>& arr) {
    if (!arr.empty()) {
        quick_sort(arr, 0, arr.size() - 1);
    }
}

void bucket_sort(vector<string>& a, int n) {
    vector<vector<string>> buckets(52);

    for (int i = 0; i < n; i++) {
        char first_char = a[i][0];
        if (first_char >= 'A' && first_char <= 'Z') {
            int bucket_index = first_char - 'A';
            buckets[bucket_index].push_back(a[i]);
        } else if (first_char >= 'a' && first_char <= 'z') {
            int bucket_index = 26 + (first_char - 'a');
            buckets[bucket_index].push_back(a[i]);
        }
    }

    for (int i = 0; i < 52; i++) {
        quick_sort(buckets[i]);
    }

    int index = 0;
    for (int i = 0; i < 52; i++) {
        for (string& s : buckets[i]) {
            a[index] = s;
            index++;
        }
    }
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n;
    input >> n;

    if (n == 0) {
        output << "0";
        return 0;
    }

    vector<string> letters;
    for (int i = 0; i < n; i++) {
        string let;
        input >> let;
        letters.push_back(let);
    }

    bucket_sort(letters, n);

    for (int i = 0; i < n; i++) {
        output << letters[i] << '\n';
    }

    return 0;
}