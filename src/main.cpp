#include "trabajoEnEquipo.cpp"

int main(int argc, char *argv[]) {
  int pisos, depsPorPiso;
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
    scanf("%d", &depsPorPiso);

    if ( depsPorPiso < 2 ) {
      printf("Tienen que ser al menos 2 pisos\n");
      continue;
    }

    break;
  }
  departamento_t edificio[pisos][depsPorPiso];
  llenaEdificio(&edificio[0][0], depsPorPiso, pisos);

  //Probamos otros módulos aquí, temporalmente.
  int pisosMayorEdad[(pisos*depsPorPiso-1)*MAX_HABITANTES_POR_DEPT];
  int departamentosMayorEdad[(pisos*depsPorPiso-1)*MAX_HABITANTES_POR_DEPT];
  int indicesDeAdultosMayorEdad[(pisos*depsPorPiso-1)*MAX_HABITANTES_POR_DEPT];

  int mayorEdad;
  int nextIndex = adultosDeMayorEdad(&edificio[0][0], depsPorPiso, pisos, pisosMayorEdad, departamentosMayorEdad, indicesDeAdultosMayorEdad, &mayorEdad);



  printAdultosDeMayorEdad(pisosMayorEdad, departamentosMayorEdad, indicesDeAdultosMayorEdad, mayorEdad, nextIndex);

  return 0;
}
