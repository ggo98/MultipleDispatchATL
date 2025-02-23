using Interop.MultipleDispatchATL;
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
            Interop.MultipleDispatchATL.ISimpleObject I = null;
            Interop.MultipleDispatchATL.ISimpleObject2 I2 = null;
            Interop.QueryDispatchForScripts.IQueryDispatchHelper QDHelper = null;
            Interop.MultipleDispatchATL.ISomeOtherInterface I3 = null;
            Interop.MultipleDispatchATL.ISomeOtherInterface I4 = null;
            try
            {
                I = new Interop.MultipleDispatchATL.SimpleObjectXO();
                MessageBox.Show(I.Method1(".NET"));
                I2 = I as ISimpleObject2;
                MessageBox.Show(I2.Method2(2).ToString());

                I3 = I as Interop.MultipleDispatchATL.ISomeOtherInterface;
                I3.SomeOtherMethod();

                // pour voir ce que ça donne, inutile d'utiliser ce biais en C#
                QDHelper = new Interop.QueryDispatchForScripts.QueryDispatchHelperXO();
                I4 = QDHelper.QueryDispatch(I, "ISomeOtherInterface");
                I4.SomeOtherMethod();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                if (null != I4)
                    Marshal.FinalReleaseComObject(I4);
                if (null != QDHelper)
                    Marshal.FinalReleaseComObject(QDHelper);
                if (null != I3)
                    Marshal.FinalReleaseComObject(I3);
                if (null != I)
                    Marshal.FinalReleaseComObject(I);
            }
        }
    }
}
