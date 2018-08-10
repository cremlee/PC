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
    public partial class win_es_boiler : Window
    {
        public Dev_Boiler_ES _gravity_boiler { get; set; }
        public DEV_Heater _DEV_Heater { get; set; }

        //public Dev_SenPressuer _Dev_SenPressuer { get; set; }

        // public DEV_Waterpump _DEV_Waterpump { get; set; }


        // public DEV_Flowmeter _DEV_Flowmeter { get; set; }

        //public DEV_Airbreak _DEV_Airbreak { get; set; }

        public Dev_SenNtc _Dev_SenNtc { get; set; }

        public Dev_SenNtc _Dev_SenNtc_2 { get; set; }
        public Dev_SenWater _Dev_SenWater { get; set; }

        public ObservableCollection<Device> _attach_dev { get; set; }

        private int waternum = 0;
        private int ntcnum = 0;
        private int pressurenum = 0;
        private int pumpnum = 0;
        private int flowmeternum = 0;
        private int airbreaknum = 0;
        private int heaternum = 0;
        public DesignerCanvas _DesignerCanvas
        {
            get; set;
        }
        //public Dev_Fan _fan { get; set; }
        public win_es_boiler(Dev_Boiler_ES a, ObservableCollection<Device> b)
        {
            _gravity_boiler = a;
            _attach_dev = new ObservableCollection<Device>();
            if (b != null && b.Count > 0)
            {
                foreach (Device item in b)
                {                                      
                    if (item.Group_id == 0x0006)
                    {
                        if (item.Position_id == 1)
                            _Dev_SenNtc = (Dev_SenNtc)item;
                        if(item.Position_id == 2)
                            _Dev_SenNtc_2=(Dev_SenNtc)item;
                        _attach_dev.Add(item);
                        ntcnum++;

                    }
                    else if (item.Group_id == 0x0007)
                    {
                        if (item.Position_id == 1)
                            _Dev_SenWater = (Dev_SenWater)item;
                        _attach_dev.Add(item);
                        waternum++;
                    }

                    else if (item.Group_id == 0x0016)
                    {
                        _DEV_Heater = (DEV_Heater)item;
                        _attach_dev.Add(_DEV_Heater);
                        heaternum++;
                    }
                }
            }

            if (heaternum == 0)
            {
                _DEV_Heater = new DEV_Heater(1, 1);
                _attach_dev.Add(_DEV_Heater);
            }
            if (ntcnum == 0)
            {
                _Dev_SenNtc_2 = new Dev_SenNtc(2);
                _Dev_SenNtc = new Dev_SenNtc(1);
                _attach_dev.Add(_Dev_SenNtc);
            }
            if (waternum == 0)
            {
                _Dev_SenWater = new Dev_SenWater(1);
                _attach_dev.Add(_Dev_SenWater);
            }



            InitializeComponent();
            this.DataContext = a;
            sp_heater.DataContext = _DEV_Heater;
            sp_ntc.DataContext = _Dev_SenNtc;
            gd_ntc_low.DataContext = _Dev_SenNtc_2;
            for (int i = 0; i < this.cb_max_cap.Items.Count; i++)
            {
                int value = Convert.ToInt32((string)(this.cb_max_cap.Items[i] as ComboBoxItem).Tag, 10);
                if (value == _gravity_boiler.Max_capability)
                {
                    this.cb_max_cap.SelectedIndex = i;
                    break;
                }
            }
            for (int i = 0; i < this.cb_water_type.Items.Count; i++)
            {
                int value = Convert.ToInt32((string)(this.cb_water_type.Items[i] as ComboBoxItem).Tag, 10);
                if (value == _gravity_boiler.Inlet_water_type)
                {
                    this.cb_water_type.SelectedIndex = i;
                    break;
                }
            }


            if (ntcnum >= 2)
            {
                gd_ntc_low.Visibility = Visibility.Visible;
                cb_ntc_type.SelectedIndex = 1;
            }
            else
            {
                gd_ntc_low.Visibility = Visibility.Hidden;
                cb_ntc_type.SelectedIndex = 0;
            }
            if (waternum >= 2)
            {
                gd_water2.Visibility = Visibility.Visible;
                cb_level_type.SelectedIndex = 1;
            }
            else 
            {
                gd_water2.Visibility = Visibility.Hidden;
                cb_level_type.SelectedIndex = 0;
            }
        }
          
        private void cb_max_cap_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            _gravity_boiler.Max_capability = Convert.ToInt32((string)(this.cb_max_cap.SelectedItem as ComboBoxItem).Tag, 10);
        }
 
        private void cb_water_type_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            _gravity_boiler.Inlet_water_type = Convert.ToInt32((string)(this.cb_water_type.SelectedItem as ComboBoxItem).Tag, 10);
        }

        private void cb_level_type_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            int num = Convert.ToInt32((string)(this.cb_level_type.SelectedItem as ComboBoxItem).Tag, 10);
            if(num ==1)
            {
                gd_water2.Visibility = Visibility.Hidden;
                try
                {
                    var selectmany = _attach_dev.Where(c => c.Group_id == 0x0007).ToList<Device>();
                    selectmany.ForEach(item => delete(item));
                }
                catch (Exception e1) { }
                _attach_dev.Add(_Dev_SenWater);
            }
            else if(num ==2)
            {
                gd_water2.Visibility = Visibility.Visible;
                try
                {
                    var selectmany = _attach_dev.Where(c => c.Group_id == 0x0007).ToList<Device>();
                    selectmany.ForEach(item => delete(item));              
                }
                catch (Exception e1) { }
                _attach_dev.Add(_Dev_SenWater);
                _attach_dev.Add(new Dev_SenWater(2));
            }
        }

        private void delete(Device a)
        {
            _attach_dev.Remove(a);
        }
        private void cb_ntc_type_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            int num = Convert.ToInt32((string)(this.cb_ntc_type.SelectedItem as ComboBoxItem).Tag, 10);
            if (num == 1)
            {
                gd_ntc_low.Visibility = Visibility.Hidden;
                try
                {
                    var selectmany = _attach_dev.Where(c => c.Group_id == 0x0006).ToList<Device>();
                    selectmany.ForEach(item => delete(item));
                }
                catch (Exception e1) { }
                _attach_dev.Add(_Dev_SenNtc);
            }
            else if (num == 2)
            {
                gd_ntc_low.Visibility = Visibility.Visible;
                try
                {
                    var selectmany = _attach_dev.Where(c => c.Group_id == 0x0006).ToList<Device>();
                    selectmany.ForEach(item => delete(item));
                }
                catch (Exception e1) { }
                _attach_dev.Add(_Dev_SenNtc);
                _attach_dev.Add(new Dev_SenNtc(2));
            }
        }

    }
}
