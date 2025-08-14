#pragma once

#include "Assert.h"

class CTestBase
{
    CAssert* _assert;
    
    const char* _testName;

public:
    virtual ~CTestBase() = default;
    
    virtual void TestCase() = 0;

    friend class CTestCoordinator;
};