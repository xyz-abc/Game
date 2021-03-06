﻿using EngineWrapper;
using System;
using GameLogik;
using System.Windows.Forms;
using System.Threading;

namespace Runnable
{
    class Program
    {
        
        static void Main(string[] args)
        {
            Startup s = new Startup();
            s.start();
        }
    }
    public class Startup
    {
        static float z;
        public EngineWrapperClass nat;
        public Random r;
        public Thread MainWindowThread;
        public Logik GameLogik;
        public System.Threading.Timer t;
        public InputHandler.InputHandler ih;
        public Startup()
        {
            z = 0;
            r = new Random();
            nat = new EngineWrapperClass();
            MainWindowThread = new Thread(nat.MainWindow);
            GameLogik = new Logik(nat);
            t = new System.Threading.Timer(Input, null, Timeout.Infinite, Timeout.Infinite);
            ih = new InputHandler.InputHandler(nat);
        }

        public void start()
        {
            Application.Run(new MainForm(MainWindowThread, t, GameLogik));
        }

        void Input(object state)
        {
            //z += 1.0f;
            //nat.setCameraRotation(.0f, .0f, z);
            //Console.WriteLine(z);
            //Console.WriteLine(nat.getCameraRotation());
            //Console.WriteLine(nat.GetDirection());
            //nat.SetDirection(r.Next(1, 5));
        }
    }
}
