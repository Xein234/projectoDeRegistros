const int MAX_HABITANTES = 6;
const float MAX_RENTA = 9000;
const float MIN_RENTA = 3000;

typedef struct mascotas_t {
  int numPerros;
  int numGatos;
  int numOtras;
} mascotas_t;


typedef struct departamento_t {
  float      renta;
  mascotas_t mascotas;
  int        numNinios;
  int        edadesNinios[5];
  int        numAdultos;
  int        edadesAdultos[6];
  float      ingreso;
} departamento_t;

departamento_t llenaDepartamento();
void llenaEdificio(departamento_t* ed, int pisos, int depsPorPiso);
int mayorEdadDeAdulto(departamento_t* edificioPtr, int depsPorPiso, int pisos);
