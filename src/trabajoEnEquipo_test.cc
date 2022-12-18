#include "../googletest/googletest/include/gtest/gtest.h"
#include "../src/trabajoEnEquipo.h"


namespace my {
namespace project {
namespace {

// The fixture for testing class Foo.
class FooTest : public ::testing::Test {
 public:

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
    .numAdultos = 1,
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
  // You can remove any or all of the following functions if their bodies would
  // be empty.

  FooTest() {
     // You can do set-up work for each test here.
  }

  ~FooTest() override {
     // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override {
  }

  void TearDown() override {
     // Code here will be called immediately after each test (right
     // before the destructor).
  }

  // Class members declared here can be used by all tests in the test suite
  // for Foo.
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(FooTest, CalculaMayorEdadDeAdulto) {
  EXPECT_EQ(mayorEdadDeAdulto(&edificio[0][0], 2, 2), 99);
}

}  // namespace
}  // namespace project
}  // namespace my

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/* TEST(HelloTest, BasicAssertions) { */
/*   // Expect two strings not to be equal. */
/*   EXPECT_STRNE("hello", "world"); */
/*   // Expect equality. */
/*   EXPECT_EQ(7 * 6, 42); */
/* } */

