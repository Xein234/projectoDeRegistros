#include "trabajoEnEquipo.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

departamento_t llenaDepartamento(int piso, int depto) {
  departamento_t departamento;

  // Esto est� en este formato:
  // solicita varlor
  // cumple requisito 1?
  //   no: regresa al inicio
  // cumple requisito 2?
  //   no: regresa al inicio
  //  ...
  //  sal del bloque de c�digo
  while (true) {
    printf(
        "Dame un valor valido para la renta del departamento %d del piso %d: ",
        piso + 1, depto + 1);

    scanf("%f", &departamento.renta);
    if (!(3000 <= departamento.renta && departamento.renta <= 9000)) {
      printf("La renta tiene que ser un numero en [3000, 9000]\n");
      continue;
    }
    break;
  }

  while (true) {
    printf("Dame el numero de adultos en este departamento: ");

    scanf("%d", &departamento.numAdultos);
    if (departamento.numAdultos < 1) {
      printf("Tiene que haber al menos un adulto por departamento\n");
      continue;
    }
    break;
  }

  for (int i = 0; i < departamento.numAdultos; i++) {
    while (true) {
      printf("Dame la edad del adulto numero %d: ", i + 1);
      scanf("%d", &departamento.edadesAdultos[i]);
      if (departamento.edadesAdultos[i] < 0) {
        printf("Tiene que ser un numero positivo\n");
        continue;
      }
      break;
    }
  }

  return departamento;
}

void llenaEdificio(departamento_t *edificioPtr, int depsPorPiso, int pisos) {
  for (int deptoActual = 0; deptoActual < depsPorPiso; deptoActual++) {
    for (int pisoActual = 0; pisoActual < pisos; pisoActual++) {
      if (pisoActual == 0 && deptoActual == 0) {
        continue;
      }
      *(edificioPtr + (pisoActual * depsPorPiso + deptoActual)) =
          llenaDepartamento(pisoActual, deptoActual);
    }
  }
}

int adultosDeMayorEdad(departamento_t *edificioPtr, int depsPorPiso, int pisos,
                       int pisosMayorEdad[], int departamentosMayorEdad[],
                       int indicesDeAdultosMayorEdad[], int* mayorEdad) {

  int edadActual = (edificioPtr + 1)->edadesAdultos[0];
  *mayorEdad = edadActual;
  pisosMayorEdad[0] = 0;
  departamentosMayorEdad[0] = 1;
  indicesDeAdultosMayorEdad[0] = 0;
  int nextIndex = 1;


  departamento_t structActual;

  for (int deptoActual = 0; deptoActual < depsPorPiso; deptoActual++) {
    for (int pisoActual = 0; pisoActual < pisos; pisoActual++) {

      if ( deptoActual == 0 && pisoActual == 0 ) {
        continue;
      }

      structActual = *(edificioPtr + (pisoActual * depsPorPiso + deptoActual));
      for (int adulto = 0; adulto < structActual.numAdultos; adulto++) {
        edadActual = structActual.edadesAdultos[adulto];

        if (edadActual < *mayorEdad) {
          continue;
        }

        if (edadActual > *mayorEdad) {
          *mayorEdad = edadActual;
          pisosMayorEdad[0] = pisoActual;
          departamentosMayorEdad[0] = deptoActual;
          indicesDeAdultosMayorEdad[0] = adulto;
          nextIndex = 1;
          continue;
        }

        pisosMayorEdad[nextIndex] = pisoActual;
        departamentosMayorEdad[nextIndex] = deptoActual;
        indicesDeAdultosMayorEdad[nextIndex] = adulto;
        nextIndex++;
      }
    }
  }

  return nextIndex;
}

void printAdultosDeMayorEdad(int pisosMayorEdad[], int departamentosMayorEdad[], int indicesAdultosDeMayorEdad[],
                             int anios, int cantidad)
{
  printf("Los adultos de mayor edad en el edificio son:\n");
  for (int i = 0; i < cantidad; ++i) {
    printf("el adulto numero %d del piso %d y departamento %d\n",
           indicesAdultosDeMayorEdad[i] + 1, pisosMayorEdad[i] + 1,
           departamentosMayorEdad[i] + 1);
  }
  printf("y todos tienen %d anios\n", anios);
  printf("\n");
}
