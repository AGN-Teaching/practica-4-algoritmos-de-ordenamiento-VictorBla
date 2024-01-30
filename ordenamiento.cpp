
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <cmath>
#include "ordenamiento_t.h"
#include "ordenamiento_rec_t.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Uso: " << argv[0] << " <n> <m>\n";
        return 1;
    }

    int n = std::stoi(argv[1]);
    int m = std::stoi(argv[2]);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10 * n);

    double total_time_insertion = 0, total_time_insertion_sq = 0;
    double total_time_selection = 0, total_time_selection_sq = 0;
    double total_time_bubble = 0, total_time_bubble_sq = 0;
    double total_time_merge = 0, total_time_merge_sq = 0;
    double total_time_quick = 0, total_time_quick_sq = 0;

    std::cout << "Tamaño del arreglo: " << n << "\n";
    std::cout << "Número de repeticiones: " << m << "\n";

    for (int i = 0; i < m; i++) {
        std::vector<int> A(n);
        for (int &a : A) {
            a = dis(gen);
        }

        std::vector<int> B(n);
        std::chrono::steady_clock::time_point start, end;
        std::chrono::duration<double> elapsed_seconds;

        std::copy(A.begin(), A.end(), B.begin());
        start = std::chrono::steady_clock::now();
        insertion_sort(&B[0], B.size());
        end = std::chrono::steady_clock::now();
        elapsed_seconds = end - start;
        total_time_insertion += elapsed_seconds.count();
        total_time_insertion_sq += elapsed_seconds.count() * elapsed_seconds.count();

        std::copy(A.begin(), A.end(), B.begin());
        start = std::chrono::steady_clock::now();
        selection_sort(&B[0], B.size());
        end = std::chrono::steady_clock::now();
        elapsed_seconds = end - start;
        total_time_selection += elapsed_seconds.count();
        total_time_selection_sq += elapsed_seconds.count() * elapsed_seconds.count();

        std::copy(A.begin(), A.end(), B.begin());
        start = std::chrono::steady_clock::now();
        bubblesort(&B[0], B.size());
        end = std::chrono::steady_clock::now();
        elapsed_seconds = end - start;
        total_time_bubble += elapsed_seconds.count();
        total_time_bubble_sq += elapsed_seconds.count() * elapsed_seconds.count();

        std::copy(A.begin(), A.end(), B.begin());
        start = std::chrono::steady_clock::now();
        merge_sort(&B[0], 0, B.size() - 1);
        end = std::chrono::steady_clock::now();
        elapsed_seconds = end - start;
        total_time_merge += elapsed_seconds.count();
        total_time_merge_sq += elapsed_seconds.count() * elapsed_seconds.count();

        std::copy(A.begin(), A.end(), B.begin());
        start = std::chrono::steady_clock::now();
        quicksort(&B[0], 0, B.size() - 1);
        end = std::chrono::steady_clock::now();
        elapsed_seconds = end - start;
        total_time_quick += elapsed_seconds.count();
        total_time_quick_sq += elapsed_seconds.count() * elapsed_seconds.count();
    }

    double avg_time_insertion = total_time_insertion / m;
    double stddev_time_insertion = std::sqrt(total_time_insertion_sq / m - avg_time_insertion * avg_time_insertion);
    std::cout << "Tiempo promedio de Insertion sort: " << avg_time_insertion << " segundos\n";
    std::cout << "Desviación estándar de Insertion sort: " << stddev_time_insertion << " segundos\n";

    double avg_time_selection = total_time_selection / m;
    double stddev_time_selection = std::sqrt(total_time_selection_sq / m - avg_time_selection * avg_time_selection);
    std::cout << "Tiempo promedio de Selection sort: " << avg_time_selection << " segundos\n";
    std::cout << "Desviación estándar de Selection sort: " << stddev_time_selection << " segundos\n";

    double avg_time_bubble = total_time_bubble / m;
    double stddev_time_bubble = std::sqrt(total_time_bubble_sq / m - avg_time_bubble * avg_time_bubble);
    std::cout << "Tiempo promedio de Bubble sort: " << avg_time_bubble << " segundos\n";
    std::cout << "Desviación estándar de Bubble sort: " << stddev_time_bubble << " segundos\n";

    double avg_time_merge = total_time_merge / m;
    double stddev_time_merge = std::sqrt(total_time_merge_sq / m - avg_time_merge * avg_time_merge);
    std::cout << "Tiempo promedio de Merge sort: " << avg_time_merge << " segundos\n";
    std::cout << "Desviación estándar de Merge sort: " << stddev_time_merge << " segundos\n";

    double avg_time_quick = total_time_quick / m;
    double stddev_time_quick = std::sqrt(total_time_quick_sq / m - avg_time_quick * avg_time_quick);
    std::cout << "Tiempo promedio de Quick sort: " << avg_time_quick << " segundos\n";
    std::cout << "Desviación estándar de Quick sort: " << stddev_time_quick << " segundos\n";

    return 0;
}
