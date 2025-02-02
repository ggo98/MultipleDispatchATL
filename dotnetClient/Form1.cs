using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace dotnetClient
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Interop.MultipleDispatchATL.ISimpleObject2 I = null;
            Interop.QueryDispatchForScripts.IQueryDispatchHelper QDHelper = null;
            Interop.MultipleDispatchATL.ISomeOtherInterface I2 = null;
            Interop.MultipleDispatchATL.ISomeOtherInterface I3 = null;
            try
            {
                I = new Interop.MultipleDispatchATL.SimpleObjectXO();
                MessageBox.Show(I.Method1(".NET"));
                MessageBox.Show(I.Method2(2).ToString());

                I2 = I as Interop.MultipleDispatchATL.ISomeOtherInterface;
                I2.SomeOtherMethod();

                // pour voir ce que ça donne, inutile d'utiliser ce biais en C#
                QDHelper = new Interop.QueryDispatchForScripts.QueryDispatchHelperXO();
                I3 = QDHelper.QueryDispatch(I, "ISomeOtherInterface");
                I3.SomeOtherMethod();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                if (null != I3)
                    Marshal.FinalReleaseComObject(I3);
                if (null != QDHelper)
                    Marshal.FinalReleaseComObject(QDHelper);
                if (null != I2)
                    Marshal.FinalReleaseComObject(I2);
                if (null != I)
                    Marshal.FinalReleaseComObject(I);
            }
        }
    }
}
