#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest/doctest.h"
#include "trabajoEnEquipo.cpp"
#include <stdio.h>

TEST_CASE("prueba todo el programa") {
  mascotas_t mascotas1 = { .numPerros = 1, .numGatos = 1, .numOtras = 1, };
  mascotas_t mascotas2 = { .numPerros = 0, .numGatos = 0, .numOtras = 0, };
  mascotas_t mascotas3 = { .numPerros = 0, .numGatos = 7, .numOtras = 0, };
  mascotas_t mascotas4 = { .numPerros = 0, .numGatos = 7, .numOtras = 0, };
  mascotas_t mascotas5 = { .numPerros = 0, .numGatos = 7, .numOtras = 0, };
  mascotas_t mascotasDelArrendatario = { .numPerros = 11, .numGatos = 22, .numOtras = 15, };

  departamento_t depDelArrendatario =\
  { .renta = 12345,
    .mascotas = mascotasDelArrendatario,
    .numNinios = 999,
    .edadesNinios = {47, 36, 24},
    .numAdultos = 3,
    .edadesAdultos = {101, 102, 103},
    .ingreso = 7890};


  departamento_t departamento1 =\
  { .renta = 3000,
    .mascotas = mascotas1,
    .numNinios = 3,
    .edadesNinios = {1, 1, 1},
    .numAdultos = 3,
    .edadesAdultos = {18, 50, 99},
    .ingreso = 4000};

  departamento_t departamento2 =\
  { .renta = 9000,
    .mascotas = mascotas2,
    .numNinios = 3,
    .edadesNinios = {2, 3, 4},
    .numAdultos = 3,
    .edadesAdultos = {18, 50, 93},
    .ingreso = 9000};

  departamento_t departamento3 =\
  { .renta = 9000,
    .mascotas = mascotas3,
    .numNinios = 2,
    .edadesNinios = {5, 6},
    .numAdultos = 2,
    .edadesAdultos = {20, 21},
    .ingreso = 4000};

  departamento_t departamento4 =\
  { .renta = 5000,
    .mascotas = mascotas4,
    .numNinios = 0,
    .edadesNinios = {},
    .numAdultos = 1,
    .edadesAdultos = {99},
    .ingreso = 6000};

  departamento_t departamento5 =\
  { .renta = 7000,
    .mascotas = mascotas5,
    .numNinios = 0,
    .edadesNinios = {},
    .numAdultos = 1,
    .edadesAdultos = {18},
    .ingreso = 8000};


  departamento_t edificio[2][3] = {
    {depDelArrendatario, departamento1, departamento2}, {departamento3, departamento4, departamento5} };
  int pisos = 2;
  int depsPorPiso = 3;
  int deptosPorPiso = 3;


  SUBCASE("testeando adultosDeMayorEdad()") {
    int pisosMayorEdad[(pisos*depsPorPiso-1)*MAX_HABITANTES_POR_DEPT];
    int departamentosMayorEdad[(pisos*depsPorPiso-1)*MAX_HABITANTES_POR_DEPT];
    int indicesDeAdultosMayorEdad[(pisos*depsPorPiso-1)*MAX_HABITANTES_POR_DEPT];

    int mayorEdad;
    int nextIndex = adultosDeMayorEdad(&edificio[0][0], depsPorPiso, pisos, pisosMayorEdad, departamentosMayorEdad, indicesDeAdultosMayorEdad, &mayorEdad);

    int indicesDeAdultosMayorEdadEsperados[2] = {2, 0};
    int pisosMayorEdadEsperados[2] = {0, 1};
    int departamentosMayorEdadEsperados[2] = {1, 1};

    CHECK(mayorEdad == 99);
    for (int i = 0; i < nextIndex; ++i) {
        CHECK(indicesDeAdultosMayorEdadEsperados[i] == indicesDeAdultosMayorEdad[i]);
        CHECK(pisosMayorEdadEsperados[i] == pisosMayorEdad[i]);
        CHECK(departamentosMayorEdadEsperados[i] == departamentosMayorEdad[i]);
    }
  }

  /* SUBCASE("testeando departamentosMayorRenta()") { */
  /*   int pisosMayorRenta[pisos*deptosPorPiso-1]; */
  /*   int deptosMayorRenta[pisos*deptosPorPiso-1]; */
  /*   int indicesMayorRenta[pisos*deptosPorPiso-1]; */

  /*   int mayorRenta; */
  /*   int nextIndex = encuentraDeptosMayorRenta(&edificio[0][0], deptosPorPiso, pisos, pisosMayorRenta, deptosMayorRenta, &mayorRenta); */

  /*   int pisosMayorRentaEsperados[2] = {0, 1}; */
  /*   int deptosMayorRentaEsperados[2] = {2, 0}; */

  /*   CHECK(mayorRenta == 9000); */
  /*     for (int i = 0; i < nextIndex; ++i) { */
  /*       CHECK(pisosMayorRenta[i] == pisosMayorRentaEsperados[i]); */
  /*       CHECK(deptosMayorRenta[i] == deptosMayorRentaEsperados[i]); */
  /*     } */
  /* } */
}
