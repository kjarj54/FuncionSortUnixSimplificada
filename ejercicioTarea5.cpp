#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;


#define MAX_LINE 100
#define MAX_LINES 1000

int compare(const char* a, const char* b) {
  	return strcmp(a, b);
}

void swap(char** a, char** b) {
  	char* temp = *a;
  	*a = *b;
  	*b = temp;
}


void quicksort(char** array, int left, int right) {
  if (left >= right) {
    return;
  }

  int pivot = left + rand() % (right - left + 1);
  swap(array[pivot], array[right]);

  int i = left;

  for (int j = left; j < right; j++) {
    if (compare(array[j], array[right]) <= 0) {
      swap(array[i], array[j]);
      i++;
    }
  }

  swap(array[i], array[right]);

  quicksort(array, left, i - 1);
  quicksort(array, i + 1, right);
}

int main() {
  
  	char* lines[MAX_LINES];
  	int n = 0;// Crear una variable para guardar el n�mero de l�neas le�das
  	char line[MAX_LINE];// Crear una variable para guardar la l�nea actual le�da del usuario

  	while (cin.getline(line, MAX_LINE) && line[0] != '\0' && n < MAX_LINES) {
    	lines[n] = new char[strlen(line) + 1];
    	strcpy(lines[n], line);
    	n++;
  	}

  quicksort(lines, 0, n - 1);

  cout<<endl<<"El orden de las lineas anteriores es:"<<endl;

  for (int i = 0; i < n; i++) {
    cout << lines[i] << endl;
    delete[] lines[i];
  }

  return 0;
}
