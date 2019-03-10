using System.Threading;
using System.Windows.Forms;

namespace zspy_cli
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var zSpyWindowThread = new Thread(() =>
            {
                Application.Run(new FakeZSpy
                {
                    Text = "[zSpy]"
                });
            });

            zSpyWindowThread.Start();

            zSpyWindowThread.Join();
        }
    }
}
