#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// Definir una constante para el tamaño máximo de cada línea
#define MAX_LINE 100

// Definir una constante para el número máximo de líneas
#define MAX_LINES 1000

//compara dos cadenas alfabéticamente
int compare(const char* a, const char* b) {
  	return strcmp(a, b);
}

// Función que intercambia dos punteros a cadenas
void swap(char** a, char** b) {
  	char* temp = *a;
  	*a = *b;
  	*b = temp;
}

//implementa el algoritmo de quicksort para ordenar un array de punteros a cadenas
void quicksort(char** array, int left, int right) {
  // Si el índice izquierdo es mayor o igual que el índice derecho, terminar la recursión
  if (left >= right) {
    return;
  }

  // Elegir un pivote al azar entre el índice izquierdo y el índice derecho
  int pivot = left + rand() % (right - left + 1);

  // Intercambiar el pivote con el último elemento del array
  swap(array[pivot], array[right]);

  // Crear una variable para guardar el índice del primer elemento mayor que el pivote
  int i = left;

  // Recorrer el array desde el índice izquierdo hasta el penúltimo elemento
  for (int j = left; j < right; j++) {
    // Si el elemento actual es menor o igual que el pivote, intercambiarlo con el elemento en el índice i e incrementar i
    if (compare(array[j], array[right]) <= 0) {
      swap(array[i], array[j]);
      i++;
    }
  }

  // Intercambiar el pivote con el elemento en el índice i
  swap(array[i], array[right]);

  // Llamar a quicksort recursivamente para las dos mitades del array
  quicksort(array, left, i - 1);
  quicksort(array, i + 1, right);
}

int main() {
  
  	char* lines[MAX_LINES];// Crear un array de punteros a cadenas vacío
  	int n = 0;// Crear una variable para guardar el número de líneas leídas
  	char line[MAX_LINE];// Crear una variable para guardar la línea actual leída del usuario

  	// Leer la entrada del usuario línea por línea hasta que se ingrese una línea vacía o se alcance el número máximo de líneas
  	while (cin.getline(line, MAX_LINE) && line[0] != '\0' && n < MAX_LINES) {
    // Asignar memoria dinámica para guardar una copia de la línea actual
    	lines[n] = new char[strlen(line) + 1];
    // Copiar la línea actual al array de punteros a cadenas
    	strcpy(lines[n], line);
    	n++;
  	}

  quicksort(lines, 0, n - 1);

  // Imprimir el resultado ordenado alfabéticamente
  for (int i = 0; i < n; i++) {
    cout << lines[i] << endl;
    // Liberar la memoria asignada para cada línea
    delete[] lines[i];
  }

  // Terminar el programa con éxito
  return 0;
}
