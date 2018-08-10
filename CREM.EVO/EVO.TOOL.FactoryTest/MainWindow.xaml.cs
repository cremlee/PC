using CREM.EVO.BLL;
using CREM.EVO.MODEL;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;

namespace EVO.TOOL.FactoryTest
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public enum UI_TYPE
        {
            UI_NONE,
            UI_SETTING,
            UI_INPUT,
            UI_OUTPUT
        }
        /// <summary>
        /// 状态查询定时器
        /// </summary>
        public DispatcherTimer Tmr = new DispatcherTimer();
        public MachineInfo _myMachineInfo = new MachineInfo();
        public MainWindow()
        {
            InitializeComponent();
            SetMainFrame(UI_TYPE.UI_NONE);
            InitVer();
        }
        private string portname = "";
        private bool InitComport()
        {
            comunication.Getinstance().SetComPort(portname, 19200);
            int ret = comunication.Getinstance().Open();
            if (ret !=0)
            {
                return false; 
            }
            comunication.EVOEvent += comunication_EVOEvent;
            return true;
        }
        private void InitVer()
        {
            Tmr.Interval = TimeSpan.FromMilliseconds(300);
            Tmr.Tick += Tmr_Tick;
            this.DataContext = _myMachineInfo;

        }
        private void comunication_EVOEvent(object sender, EVOData e)
        {
            switch (e._cmdType)
            {
                case CmdType.B2M_CMD_QUERY:
                    B2MStateQuery evost = new B2MStateQuery(e.datain, 0);
                    _myMachineInfo.Err_clean = evost.modulestate.IsCleanErr;
                    _myMachineInfo.Err_cooling = evost.modulestate.IsCoolingErr;
                    _myMachineInfo.Err_heating = evost.modulestate.IsHeatingErr;
                    _myMachineInfo.Err_soldout = evost.modulestate.IsSoldoutErr;
                    _myMachineInfo.Err_water = evost.modulestate.IsWaterErr;
                    _myMachineInfo.Exist_cup1 = evost.sensorstate.cup1;
                    _myMachineInfo.Exist_cup2 = evost.sensorstate.cup2;
                    _myMachineInfo.Exist_door = evost.sensorstate.door;
                    _myMachineInfo.Exist_driplevel = evost.sensorstate.driptraylevel;
                    _myMachineInfo.Exist_dripswitch = evost.sensorstate.driptrayswitch;
                    _myMachineInfo.machinestate = evost.machinestate;
                    _myMachineInfo.Temp_fan = evost.temperatureinfo.Fan;
                    _myMachineInfo.Temp_fridge = evost.temperatureinfo.Fridge;
                    _myMachineInfo.Temp_water = evost.temperatureinfo.Water;
                    _myMachineInfo.Brew_sw = evost.sensorstate.brew_sw;
                    _myMachineInfo.Waterlevel_low = (evost.sensorstate.waterlevel < 1 ? false : true);
                    _myMachineInfo.Waterlevel_high = (evost.sensorstate.waterlevel ==1 ? true : false);
                    break;
                
                case CmdType.B2M_CMD_DB_GET:
                    B2MDbGetting dbget = new B2MDbGetting(e.datain, 0);
                    System.Windows.Application.Current.Dispatcher.BeginInvoke(
                        new Action(() => { tbver.Text = dbget._DBGroup[0].DBValue.ToString("X4"); }));

                    break;
                default:
                    break;
            }
        }
        private void Tmr_Tick(object sender, EventArgs e)
        {
            Stquery();
        }
        private void Slider_LostMouseCapture(object sender, MouseEventArgs e)
        {
            if((sender as Slider).Value.Equals(0))
            { StopTestDevice((sender as Slider).Tag.ToString()); }
            else
            { StartTestDevice((sender as Slider).Tag.ToString(),(byte)(sender as Slider).Value); }
            
        }
        private void SetMainFrame(UI_TYPE a)
        {
            switch (a)
            {
                case UI_TYPE.UI_NONE:
                    grd_setting.Visibility = Visibility.Collapsed;
                    grd_input.Visibility = Visibility.Collapsed;
                    grd_output.Visibility = Visibility.Collapsed;
                    break;
                case UI_TYPE.UI_SETTING:
                    grd_setting.Visibility = Visibility.Visible;
                    grd_input.Visibility = Visibility.Collapsed;
                    grd_output.Visibility = Visibility.Collapsed;
                    findport();
                    break;
                case UI_TYPE.UI_INPUT:
                    grd_setting.Visibility = Visibility.Collapsed;
                    grd_input.Visibility = Visibility.Visible;
                    grd_output.Visibility = Visibility.Collapsed;
                    break;
                case UI_TYPE.UI_OUTPUT:
                    grd_setting.Visibility = Visibility.Collapsed;
                    grd_input.Visibility = Visibility.Collapsed;
                    grd_output.Visibility = Visibility.Visible;
                    break;
                default:
                    break;
            }
        }
        private void TreeViewItem_Selected(object sender, RoutedEventArgs e)
        {
            if( (sender as TreeViewItem).Tag.ToString().Equals("setting"))
            {
                SetMainFrame(UI_TYPE.UI_SETTING);
            }
            else if ((sender as TreeViewItem).Tag.ToString().Equals("input"))
            {
                SetMainFrame(UI_TYPE.UI_INPUT);
                //开启状态查询
                if (!Tmr.IsEnabled)
                {
                    Tmr.Start(); 
                }
            }
            else if ((sender as TreeViewItem).Tag.ToString().Equals("output"))
            {
                SetMainFrame(UI_TYPE.UI_OUTPUT);
            }
        }
        private void TreeViewItem_Unselected(object sender, RoutedEventArgs e)
        {
            if ((sender as TreeViewItem).Tag.ToString().Equals("input"))
            {
                //关闭状态查询
                if (Tmr.IsEnabled)
                {
                    Tmr.Stop();
                }
            }
        }
        private void Stquery()
        {
            M2BStateQuery _stqury = new M2BStateQuery();
            byte[] sendcmd = _stqury.EnCode();
            try
            {
                comunication.Getinstance().AddtoSend(sendcmd, (byte)sendcmd.Length);
            }
            catch (Exception)
            {
            }
        }
        private void StartTestDevice(string DeviceID, byte speed=0)
        {
            try
            {
                byte id = byte.Parse(DeviceID);
                M2BTest testobj;
                if (id == 9 )
                {
                     testobj = new M2BTest(id, M2BTest.Turn_on_once, 100);
                }
                else
                {
                     testobj = new M2BTest(id, M2BTest.Turn_on_always, speed);

                }
                byte[] SendCmd = testobj.EnCode();
                comunication.Getinstance().AddtoSend(SendCmd, (byte)SendCmd.Length);
            }
            catch (Exception e)
            {

                MessageBox.Show("error:" + e.ToString());
            }
        }
        private void StopTestDevice(string DeviceID, byte speed = 0)
        {
            try
            {
                byte id = byte.Parse(DeviceID);
                M2BTest testobj = new M2BTest(id, M2BTest.Turn_off,speed);
                byte[] SendCmd = testobj.EnCode();
                comunication.Getinstance().AddtoSend(SendCmd, (byte)SendCmd.Length);
            }
            catch (Exception e)
            {

                MessageBox.Show("error:" + e.ToString());
            }
        }
        private void refresh_Click(object sender, RoutedEventArgs e)
        {
            findport();
        }
        private void findport()
        {
            cb_port.Items.Clear();
            Microsoft.VisualBasic.Devices.Computer pc = new Microsoft.VisualBasic.Devices.Computer();
            if (pc.Ports.SerialPortNames.Count == 0)
            {
                //this.cb_port.Items.Add("No Com Port Use!!!");
                return;
            }
            foreach (string s in pc.Ports.SerialPortNames)
            {
                this.cb_port.Items.Add(s);
            }
        }
        private void port_set(object sender, RoutedEventArgs e)
        {
            if (portname.Equals(""))
            {
                MessageBox.Show("请选择一个正确的串口号");
                return;
            }
            if (InitComport())
            {
                tbport.Text = portname;
                tbst.Text = "opened";
                M2BDbGeting testobj = new M2BDbGeting();
                testobj.DBCnt = 1;
                testobj.IDList.Add(0x96);
                byte[] SendCmd = testobj.EnCode();
                comunication.Getinstance().AddtoSend(SendCmd, (byte)SendCmd.Length);
            }
        }
        private void cb_port_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            try
            {
                portname = (sender as ComboBox).SelectedItem.ToString();

            }
            catch (Exception)
            {

                portname = "";

            }
        }
        private void test_checked(object sender, RoutedEventArgs e)
        {
            StartTestDevice((sender as ToggleButton).Tag.ToString());
        }
        private void test_unchecked(object sender, RoutedEventArgs e)
        {
            StopTestDevice((sender as ToggleButton).Tag.ToString());
        }
    }
}
