#include "trabajoEnEquipo.h"
#include <string.h>
#include <stdio.h>
#include "datos.h"



void llenadoManual() {



}

int main(int argc, char *argv[]) {
  printf("Desea cargar los datos de datos.h o ingresarlos manualmente?\n");
  printf("[cargar/manual]: ");
  int pisos, deptosPorPiso, nextIndex;
  char respuesta[20], tipo[20];
  scanf("%s", respuesta);
  if (strcmp(respuesta, "manual") == 0) {
    printf("Cada departamento tiene como maximo 6 habitantes sin contar mascotas\n");
    printf("La renta de cada departamento oscila entre $3,000 y $9,000 \n");
    printf("El primer departamento de la planta baja ya está ocupado; no lo utilizaremos\n");
    while (true) {
    // pregunta por el tamano de la matriz
      printf("Cuantos pisos tiene el edificio?\n");
      scanf("%d", &pisos);

      if ( pisos < 2 ) {
        printf("Tienen que ser al menos 2 pisos\n");
        continue;
      }

      break;
    }

    while (true) {
      printf("Cuantos departamentos por piso tiene?\n");
      scanf("%d", &deptosPorPiso);

      if ( deptosPorPiso < 2 ) {
        printf("Tienen que ser al menos 2 pisos\n");
        continue;
      }

      break;
    }
  } else {
    if (strcmp(respuesta, "cargar") == 0) {
      pisos = DATOS_PISOS;
      deptosPorPiso = DATOS_DEPTOS_POR_PISO;
    }
  }

  depto_t edificio[pisos][deptosPorPiso];

  if (strcmp(respuesta, "manual") == 0) {
    llenaEdificio(&edificio[0][0], deptosPorPiso, pisos);
  } else if (strcmp(respuesta, "cargar") == 0) {
      for (int pisoActual = 0; pisoActual < DATOS_PISOS; ++pisoActual) {
        for (int deptoActual= 0; deptoActual < DATOS_DEPTOS_POR_PISO; ++deptoActual) {
          edificio[pisoActual][deptoActual] = DATOS_EDIFICIO[pisoActual][deptoActual];
        }
      }
    }

  while (true) {
    printf("Que tipo de analisis desea realizar?\n");
    printf("[renta/edad/mascotas/ninios/ingreso]: ");
    scanf("%s", tipo);

    int nextIndex;

    if (strcmp(tipo, "edad") == 0) {
      int pisosMayorEdad[(pisos*deptosPorPiso-1)*MAX_HABITANTES_POR_DEPTO];
      int deptosMayorEdad[(pisos*deptosPorPiso-1)*MAX_HABITANTES_POR_DEPTO];
      int indicesAdultosMayorEdad[(pisos*deptosPorPiso-1)*MAX_HABITANTES_POR_DEPTO];

      int mayorEdad;
      nextIndex = encuentraAdultosMayorEdad(&edificio[0][0], deptosPorPiso, pisos, pisosMayorEdad, deptosMayorEdad, indicesAdultosMayorEdad, &mayorEdad);

      printAdultosDeMayorEdad(pisosMayorEdad, deptosMayorEdad, indicesAdultosMayorEdad, mayorEdad, nextIndex);
    } else if (strcmp(tipo, "renta") == 0) {
      int pisosMayorRenta[pisos*deptosPorPiso-1];
      int deptosMayorRenta[pisos*deptosPorPiso-1];

      float mayorRenta;
      nextIndex = encuentraDeptosMayorRenta(&edificio[0][0], deptosPorPiso, pisos, pisosMayorRenta, deptosMayorRenta, &mayorRenta);

      printDeptosMayorRenta(pisosMayorRenta, deptosMayorRenta, mayorRenta, nextIndex);
    }
    else if (strcmp(tipo, "mascotas") == 0) {
      int pisosConPerro[pisos*deptosPorPiso-1];
      int deptosConPerro[pisos*deptosPorPiso-1];

      nextIndex = encuentraDeptosConPerro(&edificio[0][0], deptosPorPiso, pisos, pisosConPerro, deptosConPerro);
      printDeptosConPerro(pisosConPerro, deptosConPerro, nextIndex);

      
    }
  }


  return 0;
}

  /* int pisosConPerro[pisos*deptosPorPiso-1]; */
  /* int deptosConPerro[pisos*deptosPorPiso-1]; */

  /* nextIndex = encuentraDeptosConPerro(&edificio[0][0], deptosPorPiso, pisos, pisosConPerro, deptosConPerro); */

  /* printDeptosConPerro(pisosConPerro, deptosConPerro, nextIndex); */
