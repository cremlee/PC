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
    public partial class win_peripheral : Window
    {
        public DesignerCanvas _DesignerCanvas
        {
            get; set;
        }

        private win_cup_sensor _win_cup_sensor;
        private win_driptray_sensor _win_driptray_sensor;
        private win_waster_sensor _win_waster_sensor;
        private win_door_sensor _win_door_sensor;
        private win_led _win_led;
        public ObservableCollection<Device> _attach_dev { get; set; }
        public DEV_virMachine _DEV_virMachine{ get; set; }
        private win_peripheral_select _win_peripheral_select;
        public win_peripheral(DEV_virMachine b,ObservableCollection<Device> a)
        {
            _DEV_virMachine = b;
             _attach_dev = new ObservableCollection<Device>();
            if(a!=null && a.Count>0)   
            {
                foreach (Device item in a)
                {
                    _attach_dev.Add(item);
                }
            }  
            InitializeComponent();
            this.part_list.ItemsSource = _attach_dev;
        }

      
        private void Button_Click(object sender, RoutedEventArgs e)
        {

            Button b = sender as Button;
            int cmd = Convert.ToInt32(b.CommandParameter);

            if (cmd == Constant.CMD_ADD)
            {
                _win_peripheral_select = new win_peripheral_select();
                _win_peripheral_select.Owner = this;
                _win_peripheral_select.WindowStartupLocation = WindowStartupLocation.CenterOwner;
                _win_peripheral_select.UserControlBtnClicked += _win_peripheral_select_UserControlBtnClicked;
                _win_peripheral_select.ShowDialog();
            }
            else if (cmd == Constant.CMD_EDIT)
            {
                int id = Convert.ToInt32(b.Tag);
                Device item = _attach_dev.First(c => c.DeviceID == id);
                if (item.Group_id == 0x0008)
                {
                    _win_cup_sensor = new win_cup_sensor(item as Dev_SenCup);
                    _win_cup_sensor.Owner = this;
                    _win_cup_sensor.btn_save.Click += Btn_save_Click;
                    _win_cup_sensor.WindowStartupLocation = WindowStartupLocation.CenterOwner;
                    _win_cup_sensor.ShowDialog();
                }
               else if (item.Group_id == 0x000c)
                {
                    _win_led = new win_led(item as Dev_Led);
                    _win_led.Owner = this;
                    _win_led.btn_save.Click += Btn_save_Click;
                    _win_led.WindowStartupLocation = WindowStartupLocation.CenterOwner;
                    _win_led.ShowDialog();
                }
                else if (item.Group_id == 0x0018)
                {
                    _win_driptray_sensor = new win_driptray_sensor(item as  Dev_SenDriptray);
                    _win_driptray_sensor.Owner = this;
                    _win_driptray_sensor.btn_save.Click += Btn_save_Click;
                    _win_driptray_sensor.WindowStartupLocation = WindowStartupLocation.CenterOwner;
                    _win_driptray_sensor.ShowDialog();
                }
                else if (item.Group_id == 0x0019)
                {
                    _win_waster_sensor = new win_waster_sensor(item as Dev_SenWaster);
                    _win_waster_sensor.Owner = this;
                    _win_waster_sensor.btn_save.Click += Btn_save_Click;
                    _win_waster_sensor.WindowStartupLocation = WindowStartupLocation.CenterOwner;
                    _win_waster_sensor.ShowDialog();
                }
                else if (item.Group_id == 0x001a)
                {
                    _win_door_sensor = new win_door_sensor(item as Dev_SenDoor);
                    _win_door_sensor.Owner = this;
                    _win_door_sensor.btn_save.Click += Btn_save_Click;
                    _win_door_sensor.WindowStartupLocation = WindowStartupLocation.CenterOwner;
                    _win_door_sensor.ShowDialog();
                }

            }
            else if (cmd == Constant.CMD_DEL)
            {
                int id = Convert.ToInt32(b.Tag);
                Device item = _attach_dev.First(c => c.DeviceID == id);
                if(item.Group_id == 0x0008)
                    _DesignerCanvas.ReleasePositionID(item.Position_id, DesignerCanvas.DeviceType.DEV_CUP);
                else if (item.Group_id == 0x000c)
                    _DesignerCanvas.ReleasePositionID(item.Position_id, DesignerCanvas.DeviceType.DEV_LED);
                else if (item.Group_id == 0x0018)
                    _DesignerCanvas.ReleasePositionID(item.Position_id, DesignerCanvas.DeviceType.DEV_DRIP);
                else if (item.Group_id == 0x0019)
                    _DesignerCanvas.ReleasePositionID(item.Position_id, DesignerCanvas.DeviceType.DEV_WASTER);
                else if (item.Group_id == 0x001a)
                    _DesignerCanvas.ReleasePositionID(item.Position_id, DesignerCanvas.DeviceType.DEV_DOOR);
                _attach_dev.Remove(item);                
            }

        }

        private void _win_peripheral_select_UserControlBtnClicked(object sender, string id)
        {
            //MessageBox.Show(id);
            _win_peripheral_select.Close();
            if (id.Equals("0008"))
            {
                if(_DesignerCanvas.isValid(DesignerCanvas.DeviceType.DEV_CUP))
                {
                    _win_cup_sensor = new win_cup_sensor(new Dev_SenCup(_DesignerCanvas.GetPositionID(DesignerCanvas.DeviceType.DEV_CUP)));
                    _win_cup_sensor.Owner = this;
                    _win_cup_sensor.btn_save.Click += Btn_save_Click;
                    _win_cup_sensor.WindowStartupLocation = WindowStartupLocation.CenterOwner;                    
                    _win_cup_sensor.ShowDialog();
                }                    
                else
                { MessageBox.Show("error:too many"); }

            }
            else if (id.Equals("000c"))
            {
                if (_DesignerCanvas.isValid(DesignerCanvas.DeviceType.DEV_LED))
                {
                    _win_led = new win_led(new Dev_Led(0x0002,_DesignerCanvas.GetPositionID(DesignerCanvas.DeviceType.DEV_LED)));
                    _win_led.Owner = this;
                    _win_led.btn_save.Click += Btn_save_Click;
                    _win_led.WindowStartupLocation = WindowStartupLocation.CenterOwner;
                    _win_led.ShowDialog();
                }
                else
                { MessageBox.Show("error:too many"); }
            }
            else if (id.Equals("0018"))
            {
                if (_DesignerCanvas.isValid(DesignerCanvas.DeviceType.DEV_DRIP))
                {
                    _win_driptray_sensor = new win_driptray_sensor(new Dev_SenDriptray(_DesignerCanvas.GetPositionID(DesignerCanvas.DeviceType.DEV_DRIP)));
                    _win_driptray_sensor.Owner = this;
                    _win_driptray_sensor.btn_save.Click += Btn_save_Click;
                    _win_driptray_sensor.WindowStartupLocation = WindowStartupLocation.CenterOwner;
                    _win_driptray_sensor.ShowDialog();
                }
                else
                { MessageBox.Show("error:too many"); }

            }
            else if (id.Equals("0019"))
            {
                if (_DesignerCanvas.isValid(DesignerCanvas.DeviceType.DEV_WASTER))
                {
                    _win_waster_sensor = new win_waster_sensor(new Dev_SenWaster(_DesignerCanvas.GetPositionID(DesignerCanvas.DeviceType.DEV_WASTER)));
                    _win_waster_sensor.Owner = this;
                    _win_waster_sensor.btn_save.Click += Btn_save_Click;
                    _win_waster_sensor.WindowStartupLocation = WindowStartupLocation.CenterOwner;
                    _win_waster_sensor.ShowDialog();
                }
                else
                { MessageBox.Show("error:too many"); }
            }
            else if (id.Equals("001a"))
            {
                if (_DesignerCanvas.isValid(DesignerCanvas.DeviceType.DEV_DOOR))
                {
                    _win_door_sensor = new win_door_sensor(new Dev_SenDoor(_DesignerCanvas.GetPositionID(DesignerCanvas.DeviceType.DEV_DOOR)));
                    _win_door_sensor.Owner = this;
                    _win_door_sensor.btn_save.Click += Btn_save_Click;
                    _win_door_sensor.WindowStartupLocation = WindowStartupLocation.CenterOwner;
                    _win_door_sensor.ShowDialog();
                }
                else
                { MessageBox.Show("error:too many"); }
            }
            
        }

        private void Btn_save_Click(object sender, RoutedEventArgs e)
        {
            Button b = sender as Button;
            if (b.Tag.ToString().Equals("cup"))
            {
                if(_attach_dev.Any(c=>c.DeviceID == _win_cup_sensor._data.DeviceID))
                {

                     _attach_dev.Remove(_attach_dev.First(c => c.DeviceID == _win_cup_sensor._data.DeviceID));   
                   
                }
                _attach_dev.Add(_win_cup_sensor._data);
                _win_cup_sensor.Close();
            }
            else if (b.Tag.ToString().Equals("drip"))
            {
                if (_attach_dev.Any(c => c.DeviceID == _win_driptray_sensor._data.DeviceID))
                {

                    _attach_dev.Remove(_attach_dev.First(c => c.DeviceID == _win_driptray_sensor._data.DeviceID));

                }
                _attach_dev.Add(_win_driptray_sensor._data);
                _win_driptray_sensor.Close();
            }
            else if (b.Tag.ToString().Equals("waster"))
            {
                if (_attach_dev.Any(c => c.DeviceID == _win_waster_sensor._data.DeviceID))
                {

                    _attach_dev.Remove(_attach_dev.First(c => c.DeviceID == _win_waster_sensor._data.DeviceID));

                }
                _attach_dev.Add(_win_waster_sensor._data);
                _win_waster_sensor.Close();
            }
            else if (b.Tag.ToString().Equals("door"))
            {
                if (_attach_dev.Any(c => c.DeviceID == _win_door_sensor._data.DeviceID))
                {

                    _attach_dev.Remove(_attach_dev.First(c => c.DeviceID == _win_door_sensor._data.DeviceID));

                }
                _attach_dev.Add(_win_door_sensor._data);
                _win_door_sensor.Close();
            }
            else if (b.Tag.ToString().Equals("led"))
            {
                if (_attach_dev.Any(c => c.DeviceID == _win_led._data.DeviceID))
                {
                    _attach_dev.Remove(_attach_dev.First(c => c.DeviceID == _win_led._data.DeviceID));
                }
                _attach_dev.Add(_win_led._data);
                _win_led.Close();
            }
        }
    }
}
