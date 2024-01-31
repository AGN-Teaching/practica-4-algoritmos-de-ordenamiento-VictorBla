#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <cmath>
#include "ordenamiento_t.h"
#include "ordenamiento_rec_t.h"
void imprimir_info_arreglo(int numero_arreglo, int tamano_arreglo) {
    std::cout << "** Arreglo No. " << numero_arreglo << " **\n";
    std::cout << "Creando arreglo de tamano " << tamano_arreglo << "\n";
}
void ejecutar_algoritmo(std::vector<int>& A, char algoritmo, double& tiempo) {
    std::vector<int> aux = A;
    std::chrono::steady_clock::time_point inicio = std::chrono::steady_clock::now();
    switch (algoritmo) {
        case 'i':
            insertion_sort(aux.data(), aux.size());
            break;
        case 's':
            selection_sort(aux.data(), aux.size());
            break;
        case 'b':
            bubblesort(aux.data(), aux.size());
            break;
        case 'm':
            merge_sort(aux.data(), 0, aux.size() - 1);
            break;
        case 'q':
            quicksort(aux.data(), 0, aux.size() - 1);
            break;
    }
    std::chrono::steady_clock::time_point fin = std::chrono::steady_clock::now();
    std::chrono::duration<double> duracion = std::chrono::duration_cast<std::chrono::duration<double>>(fin - inicio);
    tiempo = duracion.count();
}
int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Uso: " << argv[0] << " <n> <m>\n";
        return 1;
    }
    int n = std::stoi(argv[1]);
    int m = std::stoi(argv[2]);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10 * n);
    std::vector<double> tiempos_insertion;
    std::vector<double> tiempos_selection;
    std::vector<double> tiempos_bubble;
    std::vector<double> tiempos_merge;
    std::vector<double> tiempos_quick;
    for (int i = 0; i < m; i++) {
        std::vector<int> A(n);
        for (int &a : A) {
            a = dis(gen);
        }
        imprimir_info_arreglo(i + 1, n);
        double tiempo;
        // INSERTION SORT
        ejecutar_algoritmo(A, 'i', tiempo);
        tiempos_insertion.push_back(tiempo);
        // SELECTION SORT
        ejecutar_algoritmo(A, 's', tiempo);
        tiempos_selection.push_back(tiempo);
        // BUBBLE SORT
        ejecutar_algoritmo(A, 'b', tiempo);
        tiempos_bubble.push_back(tiempo);
        // MERGE SORT
        ejecutar_algoritmo(A, 'm', tiempo);
        tiempos_merge.push_back(tiempo);
        // QUICKSORT
        ejecutar_algoritmo(A, 'q', tiempo);
        tiempos_quick.push_back(tiempo);
    }
    // Cálculo de promedios
    double avg_time_insertion = std::accumulate(tiempos_insertion.begin(), tiempos_insertion.end(), 0.0) / m;
    double avg_time_selection = std::accumulate(tiempos_selection.begin(), tiempos_selection.end(), 0.0) / m;
    double avg_time_bubble = std::accumulate(tiempos_bubble.begin(), tiempos_bubble.end(), 0.0) / m;
    double avg_time_merge = std::accumulate(tiempos_merge.begin(), tiempos_merge.end(), 0.0) / m;
    double avg_time_quick = std::accumulate(tiempos_quick.begin(), tiempos_quick.end(), 0.0) / m;
    // Cálculo de desviaciones estándar
    double stddev_time_insertion = std::sqrt(std::inner_product(tiempos_insertion.begin(), tiempos_insertion.end(), tiempos_insertion.begin(), 0.0) / m - avg_time_insertion * avg_time_insertion);
    double stddev_time_selection = std::sqrt(std::inner_product(tiempos_selection.begin(), tiempos_selection.end(), tiempos_selection.begin(), 0.0) / m - avg_time_selection * avg_time_selection);
    double stddev_time_bubble = std::sqrt(std::inner_product(tiempos_bubble.begin(), tiempos_bubble.end(), tiempos_bubble.begin(), 0.0) / m - avg_time_bubble * avg_time_bubble);
    double stddev_time_merge = std::sqrt(std::inner_product(tiempos_merge.begin(), tiempos_merge.end(), tiempos_merge.begin(), 0.0) / m - avg_time_merge * avg_time_merge);
    double stddev_time_quick = std::sqrt(std::inner_product(tiempos_quick.begin(), tiempos_quick.end(), tiempos_quick.begin(), 0.0) / m - avg_time_quick * avg_time_quick);
    // Imprimir resultados
    std::cout << "\nResultados:\n";
    printf("%-15s%-15s%-15s\n", "Algoritmo", "Promedio", "Desviacion");
    printf("%-15s%-15.9f%-15.9f\n", "Insertion Sort", avg_time_insertion, stddev_time_insertion);
    printf("%-15s%-15.9f%-15.9f\n", "Selection Sort", avg_time_selection, stddev_time_selection);
    printf("%-15s%-15.9f%-15.9f\n", "Bubble Sort", avg_time_bubble, stddev_time_bubble);
    printf("%-15s%-15.9f%-15.9f\n", "Merge Sort", avg_time_merge, stddev_time_merge);
    printf("%-15s%-15.9f%-15.9f\n", "Quick Sort", avg_time_quick, stddev_time_quick);
    return 0;
}
