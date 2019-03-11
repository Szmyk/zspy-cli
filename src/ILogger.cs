namespace zspy_cli
{
    public interface ILogger
    {
        void Information(string message);
        void Warning(string message);
        void Fault(string message);
        void Fatal(string message);
    }
}
