using Shared.Projects;

namespace TestSuit.Modules;

public class TestSuitRunnerModule : AModuleDefinition
{
    public override EModuleBinaryType BinaryType => EModuleBinaryType.Application;

    public override string Name => "TestSuitRunner";

    public override string SourcesRoot => "Sources";

    protected override void Configure()
    {
        AddDependencyModuleNames(
            "TestSuitLib"
        );
    }
}
