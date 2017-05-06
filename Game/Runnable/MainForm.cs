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

namespace Runnable
{
    public partial class MainForm : Form
    {
        private Thread MainWindowThread;
        private System.Threading.Timer t;

        public MainForm()
        {
            InitializeComponent();
        }

        public MainForm(Thread MainThread)
        {
            InitializeComponent();
            this.MainWindowThread = MainThread;
        }

        public MainForm(Thread MainThread, System.Threading.Timer t) : this(MainThread)
        {
            this.t = t;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MainWindowThread.Start();
            t.Change(500, 200);
        }

        private void button2_Click(object sender, EventArgs e)
        {

        }
    }
}
