#include "../Unity/src/unity.h"
#include "../src/trabajoEnEquipo.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_llenaDepartamento(void) {
    //test stuff
}

void test_function_should_doAlsoDoBlah(void) {
    //more test stuff
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_function_should_doBlahAndBlah);
    RUN_TEST(test_function_should_doAlsoDoBlah);
    return UNITY_END();
}
