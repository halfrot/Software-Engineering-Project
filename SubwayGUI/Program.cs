using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace SubwayGUI
{
    static class Program
    {
        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        //dll接口
        [DllImport("QuickSubway_Dll.dll", EntryPoint = "ConsoleInterface", CallingConvention = CallingConvention.Cdecl)]
        public static extern void ConsoleInterface(int type, ref byte input, ref byte output);//引用传参

        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
