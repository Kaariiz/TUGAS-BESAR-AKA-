#include <iostream>
#include <string>

using namespace std;

const int nmax = 100;
typedef struct tugas arrTugas[nmax];

struct tugas {
    string nama;
    int deadline;
};


void bubbleSort(arrTugas task, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (task[j].deadline > task[j + 1].deadline) {
                tugas temp = task[j];
                task[j] = task[j+1];
                task[j+1] = temp;
            }
        }
    }
}

int main() {
    arrTugas task = {
        {"Kerjakan latihan AI", 3},
        {"Belajar STD", 5},
        {"Belajar SMBD", 3},
        {"Persiapan presentasi", 4},
        {"Latihan coding", 1},
        {"Kerjakan pr AKA", 7},
        {"Belajar PEMSI", 6},
        {"Diskusi Kelompok", 8},
    };

    int n = 8;

    cout << "Daftar Tugas Sebelum Diurutkan" << endl;
    for (int i = 0; i < n; i++) {
        cout << i+1 << ". " << task[i].nama << ", Deadline: " << task[i].deadline << " hari" << endl;
    }

    bubbleSort(task, n);
    cout << "\n";

    cout << "Daftar Tugas Setelah Diurutkan Berdasarkan Deadline" << endl;
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << i+1 << ". " << task[i].nama << ", Deadline: " << task[i].deadline << " hari" << endl;
    }

    return 0;
}
