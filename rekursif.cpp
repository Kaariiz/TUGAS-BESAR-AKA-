
#include <iostream>
#include <string>

using namespace std;
using namespace chrono; // untuk hitung waktu eksekusi

const int nmax = 130;

struct tugas {
    string nama;
    int deadline;
};

typedef struct tugas arrTugas[nmax];

// untuk menggabungkan dua bagian array yang sudah urut
void gabung(arrTugas tugasArr, arrTugas left, arrTugas right, int low, int mid, int high) {
    int i = 0, j = 0, k = low; // indeks untuk left, right, dan tugasArr
    int nL = mid - low + 1; // panjang bagian kiri
    int nR = high - mid;    // panjang bagian kanan

    // Gabungkan kembali ke dalam tugasArr
    while (i < nL && j < nR) {
        if (left[i].deadline <= right[j].deadline) {
            tugasArr[k++] = left[i++];
        } else {
            tugasArr[k++] = right[j++];
        }
    }

    // Salin elemen sisa dari left dan right
    while (i < nL) {
        tugasArr[k++] = left[i++];
    }
    while (j < nR) {
        tugasArr[k++] = right[j++];
    }
}

void mergeSort(arrTugas tugasArr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        int nL = mid - low + 1; // panjang bagian kiri
        int nR = high - mid;    // panjang bagian kanan

        // Rekursi untuk membagi array menjadi dua bagian
        mergeSort(tugasArr, low, mid);
        mergeSort(tugasArr, mid + 1, high);

        // Array sementara untuk bagian kiri dan kanan
        tugas left[nL], right[nR];

        // Salin data ke array sementara di mergeSort
        for (int i = 0; i < nL; i++) {
            left[i] = tugasArr[low + i];
        }
        for (int j = 0; j < nR; j++) {
            right[j] = tugasArr[mid + 1 + j];
        }

        // Gabungkan kedua bagian yang sudah terurut
        gabung(tugasArr, left, right, low, mid, high);
    }
}

int main() {
    arrTugas task = {
        {"Kerjakan laporan AI", 3},
        {"Belajar Struktur Data", 5},
        {"Belajar Basis Data", 2},
        {"Persiapan Presentasi", 4},
        {"Latihan Coding", 1},
        {"Kerjakan Tugas Akhir", 7},
        {"Belajar Pemrograman", 6},
        {"Diskusi Kelompok", 8},
    };

    int n = 8;

    cout << "Daftar Tugas Sebelum Diurutkan" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << task[i].nama << ", Deadline: " << task[i].deadline << " hari" << endl;
    }

    mergeSort(task, 0, n - 1);

    cout << endl;
    cout << "Daftar Tugas Setelah Diurutkan Berdasarkan Deadline" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << task[i].nama << ", Deadline: " << task[i].deadline << " hari" << endl;
    }

    return 0;
}
