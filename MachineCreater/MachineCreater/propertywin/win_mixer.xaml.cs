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
    /// Interaction logic for win_es_brewer.xaml
    /// </summary>
    public partial class win_mixer : Window
    {
        public Dev_Mixer_L _mixer { get; set; }
        public ObservableCollection<Dev_Fan> _attach_dev { get; set; }

        public DesignerCanvas _DesignerCanvas
        {
            get; set;
        }
        //public Dev_Fan _fan { get; set; }
        public win_mixer(Dev_Mixer_L a, ObservableCollection<Device> b)
        {
            _mixer = a;
            _attach_dev = new ObservableCollection<Dev_Fan>();
            if (b.Count > 0)
            {
                foreach (Device item in b)
                {
                    _attach_dev.Add((Dev_Fan)item);
                }
            }
            InitializeComponent();
            this.DataContext = a;
            if (b.Count == 1)
            { 
                this.gd_fan.DataContext = b[0];
                this.ckb_fan.IsChecked = true;
              }   
            else
                this.gd_fan.Visibility = Visibility.Hidden;
            for (int i = 0; i < this.cb_max_cap.Items.Count; i++)
            {
                int value = Convert.ToInt32((string)(this.cb_max_cap.Items[i] as ComboBoxItem).Tag, 10);
                if (value == _mixer.Max_capability)
                {
                    this.cb_max_cap.SelectedIndex = i;
                    break;
                }
            }
        }

        private void CheckBox_Checked(object sender, RoutedEventArgs e)
        {
            if(this.ckb_fan.IsChecked==true)
            {
                _attach_dev.Clear();
                this.gd_fan.Visibility = Visibility.Visible;
                _attach_dev.Add(new Dev_Fan(_DesignerCanvas.GetPositionID(DesignerCanvas.DeviceType.DEV_FAN)));
                this.gd_fan.DataContext = _attach_dev[0];
            }
            else
            {
                this.gd_fan.Visibility = Visibility.Hidden;
                _DesignerCanvas.ReleasePositionID(_attach_dev[0].Position_id, DesignerCanvas.DeviceType.DEV_FAN);
                _attach_dev.Clear();
            }
        }

        private void cb_max_cap_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            _mixer.Max_capability = Convert.ToInt32((string)(this.cb_max_cap.SelectedItem as ComboBoxItem).Tag, 10);
        }
    }
}
