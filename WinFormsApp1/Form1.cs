using System.Diagnostics;
using System.Runtime.InteropServices;

namespace WinFormsApp1
{
    public partial class Form1 : Form
    {

        [DllImport(@"C:\Users\kkos4\OneDrive\Рабочий стол\example_dll_transfer\main\x64\Debug\main.dll")]
        static extern void SetData(string str, int len, int idx);


        public Form1()
        {
            InitializeComponent();

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Process.Start(@"C:\Users\kkos4\OneDrive\Рабочий стол\example_dll_transfer\main\x64\Debug\ConsoleApplication1.exe");
            var str = "hi";
            var idx = 199999;
            SetData(str, System.Text.ASCIIEncoding.ASCII.GetByteCount(str), idx);
        }
    }
}