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
    /// Interaction logic for win_hopper.xaml
    /// </summary>
    public partial class win_hopper : Window
    {
        public DesignerCanvas _DesignerCanvas
        {
            get; set;
        }
        public Dev_Hopper hopperitem { get; set; }
        public bool isNew { get; set; }
        public win_hopper(DesignerCanvas a, bool isnew = false)
        {
            hopperitem = new Dev_Hopper(a.GetPositionID(DesignerCanvas.DeviceType.DEV_HOPPER));
            InitializeComponent();
            isNew = isnew;
            this.DataContext = this.hopperitem;


            for (int i = 0; i < this.cb_type.Items.Count; i++)
            {
                int value = Convert.ToInt32((string)(this.cb_type.Items[i] as ComboBoxItem).Tag, 16);
                if (value == hopperitem.Powder_type)
                {
                    this.cb_type.SelectedIndex = i;
                    break;
                }
            }
            for (int i = 0; i < this.cb_max_cap.Items.Count; i++)
            {
                int value = Convert.ToInt32((string)(this.cb_max_cap.Items[i] as ComboBoxItem).Tag, 10);
                if (value == hopperitem.Max_capability)
                {
                    this.cb_max_cap.SelectedIndex = i;
                    break;
                }
            }
        }
        public win_hopper(Dev_Hopper hopperitem)
        {
            this.hopperitem = hopperitem;
            InitializeComponent();           
            this.DataContext = this.hopperitem;
            for (int i = 0; i < this.cb_type.Items.Count; i++)
            {
                int value = Convert.ToInt32((string)(this.cb_type.Items[i] as ComboBoxItem).Tag, 16);
                if (value == hopperitem.Powder_type)
                {
                    this.cb_type.SelectedIndex = i;
                    break;
                }
            }
            for (int i = 0; i < this.cb_max_cap.Items.Count; i++)
            {
                int value = Convert.ToInt32((string)(this.cb_max_cap.Items[i] as ComboBoxItem).Tag, 10);
                if (value == hopperitem.Max_capability)
                {
                    this.cb_max_cap.SelectedIndex = i;
                    break;
                }
            }
        }

      
        private void ComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            //hopperitem.Compent_type = int.Parse((string) (this.cb_type.SelectedItem as ComboBoxItem).Tag, System.Globalization.NumberStyles.HexNumber);
            hopperitem.Powder_type = Convert.ToInt32((string)(this.cb_type.SelectedItem as ComboBoxItem).Tag, 16);
        }

        private void cb_max_cap_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            hopperitem.Max_capability = Convert.ToInt32((string)(this.cb_max_cap.SelectedItem as ComboBoxItem).Tag, 10);
        }
    }
}
