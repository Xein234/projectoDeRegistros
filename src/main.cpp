#include "trabajoEnEquipo.cpp"

int main(int argc, char *argv[]) {
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

  //Probamos otros módulos aquí, temporalmente.
  int pisosMayorEdad[(pisos*deptosPorPiso-1)*MAX_HABITANTES_POR_DEPTO];
  int deptosMayorEdad[(pisos*deptosPorPiso-1)*MAX_HABITANTES_POR_DEPTO];
  int indicesDeAdultosMayorEdad[(pisos*deptosPorPiso-1)*MAX_HABITANTES_POR_DEPTO];

  int mayorEdad;
  int nextIndex = encuentraAdultosMayorEdad(&edificio[0][0], deptosPorPiso, pisos, pisosMayorEdad, deptosMayorEdad, indicesDeAdultosMayorEdad, &mayorEdad);



  printAdultosDeMayorEdad(pisosMayorEdad, deptosMayorEdad, indicesDeAdultosMayorEdad, mayorEdad, nextIndex);

  return 0;
}
