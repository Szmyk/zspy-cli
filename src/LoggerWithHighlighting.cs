using System;

namespace zspy_cli
{
    public class LoggerWithHighlighting : ILogger
    {
        private string textToHighlight;

        public LoggerWithHighlighting(string textToHighlight)
        {
            this.textToHighlight = textToHighlight;
        }

        private void writeLine (string message, ConsoleColor color)
        {
            if (message.Contains(textToHighlight))
            {
                var indexOfHighligtingText = message.IndexOf(textToHighlight);

                Console.ForegroundColor = color;

                Console.Write(message.Substring(0, indexOfHighligtingText));

                Console.BackgroundColor = ConsoleColor.Yellow;
                Console.ForegroundColor = ConsoleColor.Black;

                Console.Write(message.Substring(indexOfHighligtingText, textToHighlight.Length));

                Console.BackgroundColor = ConsoleColor.Black;
                Console.ForegroundColor = color;

                Console.WriteLine(message.Substring(indexOfHighligtingText + textToHighlight.Length));

                Console.ForegroundColor = ConsoleColor.Gray;
            }
            else
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
