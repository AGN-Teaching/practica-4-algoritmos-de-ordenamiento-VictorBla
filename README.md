[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/ke8zCzPd)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=13579506)
# Práctica 4: Algoritmos de ordenamiento
## Resumen de los resultados:
![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-VictorBla/assets/151650061/612f7682-6f6c-4af1-9182-a868c77cc001)

## Graficas de los resultados:
![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-VictorBla/assets/151650061/51d2d611-b7fe-49b1-9dc6-029cd5ba64b6)
![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-VictorBla/assets/151650061/ece49deb-4fbd-4eb4-8717-2a70f6ee98bd)
![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-VictorBla/assets/151650061/6ae3efb8-c34b-4e83-a310-768d286fd3d6)
![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-VictorBla/assets/151650061/9e631050-7e31-418d-93e8-a62a07ce2cd0)
![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-VictorBla/assets/151650061/e1690c65-6423-4516-ae5f-421fe9e56dcf)
![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-VictorBla/assets/151650061/82b1cc99-f646-4bea-8fa6-f837b09855c7)
![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-VictorBla/assets/151650061/f109c761-a399-4da1-afab-cb20780e736f)
![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-VictorBla/assets/151650061/7c2227c7-d826-422f-a797-24872e3e10b5)
![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-VictorBla/assets/151650061/751f98a1-d502-4d63-826b-12cb17d86bad)



## Analisis de los resultados:
### Insertion Sort (is): 
Este algoritmo parece ser el más rápido para arreglos pequeños (tamaño 5 a 50). Sin embargo, a medida que el tamaño del arreglo aumenta, el tiempo de ejecución de Insertion Sort también aumenta rápidamente. 

### Selection Sort (ss): 
Este algoritmo parece tener un rendimiento similar al de Insertion Sort para arreglos pequeños. Sin embargo, a medida que el tamaño del arreglo aumenta, Selection Sort parece ser más lento que Insertion Sort.

### Bubble Sort (bs): 
Este algoritmo parece ser el más lento para todos los tamaños de arreglo. 

### Merge Sort (ms): 
Este algoritmo parece ser el más rápido para arreglos grandes (tamaño 1000 y más). 

### Quick Sort (qs): 
Este algoritmo parece ser muy rápido para arreglos pequeños (tamaño 5 a 50). A medida que el tamaño del arreglo aumenta, el tiempo de ejecución de Quick Sort también aumenta, pero no tan rápidamente como Insertion Sort o Selection Sort. 
## Conclusiones:
Esta práctica ofrece una valiosa oportunidad para entender cómo los diferentes algoritmos de ordenamiento se comportan en términos de tiempo de ejecución y consistencia, especialmente en relación con el tamaño del arreglo que se está ordenando.No todos los algoritmos de ordenamiento se comportan de la misma manera. Algunos algoritmos, como Insertion Sort y Selection Sort, pueden ser más rápidos para arreglos pequeños, pero su tiempo de ejecución aumenta rápidamente a medida que el tamaño del arreglo crece. Otros algoritmos, como Merge Sort y Quick Sort, pueden ser más eficientes para arreglos grandes. Los resultados experimentales de esta práctica refuerzan lo que se espera teóricamente de estos algoritmos en términos de su complejidad temporal. Esto subraya la importancia de entender la teoría detrás de los algoritmos.
En resumen, esta práctica demuestra la importancia de entender los algoritmos de ordenamiento y cómo se comportan con diferentes tamaños de datos. También destaca la importancia de medir el rendimiento de los algoritmos en la práctica, no sólo en teoría.
## Notas:
Durante la realización de la práctica, me enfrenté a varios desafíos. Inesperadamente, el compilador de C++ que estaba utilizando dejó de funcionar, lo que me obligó a buscar alternativas. Finalmente, encontré un compilador en línea que me permitió continuar con mi trabajo.
Además, al desarrollar el código para ordenamiento.cpp, me encontré con problemas de redefinición en los archivos de los algoritmos, específicamente en ordenamiento_rec_t.h y ordenamiento_t.h. Este obstáculo añadió una capa adicional de complejidad a la tarea.
https://www.onlinegdb.com/online_c++_compiler
