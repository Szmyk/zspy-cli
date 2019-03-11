using System;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace zspy_cli
{
    public struct CopyData
    {
        public IntPtr dwData;
        public int cbData;

        [MarshalAs(UnmanagedType.LPStr)]
        public string lpData;
    }

    public class FakeZSpy : Form
    {
        private bool gothicHasStarted;

        protected override void WndProc(ref Message m)
        {
            if (!gothicHasStarted && m.Msg == 0x6) //WM_ACTIVATE
            {
                Console.WriteLine("Gothic started.");

                gothicHasStarted = true;
            }
            else if (m.Msg == 0x4A) //WM_COPYDATA
            {
                var data = (CopyData)m.GetLParam(typeof(CopyData));

                var message = data.lpData;

                if (message.StartsWith("Fatal:"))
                {
                    Program.Logger.Fatal(message);
                }
                else if (message.StartsWith("Warn:"))
                {
                    Program.Logger.Warning(message);
                }
                else if (message.StartsWith("Fault:"))
                {
                    Program.Logger.Fault(message);
                }
                else
                {
                    Program.Logger.Information(message);
                }
            }

            base.WndProc(ref m);
        }

        protected override void SetVisibleCore(bool value)
        {
            base.CreateHandle();

            base.SetVisibleCore(false);
        }
    }
}
