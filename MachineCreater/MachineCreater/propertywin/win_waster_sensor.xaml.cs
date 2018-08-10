using MachineCreater.model;
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
    /// Interaction logic for win_cup_sensor.xaml
    /// </summary>
    public partial class win_waster_sensor : Window
    {
        public Dev_SenWaster _data { get; set; }
        public win_waster_sensor(Dev_SenWaster a)
        {
            if (a != null)
                _data = a;
            else
                _data = new Dev_SenWaster(1);
            InitializeComponent();
            this.DataContext = _data;
            for (int i = 0; i < this.cb_max_cap.Items.Count; i++)
            {
                int value = Convert.ToInt32((string)(this.cb_max_cap.Items[i] as ComboBoxItem).Tag, 10);
                if (value == _data.Max_capability)
                {
                    this.cb_max_cap.SelectedIndex = i;
                    break;
                }
            }
        }

        private void cb_max_cap_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            _data.Max_capability = Convert.ToInt32((string)(this.cb_max_cap.SelectedItem as ComboBoxItem).Tag, 10);
        }
    }
}
