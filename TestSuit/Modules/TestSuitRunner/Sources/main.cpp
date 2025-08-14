// #include "Process/Process.h"
#include "TestCoordinator.h"

int main(int argc, char* argv[])
{
	// TODO: fix this?
	// GProcess.SetCommandLine(argc, (const char**)argv);

	CTestCoordinator::Run();
	CTestCoordinator::Shutdown();

	return 0;
}