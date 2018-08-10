#define DEBUG
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Threading.Tasks;
using CREM.EVO.Utility;
using CREM.EVO.MODEL;
using System.Collections.ObjectModel;
using CREM.EVO;
using System.Diagnostics;
using System.Windows.Threading;
using System.IO;
using System.Collections;
using System.Threading;


namespace CREM.EVO.BLL
{
    public class Control
    {
        public DelegateCommand ClickCommand { get; set; }
        public EVOMachine _CrtEVOMachine { get; set; }
        public WaterValve _CrtWaterValve { get; set; }
        public MixerUnit _CrtMixerUnit { get; set; }
        public CanisterUnit _CrtCanisterUnit { get; set; }
        public BeanHopperUint _CrtBeanHopperUint { get; set; }
        public DeviceUnit _CrtDeviceUnit { get; set; }
        public IngredientInfo _CrtIngredient { get; set; }
        public RecipeInfo _CrtRecipeInfo { get; set; }
        public EVOCleaning _CrtEVOCleaning { get; set; }
        public ObservableCollection<EVOMachine> _LstEVOMachine { get; set; }
        public ObservableCollection<DeviceUnit> _LstDeviceUnit { get; set; }
        
        public UiData _UiData { get; set; }
        public EvoRecipe _EvoRecipe { get; set; }
        private ComSetting _ComSetting { get; set; }
        //private comunication _comunication { get; set; }
        public IDGenrator _IDControl { get; set; }
        private EVOBaseConf _EVOBaseConf = new EVOBaseConf();
        public DBItem _crtDBItem { get; set; }
        public EvoUpdate _EvoUpdate { get; set; }
        public MachineInfo _MachineInfo { get; set; }
        
        public MachineSetingInfo _MachineSetingInfo { get; set; }
        public EVOTestForm _TestSet;
        //public EvoStCheck _EvoStCheck;

        private byte connectRtyCnt = 3;
        /// <summary>
        /// maintence data
        /// </summary>
        public ObservableCollection<EvoMaintenceInfo> _lstMaintenceInfo { get; set; }
        public IngredientSelecWin _IngredientSelecWin;

        public DelegateCommand BtnCmd { get; set; }
        public DelegateCommand ComCmd { get; set; }
        public DelegateCommand EditCMD { get; set; }
        public DelegateCommand DelCMD { get; set; }
        public DelegateCommand Del1CMD { get; private set; }



        public DelegateCommand TestCMD { get; set; }
        public DelegateCommand Del2CMD { get;  set; }

        public DispatcherTimer Tmr = new DispatcherTimer();
        /*
         * 
         * TEST water flow for each item
         
        private static byte FLOW_BREW = 20;
        private static byte FLOW_MILK = 18;
        private static byte FLOW_MILK_WATER = 18;
        private static byte FLOW_INSTANT_WATER = 20;
        private static byte FLOW_WATER = 20;
        */


        private Window _win = null;
        public Control(Window w)
        {

            _win = w;
            InitClass();
            InitFunction();
            InitDataModel();
            InitUiData();
            InitIDGenrator();
            
        }

        private void InitClass()
        {
            _UiData = new UiData();
            _CrtEVOMachine = new EVOMachine(true);
            _CrtWaterValve = new WaterValve();
            _CrtMixerUnit = new MixerUnit();
            _CrtCanisterUnit = new CanisterUnit();
            _CrtDeviceUnit = new DeviceUnit();
            _CrtBeanHopperUint = new BeanHopperUint();
            _CrtIngredient = new IngredientInfo(true);
            _CrtRecipeInfo = new RecipeInfo();
            _LstEVOMachine = new ObservableCollection<EVOMachine>();
            _LstDeviceUnit = new ObservableCollection<DeviceUnit>();
            _lstMaintenceInfo = new ObservableCollection<EvoMaintenceInfo>();
           // _EvoRecipe = new EvoRecipe();
            _IDControl = new IDGenrator();
            _crtDBItem = new DBItem();
            _EvoUpdate = new EvoUpdate();
            _MachineInfo = new MachineInfo();
            _CrtEVOCleaning = new EVOCleaning();
            _MachineSetingInfo = new MachineSetingInfo();
            Tmr.Interval = TimeSpan.FromMilliseconds(2500);
            Tmr.Tick += Tmr_Tick;
            Tmr.Start();
            _ComSetting = (ComSetting)Function.XmlSerializer.LoadFromXml("EVO.com.xml", typeof(ComSetting));
            comunication.Getinstance().SetComPort(_ComSetting.Port, _ComSetting.BaudRate);
            int ret = comunication.Getinstance().Open();
            comunication.EVOEvent += comunication_EVOEvent;
        }

