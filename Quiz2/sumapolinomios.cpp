#include <stdio.h>

int main() {
    // Declarar variables
    int numPolinomios, gradoMaximo;

    // Solicita cantidad de polinomios y máximo grado 
    printf("Ingrese el número de polinomios: ");
    scanf("%d", &numPolinomios);

    printf("Ingrese el máximo grado: ");
    scanf("%d", &gradoMaximo);

    // Creación de la matriz para guardar la suma de los coeficientes
    int resultado[gradoMaximo + 1];
    for (int i = 0; i <= gradoMaximo; i++) {
        resultado[i] = 0;
    }

    // Leer los polinomios ingresados por el usuario
    for (int i = 0; i < numPolinomios; i++) {
        printf("\nIngrese los %d coeficientes, desde el mayor hasta el menor grado, del polinomio %d separados por espacios:\n", gradoMaximo + 1, i + 1 );
        
        // Leer los coeficientes del polinomio
        int coeficiente;
        for (int j = gradoMaximo; j >= 0; j--) {
            
            if (scanf("%d", &coeficiente) != 1) {
                printf("Entrada inválida. Asegúrese de ingresar %d coeficientes.\n", gradoMaximo + 1);
                return 1;
            }
            resultado[j] += coeficiente;
        }

        // Ignorar coeficientes adicionales en la entrada
        while (getchar() != '\n');
    }

    // Imprimir el resultado de la suma de los polinomios
    printf("\nSuma de los polinomios: ");
    int primerTermino = 1;
    // Recorrer la matriz con los coeficientes sumados
    for (int i = gradoMaximo; i >= 0; i--) {
        if (resultado[i] != 0) {
            if (!primerTermino) {
                if (resultado[i] > 0) {
                    printf(" + ");
                } else {
                    printf(" - ");
                }
            } else if (resultado[i] < 0) {
                printf("-");
            }

            printf("%d", resultado[i] < 0 ? -resultado[i] : resultado[i]);

            if (i > 0) {
                printf("x^%d", i);
            }
            primerTermino = 0;
        }
    }
    // Si no se imprimió ningún término, imprimir 0
    if (primerTermino) {
        printf("0");
    }

    printf("\n");

    return 0;
}
