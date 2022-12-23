#ifndef TRABAJO_EN_EQUIPO_H
#define TRABAJO_EN_EQUIPO_H

struct foo {
    int member;
};

const int MAX_HABITANTES_POR_DEPTO = 6;
const float MAX_RENTA = 9000;
const float MIN_RENTA = 3000;

typedef struct mascotas_t {
  int numPerros;
  int numGatos;
  int numOtras;
} mascotas_t;


typedef struct depto_t {
  float      renta;
  mascotas_t mascotas;
  int        numNinios;
  int        edadesNinios[5];
  int        numAdultos;
  int        edadesAdultos[6];
  float      ingreso;
} depto_t;

depto_t llenaDepartamento(int piso, int deptoEnPiso);


void llenaEdificio(depto_t *edificioPtr, int deptosPorPiso, int pisos);

int encuentraAdultosMayorEdad(depto_t *edificioPtr, int deptosPorPiso, int pisos,
                       int pisosMayorEdad[], int deptosMayorEdad[],
                       int indicesAdultosMayorEdad[], int* mayorEdad);

void printAdultosDeMayorEdad(int pisosMayorEdad[], int deptosMayorEdad[], int indicesAdultosDeMayorEdad[], int anios, int cantidad);

int encuentraDeptosMayorRenta(depto_t *edificioPtr, int deptosPorPiso, int pisos,
                       int pisosMayorRenta[], int deptosMayorRenta[],
                                                   float* mayorRenta);


void printDeptosMayorRenta(int pisosMayorRenta[], int deptosMayorRenta[],
                           float renta, int cantidad);

int encuentraDeptosConPerro(depto_t* edificioPtr, int deptosPorPiso, int pisos, int pisosConPerro[], int deptosConPerro[]);

void printDeptosConPerro(int pisosConPerro[], int deptosConPerro[], int cantidad);

int encuentraDeptosConGato(depto_t* edificioPtr, int deptosPorPiso, int pisos, int pisosConGato[], int deptosConGato[]);

void printDeptosConGato(int pisosConGato[], int deptosConGato[], int cantidad);

int encuentraDeptosConOtraMascota(depto_t* edificioPtr, int deptosPorPiso, int pisos, int pisosConOtraMascota[], int deptosConOtraMascota[]);

void printDeptosConOtraMascota(int pisosConOtraMascota[], int deptosConOtraMascota[], int cantidad);


int encuentraDeptosMenosIngresos(depto_t* edificioPtr, int deptosPorPiso, int pisos, int pisosConMenosIngresos[], int deptosConMenosIngresos[], float* menorIngreso);

void printDeptosMenosIngreso(int pisosMenosIngresos[], int deptosMenosIngresos[], int cantidad);

int sumaRenta(depto_t* edificioPtr, int deptosPorPiso, int pisos);

int encuentraNiniosMenorEdad(depto_t *edificioPtr, int deptosPorPiso, int pisos,
                       int pisosMenorEdad[], int deptosMenorEdad[],
                       int indicesDeNiniosMenorEdad[]);

void printNiniosMenorEdad(int pisosNiniosMenorEdad[], int deptosNiniosMenorEdad[], int indicesNiniosMenorEdad[], int anios, int cantidad);

int CantNinios(depto_t *edificioPtr, int n, int m);
#endif
