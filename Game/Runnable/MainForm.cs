using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using EngineWrapper;
using System.Threading;
using GameLogik;
using GameLogik.Objects;

namespace Runnable
{
    public partial class MainForm : Form
    {
        private Thread MainWindowThread;
        private System.Threading.Timer t;
        private Logik logik;

        public MainForm()
        {
            InitializeComponent();
        }

        public MainForm(Thread MainThread)
        {
            InitializeComponent();
            this.MainWindowThread = MainThread;
        }

        public MainForm(Thread MainThread, System.Threading.Timer t, Logik log) : this(MainThread)
        {
            this.t = t;
            logik = log;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MainWindowThread.Start();
            t.Change(500, 200);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            logik.AddNewObject(new testModel());
        }
    }
}
