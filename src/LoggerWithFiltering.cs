using System;

namespace zspy_cli
{
    public class LoggerWithFiltering : ILogger
    {
        private string textToFilter;

        public LoggerWithFiltering(string textToFilter)
        {
            this.textToFilter = textToFilter;
        }

        private void writeLine(string message, ConsoleColor color)
        {
            if (message.Contains(textToFilter))
            {
                Console.ForegroundColor = color;

                Console.WriteLine(message);

                Console.ForegroundColor = ConsoleColor.Gray;
            }            
        }

        public void Information(string message)
        {
            writeLine(message, ConsoleColor.Gray);
        }

        public void Warning(string message)
        {
            writeLine(message, ConsoleColor.Green);
        }

        public void Fault(string message)
        {
            writeLine(message, ConsoleColor.DarkRed);
        }

        public void Fatal(string message)
        {
            writeLine(message, ConsoleColor.Red);
        }
    }
}
