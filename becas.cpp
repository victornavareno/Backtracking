#include <iostream>

using namespace std;

const int N = 4;

int matrizPrioridades[N][3];          // tendremos 4 estudiantes y 3 becas
int vectorEstudiantes[N] = {0};   // por defecto a 0
bool vectorBecas[N+1];                // por defecto todas las posiciones true


bool noHayCeros() {
    bool nohay = true;
    int i = 0;

    while( i < N && nohay){
        if( vectorEstudiantes[i] == 0){
            nohay = false;
        }
        else i++;
    }
    return nohay;
}

void mostrarAsignaciones() {

    for(int i =0 ; i < N ; i++){
        cout<< "Al estudiante "<< i+1 << " se le asigna la beca "<< vectorEstudiantes[i]<<endl;
    }
}


//inicializa la matriz de prioridades a los valores del ejemplo
void cargarMatrizPrioridades() {
    matrizPrioridades[0][0] = 3;
    matrizPrioridades[0][1] = 2;
    matrizPrioridades[0][2] = 4;
    matrizPrioridades[1][0] = 3;
    matrizPrioridades[1][1] = 1;
    matrizPrioridades[1][2] = 2;
    matrizPrioridades[2][0] = 1;
    matrizPrioridades[2][1] = 3;
    matrizPrioridades[2][2] = 2;
    matrizPrioridades[3][0] = 2;
    matrizPrioridades[3][1] = 3;
    matrizPrioridades[3][2] = 1;
}

//inicializa el vectorBecas a true
void cargarVectorBecas(){
    vectorBecas[0] = false;
    for (int i = 1; i <= N; i++)
    {
        vectorBecas[i] = true;
    }
}

//Muestra la matriz de prioridades de forma grafica 
void mostrarMatrizPrioridades(){
    for (int i = 0; i < N; i++)
    {
        cout << "Estudiante " << i + 1 << ": ";
        for (int j = 0; j < 3; j++)
        {
            cout  << matrizPrioridades[i][j] <<  "  ";
           
        }
         cout << endl;
    }
    cout << endl;
    cout << endl;
}

//Comprueba que para un estudiante y una prioridad, esa beca esté disponible
bool posible (int etapa, int prioridad ){
    bool esPosible = false;
        if (vectorBecas[matrizPrioridades[etapa][prioridad]] == true){
            esPosible = true;
        }
    return esPosible;    // devuelve true si el estudiante puede recibir beca
}

void backtrackingBecas(int etapa){
    bool enc = false;
    int prioridad = 0;
    while (prioridad < 3){

        if (posible(etapa, prioridad)){

            vectorEstudiantes[etapa] = matrizPrioridades[etapa][prioridad];
            vectorBecas[matrizPrioridades[etapa][prioridad]]= false;
            enc = true;
        }
        if(enc){
            if (etapa == N-1){
                if(noHayCeros() == true){
                    mostrarAsignaciones();
                }
            }
            else{
                backtrackingBecas(etapa + 1);
                vectorBecas[matrizPrioridades[etapa][prioridad]]= true; //cancelar anotacion
            }
            enc = false;
        }


        prioridad++;
    }
}



int main()
{
    //inicializo las estructuras de dato auxiliares:
    cargarMatrizPrioridades();
    cargarVectorBecas();
    mostrarMatrizPrioridades();

    backtrackingBecas(0);
    if (!noHayCeros()){
        cout<< "No hay solucion"<<endl;
    }



    return 0;
}
