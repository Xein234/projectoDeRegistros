#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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

depto_t llenaDepto();
void llenaEdificio(depto_t* ed, int pisos, int deptosPorPiso);
/* int encuentraAdultosMayorEdad(depto_t *edificioPtr, int deptosPorPiso, int pisos, */
/*                        int pisosMayorEdad[], int deptosMayorEdad[], int indicesDeAdultosMayorEdad[]); */

depto_t llenaDepartamento(int piso, int deptoEnPiso) {
  depto_t depto;

  // Esto está en este formato:
  // solicita varlor
  // cumple requisito 1?
  //   no: regresa al inicio
  // cumple requisito 2?
  //   no: regresa al inicio
  //  ...
  //  sal del bloque de código
  while (true) {
    printf(
        "Dame un valor valido para la renta del departamento %d del piso %d: ",
        piso + 1, deptoEnPiso + 1);

    scanf("%f", &depto.renta);
    if (!(3000 <= depto.renta && depto.renta <= 9000)) {
      printf("La renta tiene que ser un numero en [3000, 9000]\n");
      continue;
    }
    break;
  }

  while (true) {
    printf("Dame el numero de adultos en este depto: ");

    scanf("%d", &depto.numAdultos);
    if (depto.numAdultos < 1) {
      printf("Tiene que haber al menos un adulto por depto\n");
      continue;
    }
    break;
  }

  for (int i = 0; i < depto.numAdultos; i++) {
    while (true) {
      printf("Dame la edad del adulto numero %d: ", i + 1);
      scanf("%d", &depto.edadesAdultos[i]);
      if (depto.edadesAdultos[i] < 0) {
        printf("Tiene que ser un numero positivo\n");
        continue;
      }
      break;
    }
  }

  return depto;
}

void llenaEdificio(depto_t *edificioPtr, int deptosPorPiso, int pisos) {
  for (int deptoActual = 0; deptoActual < deptosPorPiso; deptoActual++) {
    for (int pisoActual = 0; pisoActual < pisos; pisoActual++) {
      if (pisoActual == 0 && deptoActual == 0) {
        continue;
      }
      *(edificioPtr + (pisoActual * deptosPorPiso + deptoActual)) =
          llenaDepartamento(pisoActual, deptoActual);
    }
  }
}

int encuentraAdultosMayorEdad(depto_t *edificioPtr, int deptosPorPiso, int pisos,
                       int pisosMayorEdad[], int deptosMayorEdad[],
                       int indicesDeAdultosMayorEdad[], int* mayorEdad) {

  int edadActual = (edificioPtr + 1)->edadesAdultos[0];
  *mayorEdad = edadActual;
  pisosMayorEdad[0] = 0;
  deptosMayorEdad[0] = 1;
  indicesDeAdultosMayorEdad[0] = 0;
  int nextIndex = 1;


  depto_t structActual;

  for (int deptoActual = 0; deptoActual < deptosPorPiso; deptoActual++) {
    for (int pisoActual = 0; pisoActual < pisos; pisoActual++) {

      if ( deptoActual == 0 && pisoActual == 0 ) {
        continue;
      }

      structActual = *(edificioPtr + (pisoActual * deptosPorPiso + deptoActual));
      for (int adulto = 0; adulto < structActual.numAdultos; adulto++) {
        edadActual = structActual.edadesAdultos[adulto];

        if (edadActual < *mayorEdad) {
          continue;
        }

        if (edadActual > *mayorEdad) {
          *mayorEdad = edadActual;
          pisosMayorEdad[0] = pisoActual;
          deptosMayorEdad[0] = deptoActual;
          indicesDeAdultosMayorEdad[0] = adulto;
          nextIndex = 1;
          continue;
        }

        pisosMayorEdad[nextIndex] = pisoActual;
        deptosMayorEdad[nextIndex] = deptoActual;
        indicesDeAdultosMayorEdad[nextIndex] = adulto;
        nextIndex++;
      }
    }
  }

  return nextIndex;
}

