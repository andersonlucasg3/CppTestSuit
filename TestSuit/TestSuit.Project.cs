using Shared.Projects;

namespace TestSuit.Projects;

using Modules;

public class TestSuitProject : AProjectDefinition
{
    public override string Name => "TestSuit";

    public override string SourcesRoot => "Modules";

    protected override void Configure()
    {
        AddModule<TestSuitLibModule>();
        AddModule<TestSuitRunnerModule>();
    }
}