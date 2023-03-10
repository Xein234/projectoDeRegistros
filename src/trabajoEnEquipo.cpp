#include <stdio.h>
#include "trabajoEnEquipo.h"

depto_t llenaDepto();
void llenaEdificio(depto_t* ed, int pisos, int deptosPorPiso);
/* int encuentraAdultosMayorEdad(depto_t *edificioPtr, int deptosPorPiso, int pisos, */
/*                        int pisosMayorEdad[], int deptosMayorEdad[], int indicesAdultosMayorEdad[]); */

depto_t llenaDepartamento(int piso, int deptoEnPiso) {
  depto_t depto;

  // Esto est? en este formato:
  // solicita varlor
  // cumple requisito 1?
  //   no: regresa al inicio
  // cumple requisito 2?
  //   no: regresa al inicio
  //  ...
  //  sal del bloque de c?digo
  while (true) {
    printf(
        "Renta del departamento %d del piso %d: ",
        piso + 1, deptoEnPiso + 1);

    scanf("%f", &depto.renta);
    if (!(3000 <= depto.renta && depto.renta <= 9000)) {
      printf("La renta tiene que ser un numero en [3000, 9000]\n");
      continue;
    }
    break;
  }

  while (true) {
    printf("Numero de adultos en este departamento: ");

    scanf("%d", &depto.numAdultos);
    if (depto.numAdultos < 1) {
      printf("Tiene que haber al menos un adulto por depto\n");
      continue;
    }
    break;
  }

  for (int i = 0; i < depto.numAdultos; i++) {
    while (true) {
      printf("Edad del adulto numero %d: ", i + 1);
      scanf("%d", &depto.edadesAdultos[i]);
      if (depto.edadesAdultos[i] < 18) {
        printf("Tiene que ser mayor a 18\n");
        continue;
      }
      break;
    }
  }

  printf("Numero de ninios en este departamento: ");
  scanf("%d", &depto.numNinios);

  printf("Numero de perros que habitan en este departamento: ");
  scanf("%d", &depto.mascotas.numPerros);

  printf("Numero de gatos que habitan en este departamento: ");
  scanf("%d", &depto.mascotas.numGatos);

  printf("Numero de otras mascotas que habitan en este departamento: ");
  scanf("%d", &depto.mascotas.numPerros);

  while (true) {
    printf("Ingreso mensual de los habitantes del departamento %d del piso %d: ",
           piso + 1, deptoEnPiso + 1);
    scanf ("%f", &(depto.ingreso));
    if (depto.ingreso < 3000)
    {
      printf("Con ese ingreso no pude rentar el departamento\n");
      continue;
    }

    if (depto.ingreso < depto.renta) {
      printf("Con ese ingreso se puede rentar el departamento\n");
      continue;
    }
    break;
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
                       int indicesAdultosMayorEdad[], int* mayorEdad) {

  int edadActual = (edificioPtr + 1)->edadesAdultos[0];
  *mayorEdad = edadActual;
  pisosMayorEdad[0] = 0;
  deptosMayorEdad[0] = 1;
  indicesAdultosMayorEdad[0] = 0;
  int nextIndex = 1;


  depto_t structActual;

  for (int deptoActual = 0; deptoActual < deptosPorPiso; deptoActual++) {
    for (int pisoActual = 0; pisoActual < pisos; pisoActual++) {

      if ( deptoActual == 0 && pisoActual == 0 ) {
        continue;
      }

      structActual = *(edificioPtr + (pisoActual * deptosPorPiso + deptoActual));
      for (int adulto = 0; adulto < structActual.numAdultos; adulto++) {
        if ( deptoActual == 1 && pisoActual == 0 && adulto == 0) {
          continue;
        }
        edadActual = structActual.edadesAdultos[adulto];

        if (edadActual < *mayorEdad) {
          continue;
        }

        if (edadActual > *mayorEdad) {
          *mayorEdad = edadActual;
          pisosMayorEdad[0] = pisoActual;
          deptosMayorEdad[0] = deptoActual;
          indicesAdultosMayorEdad[0] = adulto;
          nextIndex = 1;
          continue;
        }

        pisosMayorEdad[nextIndex] = pisoActual;
        deptosMayorEdad[nextIndex] = deptoActual;
        indicesAdultosMayorEdad[nextIndex] = adulto;
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
                       int pisosMayorRenta[], int deptosMayorRenta[],
                     float* mayorRenta) {

  int rentaActual = (edificioPtr + 1)->renta;
  *mayorRenta = rentaActual;
  pisosMayorRenta[0] = 0;
  deptosMayorRenta[0] = 1;
  int nextIndex = 1;


  depto_t structActual;

  for (int deptoActual = 0; deptoActual < deptosPorPiso; deptoActual++) {
    for (int pisoActual = 0; pisoActual < pisos; pisoActual++) {

      if ( (deptoActual == 0 || deptoActual == 1) && pisoActual == 0 ) {
        continue;
      }

      structActual = *(edificioPtr + (pisoActual * deptosPorPiso + deptoActual));
      rentaActual = structActual.renta;
      if (rentaActual < *mayorRenta) {
        continue;
      }

      if (rentaActual > *mayorRenta) {
        *mayorRenta = rentaActual;
        pisosMayorRenta[0] = pisoActual;
        deptosMayorRenta[0] = deptoActual;
        nextIndex = 1;
        continue;
      }

      pisosMayorRenta[nextIndex] = pisoActual;
      deptosMayorRenta[nextIndex] = deptoActual;
      nextIndex++;
    }
  }

  return nextIndex;
}

void printDeptosMayorRenta(int pisosMayorRenta[], int deptosMayorRenta[],
                           float renta, int cantidad) {
  printf("Los departamentos con mayor renta son:\n");
  for (int i = 0; i < cantidad; ++i) {
    printf("el departamento %d del piso %d\n",
           deptosMayorRenta[i] + 1, pisosMayorRenta[i] + 1);
  }
}

int encuentraDeptosConPerro(depto_t* edificioPtr, int deptosPorPiso, int pisos, int pisosConPerro[], int deptosConPerro[]) {
  depto_t structActual;
  int nextIndex = 0;

  for (int deptoActual = 0; deptoActual < deptosPorPiso; deptoActual++) {
    for (int pisoActual = 0; pisoActual < pisos; pisoActual++) {

      if ( deptoActual == 0 && pisoActual == 0 ) {
        continue;
      }

      structActual = *(edificioPtr + (pisoActual * deptosPorPiso + deptoActual));
      if (structActual.mascotas.numPerros > 0) {
        pisosConPerro[nextIndex] = pisoActual;
        deptosConPerro[nextIndex] = deptoActual;
        nextIndex++;
      }
    }
  }

  return nextIndex;
}

void printDeptosConPerro(int pisosConPerro[], int deptosConPerro[], int cantidad) {
  printf("Los departamentos con al menos un perro son:\n");
  for (int i = 0; i < cantidad; ++i) {
    printf("el departamento %d del piso %d\n", deptosConPerro[i] + 1, pisosConPerro[i] + 1);
  }
  printf("\n");
}

int encuentraDeptosConGato(depto_t* edificioPtr, int deptosPorPiso, int pisos, int pisosConGato[], int deptosConGato[]) {
  depto_t structActual;
  int nextIndex = 0;

  for (int deptoActual = 0; deptoActual < deptosPorPiso; deptoActual++) {
    for (int pisoActual = 0; pisoActual < pisos; pisoActual++) {

      if ( deptoActual == 0 && pisoActual == 0 ) {
        continue;
      }

      structActual = *(edificioPtr + (pisoActual * deptosPorPiso + deptoActual));
      if (structActual.mascotas.numGatos > 0) {
        pisosConGato[nextIndex] = pisoActual;
        deptosConGato[nextIndex] = deptoActual;
        nextIndex++;
      }
    }
  }

  return nextIndex;
}

void printDeptosConGato(int pisosConGato[], int deptosConGato[], int cantidad) {
  printf("Los departamentos con al menos un gato son:\n");
  for (int i = 0; i < cantidad; ++i) {
    printf("el departamento %d del piso %d\n", deptosConGato[i] + 1, pisosConGato[i] + 1);
  }
  printf("\n");
}

int encuentraDeptosConOtraMascota(depto_t* edificioPtr, int deptosPorPiso, int pisos, int pisosConOtraMascota[], int deptosConOtraMascota[]) {
  depto_t structActual;
  int nextIndex = 0;

  for (int deptoActual = 0; deptoActual < deptosPorPiso; deptoActual++) {
    for (int pisoActual = 0; pisoActual < pisos; pisoActual++) {

      if ( deptoActual == 0 && pisoActual == 0 ) {
        continue;
      }

      structActual = *(edificioPtr + (pisoActual * deptosPorPiso + deptoActual));
      if (structActual.mascotas.numOtras > 0) {
        pisosConOtraMascota[nextIndex] = pisoActual;
        deptosConOtraMascota[nextIndex] = deptoActual;
        nextIndex++;
      }
    }
  }

  return nextIndex;
}

void printDeptosConOtraMascota(int pisosConOtraMascota[], int deptosConOtraMascota[], int cantidad) {
  printf("Los departamentos con al menos una mascota que no es perro ni gato son:\n");
  for (int i = 0; i < cantidad; ++i) {
    printf("el departamento %d del piso %d\n", deptosConOtraMascota[i] + 1, pisosConOtraMascota[i] + 1);
  }
  printf("\n");
}

int encuentraDeptosMenosIngresos(depto_t *edificioPtr, int deptosPorPiso, int pisos,
                       int pisosConMenosIngresos[], int deptosConMenosIngresos[],
                     float* menorIngreso) {

  int ingresoActual = (edificioPtr + 1)->ingreso;
  *menorIngreso = ingresoActual;
  pisosConMenosIngresos[0] = 0;
  deptosConMenosIngresos[0] = 1;
  int nextIndex = 1;


  depto_t structActual;

  for (int deptoActual = 0; deptoActual < deptosPorPiso; deptoActual++) {
    for (int pisoActual = 0; pisoActual < pisos; pisoActual++) {

      if ( (deptoActual == 0 || deptoActual == 1) && pisoActual == 0 ) {
        continue;
      }

      structActual = *(edificioPtr + (pisoActual * deptosPorPiso + deptoActual));
      ingresoActual = structActual.ingreso;
      if (ingresoActual > *menorIngreso) {
        continue;
      }

      if (ingresoActual < *menorIngreso) {
        *menorIngreso = ingresoActual;
        pisosConMenosIngresos[0] = pisoActual;
        deptosConMenosIngresos[0] = deptoActual;
        nextIndex = 1;
        continue;
      }

      pisosConMenosIngresos[nextIndex] = pisoActual;
      deptosConMenosIngresos[nextIndex] = deptoActual;
      nextIndex++;
    }
  }

  return nextIndex;
}

void printDeptosMenosIngreso(int pisosMenosIngresos[], int deptosMenosIngresos[], int cantidad) {
  printf("Los departamentos con menos ingresos son:\n");
  for (int i = 0; i < cantidad; ++i) {
    printf("el departamento %d del piso %d\n", deptosMenosIngresos[i] + 1, pisosMenosIngresos[i] + 1);
  }
  printf("\n");
}

int sumaRenta(depto_t* edificioPtr, int deptosPorPiso, int pisos) {
  float rentaAcumulada;

  return rentaAcumulada;
}

/* int encuentraNiniosMenorEdad(depto_t *edificioPtr, int deptosPorPiso, int pisos, */
/*                        int pisosMenorEdad[], int deptosMenorEdad[], */
/*                        int indicesDeNiniosMenorEdad[], int* menorEdad) { */
/*   int nextIndex = 0; */
/*   return nextIndex; */
/* } */
int encuentraNiniosMenorEdad(depto_t *edificioPtr, int deptosPorPiso, int pisos,
                       int pisosMenorEdad[], int deptosMenorEdad[],
                       int indicesNiniosMenorEdad[], int* menorEdad) {

  int edadActual = (edificioPtr + 1)->edadesNinios[0];
  *menorEdad = edadActual;
  pisosMenorEdad[0] = 0;
  deptosMenorEdad[0] = 1;
  indicesNiniosMenorEdad[0] = 0;
  int nextIndex = 1;


  depto_t structActual;

  for (int deptoActual = 0; deptoActual < deptosPorPiso; deptoActual++) {
    for (int pisoActual = 0; pisoActual < pisos; pisoActual++) {

      if ( deptoActual == 0 && pisoActual == 0 ) {
        continue;
      }

      structActual = *(edificioPtr + (pisoActual * deptosPorPiso + deptoActual));
      for (int ninio = 0; ninio < structActual.numNinios; ninio++) {
        if ( deptoActual == 1 && pisoActual == 0 && ninio == 0) {
          continue;
        }
        edadActual = structActual.edadesNinios[ninio];

        if (edadActual > *menorEdad) {
          continue;
        }

        if (edadActual < *menorEdad) {
          *menorEdad = edadActual;
          pisosMenorEdad[0] = pisoActual;
          deptosMenorEdad[0] = deptoActual;
          indicesNiniosMenorEdad[0] = ninio;
          nextIndex = 1;
          continue;
        }

        pisosMenorEdad[nextIndex] = pisoActual;
        deptosMenorEdad[nextIndex] = deptoActual;
        indicesNiniosMenorEdad[nextIndex] = ninio;
        nextIndex++;
      }
    }
  }


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

int CantNinios(depto_t *edificioPtr, int n, int m){
  //deptosPorPiso -> n
  //piso -> m
  int i, j, cont=0;
  depto_t structActual;
  //Revisar por cada renglon y columna tomando a la cantidad de ni?os por deptos.
  for(i=0; i<m; i++){
    //por depto
    for(j=0; j<n; j++){
      //por piso
      //Exceptuando al departamento [0][0]
      structActual = *(edificioPtr + ((i * n) + j));
      if((i!=0&&j==0)||(i==0&&j!=0)){
        //Se suma a cada ni?o de la matriz depto_t
        cont=cont+structActual.numNinios;
      }
    }
  }
  //Devolver a cont a nombre de canin
  return (cont);
}

void printCantNinios(int cant) {
  printf("La cantidad de ninios en el edificio es: %d\n", cant);
}
