#include "../googletest/googletest/include/gtest/gtest.h"
#include "../src/trabajoEnEquipo.h"


namespace my {
namespace project {
namespace {

// The fixture for testing class Foo.
class FooTest : public ::testing::Test {
 public:

  mascotas_t mascotas1 = {1, 1, 1};
  departamento_t departamento1 = {3000, mascotas1, 3, {1, 1, 1}, 1, 99, 4000};
  departamento_t edificio[2][2] = { {departamento1, departamento1}, {departamento1, departamento1} };
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

