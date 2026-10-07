#include <iostream>
using namespace std;

void bestFit(int blockSize[], int m, const int processSize[], int n) {
    // Arreglo dinámico para guardar el bloque asignado a cada proceso (-1 si no se asigna)
    int* allocation = new int[n];

    for (int i = 0; i < n; ++i)
                allocation[i] = -1;

    // Algoritmo Best-Fit
    for (int i = 0; i < n; ++i) {
        int bestIdx = -1;                           // Se restablece el mejor bloque para proceso i
        for (int j = 0; j < m; ++j) {
            if (blockSize[j] >= processSize[i]) {
                // Si es el primer bloque o si su tamaño es menor que el mejor bloque actual
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j;                    // Se actualiza el id del mejor bloque
                }
            }
        }

        // Si se encontro un bloque apto
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i]; // Particionamiento dinámico
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

    bestFit(blockSize, m, processSize, n);
    return 0;
}
