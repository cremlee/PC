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
    public partial class win_led : Window
    {
        public Dev_Led _data { get; set; }
        public win_led(Dev_Led a)
        {
            InitializeComponent();
            if (a == null)
            {
                a = new Dev_Led(2,1);
            }
            else
                _data = a;
            this.DataContext = _data;

            for (int i = 0; i < this.cb_led_1.Items.Count; i++)
            {
                int value = Convert.ToInt32((string)(this.cb_led_1.Items[i] as ComboBoxItem).Tag, 10);
                if (value == _data.Compent_type)
                {
                    this.cb_led_1.SelectedIndex = i;
                    break;
                }
            }

            for (int i = 0; i < this.cb_led_2.Items.Count; i++)
            {
                int value = Convert.ToInt32((string)(this.cb_led_2.Items[i] as ComboBoxItem).Tag, 10);
                if (value == _data.Led_idel_mode)
                {
                    this.cb_led_2.SelectedIndex = i;
                    break;
                }
            }

            for (int i = 0; i < this.cb_led_3.Items.Count; i++)
            {
                int value = Convert.ToInt32((string)(this.cb_led_3.Items[i] as ComboBoxItem).Tag, 10);
                if (value == _data.Led_idel_color)
                {
                    this.cb_led_3.SelectedIndex = i;
                    break;
                }
            }

            for (int i = 0; i < this.cb_led_4.Items.Count; i++)
            {
                int value = Convert.ToInt32((string)(this.cb_led_4.Items[i] as ComboBoxItem).Tag, 10);
                if (value == _data.Led_idel_intensity)
                {
                    this.cb_led_4.SelectedIndex = i;
                    break;
                }
            }

            for (int i = 0; i < this.cb_led_5.Items.Count; i++)
            {
                int value = Convert.ToInt32((string)(this.cb_led_5.Items[i] as ComboBoxItem).Tag, 10);
                if (value == _data.Led_warn_mode)
                {
                    this.cb_led_5.SelectedIndex = i;
                    break;
                }
            }

            for (int i = 0; i < this.cb_led_6.Items.Count; i++)
            {
                int value = Convert.ToInt32((string)(this.cb_led_6.Items[i] as ComboBoxItem).Tag, 10);
                if (value == _data.Led_warn_color)
                {
                    this.cb_led_6.SelectedIndex = i;
                    break;
                }
            }

            for (int i = 0; i < this.cb_led_7.Items.Count; i++)
            {
                int value = Convert.ToInt32((string)(this.cb_led_7.Items[i] as ComboBoxItem).Tag, 10);
                if (value == _data.Led_warn_intensity)
                {
                    this.cb_led_7.SelectedIndex = i;
                    break;
                }
            }

        }

        private void cb_led_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            ComboBox cb = sender as ComboBox;
            if(cb.Name.Equals("cb_led_1")) // type
                _data.Compent_type = Convert.ToInt32((string)(this.cb_led_1.SelectedItem as ComboBoxItem).Tag, 10);
            else if (cb.Name.Equals("cb_led_2")) // 
                _data.Led_idel_mode = Convert.ToInt32((string)(this.cb_led_2.SelectedItem as ComboBoxItem).Tag, 10);
            else if (cb.Name.Equals("cb_led_3")) // 
                _data.Led_idel_color = Convert.ToInt32((string)(this.cb_led_3.SelectedItem as ComboBoxItem).Tag, 10);
            else if (cb.Name.Equals("cb_led_4")) // 
                _data.Led_idel_intensity = Convert.ToInt32((string)(this.cb_led_4.SelectedItem as ComboBoxItem).Tag, 10);
            else if (cb.Name.Equals("cb_led_5")) // 
                _data.Led_warn_mode = Convert.ToInt32((string)(this.cb_led_5.SelectedItem as ComboBoxItem).Tag, 10);
            else if (cb.Name.Equals("cb_led_6")) // 
                _data.Led_warn_color = Convert.ToInt32((string)(this.cb_led_6.SelectedItem as ComboBoxItem).Tag, 10);
            else if (cb.Name.Equals("cb_led_7")) // 
                _data.Led_warn_intensity = Convert.ToInt32((string)(this.cb_led_7.SelectedItem as ComboBoxItem).Tag, 10);
        }
    }
}
