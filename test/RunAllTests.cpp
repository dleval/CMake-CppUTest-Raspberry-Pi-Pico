#include "CppUTest/CommandLineTestRunner.h"

IMPORT_TEST_GROUP(module);

int main(int argc, char** argv)
{
    return RUN_ALL_TESTS(argc, argv);
}