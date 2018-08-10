using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace MachineCreater.propertywin
{
    /// <summary>
    /// Interaction logic for win_peripheral_select.xaml
    /// </summary>
    public partial class win_peripheral_select : Window
    {
        public delegate void SelectBtnClick(object sender, string id);
        public event SelectBtnClick UserControlBtnClicked;
        public win_peripheral_select()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            if(UserControlBtnClicked!=null)
            {
                UserControlBtnClicked(this, (sender as Button).CommandParameter.ToString());
            }
        }
    }
}
