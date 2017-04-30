using EngineWrapper;
using System;
using System.Linq;
using System.Runtime.InteropServices;
using System.Threading;
using System.Windows.Forms;

namespace InputHandler
{
    public class InputHandler
    {
        EngineWrapperClass eng;
        System.Threading.Timer t;
        byte[] keys;
        DateTime elapsedTicks;
        public InputHandler(EngineWrapperClass e)
        {
            keys = new byte[256];
            elapsedTicks = DateTime.Now;
            eng = e;

            System.Threading.Timer t = new System.Threading.Timer(nextIteration, null, 0, 20);
        }

        void nextIteration(object state)
        {
            //keys = new byte[256];
            //GetKeyboardState(keys);

            //if ((keys[(int)Keys.Left] == 1))
            if ((GetKeyState(37) & 0x8000) > 0)
            { 
                //Console.WriteLine(GetKeyState(37) & 0x8000);
                eng.deltaCameraRotation(0, -9.0f, 0);
                
            }
            if ((GetKeyState(38) & 0x8000) > 0)
            {
                //Console.WriteLine(GetKeyState(37) & 0x8000);
                eng.deltaCameraRotation(-9.0f, 0, 0);
                
            }
            if ((GetKeyState(39) & 0x8000) > 0)
            {
                //Console.WriteLine(GetKeyState(37) & 0x8000);
                eng.deltaCameraRotation(0, 9.0f, 0);
                
            }
            if ((GetKeyState(40) & 0x8000) > 0)
            {
                //Console.WriteLine(GetKeyState(37) & 0x8000);
                eng.deltaCameraRotation(9.0f, 0, 0);
                
            }
            if ((GetKeyState(0x57) & 0x8000) > 0) // W
            {
                //Console.WriteLine(GetKeyState(37) & 0x8000);
                eng.deltaCameraPosition(0, 0, 1.0f);
                
            }
            if ((GetKeyState(0x41) & 0x8000) > 0) // A
            {
                //Console.WriteLine(GetKeyState(37) & 0x8000);
                eng.deltaCameraPosition(-1.0f, 0, 0);
                
            }
            if ((GetKeyState(0x53) & 0x8000) > 0) // S
            {
                //Console.WriteLine(GetKeyState(37) & 0x8000);
                eng.deltaCameraPosition(0, 0, -1.0f);
                
            }
            if ((GetKeyState(0x44) & 0x8000) > 0) // D
            {
                //Console.WriteLine(GetKeyState(37) & 0x8000);
                eng.deltaCameraPosition(1.0f, 0, 0);
                
            }
            if ((GetKeyState(0x45) & 0x8000) > 0) // E
                eng.deltaCameraPosition(0, -1.0f, 0);
            if ((GetKeyState(0x51) & 0x8000) > 0)
                eng.deltaCameraPosition(0, 1.0f, 0);
            //t.Change(1000, Timeout.Infinite);
        }
        [DllImport("user32.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
        public static extern short GetKeyState(int nVirtKey);
        [DllImport("user32.dll")]
        public static extern int GetKeyboardState(byte[] keystate);
    }
}
