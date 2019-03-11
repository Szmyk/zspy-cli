using CommandLine;

namespace zspy_cli
{
    public class Options
    {
        [Option('h', "highlight")]
        public string Highlight { get; set; }

        [Option('f', "filter")]
        public string Filter { get; set; }
    }
}
