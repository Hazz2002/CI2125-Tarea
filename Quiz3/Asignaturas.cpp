#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

// Función para solicitar el código de la asignatura
void solicitarCodigo(char codigo[]) {
    cout << "Ingrese el codigo de la asignatura (7 caracteres): ";
    cin >> codigo;
}

// Función para solicitar el nombre de la asignatura
void solicitarNombre(char nombre[]) {
    cout << "Ingrese el nombre de la asignatura (20 caracteres): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
    cin.getline(nombre, 21);
}

// Función para escribir los datos en el archivo
void escribirEnArchivo(const string& filename, const char codigo[], const char nombre[]) {
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Error al abrir el archivo " << filename << endl;
        return;
    }
    file << codigo << "   " << nombre << endl;
    file.close();
}

// Función principal
int main() {
    const string filename = "asignaturas.txt";
    char codigo[8]; // 7 caracteres + 1 para el terminador nulo
    char nombre[21]; // 20 caracteres + 1 para el terminador nulo
    char continuar;

    do {
        // Solicitar datos
        solicitarCodigo(codigo);
        solicitarNombre(nombre);

        // Guardar en el archivo
        escribirEnArchivo(filename, codigo, nombre);

        // Preguntar si desea agregar otra asignatura
        cout << "¿Desea agregar otra asignatura? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    cout << "Datos guardados en el archivo " << filename << " exitosamente." << endl;

    return 0;
}