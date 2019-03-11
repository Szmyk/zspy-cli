using System;
using System.Threading;
using System.Windows.Forms;

using CommandLine;

namespace zspy_cli
{
    public class Program
    {
        public static ILogger Logger;

        public static void Main(string[] args)
        {
            CommandLine.Parser.Default.ParseArguments<Options>(args).WithParsed((options) =>
            {
                if (options.Highlight != null)
                {
                    Logger = new LoggerWithHighlighting(options.Highlight);
                }
                else
                {
                    Logger = new Logger();
                }

                var zSpyWindowThread = new Thread(() =>
                {
                    Application.Run(new FakeZSpy
                    {
                        Text = "[zSpy]"
                    });
                });

                zSpyWindowThread.Start();

                Console.WriteLine("Waiting for messages...");

                zSpyWindowThread.Join();
            });
        }
    }
}
