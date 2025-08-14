#pragma once

#include "TestBase.h"
#include "TestCoordinator.h"

#define REGISTER_TEST_CLASS(TestName)                                       \
C##TestName* G##TestName = []{                                              \
    return CTestCoordinator::RegisterTestClass<C##TestName>(#TestName);     \
}()