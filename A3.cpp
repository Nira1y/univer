#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
long long merge(vector <double>& a, vector<double>& buf, int left, int mid, int right){
    int idx_left = 0, idx_right = 0, idx_res = 0; //left - глобальный левый, idx_left - левый в массиве, idx_res - индекс внутри буфера
    long long invertion_count = 0;
    for(;left + idx_left < mid and mid + idx_right < right;){
        if(a[left + idx_left] >= a[mid + idx_right]){
            buf[left + idx_res] = a[left + idx_left];
            idx_left++;
        }
        else{
            buf[left + idx_res] = a[mid + idx_right];
            idx_right++;
            invertion_count += mid - (left + idx_left); // если число из правой части меньше, чем в левой, добавляем инверсии, равные текущей длине левой части - индекс текущего левого элемента
        }
        idx_res++;
    }
    for(;left + idx_left<mid;){
        buf[left + idx_res] = a[left + idx_left];
        idx_left++;
        idx_res++;
    }
    for(;mid + idx_right < right;){
        buf[left + idx_res] = a[mid + idx_right];
        idx_right++;
        idx_res++;
    }
    for(left; left < right; left++){
        a[left] = buf[left];
    }

    return invertion_count;

}
long long merge_sort(vector <double>& a, vector<double>& buf, int left, int right){
    long long invertion_count = 0;
    if (right - left <= 1) return invertion_count; //право всегда не включительно

    int mid = (left + right) / 2;
    
    invertion_count += merge_sort(a, buf, left, mid); //добавляем инверсии из каждой части массива
    invertion_count += merge_sort(a, buf, mid, right);
    invertion_count += merge(a, buf, left, mid, right); //инверсии после слияния

    return invertion_count;
}

int main(){
    ifstream input("input.txt");
    ofstream output("output.txt");
    int n;
    input >> n;

    vector <double> soldiers;
    for (int i = 0; i < n; i++){
        double heigh;
        string name;
        input >> heigh >> name;
        soldiers.push_back(heigh);
    }
    vector <double> buf (soldiers.size());

    long long invertion_count = merge_sort(soldiers, buf, 0, soldiers.size()); // счетчик инверсий после сортирвовки.
    output << invertion_count;
}