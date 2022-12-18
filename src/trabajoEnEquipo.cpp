#include <stdio.h>
#include <string.h>

int MAX_HABITANTES = 6;
float MAX_RENTA = 9000;
float MIN_RENTA = 3000;

typedef struct mascotas_t {
  int numPerros;
  int numGatos;
  int numOtras;
} mascotas_t;


typedef struct departamento_t {
  float      renta;
  int        numPerros;
  int        numGatos;
  mascotas_t mascotas;
  int        numNinios;
  int        edadesNinios[8];
  int        numAdultos;
  int        edadesAdultos[8];
  float      ingreso;
} departamento_t;


departamento_t llenaDepartamento() {
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
    printf("Dame un valor valido para la renta del departamento\n");

    scanf("%f", &departamento.renta);
    if ( !(3000 <= departamento.renta && departamento.renta <= 9000) ) {
      printf("La renta tiene que ser un entero en [3000, 9000]\n");
      continue;
    }
    break;
  }

  return departamento;
}

void llenaEdificio(departamento_t* ed, int pisos, int depsPorPiso) {
  for (int pisoActual = 0; pisoActual < pisos; pisoActual++) {
    for (int deptoActual = 0; deptoActual < depsPorPiso; deptoActual++) {
    if ( pisoActual == 0 && deptoActual == 0) {
        continue;
      }
    *(ed + (pisoActual*depsPorPiso + deptoActual)) = llenaDepartamento();
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
  llenaEdificio(&ed[0][0], pisos, depsPorPiso);
  return 0;
}
