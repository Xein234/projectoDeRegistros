#include "trabajoEnEquipo.h"
const int DATOS_PISOS = 2;
const int DATOS_DEPTOS_POR_PISO = 3;

const depto_t DATOS_EDIFICIO[][3] = {
  {
    //piso 1
    { .renta = 12345,
      .mascotas = { .numPerros = 11, .numGatos = 22, .numOtras = 15, },
      .numNinios = 999,
      .edadesNinios = {47, 36, 24},
      .numAdultos = 3,
      .edadesAdultos = {101, 102, 103},
      .ingreso = 7890
    },
    { .renta = 3000,
      .mascotas = { .numPerros = 1, .numGatos = 1, .numOtras = 1, },
      .numNinios = 3,
      .edadesNinios = {1, 1, 1},
      .numAdultos = 3,
      .edadesAdultos = {18, 50, 99},
      .ingreso = 4000},
    { .renta = 9000,
      .mascotas = { .numPerros = 0, .numGatos = 0, .numOtras = 0, },
      .numNinios = 3,
      .edadesNinios = {2, 3, 4},
      .numAdultos = 3,
      .edadesAdultos = {18, 50, 93},
      .ingreso = 9000
    },
  },
  {
  //piso 2
    { .renta = 9000,
      .mascotas = { .numPerros = 0, .numGatos = 7, .numOtras = 0, },
      .numNinios = 2,
      .edadesNinios = {5, 6},
      .numAdultos = 2,
      .edadesAdultos = {20, 21},
      .ingreso = 4000},

    { .renta = 5000,
      .mascotas = { .numPerros = 0, .numGatos = 7, .numOtras = 0, },
      .numNinios = 0,
      .edadesNinios = {},
      .numAdultos = 1,
      .edadesAdultos = {99},
      .ingreso = 6000},

    { .renta = 7000,
      .mascotas = { .numPerros = 1, .numGatos = 7, .numOtras = 0, },
      .numNinios = 0,
      .edadesNinios = {},
      .numAdultos = 1,
      .edadesAdultos = {18},
      .ingreso = 8000},
  }
};
