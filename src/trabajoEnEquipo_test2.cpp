#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest/doctest.h"
#include "trabajoEnEquipo.cpp"
#include <stdio.h>
  mascotas_t mascotasArrendatario = { .numPerros = 11, .numGatos = 22, .numOtras = 15, };
  mascotas_t mascotas1 = { .numPerros = 1, .numGatos = 1, .numOtras = 1, };
  mascotas_t mascotas2 = { .numPerros = 0, .numGatos = 0, .numOtras = 0, };
  mascotas_t mascotas3 = { .numPerros = 0, .numGatos = 7, .numOtras = 0, };
  mascotas_t mascotas4 = { .numPerros = 0, .numGatos = 7, .numOtras = 0, };
  mascotas_t mascotas5 = { .numPerros = 1, .numGatos = 7, .numOtras = 0, };

  depto_t deptoArrendatario =\
  { .renta = 12345,
    .mascotas = mascotasArrendatario,
    .numNinios = 999,
    .edadesNinios = {47, 36, 24},
    .numAdultos = 3,
    .edadesAdultos = {101, 102, 103},
    .ingreso = 7890};


  depto_t depto1 =\
  { .renta = 3000,
    .mascotas = mascotas1,
    .numNinios = 3,
    .edadesNinios = {1, 1, 1},
    .numAdultos = 3,
    .edadesAdultos = {18, 50, 99},
    .ingreso = 4000};

  depto_t depto2 =\
  { .renta = 9000,
    .mascotas = mascotas2,
    .numNinios = 3,
    .edadesNinios = {2, 3, 4},
    .numAdultos = 3,
    .edadesAdultos = {18, 50, 93},
    .ingreso = 9000};

  depto_t depto3 =\
  { .renta = 9000,
    .mascotas = mascotas3,
    .numNinios = 2,
    .edadesNinios = {5, 6},
    .numAdultos = 2,
    .edadesAdultos = {20, 21},
    .ingreso = 4000};

  depto_t depto4 =\
  { .renta = 5000,
    .mascotas = mascotas4,
    .numNinios = 0,
    .edadesNinios = {},
    .numAdultos = 1,
    .edadesAdultos = {99},
    .ingreso = 6000};

  depto_t depto5 =\
  { .renta = 7000,
    .mascotas = mascotas5,
    .numNinios = 0,
    .edadesNinios = {},
    .numAdultos = 1,
    .edadesAdultos = {18},
    .ingreso = 8000};


  depto_t edificio[][3] = {
    {deptoArrendatario, depto1, depto2}, {depto3, depto4, depto5} };
  int pisos = 2;
  int deptosPorPiso = 3;

TEST_CASE("encuentraAdultosMayorEdad()") {
  int pisosMayorEdad[(pisos*deptosPorPiso-1)*MAX_HABITANTES_POR_DEPTO];
  int deptosMayorEdad[(pisos*deptosPorPiso-1)*MAX_HABITANTES_POR_DEPTO];
  int indicesAdultosMayorEdad[(pisos*deptosPorPiso-1)*MAX_HABITANTES_POR_DEPTO];

  int mayorEdad;
  int nextIndex = encuentraAdultosMayorEdad(&edificio[0][0], deptosPorPiso, pisos, pisosMayorEdad, deptosMayorEdad, indicesAdultosMayorEdad, &mayorEdad);

  int indicesAdultosMayorEdadEsperados[] = {2, 0};
  int pisosMayorEdadEsperados[] = {0, 1};
  int deptosMayorEdadEsperados[] = {1, 1};

  CHECK(mayorEdad == 99);
  for (int i = 0; i < nextIndex; ++i) {
      CHECK(indicesAdultosMayorEdadEsperados[i] == indicesAdultosMayorEdad[i]);
      CHECK(pisosMayorEdadEsperados[i] == pisosMayorEdad[i]);
      CHECK(deptosMayorEdadEsperados[i] == deptosMayorEdad[i]);
  }
}

