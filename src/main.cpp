#include "trabajoEnEquipo.cpp"
#include <string.h>

void llenadoManual() {
  int pisos, deptosPorPiso;
  printf("Cada departamento tiene como maximo 6 habitantes sin contar mascotas\n");
  printf("La renta de cada departamento oscila entre $3,000 y $9,000 \n");
  printf("El primer departamento de la planta baja ya está ocupado; no lo utilizaremos\n");
  while (true) {
  // pregunta por el tamaño de la matriz
    printf("¿Cuantos pisos tiene el edificio?\n");
    scanf("%d", &pisos);

    if ( pisos < 2 ) {
      printf("Tienen que ser al menos 2 pisos\n");
      continue;
    }

    break;
  }

  while (true) {
    printf("¿Cuantos departamentos por piso tiene?\n");
    scanf("%d", &deptosPorPiso);

    if ( deptosPorPiso < 2 ) {
      printf("Tienen que ser al menos 2 pisos\n");
      continue;
    }

    break;
  }
  depto_t edificio[pisos][deptosPorPiso];
  llenaEdificio(&edificio[0][0], deptosPorPiso, pisos);

  char tipo[10];
  while (true) {
    printf("¿Qué tipo de análisis desea realizar?\n");
    scanf("%s", tipo);

    printf("%s", tipo);

    if (strcmp(tipo, "edad\n")) {
      int pisosMayorEdad[(pisos*deptosPorPiso-1)*MAX_HABITANTES_POR_DEPTO];
      int deptosMayorEdad[(pisos*deptosPorPiso-1)*MAX_HABITANTES_POR_DEPTO];
      int indicesAdultosMayorEdad[(pisos*deptosPorPiso-1)*MAX_HABITANTES_POR_DEPTO];

      int mayorEdad;
      int nextIndex = encuentraAdultosMayorEdad(&edificio[0][0], deptosPorPiso, pisos, pisosMayorEdad, deptosMayorEdad, indicesAdultosMayorEdad, &mayorEdad);



      printAdultosDeMayorEdad(pisosMayorEdad, deptosMayorEdad, indicesAdultosMayorEdad, mayorEdad, nextIndex);
    }
  }


  /* int pisosConPerro[pisos*deptosPorPiso-1]; */
  /* int deptosConPerro[pisos*deptosPorPiso-1]; */

  /* nextIndex = encuentraDeptosConPerro(&edificio[0][0], deptosPorPiso, pisos, pisosConPerro, deptosConPerro); */

  /* printDeptosConPerro(pisosConPerro, deptosConPerro, nextIndex); */


}

int main(int argc, char *argv[]) {
  printf("¿Desea cargar los datos de datos.h o ingresarlos manualmente?\n");
  char respuesta[20];
  scanf("%s", respuesta);
  if (strcmp(respuesta, "manual\n")) {
    llenadoManual();
  }

  return 0;
}