void printAdultosDeMayorEdad(int pisosMayorEdad[], int deptosMayorEdad[], int indicesAdultosDeMayorEdad[],
                             int anios, int cantidad)
{
  printf("Los adultos de mayor edad en el edificio son:\n");
  for (int i = 0; i < cantidad; ++i) {
    printf("el adulto numero %d del piso %d y departamento %d\n",
           indicesAdultosDeMayorEdad[i] + 1, pisosMayorEdad[i] + 1,
           deptosMayorEdad[i] + 1);
  }
  printf("y todos tienen %d anios\n", anios);
  printf("\n");
}

int encuentraDeptosMayorRenta(depto_t *edificioPtr, int deptosPorPiso, int pisos,
                       int pisosMayorRenta[], int depatosMayorRenta[],
                     int* mayorRenta) {
  perror("Aun no implementado");

  int nextIndex;
  return nextIndex;
}

void printDeptosMayorRenta(int pisosMayorRenta[], int deptosMayorRenta[],
                           float renta, int cantidad) {
  perror("Aun no implementado");
}

int encuentraDeptosConPerro(depto_t* edificioPtr, int deptosPorPiso, int pisos, int pisosConPerro[], int deptosConPerro[]) {
  depto_t structActual;
  int nextIndex = 0;

  return nextIndex;
}

void printDeptosConPerro(int pisosConPerro[], int deptosConPerro[], int cantidad) {
  printf("Los departamentos con al menos un perro son:\n");
  for (int i = 0; i < cantidad; ++i) {
    printf("el departamento %d del piso %d\n", deptosConPerro[i], pisosConPerro[i]);
  }
  printf("\n");
}

int encuentraDeptosConGato(depto_t* edificioPtr, int deptosPorPiso, int pisos, int pisosConGato[], int deptosConGato[]) {
  depto_t structActual;
  int nextIndex = 0;
  return nextIndex;
}

void printDeptosConGato(int pisosConGato[], int deptosConGato[], int cantidad) {
  printf("Los departamentos con al menos un gato son:\n");
  for (int i = 0; i < cantidad; ++i) {
    printf("el departamento %d del piso %d\n", deptosConGato[i], pisosConGato[i]);
  }
  printf("\n");
}

int encuentraDeptosConOtraMascota(depto_t* edificioPtr, int deptosPorPiso, int pisos, int pisosConOtraMascota[], int deptosConOtraMascota[]) {
  depto_t structActual;
  int nextIndex = 0;
  return nextIndex;
}

void printDeptosConOtraMascota(int pisosConOtraMascota[], int deptosConOtraMascota[], int cantidad) {
  printf("Los departamentos con al menos una mascota que no es perro ni gato son:\n");
  for (int i = 0; i < cantidad; ++i) {
    printf("el departamento %d del piso %d\n", deptosConOtraMascota[i], pisosConOtraMascota[i]);
  }
  printf("\n");
}

int encuentraDeptosMenosIngresos(depto_t* edificioPtr, int deptosPorPiso, int pisos, int pisosConMenosIngresos[], int deptosConMenosIngresos[]) {
  depto_t structActual;
  int nextIndex = 0;
  return nextIndex;
}

void printDeptosMenosIngreso(int pisosMenosIngresos[], int deptosMenosIngresos[], int cantidad) {
  printf("Los departamentos con menos ingresos son:\n");
  for (int i = 0; i < cantidad; ++i) {
    printf("el departamento %d del piso %d\n", deptosMenosIngresos[i], pisosMenosIngresos[i]);
  }
  printf("\n");
}

int sumaRenta(depto_t* edificioPtr, int deptosPorPiso, int pisos) {
  float rentaAcumulada;

  return rentaAcumulada;
}

int encuentraNiniosMenorEdad(depto_t *edificioPtr, int deptosPorPiso, int pisos,
                       int pisosMenorEdad[], int deptosMenorEdad[],
                       int indicesDeNiniosMenorEdad[]) {
  int nextIndex = 0;
  return nextIndex;
}

void printNiniosMenorEdad(int pisosNiniosMenorEdad[], int deptosNiniosMenorEdad[], int indicesNiniosMenorEdad[],
                             int anios, int cantidad)
{
  printf("Los ninios de menor edad en el edificio son:\n");
  for (int i = 0; i < cantidad; ++i) {
    printf("el ninio numero %d del piso %d y departamento %d\n",
           indicesNiniosMenorEdad[i] + 1, pisosNiniosMenorEdad[i] + 1,
           deptosNiniosMenorEdad[i] + 1);
  }
  printf("\n");
}