        protected TimeSt _mySetTime;
        void comunication_EVOEvent(object sender, EVOData e)
        {
            switch (e._cmdType)
            {
                case CmdType.TIME_OUT:
                    connectRtyCnt++;
                    if (connectRtyCnt>=3)
                    {
                        _MachineSetingInfo.Connectst = "Disconnect";
                        //System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() => { _win.IsEnabled = false; }));
                        _UiData.is_com_error_visible = false;

                    }
                    break;
                case CmdType.B2M_CMD_DB_SET:
                    B2MDbSetting dbset = new B2MDbSetting(e.datain, 0);
                    if (dbset.Result == 1)
                    {
                        //MessageBox.Show("DB SET finished");
                    }
                    else
                    {
                        //MessageBox.Show("DB SET Failed!");
                    }
                    break;
                case CmdType.B2M_CMD_DB_GET:
                    B2MDbGetting dbget = new B2MDbGetting(e.datain, 0);
                    foreach (var item in dbget._DBGroup)
                    {
                        DBDefine tmp = (DBDefine)item.DBID; switch (tmp)
                        {
                            case DBDefine.TEMP_BLOCK:
                                _MachineSetingInfo.Tempblock = (UInt16)item.DBValue;
                                break;
                            case DBDefine.TEMP_IDEL:
                                _MachineSetingInfo.Tempsave = (UInt16)item.DBValue;
                                break;
                            case DBDefine.LED_SET:
                                _MachineSetingInfo.LedbtsIndex = (byte)((item.DBValue >> 8)-1);
                                _MachineSetingInfo.LedColorIndex = (byte)((item.DBValue >> 16)-1);
                                _MachineSetingInfo.LedModeIndex = (byte)((item.DBValue >> 24)-1);
                                break;
                            case DBDefine.PRICE_UNIT:
                                break;
                            case DBDefine.TEMP_WARN:
                                _MachineSetingInfo.Tempwarn = (UInt16)item.DBValue;
                                break;
                            case DBDefine.TEMP_NORMAL:
                                _MachineSetingInfo.Temptank = (UInt16)item.DBValue;
                                break;
                            case DBDefine.FAN_SPEED:
                                _MachineSetingInfo.FanSpd = (byte)item.DBValue;
                                break;
                            case DBDefine.DRIP_FLAG:
                                break;
                            case DBDefine.JUG_FLAG:
                                break;
                            case DBDefine.GRIND_SET:
                                break;
                            case DBDefine.CANISTER_SET:
                                break;
                            case DBDefine.PIN_CODE:
                                break;
                            case DBDefine.BREW_UP_SPD:
                                break;
                            case DBDefine.BREW_DOWN_SPD:
                                break;
                            case DBDefine.BREW_TST_SPD:
                                break;
                            case DBDefine.WATER_FILTER_VOLUME:
                                break;
                            case DBDefine.FAN_RUN_TM:
                                _MachineSetingInfo.Fanruntm = (byte)item.DBValue;
                                break;
                            case DBDefine.DATE_YEAR:
                                //_MachineSetingInfo.Dt. = Function.ACII2Int(item.DBValue);
                                _mySetTime = new TimeSt();
                                _mySetTime.year = Function.ACII2Int(item.DBValue);
                                _mySetTime.Setover++;
                                Console.WriteLine(_mySetTime.ToString());
                                break;
                            case DBDefine.DATE_MONTH_DAY:
                                _mySetTime.month = Function.ACII2Int((UInt16)(item.DBValue >> 16));
                                _mySetTime.day = Function.ACII2Int((UInt16)(item.DBValue));
                                _mySetTime.Setover++;
                                Console.WriteLine(_mySetTime.ToString());
                                break;
                            case DBDefine.DATE_HOUR_MIN:
                                _mySetTime.hour = Function.ACII2Int((UInt16)(item.DBValue >> 16));
                                _mySetTime.mintue = Function.ACII2Int((UInt16)(item.DBValue));
                                _mySetTime.Setover++;
                                Console.WriteLine(_mySetTime.ToString());
                                break;
                            case DBDefine.DATE_SECOND:
                                _mySetTime.Setover++;
                                _mySetTime.second = Function.ACII2Int((UInt16)(item.DBValue));
                                Console.WriteLine(_mySetTime.ToString());
                                if (_mySetTime.Setover>=4)
                                {
                                    _MachineSetingInfo.Dt = new DateTime(_mySetTime.year, _mySetTime.month, _mySetTime.day, _mySetTime.hour, _mySetTime.mintue, _mySetTime.second);
                                }
                                break;
                            case DBDefine.CUP_ENABLE:
                                break;
                            case DBDefine.VERSION_FIRM:
                                _MachineSetingInfo.Version = "Ver:" + (item.DBValue >> 24).ToString() + "." + (item.DBValue >> 16).ToString() + (item.DBValue >> 8).ToString() + (item.DBValue).ToString();
                                Console.WriteLine("VERSION_FIRM= "+ _MachineSetingInfo.Version);
                                break;
                            case DBDefine.MACHINE_TYPE:
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                case CmdType.B2M_CMD_MAINTENCE:
                    B2MMaintenance maintencedata = new B2MMaintenance(e.datain, 0);
                    System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() => { _lstMaintenceInfo.Clear(); }));
                    if (maintencedata.Result == 1)//数据有效
                    {
                        Maintence_T tmp;
                        foreach (var item in maintencedata._table)
                        {
                            tmp = new Maintence_T(item.id, (UInt32)item.value);
                            System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() => { _lstMaintenceInfo.Add(new EvoMaintenceInfo(tmp.ToDescription(), tmp.ToValue())); }));
                        }

                    }
                    //TODO:chu li shuju 
                    break;
                case CmdType.B2M_CMD_CLEAN:
                    B2MClean cleandata = new B2MClean(e.datain, 0);
                    if (cleandata.Result == 1)
                    {
                        _UiData.is_clean_block_visible = true;
                    }
                    break;
                case CmdType.B2M_CMD_STOP_CLEAN:
                    B2MStopClean stopcleandata = new B2MStopClean(e.datain, 0);
                    if (stopcleandata.Result == 1)
                    {
                       // _UiData.is_clean_block_visible = false;
                    }
                    break;
                case CmdType.B2M_CMD_FINISH_CLEAN:
                    B2MFinishClean finishcleandata = new B2MFinishClean(e.datain, 0);
                    if (finishcleandata.Result == 1)
                    {
                         _UiData.is_clean_block_visible = false;
                    }
                    break;
                case CmdType.B2M_CMD_MAKE_BERVAGE:
                    B2MMakeBeverage makebeverage = new B2MMakeBeverage(e.datain, 0);
                    Console.WriteLine("ID="+makebeverage.ID);
                    Console.WriteLine("operatetype=" + makebeverage.operatetype);
                    Console.WriteLine("Result=" + makebeverage.Result);
                    if (comunication.Getinstance().IsTransfer)
                    {
                        _EvoUpdate.updateindex++;
                        if (_EvoUpdate.updateindex == _EvoRecipe._lstRecipeInfo.Count)
                        {
                            if (_EvoUpdate.updatetype == 1)
                            {
                                //finished;
                                System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() => _EvoUpdate.Info = "update finished"));
                                comunication.Getinstance().IsTransfer = false;
                            }
                            else
                            {
                                _EvoUpdate.updateindex = 0;
                                _EvoUpdate.updatetype = 1;
                                System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() => _EvoUpdate.Info = "start update"));
                                Update_Rcp_Method();

                            }
                        }
                        else if (_EvoUpdate.updatetype == 1)
                        {
                            _EvoUpdate.CrtAmount = _EvoUpdate.updateindex + 1;
                            System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() => _EvoUpdate.Info = string.Format("updating ID{0} Recipe", _EvoRecipe._lstRecipeInfo[_EvoUpdate.updateindex].ID)));

                            Update_Rcp_Method();

                        }
                        else
                        {
                            Update_Rcp_Method();
                        }
                    }
                    else
                    {
                        if (makebeverage.Result == 1)
                        {
                            MessageBox.Show("MAKE_BERVAGE Successed!");
                        }
                        else
                        {
                            MessageBox.Show("MAKE_BERVAGE Failed!");
                        }
                    }
                    break;
                case CmdType.B2M_CMD_MAKE_DRINK:
                    break;
                case CmdType.B2M_CMD_MAKE_INGREDIENT:
                    B2MMakeIngredient makeingredient = new B2MMakeIngredient(e.datain, 0);
                    Console.WriteLine("ID=" + makeingredient.ID);
                    Console.WriteLine("operatetype=" + makeingredient.operatetype);
                    Console.WriteLine("Result=" + makeingredient.Result);
                    if (comunication.Getinstance().IsTransfer)
                    {
                        _EvoUpdate.updateindex++;
                        if (_EvoUpdate.updateindex ==_EvoRecipe._lstIngredientInfo.Count)
                        {
                            if (_EvoUpdate.updatetype ==1)
                            {
                                //finished;
                                System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(()=>  _EvoUpdate.Info = "update finished！"));
                                comunication.Getinstance().IsTransfer = false;
                            }
                            else
                            {
                                _EvoUpdate.updateindex = 0;
                                _EvoUpdate.updatetype = 1;
                                System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() => _EvoUpdate.Info = "start update！"));
                                Update_ING_Method();

                            }
                        }
                       else if (_EvoUpdate.updatetype == 1)
                        {
                            _EvoUpdate.CrtAmount = _EvoUpdate.updateindex + 1;
                            System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() => _EvoUpdate.Info = string.Format("updating ID:{0} ingredient", _EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex].ID)));

                            Update_ING_Method();

                        }else
                        {
                            Update_ING_Method();
                        }
                    }
                    else
                    {
                        if (makeingredient.Result == 1)
                        {
                            MessageBox.Show("MAKE_INGREDIENT Successed!");
                        }
                        else
                        {
                            MessageBox.Show("MAKE_INGREDIENT Failed!");
                        }
                    }
                    break;
                case CmdType.B2M_CMD_MATCH:
                    break;
                case CmdType.B2M_CMD_MODE_REQUEST:
                    break;
                case CmdType.B2M_CMD_QUERY:
                    //TODO:状态查询数据包
                    if (connectRtyCnt >=3)
                    {
                        //System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() => { _win.IsEnabled = true; }));
                        _UiData.is_com_error_visible = false;
                        connectRtyCnt = 0;
                        _MachineSetingInfo.Connectst = "Connected";
                        //取机器设置
                        M2BDbGeting testobj = new M2BDbGeting();
                        byte[] SendCmd = testobj.GetMachineSettingCmd();
                        lock (this)
                        {
                            comunication.Getinstance().AddtoSend(SendCmd, (byte)SendCmd.Length);
                        }
                    }
                    B2MStateQuery evost = new B2MStateQuery(e.datain, 0);
                    _MachineInfo.Err_clean = evost.modulestate.IsCleanErr;
                    _MachineInfo.Err_cooling = evost.modulestate.IsCoolingErr;
                    _MachineInfo.Err_heating = evost.modulestate.IsHeatingErr;
                    _MachineInfo.Err_soldout = evost.modulestate.IsSoldoutErr;
                    _MachineInfo.Err_water = evost.modulestate.IsWaterErr;
                    _MachineInfo.Exist_cup1 = evost.sensorstate.cup1;
                    _MachineInfo.Exist_cup2 = evost.sensorstate.cup2;
                    _MachineInfo.Exist_door = evost.sensorstate.door;
                    _MachineInfo.Exist_driplevel = evost.sensorstate.driptraylevel;
                    _MachineInfo.Exist_dripswitch = evost.sensorstate.driptrayswitch;
                    _MachineInfo.machinestate = evost.machinestate;
                    _MachineInfo.Temp_fan = evost.temperatureinfo.Fan;
                    _MachineInfo.Temp_fridge = evost.temperatureinfo.Fridge;
                    _MachineInfo.Temp_water = evost.temperatureinfo.Water;
                    _MachineInfo.Waterlevel_low = (evost.sensorstate.waterlevel < 1 ? false : true);
                    _MachineInfo.Waterlevel_high = (evost.sensorstate.waterlevel == 1 ? true : false);
                    //Console.WriteLine("hight = " + _MachineInfo.Waterlevel_high + "low" + _MachineInfo.Waterlevel_low);
                    if (evost.machinestate == MachineState.Mode_Clean_Finish)
                    {
                        //_UiData.is_clean_block_visible = false;
                        //send finish
                        M2BFinishClean finishclean = new M2BFinishClean();
                        byte[] sendcmd = finishclean.EnCode();
                        lock (this)
                        {
                            comunication.Getinstance().AddtoSend(sendcmd, (byte)sendcmd.Length);
                        }
                    }
                    break;
                case CmdType.B2M_CMD_TEST:
                    B2MTest test = new B2MTest(e.datain, 0);
                    Console.WriteLine("TEST ID ="+test.ID);
                    Console.WriteLine("TEST Type =" + test.operatetype);
                    Console.WriteLine("TEST Result =" + test.Result);
                    if (test.Result == 1)
                    {
                    }
                    else
                    {
                        MessageBox.Show("TEST Failed!");
                    }
                    break;
             /*   
              * case CmdType.M2B_CMD_CLEAN:
                    break;
                case CmdType.M2B_CMD_MAKE_BERVAGE:
                    break;
                case CmdType.M2B_CMD_MAKE_DRINK:
                    break;
                case CmdType.M2B_CMD_MAKE_INGREDIENT:
                    break;
                case CmdType.M2B_CMD_MATCH:
                    break;
                case CmdType.M2B_CMD_MODE_REQUEST:
                    break;
                case CmdType.M2B_CMD_QUERY:
                    break;
                case CmdType.M2B_CMD_TEST:
                    break;
              * 
              */
                default:
                    break;
            }
        }

        void Tmr_Tick(object sender, EventArgs e)
        {
            if (comunication.Getinstance().Isopen)
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
        }
        private void InitIDGenrator()
        {
            _IDControl = (IDGenrator)Function.XmlSerializer.LoadFromXml("EVO.ID.xml", typeof(IDGenrator));

            if (_IDControl ==null)
            {
                _IDControl = new IDGenrator();
                for (int i = 1; i < 101; i++)
                {
                    IDProperty tmp = new IDProperty();
                    tmp.ID = (UInt16)i;
                    tmp.IsUsed = false;
                    _IDControl.LstIngIDProperty.Add(tmp);
                    tmp = new IDProperty();
                    tmp.ID = (UInt16)i;
                    tmp.IsUsed = false;
                    _IDControl.LstRcpIDProperty.Add(tmp);
                }
                Function.XmlSerializer.SaveToXml("EVO.ID.xml", _IDControl, typeof(IDGenrator), null);
            }
        }
        private void GetLstDeviceUnit()
        {
            _LstDeviceUnit.Clear();
            DeviceUnit devtmp;
            if (_CrtEVOMachine!=null)
            {
                foreach (var item in _CrtEVOMachine._WaterValve)
                {
                    devtmp = new DeviceUnit();
                    devtmp._Type = DeviceType.DEV_VALVE;
                    devtmp.Name = item.Name;
                    devtmp.DeviceIoAdress = item.DeviceIoAdress;
                    devtmp.DeviceID = item.DeviceID;
                    
                    _LstDeviceUnit.Add(devtmp);
                }
                foreach (var item in _CrtEVOMachine._MixerUnit)
                {
                    devtmp = new DeviceUnit();
                    devtmp._Type = DeviceType.DEV_MIXER;
                    devtmp.Name = item.Name;
                    devtmp.DeviceIoAdress = item.DeviceIoAdress;
                    devtmp.DeviceID = item.DeviceID;
                    devtmp.Speed = item.Speed;
                    _LstDeviceUnit.Add(devtmp);
                }
                foreach (var item in _CrtEVOMachine._CanisterUnit)
                {
                    devtmp = new DeviceUnit();
                    devtmp._Type = DeviceType.DEV_CANISTER;
                    devtmp.Name = item.Name;
                    devtmp.DeviceIoAdress = item.DeviceIoAdress;
                    devtmp.DeviceID = item.DeviceID;

                    _LstDeviceUnit.Add(devtmp);
                }
                foreach (var item in _CrtEVOMachine._BeanHopperUint)
                {
                    devtmp = new DeviceUnit();
                    devtmp._Type = DeviceType.DEV_HOPPER;
                    devtmp.Name = item.Name;
                    devtmp.DeviceIoAdress = item.DeviceIoAdress;
                    devtmp.DeviceID = item.DeviceID;

                    _LstDeviceUnit.Add(devtmp);
                }

            }
        }
        private void InitFunction()
        {
            this.BtnCmd = new DelegateCommand();
            this.BtnCmd.ExecuteCommand = new Action<object>(this.DealWithBtnCmd);
            this.ComCmd = new DelegateCommand();
            this.ComCmd.ExecuteCommand = new Action<object>(this.DealWithComCmd);
            this.EditCMD = new DelegateCommand();
            this.EditCMD.ExecuteCommand = new Action<object>(this.DealWithEditCMD);
            this.DelCMD = new DelegateCommand();
            this.DelCMD.ExecuteCommand = new Action<object>(this.DealWithDelCMD);
            this.Del1CMD = new DelegateCommand();
            this.Del1CMD.ExecuteCommand = new Action<object>(this.DealWithDel1CMD);
            this.Del2CMD = new DelegateCommand();
            this.Del2CMD.ExecuteCommand = new Action<object>(this.DealWithDel2CMD);

            this.TestCMD = new DelegateCommand();
            this.TestCMD.ExecuteCommand = new Action<object>(this.DealWithTestCMD);
        }

        private void DealWithTestCMD(object obj)
        {
            // todo : 解析obj
            string[] Paramlst = obj.ToString().Split(':');
            byte DeviceId = byte.Parse(Paramlst[0]);
            byte flag = byte.Parse(Paramlst[1]);
#if DEBUG
            Console.WriteLine("DealWithTestCMD :" + obj.ToString());
#endif
            M2BTest tmp = new M2BTest(DeviceId, flag, 100);
            byte[] SendCmd = tmp.EnCode();
            comunication.Getinstance().AddtoSend(SendCmd, (byte)SendCmd.Length);
        }

        private void DealWithDel1CMD(object obj)
        {
            UInt16 id = UInt16.Parse(obj.ToString());
            MessageBox.Show("DealWithDel1CMD" + obj.ToString());
            _IDControl.CGID(id);
            _EvoRecipe._lstIngredientInfo.Remove(_EvoRecipe._lstIngredientInfo.First(c => c.ID == id));
            SaveIngredientData();
        }

        private void DealWithDel2CMD(object obj)
        {
            UInt16 id = UInt16.Parse(obj.ToString());
            MessageBox.Show("DealWithDel2CMD" + obj.ToString());
            _IDControl.CGID(id,1);
            _EvoRecipe._lstRecipeInfo.Remove(_EvoRecipe._lstRecipeInfo.First(c => c.ID == id));
            SaveIngredientData();
        }

        private void DealWithDelCMD(object obj)
        {
            UInt16 id = UInt16.Parse(obj.ToString());
            MessageBox.Show("DealWithDelCMD" + obj.ToString());
            _IDControl.CGID(id);
            _CrtRecipeInfo._lstIngredientStep.Remove(_CrtRecipeInfo._lstIngredientStep.First(c => c.ID == id));
            SaveIngredientData();

        }

        private void DealWithEditCMD(object obj)
        {
            UInt16 id = UInt16.Parse(obj.ToString());
            MessageBox.Show("DealWithEditCMD"+obj.ToString());
            object crtstep = _CrtRecipeInfo._lstIngredientStep.First(c => c.ID == id);
            if (crtstep!=null)
            {
                UInt16 stm = (crtstep as IngredientStep).StartTime;
                if ((crtstep as IngredientStep)._Type == (byte) IngredientType.FILTERBREW)
                {
                    Ingredient_FilterBrew win = new Ingredient_FilterBrew(id, stm, _EvoRecipe);
                    win.Show();
                    win.Closing += win_Closing;
                }
                if ((crtstep as IngredientStep)._Type == (byte)IngredientType.INSTANTPOWDER)
                {
                    Ingredient_Instant win = new Ingredient_Instant(id, stm, _EvoRecipe, _CrtEVOMachine._CanisterUnit);
                    win.Show();
                    win.Closing += win_Closing;
                }
            }
           
            
        }

        void win_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            UpdateRecipe();
        }


        public void TransferFile(object a)
        {
            Hashtable table;
            int totalpacketnum;

            EvoUpdate tmp = a as EvoUpdate;
            table = tmp.filetable;
            totalpacketnum = tmp.TotalAmount;
            comunication.Getinstance().IsTransfer = true;
            comunication.Getinstance().TotalCnt = (UInt16)totalpacketnum;
            comunication.Getinstance().CurrentCnt = 0;
            while (comunication.Getinstance().IsTransfer)
            {
                UInt16 crt = comunication.Getinstance().CurrentCnt;
                if (totalpacketnum<=crt)
                {
                    comunication.Getinstance().IsTransfer = false;
                    break;
                }
                _EvoUpdate.CrtAmount = crt+1;
                byte[] data = (byte[])table[(int)crt];
                M2BTransfer _M2BTransfer = new M2BTransfer(_EvoUpdate.FileType, (UInt16)totalpacketnum, (UInt16)_EvoUpdate.CrtAmount, data, data.Length);
                byte[] sendcmd = _M2BTransfer.EnCode();
               System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() => _EvoUpdate.Info = DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss ") + string.Format("begin transfer file  packet[{0}] ",crt)));
                comunication.Getinstance().AddtoSend(sendcmd, sendcmd.Length);
                comunication.Getinstance().eventWait.WaitOne();
                comunication.Getinstance().eventWait.Reset();
            }
        }
        private void DealWithComCmd(object obj)
        {
            int i = int.Parse(obj.ToString());
            CommandCmdDef.ComCmd crtcmd = (CommandCmdDef.ComCmd)i;
            M2BTest tmp;
            byte[] SendCmd;
            try
            {
                switch (crtcmd)
                {
                    
                    case CommandCmdDef.ComCmd.MAINTENCE_GET:
                        //DONE:GET ALL MAITENCE DATA
                        M2BMaintenance maintencecmd = new M2BMaintenance();
                        SendCmd = maintencecmd.EnCode();
                        comunication.Getinstance().AddtoSend(SendCmd, (byte)SendCmd.Length);
                        break;
                    case CommandCmdDef.ComCmd.DB_SET:
                       //TODO:设置数据库
                        M2BDbSetting dbset = new M2BDbSetting();
                        dbset._DBGroup.Add(new DBStruct() { DBID = (byte)_crtDBItem.DBID, DBValue = (UInt32)_crtDBItem.DBvalue });
                        SendCmd = dbset.EnCode();
                        comunication.Getinstance().AddtoSend(SendCmd, (byte)SendCmd.Length);
                        break;
                    case CommandCmdDef.ComCmd.UPDATE_FIRM:
                    case CommandCmdDef.ComCmd.UPDATE_RCP:
                        /*
                         * first get filename to be update
                         * second calc the file size ,do packge the com cmd 128 max/per packge
                         * set the pbvalue & set the info msg
                         * send the first packge wait until error or transfer finish.
                         */
                        FileStream fs=null;
                        BinaryReader bw=null;
                        _EvoUpdate.Info = DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss ") + "ready to transfer file " + _EvoUpdate.RcpFileName;
                        _EvoUpdate.Clearfiletable();
                        _EvoUpdate.FileType = (crtcmd == CommandCmdDef.ComCmd.UPDATE_RCP) ? M2BTransfer.TYPE_FILE : M2BTransfer.TYPE_Program; 
                        try
                        {
                            fs = new FileStream((crtcmd == CommandCmdDef.ComCmd.UPDATE_RCP ? _EvoUpdate.RcpFileName : _EvoUpdate.FirmFileName), FileMode.Open);
                            bw = new BinaryReader(fs);

                            int packagenum = 0;
                            bool isLastPkg = false;
                            if (fs.Length >= 1024)
                            {
                                packagenum = (int)(fs.Length / 1024);
                            }
                            if (fs.Length % 1024 != 0)
                            {
                                isLastPkg = true;
                            }
                            if (isLastPkg)
                            {
                                _EvoUpdate.TotalAmount = packagenum + 1;
                            }
                            else
                            {
                                _EvoUpdate.TotalAmount = packagenum;

                            }
                            for (int cnt = 0; cnt < packagenum; cnt++)
                            {
                                byte[] inbuf = bw.ReadBytes(1024);
                                _EvoUpdate.AddtoHashMap(cnt, inbuf);
                            }
                            if (isLastPkg)
                            {
                                byte[] lastbuf = bw.ReadBytes((int)fs.Length - 1024 * packagenum);
                                _EvoUpdate.AddtoHashMap(packagenum, lastbuf);
                            }
                            _EvoUpdate.Info = DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss ") + "Current file Total package : " + _EvoUpdate.TotalAmount.ToString();
                            ThreadPool.QueueUserWorkItem(new WaitCallback(TransferFile), _EvoUpdate);
                        }
                        catch (Exception)
                        {
                            throw;
                        }
                        finally
                        {
                            if (bw!=null)
                            {
                                bw.Close();
                            }
                            if (fs!=null)
                            {
                                fs.Close();
                            }
                        }

                        break;
                    
                    case CommandCmdDef.ComCmd.MAKE_INGERDIENT_DELETE:
                    case CommandCmdDef.ComCmd.MAKE_INGERDIENT_MODIFY:
                    case CommandCmdDef.ComCmd.MAKE_INGERDIENT_ADD:
                    case CommandCmdDef.ComCmd.MAKE_INGERDIENT_REVIEW:
                    case CommandCmdDef.ComCmd.MAKE_INGERDIENT_BACKUP:
                        if (!_MachineSetingInfo.Connectst.Equals("Connected"))
                        {
                            MessageBox.Show("connect the machine first!!"); break;
                        }
                        GetAllMachineParam();
                        M2BMakeIngredient m2bMakeIngredient = new M2BMakeIngredient((byte)_CrtIngredient.Type);
                        m2bMakeIngredient.ID = _CrtIngredient.ID;
                        m2bMakeIngredient.operatetype = (byte)(crtcmd - 0x70);
                        switch (_CrtIngredient.Type)
                        {
                            case IngredientType.ESPRESSO:
                                break;
                            case IngredientType.FILTERBREW:
                                M2BMakeIngredient.FilterBrewPhaseStep steptmp = new M2BMakeIngredient.FilterBrewPhaseStep();
                                /*
                                 * Filter brewer process	Phase 1	Phase 2	Phase 3	Phase 4	Phase 5	Phase 6	Phase 7	Phase 8	Phase 9
                                                            Brew motor	X sec	wait Xs	X sec	wait Xs	X sec	wait Xs	X sec	wait Xs	Run to switch
                                                            Brew motor speed	20-100%	0%	20-100%	0%	20-100%	0%	20-100%	0%	100%
                                                            Water valve	X ml																														
                                                            Grinder	X sec																															
                                 * Run brew motor for X seconds with X PWM (speed), start water valve and dispense X ml. start grinder and run X seconds.
                                 * When to start water+grinder could be selected between ex. “Time” – you set start/stop time manually, “Start of phase” – grinder+water will start when brewer reach a start of a phase, “End of phase” – grinder+water will start when brewer reach a end of a phase.
                                 */
                                steptmp.grinder1Type = (UInt16)_CrtIngredient._FilterBrew.Grind1Type;
                                steptmp.grinder2Type = (UInt16)_CrtIngredient._FilterBrew.Grind2Type;
                                steptmp.grinder1powder =(UInt16)( ((_CrtIngredient._FilterBrew.Grind1Cnt / 10) << 8) + (_CrtIngredient._FilterBrew.Grind1Cnt % 10));
                                steptmp.grinder2powder = (UInt16)(((_CrtIngredient._FilterBrew.Grind2Cnt / 10) << 8) + (_CrtIngredient._FilterBrew.Grind2Cnt % 10));
                                steptmp.motorWaitTime = 0;
                                steptmp.WaterFlowTime = (UInt16)(_CrtIngredient._FilterBrew.WaterVolume * 1000 / MachineParam.BrewFlowRate);
                                m2bMakeIngredient._ProcessFilterBrew.FilterBrewPhaseGroup.Add(steptmp);
                                /*Pause brew motor for X Seconds (this phase is now called “Pre Brew”)
                                 */
                                steptmp = new M2BMakeIngredient.FilterBrewPhaseStep();
                                steptmp.grinder1powder =0;
                                steptmp.grinder2powder =0;
                                steptmp.motorWaitTime = _CrtIngredient._FilterBrew.Tm_Pre;
                                steptmp.WaterFlowTime = 0;
                                m2bMakeIngredient._ProcessFilterBrew.FilterBrewPhaseGroup.Add(steptmp);
                                steptmp = new M2BMakeIngredient.FilterBrewPhaseStep();
                                /*Pause brew motor for X Seconds (this phase is now called “Extraction time”)
                                 */
                                steptmp = new M2BMakeIngredient.FilterBrewPhaseStep();
                                steptmp.grinder1Type = 0;
                                steptmp.grinder2Type =0;
                                steptmp.grinder1powder = 0;
                                steptmp.grinder2powder = 0;
                                steptmp.motorWaitTime = _CrtIngredient._FilterBrew.Tm_Press;
                                steptmp.WaterFlowTime = 0;
                                m2bMakeIngredient._ProcessFilterBrew.FilterBrewPhaseGroup.Add(steptmp);
                                steptmp = new M2BMakeIngredient.FilterBrewPhaseStep();
                                /*Pause brew motor for X Seconds (this phase is now called “Decompress time”)
                                 */
                                steptmp = new M2BMakeIngredient.FilterBrewPhaseStep();
                                steptmp.grinder1Type = 0;
                                steptmp.grinder2Type =0;
                                steptmp.grinder1powder = 0;
                                steptmp.grinder2powder = 0;
                                steptmp.motorWaitTime = _CrtIngredient._FilterBrew.Tm_Depress;
                                steptmp.WaterFlowTime = 0;
                                m2bMakeIngredient._ProcessFilterBrew.FilterBrewPhaseGroup.Add(steptmp);
                                steptmp = new M2BMakeIngredient.FilterBrewPhaseStep();
                                /*Pause brew motor for X Seconds (this phase is now called “Empty time”) coffee comes out in cup
                                 */
                                steptmp = new M2BMakeIngredient.FilterBrewPhaseStep();
                                steptmp.grinder1Type = 0;
                                steptmp.grinder2Type =0;
                                steptmp.grinder1powder = 0;
                                steptmp.grinder2powder = 0;
                                steptmp.motorWaitTime = _CrtIngredient._FilterBrew.Tm_DelayOpen;
                                steptmp.WaterFlowTime = 0;
                                m2bMakeIngredient._ProcessFilterBrew.FilterBrewPhaseGroup.Add(steptmp);
                                steptmp = new M2BMakeIngredient.FilterBrewPhaseStep();
                                m2bMakeIngredient._ProcessFilterBrew.PhaseCount = 5;
                                m2bMakeIngredient._ProcessFilterBrew.postionDown = _CrtIngredient._FilterBrew.ActionDownPostion;
                                m2bMakeIngredient._ProcessFilterBrew.postionUp = _CrtIngredient._FilterBrew.ActionUpPostion;

                                break; 
                            case IngredientType.FRESHMILK:
                                /*
                                 * Hot milk process	Phase 1	Phase 2	Phase 3	Phase 4		
                                    Clean water valve	1,5s																			4s								
                                    Milk pump	6,5s	10s	X ml	14s		
                                    Milk pump speed	75%	75%	75%	75%		
                                    Milk heaters	Allow	Allow	Allow	Allow		
                                    Valve to driptray	6,5s	5s																				3s		
                                    Valve to cup											1,5s	X ml	11s				
                                    Milk valve (fridge)						10s	X ml												
                                    Milk Whipper											1,5s	X ml	12s			
                                    Whipper speed											20-100%	20-100%	20-100%			
                                    Mixer bowl flush valve																																1,5s
                                Action steps	
Action 1 – Phase 1 (Initial cleaning)	Start the clean water valve from hot water tank, milk pump at 75% PWM, and no current (OFF) to the 3/2 valve to make it towards milk waste. Heaters are allowed to work towards Prio temp. Heaters shall have option to be turned OFF during the process to be able to make cold milk as well.
Action 2 – Phase 2 (pre fill up)	Once phase 1 is finished we activate the 3/2 valve in the fridge to start pumping milk into the system. For 5 seconds we still have the other 3/2 valve towards milk waste since there is some water left in the tubing, it also takes around 5 seconds to fill all tubes and heaters with milk. After 5 seconds we then swap 3/2 valve (turn it ON) towards the mixer bowl, at the same time we start the whipper.
Action 3 – Phase 3 (dispense milk)	Now we just continue run the pump at 75% and the 3/2 valves are active to pump milk and direct it towards mixer bowl. To determine how long these components shall run the milk use a fixed flow, 18ml/s. if you want ex. 150ml milk it means that components will run for 8,3 seconds in this step.
Action 4 – Phase 4 (After cleaning)	Now we start the water valve from the tank again and close the valve in fridge for milk. We still dispense towards the mixer bowl since we want as much remaining milk/water in the system to go into the cup. The last 3 seconds we turn off the 3/2 valve towards the mixer so the last part goes into the milk waste instead. When all internal flushing is done we activate the water valve in tank for chocolate (mixer flush valve) for 1.5s to rinse the mixer bowl properly in the end.
** Valve to milk waste/mixer is same 3/2 valve. If no current and valve is off = towards drip tray, if you activate valve with current = towards cup.
Heaters have two temperature settings, “Idle temp” and “Prio temp”. When machine is standing still and no one using machine the heaters will keep the Idle temperature setting. Ex 60°C. When you start a milk drink the heaters are allowed to heat up and use the Prio temperature during the process. Ex. 75°C. When drink is finished the heaters go back and use the Idle setting again. 
                                 * 
                                 */
                                m2bMakeIngredient._ProcessFreshMilk.dispenseMilkTime = (UInt16)(_CrtIngredient._FreshMilk.MilkVolume * 1000 / MachineParam.Mixer1FlowRate);
                                m2bMakeIngredient._ProcessFreshMilk.preFlushTime = (UInt16)(_CrtIngredient._FreshMilk.Preflush * 1000 / MachineParam.Mixer1FlowRate);
                                m2bMakeIngredient._ProcessFreshMilk.aftFlushTime = (UInt16)(_CrtIngredient._FreshMilk.AfterFlush * 1000 / MachineParam.Mixer1FlowRate);
                                m2bMakeIngredient._ProcessFreshMilk.heaterAction = _CrtIngredient._FreshMilk.HeaterFlag;
                                m2bMakeIngredient._ProcessFreshMilk.whipperSpeed = (byte)_CrtIngredient._FreshMilk.WhipperSpeed;
                                break;
                            case IngredientType.INSTANTPOWDER:
                                /*
                                 *  Action step	
                                    Action 1 – Pre flush	First we must dispense a little water so we have water in the mixer bowl before we start canister and whipper. Normally 15ml or 1 sec
                                    Action 2 – Pause	Here we have a pause so the water have time to fall down from tank through the tubes and into the mixer bowl.
                                    Action 3 – Dispense	We can now start all components such as water valve, canister and whipper at X PWM. When the setting that have longest time is finished it goes to next step.
                                    Action 4 – Pause	Another pause to make all water/drink empty the mixer bowl. 
                                    Action 5 – After flush	Run water again to flush out all remains, normally 15ml or 1 sek.
                                 * 
                                 */
                                m2bMakeIngredient._ProcessInstantPowder.canisterCnt = 2;
                                UInt32 canisterpowder = (UInt32)((_CrtIngredient._InstantPowder.PackageOneType << 16 )+ (((_CrtIngredient._InstantPowder.PackageOneAmt / 10) << 8) + (_CrtIngredient._InstantPowder.PackageOneAmt % 10)));
                                m2bMakeIngredient._ProcessInstantPowder.canisterPowderGroup.Add(canisterpowder);
                                canisterpowder = (UInt32)((_CrtIngredient._InstantPowder.PackageTwoType << 16 )+ (((_CrtIngredient._InstantPowder.PackageTwoAmt / 10) << 8) + (_CrtIngredient._InstantPowder.PackageTwoAmt % 10)));
                                m2bMakeIngredient._ProcessInstantPowder.canisterPowderGroup.Add(canisterpowder);
                                m2bMakeIngredient._ProcessInstantPowder.MixIndex = (byte)_CrtIngredient._InstantPowder.MixIndex;
                                m2bMakeIngredient._ProcessInstantPowder.waterDispenseTime = (UInt16)(_CrtIngredient._InstantPowder.WaterVolume * 1000 / MachineParam.Mixer1FlowRate);
                                m2bMakeIngredient._ProcessInstantPowder.preFlushTime = (UInt16)(_CrtIngredient._InstantPowder.PreFlush * 1000 / MachineParam.Mixer1FlowRate);
                                m2bMakeIngredient._ProcessInstantPowder.aftFlushTime = (UInt16)(_CrtIngredient._InstantPowder.AfterFlush * 1000 / MachineParam.Mixer1FlowRate);
                                m2bMakeIngredient._ProcessInstantPowder.pauseTime = _CrtIngredient._InstantPowder.PreFlushTm;
                                m2bMakeIngredient._ProcessInstantPowder.pauseTime1 = _CrtIngredient._InstantPowder.PostFlushTm;
                                m2bMakeIngredient._ProcessInstantPowder.whipperSpeed = (byte)_CrtIngredient._InstantPowder.WhipperSpeed;
                                m2bMakeIngredient._ProcessInstantPowder.waterType = _CrtIngredient._InstantPowder.WaterType;
                                break;
                            case IngredientType.Water:
                                m2bMakeIngredient._ProcessWater.WaterType = _CrtIngredient._Water.WaterType;
                                m2bMakeIngredient._ProcessWater.DispenseTm = (UInt16)(_CrtIngredient._Water.WaterVolume * 1000 / MachineParam.HotwaterFlowRate);
                                break;
                            case IngredientType.NoSelect:
                                break;
                            default:
                                break;
                        }
                        SendCmd = m2bMakeIngredient.EnCode();
                        comunication.Getinstance().AddtoSend(SendCmd, (byte)SendCmd.Length);
                         break;
                    case CommandCmdDef.ComCmd.MAKE_BAVERAGE_ADD:
                    case CommandCmdDef.ComCmd.MAKE_BAVERAGE_DELETE:
                    case CommandCmdDef.ComCmd.MAKE_BAVERAGE_BACKUP:
                    case CommandCmdDef.ComCmd.MAKE_BAVERAGE_MODIFY:
                    case CommandCmdDef.ComCmd.MAKE_BAVERAGE_REVIEW:
                        if (!_MachineSetingInfo.Connectst.Equals("Connected"))
                        {
                            MessageBox.Show("connect the machine first!!"); break;
                        }
                        M2BMakeBeverage cmdtmp = new M2BMakeBeverage(_CrtRecipeInfo._publicInfo);
                        cmdtmp.ID = _CrtRecipeInfo.ID;
                        cmdtmp.operatetype =(byte) (crtcmd - 0x80);
                        foreach (var item in _CrtRecipeInfo._lstIngredientStep)
                        {
                            M2BMakeBeverage.IngredientStep steptmp = new M2BMakeBeverage.IngredientStep();
                            steptmp.ID = item.ID;
                            steptmp._Type = item._Type;
                            steptmp.startTime = item.StartTime;
                            steptmp.percent = item.ScaleRate;
                            cmdtmp.igredientStepGroup.Add(steptmp);
                        }
                        cmdtmp.ingredientCnt = (byte)_CrtRecipeInfo._lstIngredientStep.Count;
                        SendCmd = cmdtmp.EnCode();
                        comunication.Getinstance().AddtoSend(SendCmd, (byte)SendCmd.Length);
                        break;
                    case CommandCmdDef.ComCmd.TEST_START:
                        tmp = new M2BTest((byte)_CrtDeviceUnit.DeviceID, M2BTest.Turn_on_always, _CrtDeviceUnit.Speed);
                        SendCmd = tmp.EnCode();
                        comunication.Getinstance().AddtoSend(SendCmd, (byte)SendCmd.Length);
                        break;
                    case CommandCmdDef.ComCmd.TEST_STOP:
                        tmp = new M2BTest((byte)_CrtDeviceUnit.DeviceID, M2BTest.Turn_off);
                        SendCmd = tmp.EnCode();
                        comunication.Getinstance().AddtoSend(SendCmd, (byte)SendCmd.Length);
                        break;
                    case CommandCmdDef.ComCmd.UI_COM_SET:
                        _TestSet = new EVOTestForm();
                        _TestSet.Show();
                        _TestSet.Closed += _TestSet_Closed;
                        break;
                    default:
                        break;
                }
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
            }
            
        }

        private void GetAllMachineParam()
        {
            //TODO:获取所有设备的硬件参数
            /*
            object obj = (_CrtEVOMachine._WaterValve.First(c=>c.DeviceID== (byte)MachineParam.IDTYPE.brehotwatervalve));
            MachineParam.BrewFlowRate = (obj == null ? 20 : (obj as WaterValve).Flow);
            obj = (_CrtEVOMachine._WaterValve.First(c => c.DeviceID == (byte)MachineParam.IDTYPE.MIXER1watervalve));
            MachineParam.Mixer1FlowRate = (obj == null ? 20 : (obj as WaterValve).Flow);
            obj = (_CrtEVOMachine._WaterValve.First(c => c.DeviceID == (byte)MachineParam.IDTYPE.MIXER2watervalve));
            MachineParam.Mixer2FlowRate = (obj == null ? 20 : (obj as WaterValve).Flow);
            */
        }

        void _TestSet_Closed(object sender, EventArgs e)
        {
           _ComSetting = (ComSetting)Function.XmlSerializer.LoadFromXml("EVO.com.xml", typeof(ComSetting));
           comunication.Getinstance().SetComPort(_ComSetting.Port, _ComSetting.BaudRate);
           int ret= comunication.Getinstance().Open();
           Console.WriteLine("Open Com == "+ret);          
        }

        private void InitUiData()
        {
            _UiData.is_machineset_visible = false;
            _UiData.is_mainselect_visible = true;
        }
        
        private void DealWithBtnCmd(object obj)
        {
            M2BDbSetting aa;
            DBStruct aac;
            byte[] sendcmd;
            int i = int.Parse(obj.ToString());
            CommandCmdDef.BtnCmd crtcmd = (CommandCmdDef.BtnCmd)i;
#if DEBUG
            Console.WriteLine(crtcmd.ToString());
#endif
            if (Tmr.IsEnabled)
            {
                Tmr.Interval = TimeSpan.FromMilliseconds(2000);
            }
            switch (crtcmd)
            {
                /*
                one-key to update recipe
                */
                case CommandCmdDef.BtnCmd.UI_TEST_CALIBRATION:
                    _UiData.SetUiVisible(CommandCmdDef.UiIndex.UI_TEST_CALIBRATION);
                    break;
                case CommandCmdDef.BtnCmd.UI_TEST_OVERVIW:
                    _UiData.SetUiVisible(CommandCmdDef.UiIndex.UI_TEST_OVERVIW);
                    //start ststus quary
                    if (Tmr.IsEnabled)
                    {
                        Tmr.Interval = TimeSpan.FromMilliseconds(500);
                    }
                    break;
                case CommandCmdDef.BtnCmd.UI_ING_DETAIL:
                    _UiData.SetUiVisible(CommandCmdDef.UiIndex.UI_ING_DETAIL);
                    break;
                case CommandCmdDef.BtnCmd.UI_RCP_DETAIL:
                    _UiData.SetUiVisible(CommandCmdDef.UiIndex.UI_RCP_DETAIL);
                    break;
                case CommandCmdDef.BtnCmd.UI_RCP_LIST:
                    _UiData.SetUiVisible(CommandCmdDef.UiIndex.UI_RCP_LIST);
                    break;
                case CommandCmdDef.BtnCmd.UI_ING_LIST:
                    _UiData.SetUiVisible(CommandCmdDef.UiIndex.UI_ING_LIST);
                    break;
                case CommandCmdDef.BtnCmd.UP_ING:
                    if (!_MachineSetingInfo.Connectst.Equals("Connected"))
                    {
                        MessageBox.Show("connect the machine first!!");break;
                    }
                    _UiData.SetUiVisible(CommandCmdDef.UiIndex.UI_UPDATE);
                     GetAllMachineParam();
                    _EvoUpdate.TotalAmount = _EvoRecipe._lstIngredientInfo.Count();
                    _EvoUpdate.CrtAmount = 0;
                    _EvoUpdate.Info = "Ready for updating....";
                    comunication.Getinstance().IsTransfer = true;
                    _EvoUpdate.updateindex = 0;
                    _EvoUpdate.updatetype = 0;
                    _EvoUpdate.UpdateInfo.Clear();
                    Update_ING_Method();
                    break;
                case CommandCmdDef.BtnCmd.UP_RCP:
                    if (!_MachineSetingInfo.Connectst.Equals("Connected"))
                    {
                        MessageBox.Show("connect the machine first!!"); break;
                    }
                    _UiData.SetUiVisible(CommandCmdDef.UiIndex.UI_UPDATE);

                    GetAllMachineParam();
                    _EvoUpdate.TotalAmount = _EvoRecipe._lstRecipeInfo.Count();
                    _EvoUpdate.CrtAmount = 0;
                    _EvoUpdate.Info = "ready for updating...";
                    comunication.Getinstance().IsTransfer = true;
                    _EvoUpdate.updateindex = 0;
                    _EvoUpdate.updatetype = 0;
                    _EvoUpdate.UpdateInfo.Clear();
                    Update_Rcp_Method();
                    break;
                case CommandCmdDef.BtnCmd.UI_UPDATE:
                    //if (!_MachineSetingInfo.Connectst.Equals("Connected"))
                    //{
                    //    MessageBox.Show("connect the machine first!!"); break;
                    //}
                    _UiData.SetUiVisible(CommandCmdDef.UiIndex.UI_UPDATE);
                    break;
                case CommandCmdDef.BtnCmd.UI_STCHECK:
                    EvoStCheck _EvoStCheck = new EvoStCheck(_MachineInfo);
                    _EvoStCheck.Unloaded += _EvoStCheck_Unloaded;
                    _EvoStCheck.Show();
                    if (!Tmr.IsEnabled)
                    {
                     Tmr.Start();   
                    }
                    
                    break;
                case CommandCmdDef.BtnCmd.UI_DB:
                    _EVOBaseConf = (EVOBaseConf)Function.XmlSerializer.LoadFromXml("EVO.base.xml", typeof(EVOBaseConf));
                    if (_EVOBaseConf == null)
                    {
                        _EVOBaseConf = new EVOBaseConf();
                    }
                    if (!_MachineSetingInfo.Connectst.Equals("Connected"))
                    {
                        MessageBox.Show("connect the machine first!!"); break;
                    }
                    _UiData.SetUiVisible(CommandCmdDef.UiIndex.UI_DB);
                    //todo：send db get cmd 
                    M2BDbGeting testobj = new M2BDbGeting();
                    byte[] SendCmd = testobj.GetMachineSettingCmd();
                    lock (this)
                    {
                        comunication.Getinstance().AddtoSend(SendCmd, (byte)SendCmd.Length);
                    }
                    break;
                case CommandCmdDef.BtnCmd.DB_GET:
                    DBItem dbtmp = _EVOBaseConf.Search(_crtDBItem.DBID);
                    if (dbtmp!=null)
                    {
                        _crtDBItem.DBvalue = dbtmp.DBvalue;
                        _crtDBItem.Description = dbtmp.Description;
                    }
                    break;
                case CommandCmdDef.BtnCmd.DB_SET:
                    _EVOBaseConf.Set(_crtDBItem);
                    Function.XmlSerializer.SaveToXml("EVO.base.xml", _EVOBaseConf, typeof(EVOBaseConf), null);
                    break;
                case CommandCmdDef.BtnCmd.ASSIT_FUN:
                    EVOToolWin  _EVOToolWin= new EVOToolWin();
                    _EVOToolWin.Show();
                    break;
                case CommandCmdDef.BtnCmd.UI_RECIPESYS:
                    if (_CrtEVOMachine.Name!=null)
                    {
                        _UiData.SetUiVisible(CommandCmdDef.UiIndex.UI_RECIPESYS);
                    }
                    else { MessageBox.Show("Please Select the machine type First!");break; }
                    break;
                case CommandCmdDef.BtnCmd.UI_MachineTest:
                    if (!_MachineSetingInfo.Connectst.Equals("Connected"))
                    {
                        MessageBox.Show("connect the machine first!!"); break;
                    }
                    _UiData.SetUiVisible(CommandCmdDef.UiIndex.UI_MachineTest);
                    GetLstDeviceUnit();
                    break;
                case CommandCmdDef.BtnCmd.MAIN_SAVE:
                    Function.XmlSerializer.SaveToXml("EVO.conf.xml", _CrtEVOMachine, typeof(EVOMachine), null);
                    MessageBox.Show("Save OK!");
                    //InitDataModel();
                    break;
                case CommandCmdDef.BtnCmd.MAIN_BACK:
                    _UiData.SetUiVisible(CommandCmdDef.UiIndex.UI_MainSelect);
                    break;
                case CommandCmdDef.BtnCmd.VALVE_ADD:
                    _CrtEVOMachine._WaterValve.Add(WaterValve.New());
                    break;
                case CommandCmdDef.BtnCmd.VALVE_DEL:
                    foreach (var item in _CrtEVOMachine._WaterValve)
                    {
                        if (item.IsSelected)
                        {

                            _CrtEVOMachine._WaterValve.Remove(item);
                            break;
                        }
                    }
                    BtnCmd.ExecuteCommand(1);
                    BtnCmd.ExecuteCommand(530);
                    break;
                case CommandCmdDef.BtnCmd.VALVE_SAVE:
                    foreach (var item in _CrtEVOMachine._WaterValve)
                    {
                        if (item.IsSelected)
                        {
                            item.Name = _CrtWaterValve.Name;
                            item.DeviceIoAdress = _CrtWaterValve.DeviceIoAdress;
                            item.Flow = _CrtWaterValve.Flow;
                            item.DeviceID = _CrtWaterValve.DeviceID;
                            break;
                        }
                    }
                    break;
                case CommandCmdDef.BtnCmd.MIXSER_ADD:
                    _CrtEVOMachine._MixerUnit.Add(_CrtMixerUnit.copy());
                    break;
                case CommandCmdDef.BtnCmd.MIXSER_DEL:
                    foreach (var item in _CrtEVOMachine._MixerUnit)
                    {
                        if (item.IsSelected)
                        {

                            _CrtEVOMachine._MixerUnit.Remove(item);
                            break;
                        }
                    }
                    break;
                case CommandCmdDef.BtnCmd.MIXSER_SAVE:
                    foreach (var item in _CrtEVOMachine._MixerUnit)
                    {
                        if (item.IsSelected)
                        {
                            item.Name = _CrtMixerUnit.Name;
                            item.DeviceIoAdress = _CrtMixerUnit.DeviceIoAdress;
                            item.DeviceID = _CrtMixerUnit.DeviceID;
                            item.Speed = _CrtMixerUnit.Speed;
                            break;
                        }
                    }
                    break;
                case CommandCmdDef.BtnCmd.CANISTER_ADD:
                    _CrtEVOMachine._CanisterUnit.Add(CanisterUnit.New());
                    break;
                case CommandCmdDef.BtnCmd.CANISTER_DEL:
                    foreach (var item in _CrtEVOMachine._CanisterUnit)
                    {
                        if (item.IsSelected)
                        {

                            _CrtEVOMachine._CanisterUnit.Remove(item);
                            break;
                        }
                    }
                    BtnCmd.ExecuteCommand(1);
                    BtnCmd.ExecuteCommand(531);
                    break;
                case CommandCmdDef.BtnCmd.CANISTER_SAVE:
                    foreach (var item in _CrtEVOMachine._CanisterUnit)
                    {
                        if (item.IsSelected)
                        {
                            item.Name = _CrtCanisterUnit.Name;
                            item.DeviceIoAdress = _CrtCanisterUnit.DeviceIoAdress;
                            item.Flow = _CrtCanisterUnit.Flow;
                            item.DeviceID = _CrtCanisterUnit.DeviceID;
                            item.Postion = _CrtCanisterUnit.Postion;
                            item.Powdertype = _CrtCanisterUnit.Powdertype;
                            break;
                        }
                    }
                    BtnCmd.ExecuteCommand(1);
                    break;

                case CommandCmdDef.BtnCmd.BEANHOPPER_ADD:
                    _CrtEVOMachine._BeanHopperUint.Add(_CrtBeanHopperUint);
                    break;
                case CommandCmdDef.BtnCmd.BEANHOPPER_DEL:
                    foreach (var item in _CrtEVOMachine._BeanHopperUint)
                    {
                        if (item.IsSelected)
                        {

                            _CrtEVOMachine._BeanHopperUint.Remove(item);
                            break;
                        }
                    }
                    break;
                case CommandCmdDef.BtnCmd.BEANHOPPER_SAVE:
                    foreach (var item in _CrtEVOMachine._BeanHopperUint)
                    {
                        if (item.IsSelected)
                        {
                            item.Name = _CrtBeanHopperUint.Name;
                            item.DeviceIoAdress = _CrtBeanHopperUint.DeviceIoAdress;
                            item.Flow = _CrtBeanHopperUint.Flow;
                            item.DeviceID = _CrtBeanHopperUint.DeviceID;
                            item.Powdertype=_CrtBeanHopperUint.Powdertype;
                            break;
                        }
                    }
                    break;
                case CommandCmdDef.BtnCmd.INGRED_SAVE:
                    foreach (var item in _EvoRecipe._lstIngredientInfo)
                    {
                        if (item.IsSelected)
                        {
                            item.Name = _CrtIngredient.Name;
                            item.ID = _CrtIngredient.ID;
                            item.Type = _CrtIngredient.Type;
                            item.CrtModifyStatus = CommandCmdDef.ModifyType.MODIFY;
                            UInt16 ustm =0;
                            switch (item.Type)
                            {
                                case IngredientType.ESPRESSO:
                                    item._Espresso.WaterVolume = _CrtIngredient._Espresso.WaterVolume;
                                    item._Espresso.Grind1Cnt =   _CrtIngredient._Espresso.Grind1Cnt;
                                    item._Espresso.Grind2Cnt =   _CrtIngredient._Espresso.Grind2Cnt;
                                    item._Espresso.Tm_Infusio =  _CrtIngredient._Espresso.Tm_Infusio;
                                    item._Espresso.Tm_Pause =    _CrtIngredient._Espresso.Tm_Pause;
                                    item._Espresso.Tm_Press =    _CrtIngredient._Espresso.Tm_Press;
                                    item._Espresso.Tm_DelayOpen =_CrtIngredient._Espresso.Tm_DelayOpen;
                                    ustm = _CrtIngredient._Espresso.UsedTime;
                                    break;
                                case IngredientType.FILTERBREW:
                                    item._FilterBrew.WaterVolume  = _CrtIngredient._FilterBrew.WaterVolume;
                                    item._FilterBrew.Grind1Type = _CrtIngredient._FilterBrew.Grind1Type;
                                    item._FilterBrew.Grind2Type = _CrtIngredient._FilterBrew.Grind2Type;
                                    item._FilterBrew.Grind1Cnt    = _CrtIngredient._FilterBrew.Grind1Cnt;
                                    item._FilterBrew.Grind2Cnt    = _CrtIngredient._FilterBrew.Grind2Cnt;
                                    item._FilterBrew.Tm_DelayOpen = _CrtIngredient._FilterBrew.Tm_DelayOpen;
                                    item._FilterBrew.Tm_Depress   = _CrtIngredient._FilterBrew.Tm_Depress;
                                    item._FilterBrew.Tm_Pre       = _CrtIngredient._FilterBrew.Tm_Pre;
                                    item._FilterBrew.Tm_Press     = _CrtIngredient._FilterBrew.Tm_Press;
                                    item._FilterBrew.ActionDownPostion = _CrtIngredient._FilterBrew.ActionDownPostion;
                                    item._FilterBrew.ActionUpPostion = _CrtIngredient._FilterBrew.ActionUpPostion;
                                    ustm = _CrtIngredient._FilterBrew.UsedTime;

                                    break;
                                case IngredientType.FRESHMILK:
                                    item._FreshMilk.HeaterFlag      = _CrtIngredient._FreshMilk.HeaterFlag;
                                    item._FreshMilk.MilkVolume      = _CrtIngredient._FreshMilk.MilkVolume;
                                    item._FreshMilk.Preflush = _CrtIngredient._FreshMilk.Preflush;
                                    item._FreshMilk.WhipperSpeed    = _CrtIngredient._FreshMilk.WhipperSpeed;
                                    item._FreshMilk.AfterFlush      = _CrtIngredient._FreshMilk.AfterFlush;
                                    ustm = _CrtIngredient._FreshMilk.UsedTime;
                                    break;
                                case IngredientType.INSTANTPOWDER:
                                    item._InstantPowder.MixIndex        = _CrtIngredient._InstantPowder.MixIndex;     
                                    item._InstantPowder.WhipperSpeed    = _CrtIngredient._InstantPowder.WhipperSpeed; 
                                    item._InstantPowder.WaterVolume     = _CrtIngredient._InstantPowder.WaterVolume;  
                                    item._InstantPowder.PackageOneType    = _CrtIngredient._InstantPowder.PackageOneType ;
                                    item._InstantPowder.PackageOneAmt    = _CrtIngredient._InstantPowder.PackageOneAmt; 
                                    item._InstantPowder.PackageTwoType    = _CrtIngredient._InstantPowder.PackageTwoType;
                                    item._InstantPowder.PackageTwoAmt    = _CrtIngredient._InstantPowder.PackageTwoAmt; 
                                    item._InstantPowder.PreFlush        = _CrtIngredient._InstantPowder.PreFlush;
                                    item._InstantPowder.AfterFlush      = _CrtIngredient._InstantPowder.AfterFlush;
                                    item._InstantPowder.PostFlushTm = _CrtIngredient._InstantPowder.PostFlushTm;
                                    item._InstantPowder.PreFlushTm = _CrtIngredient._InstantPowder.PreFlushTm;


                                    ustm = _CrtIngredient._InstantPowder.UsedTime;
                                    item._InstantPowder.WaterType = _CrtIngredient._InstantPowder.WaterType;
 
                                    break;
                                case IngredientType.Water:
                                    item._Water.WaterType = _CrtIngredient._Water.WaterType;
                                    item._Water.WaterVolume = _CrtIngredient._Water.WaterVolume;
                                    ustm = _CrtIngredient._Water.UsedTime;
                                    break;
                                default:
                                    break;
                            }
                            foreach (var item1 in _EvoRecipe._lstRecipeInfo)
                            {
                                foreach (var itemret in item1._lstIngredientStep)
                                {
                                    if (itemret.ID == item.ID)
                                    {
                                        itemret.UsedTime = ustm;
                                    }
                                }
                            }
                            break;
                            /*更新菜单的used时间 
                             */ 
                        }
                    }
                    SaveIngredientData();
                    break;
                case CommandCmdDef.BtnCmd.INGRED_ADD:
                    /*
                     * 提示配方选择
                     * 选择配方，OK，新增一条配方
                     */
                    _IngredientSelecWin = new IngredientSelecWin(_win);
                    _IngredientSelecWin.Show();
                    _IngredientSelecWin.Closed += _IngredientSelecWin_Closed;
                    break;
                case CommandCmdDef.BtnCmd.INGRED_DEL:
                    foreach (var item in _EvoRecipe._lstIngredientInfo)
                    {
                        if (item.IsSelected)
                        {
                            _IDControl.CGID(item.ID);
                            _EvoRecipe._lstIngredientInfo.Remove(item);
                            break;
                        }
                    }
                    SaveIngredientData();
                    break;


                case CommandCmdDef.BtnCmd.RCP_ADD:
                    RecipeInfo tmprcp = new RecipeInfo();
                    tmprcp.Name = "New Recipe";
                    tmprcp.ID = _IDControl.GetID(1);
                    tmprcp.CrtModifyStatus = CommandCmdDef.ModifyType.NEWONE;
                    _EvoRecipe._lstRecipeInfo.Add(tmprcp);
                    break;
                case CommandCmdDef.BtnCmd.RCP_DEL:
                    foreach (var item in _EvoRecipe._lstRecipeInfo)
                    {
                        if (item.IsSelected)
                        {
                            _IDControl.CGID(item.ID,1);
                            _EvoRecipe._lstRecipeInfo.Remove(item);
                            break;
                        }
                    }
                    SaveIngredientData();
                    break;
                case CommandCmdDef.BtnCmd.RCP_SAVE:
                    foreach (var item in _EvoRecipe._lstRecipeInfo)
                    {
                        if (item.IsSelected)
                        {
                            item.Name = _CrtRecipeInfo.Name;
                            item.ID = _CrtRecipeInfo.ID;
                            item.CrtModifyStatus = _CrtRecipeInfo.CrtModifyStatus;

                            item._publicInfo.CupSensor = _CrtRecipeInfo._publicInfo.CupSensor;
                            item._publicInfo.DispenseType = _CrtRecipeInfo._publicInfo.DispenseType;
                            item._publicInfo.LedColor = _CrtRecipeInfo._publicInfo.LedColor;
                            item._publicInfo.LedIntensity = _CrtRecipeInfo._publicInfo.LedIntensity;
                            item._publicInfo.Ledmode = _CrtRecipeInfo._publicInfo.Ledmode;
                            item._publicInfo.price = _CrtRecipeInfo._publicInfo.price;
                            item._publicInfo.setCups = _CrtRecipeInfo._publicInfo.setCups;
                            item._publicInfo.setMilk = _CrtRecipeInfo._publicInfo.setMilk;
                            item._publicInfo.setStrength = _CrtRecipeInfo._publicInfo.setStrength;
                            item._publicInfo.setSugar = _CrtRecipeInfo._publicInfo.setSugar;
                            item._publicInfo.setVolume = _CrtRecipeInfo._publicInfo.setVolume;
                            item._publicInfo.UseCount = _CrtRecipeInfo._publicInfo.UseCount;
                            item._lstIngredientStep.Clear();
                            foreach (var item1 in _CrtRecipeInfo._lstIngredientStep)
                            {
                                item._lstIngredientStep.Add(item1);
                            }
                        }
                    }
                    SaveIngredientData();
                    break;


                case CommandCmdDef.BtnCmd.RCP_INGRED_ADD:
                    EVO tmp = new EVO();
                    tmp.InitEVO(_EvoRecipe._lstIngredientInfo);
                    tmp.myclick += tmp_myclick;
                    tmp.Show();
                    break;
                case CommandCmdDef.BtnCmd.RCP_INGRED_DEL:
                    foreach (var item in _CrtRecipeInfo._lstIngredientStep)
                    {
                        if (item.IsSelected)
                        {
                            _CrtRecipeInfo._lstIngredientStep.Remove(item);
                            break;
                        }
                    }
                    SaveIngredientData();
                    break;
                case CommandCmdDef.BtnCmd.RCP_INGRED_SAVE:
                   foreach (var item in _EvoRecipe._lstRecipeInfo)
                    {
                        if (item.IsSelected)
                        {
                            item.Name = _CrtRecipeInfo.Name;
                            item.ID = _CrtRecipeInfo.ID;
                            item.CrtModifyStatus = _CrtRecipeInfo.CrtModifyStatus;
                            item._publicInfo.CupSensor = _CrtRecipeInfo._publicInfo.CupSensor;
                            item._publicInfo.DispenseType = _CrtRecipeInfo._publicInfo.DispenseType;
                            item._publicInfo.LedColor = _CrtRecipeInfo._publicInfo.LedColor;
                            item._publicInfo.LedIntensity = _CrtRecipeInfo._publicInfo.LedIntensity;
                            item._publicInfo.Ledmode = _CrtRecipeInfo._publicInfo.Ledmode;
                            item._publicInfo.price = _CrtRecipeInfo._publicInfo.price;
                            item._publicInfo.setCups = _CrtRecipeInfo._publicInfo.setCups;
                            item._publicInfo.setMilk = _CrtRecipeInfo._publicInfo.setMilk;
                            item._publicInfo.setStrength = _CrtRecipeInfo._publicInfo.setStrength;
                            item._publicInfo.setSugar = _CrtRecipeInfo._publicInfo.setSugar;
                            item._publicInfo.setVolume = _CrtRecipeInfo._publicInfo.setVolume;
                            item._publicInfo.UseCount = _CrtRecipeInfo._publicInfo.UseCount;
                            item._lstIngredientStep.Clear();
                            foreach (var item1 in _CrtRecipeInfo._lstIngredientStep)
                            {
                                item._lstIngredientStep.Add(item1);
                            }
                        }
                    }
                    SaveIngredientData();
                    break;
                    /*
                     * 
                     * 
                     * 
                     * 
                     * 
                     * 
                     */
                case CommandCmdDef.BtnCmd.UI_MainSelect:
                    _UiData.SetUiVisible(CommandCmdDef.UiIndex.UI_MainSelect);
                    break;
                case CommandCmdDef.BtnCmd.UI_MachineSet:
                    _UiData.SetUiVisible(CommandCmdDef.UiIndex.UI_MachineSet);
                    break;
                case CommandCmdDef.BtnCmd.UI_CLEANSYS:
                    //MessageBox.Show("This Function is not Complete");
                   // break;
                    //TODO:获取清洁的菜单选项
                    _UiData.SetUiVisible(CommandCmdDef.UiIndex.UI_CLEANSYS);
                    break;
                case CommandCmdDef.BtnCmd.UI_SET_VALVE:
                    _UiData.SetUiVisible(CommandCmdDef.UiIndex.UI_SET_VALVE);
                    break;
                case CommandCmdDef.BtnCmd.UI_HIDE_VALVE:
                    _UiData.HideUiVisble(CommandCmdDef.UiIndex.UI_SET_VALVE);
                    break;
                case CommandCmdDef.BtnCmd.UI_SET_CANISTER:
                    _UiData.SetUiVisible(CommandCmdDef.UiIndex.UI_SET_CANISTER);
                    break;
                case CommandCmdDef.BtnCmd.UI_HIDE_CANISTER:
                    _UiData.HideUiVisble(CommandCmdDef.UiIndex.UI_SET_CANISTER);
                    break;
                case CommandCmdDef.BtnCmd.UI_SET_MIXER:
                    _UiData.SetUiVisible(CommandCmdDef.UiIndex.UI_SET_MIXER);
                    break;
                case CommandCmdDef.BtnCmd.UI_SET_BEANHOPPER:
                    _UiData.SetUiVisible(CommandCmdDef.UiIndex.UI_SET_BEANHOPPER);
                    break;
                case CommandCmdDef.BtnCmd.UI_HIDE_MIXER:
                    _UiData.HideUiVisble(CommandCmdDef.UiIndex.UI_SET_MIXER);

                    break;
                case CommandCmdDef.BtnCmd.UI_HIDE_BEANHOPPER:
                    _UiData.HideUiVisble(CommandCmdDef.UiIndex.UI_SET_BEANHOPPER);
                    break;
                case CommandCmdDef.BtnCmd.UI_CLEAN_DAILY:
                case CommandCmdDef.BtnCmd.UI_CLEAN_WEEKLY:
                case CommandCmdDef.BtnCmd.UI_CLEAN_CLEAN_BREW:
                case CommandCmdDef.BtnCmd.UI_CLEAN_CLEAN_GRINDER:
                case CommandCmdDef.BtnCmd.UI_CLEAN_CLEAN_MIXER:
                case CommandCmdDef.BtnCmd.UI_CLEAN_CLEAN_VALVE:
                case CommandCmdDef.BtnCmd.UI_CLEAN_FLUSH_BREW:
                case CommandCmdDef.BtnCmd.UI_CLEAN_OPEN_BREW:
                case CommandCmdDef.BtnCmd.UI_CLEAN_WATERFLUSH:
                    _UiData.Clean_type = (UInt16)crtcmd;
                    break;

                case CommandCmdDef.BtnCmd.SET_DB_DATE:
                    aa = new M2BDbSetting();

                    aac = new DBStruct();
                    aac.DBID = 0x91;
                    aac.DBValue = (uint)Function.Int2Ascii(_MachineSetingInfo.Dt.Year);
                    aa._DBGroup.Add(aac);

                    aac = new DBStruct();
                    aac.DBID = 0x92;
                    aac.DBValue = (uint)Function.Int2Ascii(_MachineSetingInfo.Dt.Month*100+ _MachineSetingInfo.Dt.Day);
                    aa._DBGroup.Add(aac);

                    aac = new DBStruct();
                    aac.DBID = 0x93;
                    aac.DBValue = (uint)Function.Int2Ascii(_MachineSetingInfo.Dt.Hour * 100 + _MachineSetingInfo.Dt.Minute);
                    aa._DBGroup.Add(aac);

                    aac = new DBStruct();
                    aac.DBID = 0x94;
                    aac.DBValue = aac.DBValue = (uint)Function.Int2Ascii(_MachineSetingInfo.Dt.Second);
                    aa._DBGroup.Add(aac);
                    aa.DBCnt = 4;
                    sendcmd = aa.EnCode();
                    lock (this)
                    {
                        comunication.Getinstance().AddtoSend(sendcmd, (byte)sendcmd.Length);
                    }
                    break;
                case CommandCmdDef.BtnCmd.SET_DB_LED:
                    aa = new M2BDbSetting();
                    aac = new DBStruct();
                    aa.DBCnt = 1;
                    aac.DBID = 3;
                    aac.DBValue = (uint)(1 + ((_MachineSetingInfo.LedbtsIndex+1) << 8) + ((_MachineSetingInfo.LedColorIndex+1) << 16) + ((_MachineSetingInfo.LedModeIndex+1) << 24));
                    aa._DBGroup.Add(aac);
                    sendcmd = aa.EnCode();
                    lock (this)
                    {
                        comunication.Getinstance().AddtoSend(sendcmd, (byte)sendcmd.Length);
                    }
                    break;
                case CommandCmdDef.BtnCmd.SET_DB_FAN:
                    aa = new M2BDbSetting();
                    aa.DBCnt = 2;

                    aac = new DBStruct();
                    aac.DBID = 7;
                    aac.DBValue = _MachineSetingInfo.FanSpd;
                    aa._DBGroup.Add(aac);

                    aac = new DBStruct();
                    aac.DBID = 0x11;
                    aac.DBValue = (uint)(_MachineSetingInfo.Fanruntm+ (_MachineSetingInfo.Fanconflag<<24));
                    aa._DBGroup.Add(aac);

                    sendcmd = aa.EnCode();
                    lock (this)
                    {
                        comunication.Getinstance().AddtoSend(sendcmd, (byte)sendcmd.Length);
                    }
                    break;
                case CommandCmdDef.BtnCmd.SET_DB_TEMP:
                    aa = new M2BDbSetting();
                    aa.DBCnt = 4;

                    aac = new DBStruct();
                    aac.DBID = 1;
                    aac.DBValue = _MachineSetingInfo.Tempblock;
                    aa._DBGroup.Add(aac);

                    aac = new DBStruct();
                    aac.DBID = 2;
                    aac.DBValue = _MachineSetingInfo.Tempsave;
                    aa._DBGroup.Add(aac);

                    aac = new DBStruct();
                    aac.DBID = 5;
                    aac.DBValue = _MachineSetingInfo.Tempwarn;
                    aa._DBGroup.Add(aac);

                    aac = new DBStruct();
                    aac.DBID = 6;
                    aac.DBValue = _MachineSetingInfo.Temptank;
                    aa._DBGroup.Add(aac);
                    sendcmd = aa.EnCode();
                    lock (this)
                    {
                        comunication.Getinstance().AddtoSend(sendcmd, (byte)sendcmd.Length);
                    }
                    break;
                case CommandCmdDef.BtnCmd.SET_DB_RST:
                    M2BFctoryRst fctrst = new M2BFctoryRst();
                    sendcmd = fctrst.EnCode();
                    lock (this)
                    {
                        comunication.Getinstance().AddtoSend(sendcmd, (byte)sendcmd.Length);
                    }
                    break;
                default:
                    break;
            }
        }

        private void Update_Rcp_Method()
        {
            M2BMakeBeverage cmdtmp = new M2BMakeBeverage(_EvoRecipe._lstRecipeInfo[_EvoUpdate.updateindex]._publicInfo);
            cmdtmp.ID = _EvoRecipe._lstRecipeInfo[_EvoUpdate.updateindex].ID;

            cmdtmp.operatetype = 3;
            if (_EvoUpdate.updatetype == 1)
            {
                cmdtmp.operatetype = 2;
            }

            foreach (var item in _EvoRecipe._lstRecipeInfo[_EvoUpdate.updateindex]._lstIngredientStep)
            {
                M2BMakeBeverage.IngredientStep steptmp = new M2BMakeBeverage.IngredientStep();
                steptmp.ID = item.ID;
                steptmp._Type = item._Type;
                steptmp.startTime = item.StartTime;
                steptmp.percent = item.ScaleRate;
                cmdtmp.igredientStepGroup.Add(steptmp);
            }
            cmdtmp.ingredientCnt = (byte)_EvoRecipe._lstRecipeInfo[_EvoUpdate.updateindex]._lstIngredientStep.Count;
            byte[] SendCmd = cmdtmp.EnCode();
            comunication.Getinstance().AddtoSend(SendCmd, (byte)SendCmd.Length);
        }

        private void Update_ING_Method()
        {
            M2BMakeIngredient m2bMakeIngredient = new M2BMakeIngredient((byte)_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex].Type);
            m2bMakeIngredient.ID = _EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex].ID;
            m2bMakeIngredient.operatetype = 3;
            if (_EvoUpdate.updatetype == 1)
            {
                m2bMakeIngredient.operatetype = 2;
            }
            switch (_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex].Type)
            {
                case IngredientType.ESPRESSO:
                    break;
                case IngredientType.FILTERBREW:
                    M2BMakeIngredient.FilterBrewPhaseStep steptmp = new M2BMakeIngredient.FilterBrewPhaseStep();
                    /*
                     * Filter brewer process	Phase 1	Phase 2	Phase 3	Phase 4	Phase 5	Phase 6	Phase 7	Phase 8	Phase 9
                                                Brew motor	X sec	wait Xs	X sec	wait Xs	X sec	wait Xs	X sec	wait Xs	Run to switch
                                                Brew motor speed	20-100%	0%	20-100%	0%	20-100%	0%	20-100%	0%	100%
                                                Water valve	X ml																														
                                                Grinder	X sec																															
                     * Run brew motor for X seconds with X PWM (speed), start water valve and dispense X ml. start grinder and run X seconds.
                     * When to start water+grinder could be selected between ex. “Time” – you set start/stop time manually, “Start of phase” – grinder+water will start when brewer reach a start of a phase, “End of phase” – grinder+water will start when brewer reach a end of a phase.
                     */
                    steptmp.grinder1Type = (UInt16)_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._FilterBrew.Grind1Type;
                    steptmp.grinder2Type = (UInt16)_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._FilterBrew.Grind2Type;
                    steptmp.grinder1powder = (UInt16)(((_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._FilterBrew.Grind1Cnt / 10) << 8) + (_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._FilterBrew.Grind1Cnt % 10));
                    steptmp.grinder2powder = (UInt16)(((_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._FilterBrew.Grind2Cnt / 10) << 8) + (_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._FilterBrew.Grind2Cnt % 10));
                    steptmp.motorWaitTime = 0;
                    steptmp.WaterFlowTime = (UInt16)(_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._FilterBrew.WaterVolume * 1000 / MachineParam.BrewFlowRate);
                    m2bMakeIngredient._ProcessFilterBrew.FilterBrewPhaseGroup.Add(steptmp);
                    /*Pause brew motor for X Seconds (this phase is now called “Pre Brew”)
                     */
                    steptmp = new M2BMakeIngredient.FilterBrewPhaseStep();
                    steptmp.grinder1powder = 0;
                    steptmp.grinder2powder = 0;
                    steptmp.motorWaitTime = _EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._FilterBrew.Tm_Pre;
                    steptmp.WaterFlowTime = 0;
                    m2bMakeIngredient._ProcessFilterBrew.FilterBrewPhaseGroup.Add(steptmp);
                    steptmp = new M2BMakeIngredient.FilterBrewPhaseStep();
                    /*Pause brew motor for X Seconds (this phase is now called “Extraction time”)
                     */
                    steptmp = new M2BMakeIngredient.FilterBrewPhaseStep();
                    steptmp.grinder1Type = 0;
                    steptmp.grinder2Type = 0;
                    steptmp.grinder1powder = 0;
                    steptmp.grinder2powder = 0;
                    steptmp.motorWaitTime = _EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._FilterBrew.Tm_Press;
                    steptmp.WaterFlowTime = 0;
                    m2bMakeIngredient._ProcessFilterBrew.FilterBrewPhaseGroup.Add(steptmp);
                    steptmp = new M2BMakeIngredient.FilterBrewPhaseStep();
                    /*Pause brew motor for X Seconds (this phase is now called “Decompress time”)
                     */
                    steptmp = new M2BMakeIngredient.FilterBrewPhaseStep();
                    steptmp.grinder1Type = 0;
                    steptmp.grinder2Type = 0;
                    steptmp.grinder1powder = 0;
                    steptmp.grinder2powder = 0;
                    steptmp.motorWaitTime = _EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._FilterBrew.Tm_Depress;
                    steptmp.WaterFlowTime = 0;
                    m2bMakeIngredient._ProcessFilterBrew.FilterBrewPhaseGroup.Add(steptmp);
                    steptmp = new M2BMakeIngredient.FilterBrewPhaseStep();
                    /*Pause brew motor for X Seconds (this phase is now called “Empty time”) coffee comes out in cup
                     */
                    steptmp = new M2BMakeIngredient.FilterBrewPhaseStep();
                    steptmp.grinder1Type = 0;
                    steptmp.grinder2Type = 0;
                    steptmp.grinder1powder = 0;
                    steptmp.grinder2powder = 0;
                    steptmp.motorWaitTime = _EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._FilterBrew.Tm_DelayOpen;
                    steptmp.WaterFlowTime = 0;
                    m2bMakeIngredient._ProcessFilterBrew.FilterBrewPhaseGroup.Add(steptmp);
                    steptmp = new M2BMakeIngredient.FilterBrewPhaseStep();
                    m2bMakeIngredient._ProcessFilterBrew.PhaseCount = 5;
                    m2bMakeIngredient._ProcessFilterBrew.postionDown = _EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._FilterBrew.ActionDownPostion;
                    m2bMakeIngredient._ProcessFilterBrew.postionUp = _EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._FilterBrew.ActionUpPostion;

                    break;
                case IngredientType.FRESHMILK:
                    /*
                     * Hot milk process	Phase 1	Phase 2	Phase 3	Phase 4		
                        Clean water valve	1,5s																			4s								
                        Milk pump	6,5s	10s	X ml	14s		
                        Milk pump speed	75%	75%	75%	75%		
                        Milk heaters	Allow	Allow	Allow	Allow		
                        Valve to driptray	6,5s	5s																				3s		
                        Valve to cup											1,5s	X ml	11s				
                        Milk valve (fridge)						10s	X ml												
                        Milk Whipper											1,5s	X ml	12s			
                        Whipper speed											20-100%	20-100%	20-100%			
                        Mixer bowl flush valve																																1,5s
                    Action steps	
Action 1 – Phase 1 (Initial cleaning)	Start the clean water valve from hot water tank, milk pump at 75% PWM, and no current (OFF) to the 3/2 valve to make it towards milk waste. Heaters are allowed to work towards Prio temp. Heaters shall have option to be turned OFF during the process to be able to make cold milk as well.
Action 2 – Phase 2 (pre fill up)	Once phase 1 is finished we activate the 3/2 valve in the fridge to start pumping milk into the system. For 5 seconds we still have the other 3/2 valve towards milk waste since there is some water left in the tubing, it also takes around 5 seconds to fill all tubes and heaters with milk. After 5 seconds we then swap 3/2 valve (turn it ON) towards the mixer bowl, at the same time we start the whipper.
Action 3 – Phase 3 (dispense milk)	Now we just continue run the pump at 75% and the 3/2 valves are active to pump milk and direct it towards mixer bowl. To determine how long these components shall run the milk use a fixed flow, 18ml/s. if you want ex. 150ml milk it means that components will run for 8,3 seconds in this step.
Action 4 – Phase 4 (After cleaning)	Now we start the water valve from the tank again and close the valve in fridge for milk. We still dispense towards the mixer bowl since we want as much remaining milk/water in the system to go into the cup. The last 3 seconds we turn off the 3/2 valve towards the mixer so the last part goes into the milk waste instead. When all internal flushing is done we activate the water valve in tank for chocolate (mixer flush valve) for 1.5s to rinse the mixer bowl properly in the end.
** Valve to milk waste/mixer is same 3/2 valve. If no current and valve is off = towards drip tray, if you activate valve with current = towards cup.
Heaters have two temperature settings, “Idle temp” and “Prio temp”. When machine is standing still and no one using machine the heaters will keep the Idle temperature setting. Ex 60°C. When you start a milk drink the heaters are allowed to heat up and use the Prio temperature during the process. Ex. 75°C. When drink is finished the heaters go back and use the Idle setting again. 
                     * 
                     */
                    m2bMakeIngredient._ProcessFreshMilk.dispenseMilkTime = (UInt16)(_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._FreshMilk.MilkVolume * 1000 / MachineParam.Mixer1FlowRate);
                    m2bMakeIngredient._ProcessFreshMilk.preFlushTime = (UInt16)(_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._FreshMilk.Preflush * 1000 / MachineParam.Mixer1FlowRate);
                    m2bMakeIngredient._ProcessFreshMilk.aftFlushTime = (UInt16)(_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._FreshMilk.AfterFlush * 1000 / MachineParam.Mixer1FlowRate);
                    m2bMakeIngredient._ProcessFreshMilk.heaterAction = _EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._FreshMilk.HeaterFlag;
                    m2bMakeIngredient._ProcessFreshMilk.whipperSpeed = (byte)_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._FreshMilk.WhipperSpeed;
                    break;
                case IngredientType.INSTANTPOWDER:
                    /*
                     *  Action step	
                        Action 1 – Pre flush	First we must dispense a little water so we have water in the mixer bowl before we start canister and whipper. Normally 15ml or 1 sec
                        Action 2 – Pause	Here we have a pause so the water have time to fall down from tank through the tubes and into the mixer bowl.
                        Action 3 – Dispense	We can now start all components such as water valve, canister and whipper at X PWM. When the setting that have longest time is finished it goes to next step.
                        Action 4 – Pause	Another pause to make all water/drink empty the mixer bowl. 
                        Action 5 – After flush	Run water again to flush out all remains, normally 15ml or 1 sek.
                     * 
                     */
                    m2bMakeIngredient._ProcessInstantPowder.canisterCnt = 2;
                    UInt32 canisterpowder = (UInt32)((_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._InstantPowder.PackageOneType << 16) + (((_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._InstantPowder.PackageOneAmt / 10) << 8) + (_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._InstantPowder.PackageOneAmt % 10)));
                    m2bMakeIngredient._ProcessInstantPowder.canisterPowderGroup.Add(canisterpowder);
                    canisterpowder = (UInt32)((_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._InstantPowder.PackageTwoType << 16) + (((_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._InstantPowder.PackageTwoAmt / 10) << 8) + (_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._InstantPowder.PackageTwoAmt % 10)));
                    m2bMakeIngredient._ProcessInstantPowder.canisterPowderGroup.Add(canisterpowder);
                    m2bMakeIngredient._ProcessInstantPowder.MixIndex = (byte)_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._InstantPowder.MixIndex;
                    m2bMakeIngredient._ProcessInstantPowder.waterDispenseTime = (UInt16)(_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._InstantPowder.WaterVolume * 1000 / MachineParam.Mixer1FlowRate);
                    m2bMakeIngredient._ProcessInstantPowder.preFlushTime = (UInt16)(_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._InstantPowder.PreFlush * 1000 / MachineParam.Mixer1FlowRate);
                    m2bMakeIngredient._ProcessInstantPowder.aftFlushTime = (UInt16)(_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._InstantPowder.AfterFlush * 1000 / MachineParam.Mixer1FlowRate);
                    m2bMakeIngredient._ProcessInstantPowder.pauseTime = 1500;
                    m2bMakeIngredient._ProcessInstantPowder.pauseTime1 = 2000;
                    m2bMakeIngredient._ProcessInstantPowder.whipperSpeed = (byte)_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._InstantPowder.WhipperSpeed;
                    m2bMakeIngredient._ProcessInstantPowder.waterType = _EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._InstantPowder.WaterType;
                    break;
                case IngredientType.Water:
                    m2bMakeIngredient._ProcessWater.WaterType = _EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._Water.WaterType;
                    m2bMakeIngredient._ProcessWater.DispenseTm = (UInt16)(_EvoRecipe._lstIngredientInfo[_EvoUpdate.updateindex]._Water.WaterVolume * 1000 / MachineParam.HotwaterFlowRate);
                    break;
                case IngredientType.NoSelect:
                    break;
                default:
                    break;
            }
            byte[] SendCmd = m2bMakeIngredient.EnCode();
            comunication.Getinstance().AddtoSend(SendCmd, (byte)SendCmd.Length);
        }

        private void InitCleanProcess()
        {
            _CrtEVOCleaning = (EVOCleaning)Function.XmlSerializer.LoadFromXml("EVO.clean.xml", typeof(EVOCleaning));
            if (_CrtEVOCleaning == null)
            {
                _CrtEVOCleaning = new EVOCleaning();
                Function.XmlSerializer.SaveToXml("EVO.clean.xml", _CrtEVOCleaning, typeof(EVOCleaning), null);
            }
        }

        void _EvoStCheck_Unloaded(object sender, RoutedEventArgs e)
        {
            if (Tmr.IsEnabled)
            {
                Tmr.Stop();
            }
        }

        void tmp_myclick(object sender, System.Windows.Input.MouseButtonEventArgs e)
        {
            Console.WriteLine(sender.ToString());
            IngredientStep tmpstep = sender as IngredientStep;
            System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() => _CrtRecipeInfo._lstIngredientStep.Add(tmpstep)));
        }

        void _IngredientSelecWin_Closed(object sender, EventArgs e)
        {
            Console.WriteLine("aa");

            IngredientInfo ingtmp =null;
            IngredientType tmp = (sender as IngredientSelecWin).Type;
            switch (tmp)
            {
                case IngredientType.ESPRESSO:
                     ingtmp = new IngredientInfo( IngredientType.ESPRESSO);
                     ingtmp.IsSelected = true;
                     ingtmp.ID = _IDControl.GetID();
                    _EvoRecipe._lstIngredientInfo.Add(ingtmp);
                    break;
                case IngredientType.FILTERBREW:
                     ingtmp = new IngredientInfo( IngredientType.FILTERBREW);
                     ingtmp.IsSelected = true;
                     ingtmp.ID = _IDControl.GetID();
                    _EvoRecipe._lstIngredientInfo.Add(ingtmp);
                    Console.WriteLine("aaa");

                    break;
                case IngredientType.FRESHMILK:
                    ingtmp = new IngredientInfo( IngredientType.FRESHMILK);
                    ingtmp.IsSelected = true;
                    ingtmp.ID = _IDControl.GetID();
                    _EvoRecipe._lstIngredientInfo.Add(ingtmp);
                    break;
                case IngredientType.INSTANTPOWDER:
                    ingtmp = new IngredientInfo( IngredientType.INSTANTPOWDER);
                    ingtmp.IsSelected = true;
                    ingtmp.ID = _IDControl.GetID();
                    _EvoRecipe._lstIngredientInfo.Add(ingtmp);
                    break;
                case IngredientType.Water:
                    //TODO:Water
                    ingtmp = new IngredientInfo( IngredientType.Water);
                    ingtmp.IsSelected = true;
                    ingtmp.ID = _IDControl.GetID();
                    _EvoRecipe._lstIngredientInfo.Add(ingtmp);
                    break;
                case IngredientType.NoSelect:
                    break;
                default:
                    break;
            }
            Console.WriteLine("ingtmp"+ ingtmp.ToString());
            if (ingtmp!=null)
            {
                SaveIngredientData();
            }
        }
        public void UpdateEvoMachine()
        {
            foreach (var item in _LstEVOMachine)
            {
                if (item.IsSelected)
                {
                    _CrtEVOMachine.Name = item.Name;
                    _CrtEVOMachine.MachineID = item.MachineID;
                    _CrtEVOMachine.ValveAmt = item.ValveAmt;
                    _CrtEVOMachine.MixerAmt = item.MixerAmt;
                    _CrtEVOMachine.CanisterAmt = item.CanisterAmt;
                    _CrtEVOMachine.BeanHopperAmt = item.BeanHopperAmt;
                    _CrtEVOMachine._WaterValve.Clear();
                    foreach (var item1 in item._WaterValve)
                    {
                        _CrtEVOMachine._WaterValve.Add(item1);
                    }
                    _CrtEVOMachine._MixerUnit.Clear();
                    foreach (var item1 in item._MixerUnit)
                    {
                        _CrtEVOMachine._MixerUnit.Add(item1);
                    }
                    _CrtEVOMachine._CanisterUnit.Clear();
                    foreach (var item1 in item._CanisterUnit)
                    {
                        _CrtEVOMachine._CanisterUnit.Add(item1);
                    }
                    _CrtEVOMachine._BeanHopperUint.Clear();
                    foreach (var item1 in item._BeanHopperUint)
                    {
                        _CrtEVOMachine._BeanHopperUint.Add(item1);
                    }
                    break;
                }
            }
        }
        public void UpdateWaterValve()
        {
            
            foreach (var item in _CrtEVOMachine._WaterValve)
            {
                if (item.IsSelected)
                {
                    _CrtWaterValve.Name = item.Name;
                    _CrtWaterValve.DeviceIoAdress = item.DeviceIoAdress;
                    _CrtWaterValve.Flow = item.Flow;
                    _CrtWaterValve.DeviceID = item.DeviceID;
                }
            }
        }
        public void UpdateCanisterValve()
        {
            foreach (var item in _CrtEVOMachine._CanisterUnit)
            {
                if (item.IsSelected)
                {
                    _CrtCanisterUnit.Name = item.Name;
                    _CrtCanisterUnit.DeviceIoAdress = item.DeviceIoAdress;
                    _CrtCanisterUnit.Flow = item.Flow;
                    _CrtCanisterUnit.DeviceID = item.DeviceID;
                    _CrtCanisterUnit.Postion = item.Postion;
                    _CrtCanisterUnit.Powdertype = item.Powdertype;
                }
            }
        }
        public void UpdateDevice()
        {
            foreach (var item in _LstDeviceUnit)
            {
                if (item.IsSelected)
                {
                    _CrtDeviceUnit.Name = item.Name;
                    _CrtDeviceUnit.DeviceIoAdress = item.DeviceIoAdress;
                    _CrtDeviceUnit._Type = item._Type;
                    _CrtDeviceUnit.DeviceID = item.DeviceID;
                    _CrtDeviceUnit.Speed = item.Speed;
                    
                }
            }
        }
        public void UpdateBeanHopperValve()
        {
            foreach (var item in _CrtEVOMachine._BeanHopperUint)
            {
                if (item.IsSelected)
                {
                    _CrtBeanHopperUint.Name = item.Name;
                    _CrtBeanHopperUint.DeviceIoAdress = item.DeviceIoAdress;
                    _CrtBeanHopperUint.Flow = item.Flow;
                    _CrtBeanHopperUint.DeviceID = item.DeviceID;
                    _CrtBeanHopperUint.Powdertype = item.Powdertype;


                }
            }
        }
        public void UpdateMixerUnit()
        {
            foreach (var item in _CrtEVOMachine._MixerUnit)
            {
                if (item.IsSelected)
                {
                    _CrtMixerUnit.Name = item.Name;
                    _CrtMixerUnit.DeviceIoAdress = item.DeviceIoAdress;
                    _CrtMixerUnit.DeviceID = item.DeviceID;
                    _CrtMixerUnit.Speed = item.Speed;
                    
                }
            }
        }
        public void UpdateIngredient()
        {
            foreach (var item in _EvoRecipe._lstIngredientInfo)
            {
                if (item.IsSelected)
                {
                    _CrtIngredient.ID = item.ID;
                    _CrtIngredient.Type = item.Type;
                    _CrtIngredient.Name = item.Name;                   
                    switch (item.Type)
                    {
                        case IngredientType.ESPRESSO:    
                            _CrtIngredient._Espresso.WaterVolume = item._Espresso.WaterVolume;
                            _CrtIngredient._Espresso.Grind1Cnt = item._Espresso.Grind1Cnt;
                            _CrtIngredient._Espresso.Grind2Cnt = item._Espresso.Grind2Cnt;
                            _CrtIngredient._Espresso.Tm_Infusio = item._Espresso.Tm_Infusio;
                            _CrtIngredient._Espresso.Tm_Pause = item._Espresso.Tm_Pause;
                            _CrtIngredient._Espresso.Tm_Press = item._Espresso.Tm_Press;
                            _CrtIngredient._Espresso.Tm_DelayOpen = item._Espresso.Tm_DelayOpen;

                            break;
                        case IngredientType.FILTERBREW:
                            _CrtIngredient._FilterBrew.WaterVolume = item._FilterBrew.WaterVolume;
                            _CrtIngredient._FilterBrew.Grind1Type = item._FilterBrew.Grind1Type;
                            _CrtIngredient._FilterBrew.Grind2Type = item._FilterBrew.Grind2Type;

                            _CrtIngredient._FilterBrew.Grind1Cnt = item._FilterBrew.Grind1Cnt;
                            _CrtIngredient._FilterBrew.Grind2Cnt = item._FilterBrew.Grind2Cnt;
                            _CrtIngredient._FilterBrew.Tm_DelayOpen = item._FilterBrew.Tm_DelayOpen;
                            _CrtIngredient._FilterBrew.Tm_Depress = item._FilterBrew.Tm_Depress;
                            _CrtIngredient._FilterBrew.Tm_Pre = item._FilterBrew.Tm_Pre;
                            _CrtIngredient._FilterBrew.Tm_Press = item._FilterBrew.Tm_Press;
                            _CrtIngredient._FilterBrew.ActionDownPostion = item._FilterBrew.ActionDownPostion;
                            _CrtIngredient._FilterBrew.ActionUpPostion = item._FilterBrew.ActionUpPostion;
                            break;
                        case IngredientType.FRESHMILK:
                            _CrtIngredient._FreshMilk.HeaterFlag = item._FreshMilk.HeaterFlag;
                            _CrtIngredient._FreshMilk.MilkVolume = item._FreshMilk.MilkVolume;
                            _CrtIngredient._FreshMilk.Preflush = item._FreshMilk.Preflush;
                            _CrtIngredient._FreshMilk.WhipperSpeed = item._FreshMilk.WhipperSpeed;
                            _CrtIngredient._FreshMilk.AfterFlush = item._FreshMilk.AfterFlush;
                            
                            break;
                        case IngredientType.INSTANTPOWDER:
                            _CrtIngredient._InstantPowder.MixIndex        = item._InstantPowder.MixIndex;     
                            _CrtIngredient._InstantPowder.WhipperSpeed    = item._InstantPowder.WhipperSpeed; 
                            _CrtIngredient._InstantPowder.WaterVolume     = item._InstantPowder.WaterVolume;  
                            _CrtIngredient._InstantPowder.PackageOneType    = item._InstantPowder.PackageOneType ;
                            _CrtIngredient._InstantPowder.PackageOneAmt    = item._InstantPowder.PackageOneAmt; 
                            _CrtIngredient._InstantPowder.PackageTwoType    = item._InstantPowder.PackageTwoType;
                            _CrtIngredient._InstantPowder.PackageTwoAmt   = item._InstantPowder.PackageTwoAmt;
                            _CrtIngredient._InstantPowder.WaterType = item._InstantPowder.WaterType;
                            _CrtIngredient._InstantPowder.PreFlush        = item._InstantPowder.PreFlush;
                            _CrtIngredient._InstantPowder.AfterFlush      = item._InstantPowder.AfterFlush;
                            _CrtIngredient._InstantPowder.PostFlushTm = item._InstantPowder.PostFlushTm;
                            _CrtIngredient._InstantPowder.PreFlushTm = item._InstantPowder.PreFlushTm;
                            break;
                        case IngredientType.Water:
                            _CrtIngredient._Water.WaterType = item._Water.WaterType;
                            _CrtIngredient._Water.WaterVolume = item._Water.WaterVolume;
                            break;
                        default:
                            break;
                    }

                }
            }
        }

        public void UpdateRecipe()
        {
            foreach (var item in _EvoRecipe._lstRecipeInfo)
            {
                if (item.IsSelected)
                {
                    _CrtRecipeInfo.Name = item.Name;
                    _CrtRecipeInfo.ID = item.ID;
                    _CrtRecipeInfo.CrtModifyStatus = item.CrtModifyStatus;

                    _CrtRecipeInfo._publicInfo.CupSensor = item._publicInfo.CupSensor;
                    _CrtRecipeInfo._publicInfo.DispenseType = item._publicInfo.DispenseType;
                    _CrtRecipeInfo._publicInfo.LedColor = item._publicInfo.LedColor;
                    _CrtRecipeInfo._publicInfo.LedIntensity = item._publicInfo.LedIntensity;
                    _CrtRecipeInfo._publicInfo.Ledmode = item._publicInfo.Ledmode;
                    _CrtRecipeInfo._publicInfo.price = item._publicInfo.price;
                    _CrtRecipeInfo._publicInfo.setCups = item._publicInfo.setCups;
                    _CrtRecipeInfo._publicInfo.setMilk = item._publicInfo.setMilk;
                    _CrtRecipeInfo._publicInfo.setStrength = item._publicInfo.setStrength;
                    _CrtRecipeInfo._publicInfo.setSugar = item._publicInfo.setSugar;
                    _CrtRecipeInfo._publicInfo.setVolume = item._publicInfo.setVolume;
                    _CrtRecipeInfo._publicInfo.UseCount = item._publicInfo.UseCount;


                    _CrtRecipeInfo._lstIngredientStep.Clear();
                    foreach (var item1 in item._lstIngredientStep)
                    {
                        _CrtRecipeInfo._lstIngredientStep.Add(item1);
                    }
                }
            }
        }
        public void InitDataModel()
        {
            _LstEVOMachine.Clear();
            //TODO:get form config path;

            var ret = Function.XmlSerializer.LoadFromXml("EVO.conf.xml", typeof(EVOMachine));
            EVOMachine tmp = (EVOMachine)ret;
            tmp.ValveAmt = tmp._WaterValve.Count;
            tmp.MixerAmt = tmp._MixerUnit.Count;
            tmp.CanisterAmt = tmp._CanisterUnit.Count;
            tmp.BeanHopperAmt = tmp._BeanHopperUint.Count;
            _LstEVOMachine.Add(tmp);
            InitIngredientData();
            InitCleanProcess();
        }

        private void InitIngredientData()
        {
            _EvoRecipe = (EvoRecipe)Function.XmlSerializer.LoadFromXml("EVO.Ingredient.xml", typeof(EvoRecipe));
            if (_EvoRecipe == null)
            {
                _EvoRecipe = new EvoRecipe();
                _EvoRecipe._lstIngredientInfo = new ObservableCollection<IngredientInfo>();
                _EvoRecipe._lstRecipeInfo = new ObservableCollection<RecipeInfo>();
            }
        }
        private void SaveIngredientData()
        {
            Function.XmlSerializer.SaveToXml("EVO.Ingredient.xml", _EvoRecipe, typeof(EvoRecipe), null);
            Function.XmlSerializer.SaveToXml("EVO.ID.xml", _IDControl, typeof(IDGenrator), null);
            MessageBox.Show("SaveIngredientData success");
        }
        public void SaveEVOMachineSet()
        {
            _CrtEVOMachine.Name = "EVO-B13";
            _CrtEVOMachine.MachineID = 0001;
            WaterValve tmpWaterValve = new WaterValve("Hot Water",0x0001,10);
            _CrtEVOMachine._WaterValve.Add(tmpWaterValve);
            tmpWaterValve = new WaterValve("Brew Hot Water", 0x0002, 10);
            _CrtEVOMachine._WaterValve.Add(tmpWaterValve);
            MixerUnit tmpmix = new MixerUnit("Mix1",0x0003);
            _CrtEVOMachine._MixerUnit.Add(tmpmix);
            Function.XmlSerializer.SaveToXml("EVO.conf.xml", _CrtEVOMachine, typeof(EVOMachine), null);
        }

       
    }
}
