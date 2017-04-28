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
        public EngineWrapperClass nat;
        public Random r;
        public Thread MainWindowThread;
        public Logik GameLogik;
        public System.Threading.Timer t;
        public Startup()
        {
            r = new Random();
            nat = new EngineWrapperClass();
            MainWindowThread = new Thread(nat.MainWindow);
            GameLogik = new Logik();
            t = new System.Threading.Timer(Input, null, Timeout.Infinite, Timeout.Infinite);
        }

        public void start()
        {



            //Console.WriteLine("EngineWrapper Test : \t" + nat.TestWrapper());

            Console.WriteLine("C# Library Test : \t" + (GameLogik.TestLogik()));

            Application.Run(new MainForm(MainWindowThread, t));
        }

        void Input(object state)
        {
            Console.WriteLine(nat.GetDirection());
            nat.SetDirection(r.Next(1, 5));
        }
    }
}