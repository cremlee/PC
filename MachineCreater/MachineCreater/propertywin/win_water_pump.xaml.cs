using MachineCreater.model;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
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
    public partial class win_water_pump : Window
    {
        public DesignerCanvas _DesignerCanvas
        {
            get; set;
        }
        public DEV_Waterpump _data_pump { get; set; }
        public DEV_Flowmeter _data_flow { get; set; }
        public win_water_pump(DEV_Waterpump a, ObservableCollection<Device> b)
        {
            InitializeComponent();
            if (a == null)
                _data_pump = new DEV_Waterpump(1,1);
            else
            {
                _data_pump = a;
            }
            if (b == null)
                _data_flow = new DEV_Flowmeter(1, 1);
            else
            {
                if(b.Count>=1)
                    _data_flow = (DEV_Flowmeter)b[0];
                else
                    _data_flow = new DEV_Flowmeter(1, 1);
            }
            this.sp_flowmeter.DataContext = _data_flow;
            this.sp_pump.DataContext = _data_pump;
            for (int i = 0; i < this.pump_type.Items.Count; i++)
            {
                int value = Convert.ToInt32((string)(this.pump_type.Items[i] as ComboBoxItem).Tag, 10);
                if (value == _data_pump.Compent_type)
                {
                    this.pump_type.SelectedIndex = i;
                    break;
                }
            }
            for (int i = 0; i < this.cb_flow.Items.Count; i++)
            {
                int value = Convert.ToInt32((string)(this.cb_flow.Items[i] as ComboBoxItem).Tag, 10);
                if (value == _data_flow.Compent_type)
                {
                    this.cb_flow.SelectedIndex = i;
                    break;
                }
            }
        }

        private void pump_type_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            _data_pump.Compent_type = Convert.ToInt32((string)(this.pump_type.SelectedItem as ComboBoxItem).Tag, 10);
        }

        private void cb_flow_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            _data_flow.Compent_type = Convert.ToInt32((string)(this.cb_flow.SelectedItem as ComboBoxItem).Tag, 10);
        }
    }
}
