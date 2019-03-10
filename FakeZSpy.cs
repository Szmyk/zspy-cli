﻿using System;
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
        protected override void WndProc(ref Message m)
        {
            if (m.Msg == 0x4A) //WM_COPYDATA
            {
                var data = (CopyData)m.GetLParam(typeof(CopyData));

                var message = data.lpData;

                Console.WriteLine(message);
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
