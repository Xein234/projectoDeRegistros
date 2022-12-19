#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest/doctest.h"
#include "trabajoEnEquipo.cpp"
#include <stdio.h>

TEST_CASE("prueba todo el programa") {
  mascotas_t mascotas1 = { .numPerros = 1, .numGatos = 1, .numOtras = 1, };
  mascotas_t mascotas2 = { .numPerros = 0, .numGatos = 0, .numOtras = 0, };
  mascotas_t mascotas3 = { .numPerros = 0, .numGatos = 7, .numOtras = 0, };

  departamento_t depDelArrendatario;

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
    .ingreso = 4000};

  departamento_t departamento3 =\
  { .renta = 5000,
    .mascotas = mascotas3,
    .numNinios = 0,
    .edadesNinios = {},
    .numAdultos = 1,
    .edadesAdultos = {99},
    .ingreso = 4000};

  departamento_t edificio[2][2] = { {depDelArrendatario, departamento1}, {departamento2, departamento3} };
  int pisos = 2;
  int depsPorPiso = 2;

  int pisosMayorEdad[(pisos*depsPorPiso-1)*MAX_HABITANTES_POR_DEPT];
  int departamentosMayorEdad[(pisos*depsPorPiso-1)*MAX_HABITANTES_POR_DEPT];
  int indicesDeAdultosMayorEdad[(pisos*depsPorPiso-1)*MAX_HABITANTES_POR_DEPT];

  int nextIndex = adultosDeMayorEdad(&edificio[0][0], depsPorPiso, pisos, pisosMayorEdad, departamentosMayorEdad, indicesDeAdultosMayorEdad);

  int indicesDeAdultosMayorEdadEsperados[2] = {2, 0};
  int pisosMayorEdadEsperados[2] = {0, 1};
  int departamentosMayorEdadEsperados[2] = {1, 1};

  SUBCASE("testeando adultosDeMayorEdad()") {
    for (int i = 0; i < nextIndex; ++i) {
        CHECK(indicesDeAdultosMayorEdadEsperados[i] == indicesDeAdultosMayorEdad[i]);
        CHECK(pisosMayorEdadEsperados[i] == pisosMayorEdad[i]);
        CHECK(departamentosMayorEdadEsperados[i] == departamentosMayorEdad[i]);
    }
  }
}