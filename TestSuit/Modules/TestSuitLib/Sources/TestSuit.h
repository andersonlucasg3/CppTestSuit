#pragma once

#include "Assert.h"
#include "Logger.h"
#include "TestBase.h"
#include "TestCoordinator.h"

#define REGISTER_TEST_CLASS(TestName)                                       \
C##TestName* G##TestName = []{                                              \
    return CTestCoordinator::RegisterTestClass<C##TestName>(#TestName);     \
}()

#define DEFINE_TEST_RUNNER()                                                \
int main(int argc, char* argv[])                                            \
{                                                                           \
	return CTestCoordinator::Run() ? 0 : 255;                               \
}