using CREM.EVO.BLL;
using CREM.EVO.MODEL;
using CREM.EVO.Utility;
using System;
using System.Collections.Generic;
using System.Diagnostics;
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
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;
/*   
version 1.1 release 20160221 
1. fix the wipper speed is not correct 
2. improve the ingredient modify ui
3. use the convert for each parameter with double type 
4. make the base recipe for MF13 from cqrs
 */
namespace CREM.EVO
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private CREM.EVO.BLL.Control _my;
        public MainWindow()
        {
            readparam();
            _my = new BLL.Control(this);
            InitializeComponent();
            InitEvoCalibrationWin();
            this.DataContext = _my;
            
        }

        public static byte MajorVersion = 1;
        public static byte MinorVersion = 1;


        private void ListView_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            ListView tmp = sender as ListView;
            if (tmp.SelectedItem != null)
            {
                switch (tmp.Tag.ToString())
                {
                    case "Main":
                        _my.UpdateEvoMachine();
                        break;
                    case "Valve":
                        _my.UpdateWaterValve();
                        break;
                    case "Mixser":
                        _my.UpdateMixerUnit();
                        break;
                    case "Canister":
                        _my.UpdateCanisterValve();
                        break;
                    case "BeanHopper":
                        _my.UpdateBeanHopperValve();
                        break;
                    case "DEVTEST":
                        _my.UpdateDevice();
                        break;
                    case "Ingredient":
                        _my.UpdateIngredient();
                        FillPackageType();
                        ReloadCanisterIngredient();
                        FillBeanType();
                        break;
                    case "Recipe":
                        _my.UpdateRecipe();
                        // tbrcp.IsEnabled = true;
                        //spcmd.IsEnabled = true;
                        break;
                    default:
                        break;
                }
            }
            Console.WriteLine(sender.GetType());
        }

        private void FillBeanType()
        {
            gg1.Items.Clear();
            gg2.Items.Clear();
            ComboBoxItem tmp;
            if (_my._CrtEVOMachine._BeanHopperUint.Count == 1)
            {
                _my._CrtIngredient._FilterBrew.Grind2Cnt = 0;
                _my._CrtIngredient._FilterBrew.Grind2Type = 0;
                g2.IsEnabled = false;
                gg2.IsEnabled = false;
                gg1.IsEnabled = false;
                tmp = new ComboBoxItem();
                tmp.Tag = _my._CrtEVOMachine._BeanHopperUint[0].Powdertype;
                tmp.Content = _my._CrtEVOMachine._BeanHopperUint[0].GetPowdertype();
                gg1.Items.Add(tmp);
                gg1.SelectedIndex = 0;
                _my._CrtIngredient._FilterBrew.Grind1Type = (byte)(_my._CrtEVOMachine._BeanHopperUint[0].Powdertype + 0x80);
            }
            else if (_my._CrtEVOMachine._BeanHopperUint.Count == 2)
            {
                tmp = new ComboBoxItem();
                tmp.Tag = _my._CrtEVOMachine._BeanHopperUint[0].Powdertype;
                tmp.Content = _my._CrtEVOMachine._BeanHopperUint[0].GetPowdertype();
                gg1.Items.Add(tmp);
                gg1.SelectedIndex = 0;
                tmp = new ComboBoxItem();
                tmp.Tag = _my._CrtEVOMachine._BeanHopperUint[1].Powdertype;
                tmp.Content = _my._CrtEVOMachine._BeanHopperUint[1].GetPowdertype();
                gg2.Items.Add(tmp);
                gg2.SelectedIndex = 0;
                gg1.IsEnabled = false;
                gg2.IsEnabled = false;
                _my._CrtIngredient._FilterBrew.Grind1Type = (byte)(_my._CrtEVOMachine._BeanHopperUint[0].Powdertype + 0x80);
                _my._CrtIngredient._FilterBrew.Grind2Type = (byte)(_my._CrtEVOMachine._BeanHopperUint[1].Powdertype + 0x81);

            }
        }
        private void ReloadCanisterIngredient()
        {
            cc2.IsEnabled = false;
            cc4.IsEnabled = false;
            if (_my._CrtIngredient._InstantPowder.PackageOneType != 0)
            {
                foreach (var item in cc1.Items)
                {
                    ComboBoxItem tmp = item as ComboBoxItem;
                    if (tmp.Tag == null)
                    {
                        continue;
                    }
                    if ((tmp.Tag as CanisterUnit).Powdertype == _my._CrtIngredient._InstantPowder.PackageOneType)
                    {
                        cc1.SelectedItem = tmp;
                    }

                }
                cc2.IsEnabled = true;
            }
            else
            {
                cc1.SelectedIndex = 0;
            }
            if (_my._CrtIngredient._InstantPowder.PackageTwoType != 0)
            {
                foreach (var item in cc3.Items)
                {
                    ComboBoxItem tmp = item as ComboBoxItem;
                    if (tmp.Tag == null)
                    {
                        continue;
                    }
                    if ((tmp.Tag as CanisterUnit).Powdertype == _my._CrtIngredient._InstantPowder.PackageTwoType)
                    {
                        cc3.SelectedItem = tmp;
                    }
                }
                cc4.IsEnabled = true;
            }
            else
            {
                cc3.SelectedIndex = 0;

            }
        }
        private void FillPackageType()
        {
            cc1.Items.Clear();
            cc3.Items.Clear();
            ComboBoxItem tmp;
            tmp = new ComboBoxItem();
            tmp.Tag = null;
            tmp.Content = "Not Used";
            cc1.Items.Add(tmp);
            tmp = new ComboBoxItem();
            tmp.Tag = null;
            tmp.Content = "Not Used";
            cc3.Items.Add(tmp);
            foreach (var item in _my._CrtEVOMachine._CanisterUnit)
            {
                tmp = new ComboBoxItem();
                tmp.Tag = item;
                tmp.Content = item.GetPowdertype();
                cc1.Items.Add(tmp);
                tmp = new ComboBoxItem();
                tmp.Tag = item;
                tmp.Content = item.GetPowdertype();
                cc3.Items.Add(tmp);
            }
        }
        private void btndel_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show((sender as Button).Tag.ToString());
        }

        //////////////////////////////calibration///////////////////////////
        public void InitEvoCalibrationWin()
        {
            InitializeComponent();
            this.grd_test.Visibility = Visibility.Hidden;
            grd_test_temp.Visibility = System.Windows.Visibility.Hidden;
            this.grd_cal.Visibility = System.Windows.Visibility.Hidden;
            grd_test_brew.Visibility = System.Windows.Visibility.Hidden;
            this.grd_Process.Visibility = System.Windows.Visibility.Hidden;
            Tmr.Interval = TimeSpan.FromSeconds(5);
            Tmr.Tick += Tmr_Tick;
            Tmrpb.Interval = TimeSpan.FromSeconds(0.1);
            Tmrpb.Tick += Tmrpb_Tick;
            comunication.EVOEvent += comunication_EVOEvent;
        }

        void Tmrpb_Tick(object sender, EventArgs e)
        {
            Tmrpb.Stop();
            _crtpbValue++;
            if (_crtpbValue >= 150)
            {
                this.grd_Process.Visibility = System.Windows.Visibility.Hidden;
                grd_cal.Visibility = System.Windows.Visibility.Visible;
                this.tb_title_cal.Text = this.tb_title.Text;
                return;
            }
            else
            {
                pbar.Value = _crtpbValue;
            }
            Tmrpb.Start();
        }

        void comunication_EVOEvent(object sender, EVOData e)
        {
            if (e._cmdType == CmdType.B2M_CMD_CAL)
            {
                B2MCalibration dbcal = new B2MCalibration(e.datain, 0);
                if (dbcal.Result == 1)
                {
                    if (dbcal.calPartNo <= 0x8d)
                    {
                        System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() =>
                        {
                            _crtpbValue = 0;
                            this.grd_Process.Visibility = Visibility.Visible;
                            Tmrpb.Start();
                        }));
                    }
                }
            }
        }

        void Tmr_Tick(object sender, EventArgs e)
        {
            M2BStateQuery _stqury = new M2BStateQuery();
            byte[] sendcmd = _stqury.EnCode();
            try
            {
                lock (this)
                {
                    comunication.Getinstance().AddtoSend(sendcmd, (byte)sendcmd.Length);
                }
            }
            catch (Exception)
            {
            }
        }
        private byte _CalPartNo = 0;
        private UInt16 _CalValue = 0;
        public DispatcherTimer Tmr = new DispatcherTimer();
        public DispatcherTimer Tmrpb = new DispatcherTimer();
        private int _crtpbValue = 0;
        /*
         * 
         */
        private void Test_Click(object sender, RoutedEventArgs e)
        {
            Button tmp = sender as Button;
            _CalPartNo = byte.Parse(tmp.Tag.ToString());
            CalibrateType cltype = (CalibrateType)int.Parse(tmp.Tag.ToString());
            this.tb_title.Text = cltype.ToString();

            switch (cltype)
            {
                case CalibrateType.CAL_HOT:
                case CalibrateType.CAL_HOT_BREW:
                case CalibrateType.CAL_HOT_MIX_ONE:
                case CalibrateType.CAL_HOT_MIX_TWO:
                case CalibrateType.CAL_CANISTER_ONE:
                case CalibrateType.CAL_CANISTER_TWO:
                case CalibrateType.CAL_CANISTER_THREE:
                case CalibrateType.CAL_CANISTER_FOUR:
                case CalibrateType.CAL_BREW_100:
                case CalibrateType.CAL_BREW_75:
                case CalibrateType.CAL_BREW_50:
                case CalibrateType.CAL_CARBON:
                case CalibrateType.CAL_COLD:
                case CalibrateType.CAL_COLD_MIX:
                    if (MessageBox.Show(this, "Please place the cup,then press the ok to start!", "Calibration", MessageBoxButton.OKCancel) == MessageBoxResult.OK)
                    {
                        M2BCalibration calcmd = new M2BCalibration(_CalPartNo, _CalValue);
                        byte[] sendcmd = calcmd.EnCode();
                        lock (this)
                        {
                            comunication.Getinstance().AddtoSend(sendcmd, (byte)sendcmd.Length);
                        }
                    }

                    break;
                case CalibrateType.CAL_TEMPERATURE:
                    grd_test_brew.Visibility = System.Windows.Visibility.Hidden;
                    this.grd_test.Visibility = Visibility.Hidden;
                    this.grd_cal.Visibility = System.Windows.Visibility.Hidden;
                    this.grd_test_temp.Visibility = System.Windows.Visibility.Visible;
                    this.tb_title1.Text = cltype.ToString();
                    //TODO:开启温度查询
                    Tmr.Start();
                    break;
                default:
                    break;
            }
        }

        private void Cal_Click(object sender, RoutedEventArgs e)
        {

            Button tmp = sender as Button;
            if (_CalPartNo != byte.Parse(tmp.Tag.ToString()) || _CalValue == 0)
            {
                MessageBox.Show("Error!");
                return;
            }
            CalibrateType cltype = (CalibrateType)int.Parse(tmp.Tag.ToString());
            this.tb_title_cal.Text = cltype.ToString();
            this.grd_cal.Visibility = System.Windows.Visibility.Visible;
            switch (cltype)
            {
                case CalibrateType.CAL_HOT:
                    CalInport1.Maximum = 1000;
                    CalInport1.Minimum = 50;
                    break;
                case CalibrateType.CAL_HOT_BREW:
                    CalInport1.Maximum = 1000;
                    CalInport1.Minimum = 50;
                    break;
                case CalibrateType.CAL_HOT_MIX_ONE:
                    CalInport1.Maximum = 1000;
                    CalInport1.Minimum = 50;
                    break;
                case CalibrateType.CAL_HOT_MIX_TWO:
                    CalInport1.Maximum = 1000;
                    CalInport1.Minimum = 50;
                    break;
                case CalibrateType.CAL_CANISTER_ONE:
                    CalInport1.Maximum = 100;
                    CalInport1.Minimum = 20;
                    break;
                case CalibrateType.CAL_CANISTER_TWO:
                    CalInport1.Maximum = 100;
                    CalInport1.Minimum = 20;
                    break;
                case CalibrateType.CAL_CANISTER_THREE:
                    CalInport1.Maximum = 100;
                    CalInport1.Minimum = 20;
                    break;
                case CalibrateType.CAL_CANISTER_FOUR:
                    CalInport1.Maximum = 100;
                    CalInport1.Minimum = 20;
                    break;
                case CalibrateType.CAL_BREW_100:
                case CalibrateType.CAL_BREW_75:
                case CalibrateType.CAL_BREW_50:
                    this.grd_cal.Visibility = System.Windows.Visibility.Hidden;
                    break;
                case CalibrateType.CAL_TEMPERATURE:
                    this.grd_cal.Visibility = System.Windows.Visibility.Hidden;
                    break;
                default:
                    break;
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            //TODO:Send Cal CMD
            _CalValue = (UInt16)CalInport.Value;
            if (_CalValue == 0)
            {
                MessageBox.Show("Value can not be null!!!");
                return;
            }
            M2BCalibration calcmd = new M2BCalibration(_CalPartNo, _CalValue);
            byte[] sendcmd = calcmd.EnCode();
            lock (this)
            {
                comunication.Getinstance().AddtoSend(sendcmd, (byte)sendcmd.Length);
            }
            MessageBox.Show("Calibration is start ,please wait");
            grd_test.Visibility = System.Windows.Visibility.Hidden;
            grd_test_temp.Visibility = System.Windows.Visibility.Hidden;
            this.grd_cal.Visibility = System.Windows.Visibility.Hidden;
            grd_test_brew.Visibility = System.Windows.Visibility.Hidden;
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            grd_test_brew.Visibility = System.Windows.Visibility.Hidden;
            this.grd_cal.Visibility = System.Windows.Visibility.Hidden;
            grd_test.Visibility = System.Windows.Visibility.Hidden;
            grd_test_temp.Visibility = System.Windows.Visibility.Hidden;
            Tmr.Stop();

        }

        private void temp_Cal(object sender, RoutedEventArgs e)
        {

            M2BDbSetting dbset = new M2BDbSetting();
            DBStruct tmp = new DBStruct();
            tmp.DBID = 0x8d;
            tmp.DBValue = (uint)water_temp.Value;
            dbset._DBGroup.Add(tmp);
            byte[] sendcmd = dbset.EnCode();
            lock (this)
            {
                comunication.Getinstance().AddtoSend(sendcmd, (byte)sendcmd.Length);
            }
            MessageBox.Show("Set Temp Finished");

        }

        private void Cal_Button_Click(object sender, RoutedEventArgs e)
        {
            M2BDbSetting dbset = new M2BDbSetting();
            DBStruct tmp = new DBStruct();
            tmp.DBID = _CalPartNo;
            tmp.DBValue = (uint)CalInport1.Value;
            dbset._DBGroup.Add(tmp);
            byte[] sendcmd = dbset.EnCode();
            lock (this)
            {
                comunication.Getinstance().AddtoSend(sendcmd, (byte)sendcmd.Length);
            }
            //MessageBox.Show("SET DB");
        }

        private void brew_Cal(object sender, RoutedEventArgs e)
        {
            M2BCalibration calcmd = new M2BCalibration(_CalPartNo, _CalValue);
            byte[] sendcmd = calcmd.EnCode();
            lock (this)
            {
                comunication.Getinstance().AddtoSend(sendcmd, (byte)sendcmd.Length);
            }
        }

        private void PackageoneType_Change(object sender, SelectionChangedEventArgs e)
        {
            if ((sender as ComboBox).SelectedItem != null)
            {
                cc3.Items.Clear();
                ComboBoxItem tmpp = new ComboBoxItem();
                tmpp.Tag = null;
                tmpp.Content = "Not Used";
                cc3.Items.Add(tmpp);
                ComboBoxItem obj = (ComboBoxItem)((sender as ComboBox).SelectedItem);
                cc2.IsEnabled = true;

                if (obj.Tag == null)
                {
                    _my._CrtIngredient._InstantPowder.PackageOneType = 0;
                    _my._CrtIngredient._InstantPowder.PackageOneAmt = 0;
                    return;
                }
                CanisterUnit tmp1 = (CanisterUnit)obj.Tag;

                _my._CrtIngredient._InstantPowder.PackageOneType = tmp1.Powdertype;
                foreach (var item in _my._CrtEVOMachine._CanisterUnit)
                {
                    ComboBoxItem tmp = new ComboBoxItem();
                    if (tmp1.Postion == 0)
                    {
                        if (item.Postion == 1)
                        {
                            tmp.Tag = item;
                            tmp.Content = item.GetPowdertype();
                            cc3.Items.Add(tmp);
                            break;

                        }
                    }
                    if (tmp1.Postion == 1)
                    {
                        if (item.Postion == 0)
                        {
                            tmp.Tag = item;
                            tmp.Content = item.GetPowdertype();
                            cc3.Items.Add(tmp);
                            break;

                        }

                    }
                    if (tmp1.Postion == 2)
                    {
                        if (item.Postion == 3)
                        {
                            tmp.Tag = item;
                            tmp.Content = item.GetPowdertype();
                            cc3.Items.Add(tmp);
                            break;

                        }

                    }
                    if (tmp1.Postion == 3)
                    {
                        if (item.Postion == 2)
                        {
                            tmp.Tag = item;
                            tmp.Content = item.GetPowdertype();
                            cc3.Items.Add(tmp);
                            break;

                        }

                    }
                }
            }
            else
            {
                // _my._CrtIngredient._InstantPowder.PackageOneType = 0;
                // _my._CrtIngredient._InstantPowder.PackageOneAmt = 0;
                cc2.IsEnabled = false;
            }
        }

        private void PackagetwoType_Change(object sender, SelectionChangedEventArgs e)
        {
            if ((sender as ComboBox).SelectedItem != null)
            {
                ComboBoxItem obj = (ComboBoxItem)((sender as ComboBox).SelectedItem);
                cc4.IsEnabled = true;
                if (obj.Tag == null)
                {
                    _my._CrtIngredient._InstantPowder.PackageTwoType = 0;
                    _my._CrtIngredient._InstantPowder.PackageTwoAmt = 0;
                    return;
                }
                CanisterUnit tmp1 = (CanisterUnit)obj.Tag;
                _my._CrtIngredient._InstantPowder.PackageTwoType = tmp1.Powdertype;


            }
            else
            {
                cc4.IsEnabled = false; ;

            }
        }

        private void menu_check(object sender, RoutedEventArgs e)
        {
            menuType tmp = (menuType)(int.Parse((sender as MenuItem).Tag.ToString()));
            //MessageBox.Show(tmp.ToString());
            Process myProcess;
            switch (tmp)
            {
                case menuType.MENU_CALIBRATION:
                    EvoCalibrationWin wina = new EvoCalibrationWin(_my._MachineInfo);
                    wina.Show();
                    break;
                case menuType.MENU_IMPORT:
                    Microsoft.Win32.OpenFileDialog op = new Microsoft.Win32.OpenFileDialog();
                    op.InitialDirectory = AppDomain.CurrentDomain.BaseDirectory + "outport";
                    op.Filter = "evos File|*.evos";
                    op.FilterIndex = 1;
                    if ((bool)op.ShowDialog())
                    {
                        string savePath = op.FileName;
                        if (MessageBox.Show("Overwrite the current config?", "Hint", MessageBoxButton.YesNo) == MessageBoxResult.Yes)
                        {
                            FunctionFileManage.ImpportDB(savePath);
                        }
                    }
                    break;
                case menuType.MENU_EXPORT:
                    Microsoft.Win32.SaveFileDialog openFileDialog = new Microsoft.Win32.SaveFileDialog();
                    openFileDialog.InitialDirectory = AppDomain.CurrentDomain.BaseDirectory + "outport";
                    openFileDialog.Filter = "evos File|*.evos";
                    openFileDialog.FilterIndex = 1;

                    if ((bool)openFileDialog.ShowDialog())
                    {
                        string savePath = openFileDialog.FileName;
                        FunctionFileManage.ExportDB(savePath);
                    }
                    break;
                case menuType.MENU_COM:
                    _my.ComCmd.Execute(513);
                    break;
                case menuType.MENU_VISUAL:
                    myProcess = new Process();
                    try
                    {
                        myProcess.StartInfo.UseShellExecute = false;
                        myProcess.StartInfo.FileName = "GIFConverter.exe";
                        myProcess.StartInfo.CreateNoWindow = true;
                        myProcess.Start();
                    }
                    catch (Exception e1)
                    {
                        Console.WriteLine(e1.Message);
                    }
                    break;
                case menuType.MENU_PIC:
                    myProcess = new Process();
                    try
                    {
                        myProcess.StartInfo.UseShellExecute = false;
                        myProcess.StartInfo.FileName = "EVO.TOOL.MAKEPIC.exe";
                        myProcess.StartInfo.CreateNoWindow = true;
                        myProcess.Start();
                    }
                    catch (Exception e1)
                    {
                        Console.WriteLine(e1.Message);
                    }
                    break;
                case menuType.MENU_USB:
                    myProcess = new Process();
                    try
                    {
                        myProcess.StartInfo.UseShellExecute = false;
                        myProcess.StartInfo.FileName = "EVO.TOOL.USBFILE.exe";
                        myProcess.StartInfo.CreateNoWindow = true;
                        myProcess.Start();
                    }
                    catch (Exception e1)
                    {
                        Console.WriteLine(e1.Message);
                    }
                    break;
                case menuType.MENU_HELP:
                    MessageBox.Show("Coming Soon!!!");
                    break;
                case menuType.MENU_ABOUT:
                    MessageBox.Show("Version:"+ MajorVersion.ToString()+"."+ MinorVersion.ToString() + " supported by Crem", "Infomation");
                    break;
                default:
                    break;
            }
        }
        private static void readparam()
        {
            string command = Environment.CommandLine;
            string[] para = command.Split('\"');
            if (para.Length > 3)
            {
                string pathC = para[3];
                if (pathC.EndsWith("evos"))
                {
                    string folder = para[1].Substring(0,para[1].LastIndexOf('\\'));
                    System.IO.DirectoryInfo di = new System.IO.DirectoryInfo(folder+"\\config");
                    if (di.GetFiles().Length > 0)
                    {
                        if (MessageBox.Show("Overwrite the current config?", "Hint", MessageBoxButton.YesNo) == MessageBoxResult.Yes)
                        {
                            FunctionFileManage.ImpportDB(pathC, folder + "\\config\\");
                        }
                        else
                        {
                        }
                    }
                }
            }
        }
        private void clean_start(object sender, RoutedEventArgs e)
        {
            Button obj = sender as Button;
            if (obj != null)
            {
                byte action = byte.Parse(obj.Tag.ToString());
                lock (this)
                {
                    M2BClean cleancmd = new M2BClean(action);
                    byte[] sendcmd = cleancmd.EnCode();
                    comunication.Getinstance().AddtoSend(sendcmd, (byte)sendcmd.Length);
                }
            }
        }

        private void clean_stop(object sender, RoutedEventArgs e)
        {
            Button obj = sender as Button;
            if (obj != null)
            {
                lock (this)
                {
                    M2BStopClean cleancmd = new M2BStopClean();
                    byte[] sendcmd = cleancmd.EnCode();
                    comunication.Getinstance().AddtoSend(sendcmd, (byte)sendcmd.Length);
                }
            }
        }

        private void lst_update(object sender, DataTransferEventArgs e)
        {
            ListBox lsb = sender as ListBox;
            lsb.ScrollIntoView(lsb.Items.Count);
        }
    }

    public enum menuType
    {
        MENU_IMPORT = 1,
        MENU_EXPORT,
        MENU_COM,
        MENU_VISUAL,
        MENU_PIC,
        MENU_USB,
        MENU_HELP,
        MENU_ABOUT,
        MENU_CALIBRATION
    }
}
