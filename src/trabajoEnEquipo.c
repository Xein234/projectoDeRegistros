#include <stdio.h>
#include <string.h>
#include "trabajoEnEquipo.h"
#include <stdbool.h>



departamento_t llenaDepartamento(int piso, int depto) {
  departamento_t departamento;

  // Esto está en este formato:
  // solicita varlor
  // cumple requisito 1?
  //   no: regresa al inicio
  // cumple requisito 2?
  //   no: regresa al inicio
  //  ...
  //  sal del bloque de código
  while (true) {
    printf("Dame un valor valido para la renta del departamento %d del piso %d:", piso + 1, depto + 1);

    scanf("%f", &departamento.renta);
    if ( !(3000 <= departamento.renta && departamento.renta <= 9000) ) {
      printf("La renta tiene que ser un numero en [3000, 9000]\n");
      continue;
    }
    break;
  }

  while (true) {
    printf("Dame el numero de adultos en este departamento: ");

    scanf("%d", &departamento.numAdultos);
    if ( departamento.numAdultos < 1) {
      printf("Tiene que haber al menos un adulto por departamento\n");
      continue;
    }
    break;
  }

  for ( int i = 0; i < departamento.numAdultos; i++ ) {
    while (true) {
      printf("Dame la edad del adulto numero %d: ", i+1 );
      scanf("%d", &departamento.edadesAdultos[i]);
      if ( departamento.edadesAdultos[i] < 0 ) {
        printf("Tiene que ser un numero positivo\n");
        continue;
      }
      break;
    }
  }

  return departamento;
}

void llenaEdificio(departamento_t* edificioPtr, int depsPorPiso, int pisos) {
  for (int deptoActual = 0; deptoActual < depsPorPiso; deptoActual++) {
    for (int pisoActual = 0; pisoActual < pisos; pisoActual++) {
    if ( pisoActual == 0 && deptoActual == 0) {
        continue;
      }
    *(edificioPtr + (pisoActual*depsPorPiso + deptoActual)) = llenaDepartamento(pisoActual, deptoActual);
    }
  }
}


int main(int argc, char *argv[]) {
  int pisos, depsPorPiso;
  printf("Cada departamento tiene como maximo 6 habitantes sin contar mascotas\n");
  printf("La renta de cada departamento oscila entre $3,000 y $9,000 \n");
  printf("El primer departamento de la planta baja ya está ocupado; no lo utilizaremos\n");
  while (true) {
    printf("¿Cuantos pisos tiene el edificio?\n");
    scanf("%d",&pisos);

    if ( pisos < 2 ) {
      printf("Tienen que ser al menos 2 pisos\n");
      continue;
    }

    break;
  }

  while (true) {
    printf("¿Cuantos departamentos por piso tiene?\n");
    scanf("%d", &depsPorPiso);

    if ( depsPorPiso < 2 ) {
      printf("Tienen que ser al menos 2 pisos\n");
      continue;
    }

    break;
  }
  departamento_t ed[pisos][depsPorPiso];
  llenaEdificio(&ed[0][0], depsPorPiso, pisos);
  return 0;
}

int mayorEdadDeAdulto(departamento_t* edificioPtr, int depsPorPiso, int pisos) {
  int mayorEdad = (edificioPtr + 2)->edadesAdultos[0];
  departamento_t structActual;

  for (int deptoActual = 0; deptoActual < depsPorPiso; deptoActual++) {
    for (int pisoActual = 0; pisoActual < pisos; pisoActual++) {
      structActual = *(edificioPtr + (pisoActual*depsPorPiso + deptoActual));
      for (int adulto = 0; adulto < structActual.numAdultos; adulto++) {
        if ( structActual.edadesAdultos[adulto] > mayorEdad ) {
          mayorEdad = structActual.edadesAdultos[adulto];
        }
      }
    }
  }
  return mayorEdad;
}
