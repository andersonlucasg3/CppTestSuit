using Shared.Projects;

namespace TestSuit.Modules;

public class TestSuitLibModule : AModuleDefinition
{
    public override EModuleBinaryType BinaryType => EModuleBinaryType.DynamicLibrary;

    public override string Name => "TestSuitLib";

    public override string SourcesRoot => "Sources";

    protected override void Configure(AProjectDefinition InOwnerProject)
    {
        
    }
}
