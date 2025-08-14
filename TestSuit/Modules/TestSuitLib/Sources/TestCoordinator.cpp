#include "TestCoordinator.h"

#include "Assert.h"
#include "Logger.h"

std::vector<CTestBase*> CTestCoordinator::AllTests;

void CTestCoordinator::Run()
{
    // CLogger::InitializeLogFile("Tests.log");
    CLogger::Log("Initializing TestCoordinator");

    bool bHadAnyFailures = false;

    for (CTestBase* Test : AllTests)
    {
        if (!Test) continue;

        CAssert Assert;

        CLogger::Log("TestCoordinator: Running test cases for {}", Test->_testName);

        Test->_assert = &Assert;

        Test->TestCase();

        if (Assert._bHadAnyErrors)
        {
            bHadAnyFailures = true;

            for (const CTestAssertInfo& Info : Assert._failedTestCases)
            {
                CLogger::Error("{} - {} - {}:{}", Info.Expression, Info.FunctionName, Info.FileName, Info.LineNumber);
            }
        }
    }

    if (bHadAnyFailures)
    {
        CLogger::Log("Tests finished with errors.");
    }
    else
    {
	    CLogger::Log("Tests finished with no errors.");
    }
}

void CTestCoordinator::Shutdown()
{
    for (CTestBase* Test : AllTests) 
    {
        delete Test;
    }
}