TEST_CASE("encuentraDeptosMayorRenta()") {
  int pisosMayorRenta[pisos*deptosPorPiso-1];
  int deptosMayorRenta[pisos*deptosPorPiso-1];

  int mayorRenta;
  int nextIndex = encuentraDeptosMayorRenta(&edificio[0][0], deptosPorPiso, pisos, pisosMayorRenta, deptosMayorRenta, &mayorRenta);

  int pisosMayorRentaEsperados[] = {0, 1};
  int deptosMayorRentaEsperados[] = {2, 0};

  CHECK(nextIndex == 2);

  CHECK(mayorRenta == 9000);
    for (int i = 0; i < nextIndex; ++i) {
      CHECK(pisosMayorRenta[i] == pisosMayorRentaEsperados[i]);
      CHECK(deptosMayorRenta[i] == deptosMayorRentaEsperados[i]);
    }
}

TEST_CASE("encuentraDeptosConPerro()"){
  int pisosConPerro[pisos*deptosPorPiso-1];
  int deptosConPerro[pisos*deptosPorPiso-1];

  int nextIndex = encuentraDeptosConPerro(&edificio[0][0], deptosPorPiso, pisos, pisosConPerro, deptosConPerro);

  int pisosConPerroEsperados[] = {0, 1};
  int deptosConPerroEsperados[] = {1, 2};

  CHECK(nextIndex == 2);
    for (int i = 0; i < nextIndex; ++i) {
      CHECK(pisosConPerro[i] == pisosConPerroEsperados[i]);
      CHECK(deptosConPerro[i] == deptosConPerroEsperados[i]);
    }
}

TEST_CASE("encuentraDeptosConGato()"){
  int pisosConGato[pisos*deptosPorPiso-1];
  int deptosConGato[pisos*deptosPorPiso-1];

  int nextIndex = encuentraDeptosConGato(&edificio[0][0], deptosPorPiso, pisos, pisosConGato, deptosConGato);

  int pisosConGatoEsperados[] =  {0, 1, 1, 1};
  int deptosConGatoEsperados[] = {1, 0, 1, 2};

  CHECK(nextIndex == 4);
    for (int i = 0; i < nextIndex; ++i) {
      CHECK(pisosConGato[i] == pisosConGatoEsperados[i]);
      CHECK(deptosConGato[i] == deptosConGatoEsperados[i]);
    }
}

TEST_CASE("encuentraFamiliaMenosIngresos()"){
  int pisosMenosIngresos[pisos*deptosPorPiso-1];
  int deptosMenosIngresos[pisos*deptosPorPiso-1];

  int nextIndex = encuentraDeptosMenosIngresos(&edificio[0][0], deptosPorPiso, pisos, pisosMenosIngresos, deptosMenosIngresos);

  int pisosMenosIngresosEsperados[] =  {0, 1};
  int deptosMenosIngresosEsperados[] = {1, 0};

  CHECK(nextIndex == 2);
    for (int i = 0; i < nextIndex; ++i) {
      CHECK(pisosMenosIngresos[i] == pisosMenosIngresosEsperados[i]);
      CHECK(deptosMenosIngresos[i] == deptosMenosIngresosEsperados[i]);
    }
}

TEST_CASE("sumaRenta()"){
  CHECK(sumaRenta(&edificio[0][0], deptosPorPiso, pisos) == 33000.0);
}

TEST_CASE("encuentraNiniosMenorEdad()") {
  int pisosNiniosMenorEdad[pisos*deptosPorPiso-1];
  int deptosNiniosMenorEdad[pisos*deptosPorPiso-1];
  int indicesNiniosMenorEdad[(pisos*deptosPorPiso-1)*MAX_HABITANTES_POR_DEPTO];

  int nextIndex = encuentraNiniosMenorEdad(&edificio[0][0], deptosPorPiso, pisos, pisosNiniosMenorEdad, deptosNiniosMenorEdad, indicesNiniosMenorEdad);

  int indicesNiniosMenorEdadEsperados[] = {1, 1, 1};
  int pisosNiniosMenorEdadEsperados[] =  {0, 0, 0};
  int deptosNiniosMenorEdadEsperados[] = {1, 1, 1};

  CHECK(nextIndex == 3);
    for (int i = 0; i < nextIndex; ++i) {
      CHECK(indicesNiniosMenorEdadEsperados[i] == indicesNiniosMenorEdad[i]);
      CHECK(pisosNiniosMenorEdad[i] == pisosNiniosMenorEdadEsperados[i]);
      CHECK(deptosNiniosMenorEdad[i] == deptosNiniosMenorEdadEsperados[i]);
    }
}
