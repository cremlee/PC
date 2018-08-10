using MachineCreater.model;
using MachineCreater.Utils;
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
    /// Interaction logic for Window1.xaml
    /// </summary>
    public partial class win_grinder : Window
    {
        public DesignerCanvas _DesignerCanvas
        {
            get; set;
        }
        private win_hopper _win_hopper;
        public Dev_Grinder _grinder { get; set; }
        public ObservableCollection<Dev_Hopper> _attach_dev { get; set; }
        public win_grinder(Dev_Grinder grinder, ObservableCollection<Device> a)
        {
            _grinder = grinder;          
             _attach_dev = new ObservableCollection<Dev_Hopper>();
            if(a!=null && a.Count>0)   
            {
                foreach (Device item in a)
                {
                    _attach_dev.Add((Dev_Hopper)item);
                }
            }  
            InitializeComponent();
            this.DataContext = _grinder;
            this.part_list.ItemsSource = _attach_dev;
        }

      
        private void Button_Click(object sender, RoutedEventArgs e)
        {

            Button b = sender as Button;
            int cmd = Convert.ToInt32(b.CommandParameter);

            if (cmd == Constant.CMD_ADD)
            {
                if (_DesignerCanvas.isValid(DesignerCanvas.DeviceType.DEV_HOPPER))
                {
                    _win_hopper = new win_hopper(_DesignerCanvas, true);
                    _win_hopper.Owner = this;
                    _win_hopper.WindowStartupLocation = WindowStartupLocation.CenterOwner;
                    _win_hopper.btn_save.Click += Btn_save_Click;
                    _win_hopper.ShowDialog();
                }
                else
                {
                    MessageBox.Show("Too many hopper!");
                }
            }
            else if (cmd == Constant.CMD_EDIT)
            {
                int id = Convert.ToInt32(b.Tag);                
                _win_hopper = new win_hopper(_attach_dev.First(c => c.DeviceID == id));
                _win_hopper.Owner = this;
                _win_hopper.WindowStartupLocation = WindowStartupLocation.CenterOwner;
                _win_hopper.btn_save.Click += Btn_save_Click;       
                _win_hopper.ShowDialog();
            }
            else if (cmd == Constant.CMD_DEL)
            {
                int id = Convert.ToInt32(b.Tag);
                Dev_Hopper item = _attach_dev.First(c => c.DeviceID == id);
                _DesignerCanvas.ReleasePositionID(item.Position_id, DesignerCanvas.DeviceType.DEV_HOPPER);                
                _attach_dev.Remove(item);                
            }

        }

        private void Btn_save_Click(object sender, RoutedEventArgs e)
        {
            //Console.WriteLine(_win_hopper.hopperitem.ToString());
             if(_win_hopper.isNew)
            {
                _attach_dev.Add(_win_hopper.hopperitem);
            }
            _win_hopper.Close();
        }

       
    }
}
