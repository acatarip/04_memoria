#include <iostream>
using namespace std;

void nextFit(int blockSize[], int m, const int processSize[], int n) {
    // Arreglo dinámico para guardar el bloque asignado a cada proceso (-1 si no se asigna)
    int* allocation = new int[n];
    int j = 0; // Apuntador a la ultima posicion examinada en el arreglo de bloques
    
    for (int i = 0; i < n; ++i)
                allocation[i] = -1;

    // Algoritmo Next-Fit
    for (int i = 0; i < n; ++i) {
        int count = 0;
        
        while (count < m) {   // Mientras no se exceda el maximo de bloques
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i]; // Particionamiento dinámico
                break;
            }
            j = (j + 1) % m; // Si llega al final, volverá al principio 
            count++;
        }
    }

    // Salida
    cout << "\nNo. Proceso\tTamano Proceso\tNo. Bloque\tEspacio Libre Bloque\n";
    for (int i = 0; i < n; ++i) {
        cout << " " << (i + 1) << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1) 
		cout << (allocation[i] + 1) << "\t\t" << blockSize[allocation[i]];
        else
		cout << "No Asignado\tN/A";
        cout << "\n";
    }

    delete[] allocation; // libera memoria
}

int main() {
    int blockSize[]   = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 301};

    int m = sizeof(blockSize)   / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    nextFit(blockSize, m, processSize, n);

    return 0;
}
