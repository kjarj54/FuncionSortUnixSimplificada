#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// Definir una constante para el tama�o m�ximo de cada l�nea
#define MAX_LINE 100

// Definir una constante para el n�mero m�ximo de l�neas
#define MAX_LINES 1000

//compara dos cadenas alfab�ticamente
int compare(const char* a, const char* b) {
  	return strcmp(a, b);
}

// Funci�n que intercambia dos punteros a cadenas
void swap(char** a, char** b) {
  	char* temp = *a;
  	*a = *b;
  	*b = temp;
}

//implementa el algoritmo de quicksort para ordenar un array de punteros a cadenas
void quicksort(char** array, int left, int right) {
  // Si el �ndice izquierdo es mayor o igual que el �ndice derecho, terminar la recursi�n
  if (left >= right) {
    return;
  }

  // Elegir un pivote al azar entre el �ndice izquierdo y el �ndice derecho
  int pivot = left + rand() % (right - left + 1);

  // Intercambiar el pivote con el �ltimo elemento del array
  swap(array[pivot], array[right]);

  // Crear una variable para guardar el �ndice del primer elemento mayor que el pivote
  int i = left;

  // Recorrer el array desde el �ndice izquierdo hasta el pen�ltimo elemento
  for (int j = left; j < right; j++) {
    // Si el elemento actual es menor o igual que el pivote, intercambiarlo con el elemento en el �ndice i e incrementar i
    if (compare(array[j], array[right]) <= 0) {
      swap(array[i], array[j]);
      i++;
    }
  }

  // Intercambiar el pivote con el elemento en el �ndice i
  swap(array[i], array[right]);

  // Llamar a quicksort recursivamente para las dos mitades del array
  quicksort(array, left, i - 1);
  quicksort(array, i + 1, right);
}

int main() {
  
  	char* lines[MAX_LINES];// Crear un array de punteros a cadenas vac�o
  	int n = 0;// Crear una variable para guardar el n�mero de l�neas le�das
  	char line[MAX_LINE];// Crear una variable para guardar la l�nea actual le�da del usuario

  	// Leer la entrada del usuario l�nea por l�nea hasta que se ingrese una l�nea vac�a o se alcance el n�mero m�ximo de l�neas
  	while (cin.getline(line, MAX_LINE) && line[0] != '\0' && n < MAX_LINES) {
    // Asignar memoria din�mica para guardar una copia de la l�nea actual
    	lines[n] = new char[strlen(line) + 1];
    // Copiar la l�nea actual al array de punteros a cadenas
    	strcpy(lines[n], line);
    	n++;
  	}

  quicksort(lines, 0, n - 1);

  // Imprimir el resultado ordenado alfab�ticamente
  for (int i = 0; i < n; i++) {
    cout << lines[i] << endl;
    // Liberar la memoria asignada para cada l�nea
    delete[] lines[i];
  }

  // Terminar el programa con �xito
  return 0;
}
