#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
void bubble_sort(vector<int>& time, vector<int>& index, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(time[j+1] > time[j]){
                int temp = time[j];
                time[j] = time[j+1];
                time[j+1] = temp;

                int temp_index = index[j];
                index[j] = index[j+1];
                index[j+1] = temp_index;
            }      
        }
    }
}

int main(){
    vector<int> times;
    vector<int> indexes;
    ifstream input("c.in");
    ofstream output("c.out");

    int n;
    input >> n;
    for (int i = 0; i < n; i++){
        int time;
        input >> time;
        times.push_back(time);

        indexes.push_back(i+1);
    }

    bubble_sort(times, indexes, n);

    for(int i = 0; i < n; i++){
        output << indexes[i] << ' ';
    }
}