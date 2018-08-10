using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CREM.EVO.MODEL
{
   public class UiData : NotificationObject
    {
        private UInt16 _clean_type;
        private bool _is_mainselect_visible;
        public bool is_mainselect_visible
        {
            get { return _is_mainselect_visible; }
            set { if (_is_mainselect_visible == value)return; _is_mainselect_visible = value; this.RaisePropertyChanged("is_mainselect_visible"); }
        }

        private bool _is_machineset_visible;

        public bool is_machineset_visible
        {
            get { return _is_machineset_visible; }
            set { if (_is_machineset_visible == value)return; _is_machineset_visible = value; this.RaisePropertyChanged("is_machineset_visible"); }
        }
        private bool _is_machinetest_visible;
        public bool is_machinetest_visible
        {
            get { return _is_machinetest_visible; }
            set { if (_is_machinetest_visible == value)return; _is_machinetest_visible = value; this.RaisePropertyChanged("is_machinetest_visible"); }
        }

        private bool _is_ComSet_visible;
        public bool is_ComSet_visible
        {
            get { return _is_ComSet_visible; }
            set { if (_is_ComSet_visible == value)return; _is_ComSet_visible = value; this.RaisePropertyChanged("is_ComSet_visible"); }
        }

        private bool _is_Recipe_visible;
        public bool is_Recipe_visible
        {
            get { return _is_Recipe_visible; }
            set { if (_is_Recipe_visible == value)return; _is_Recipe_visible = value; this.RaisePropertyChanged("is_Recipe_visible"); }
        }
        private bool _is_Clean_visible;
        public bool is_Clean_visible
        {
            get { return _is_Clean_visible; }
            set { if (_is_Clean_visible == value)return; _is_Clean_visible = value; this.RaisePropertyChanged("is_Clean_visible"); }
        }

        private bool _is_DB_visible;
        public bool is_DB_visible
        {
            get { return _is_DB_visible; }
            set { if (_is_DB_visible == value)return; _is_DB_visible = value; this.RaisePropertyChanged("is_DB_visible"); }
        }

        private bool _is_Update_visible;
        public bool is_Update_visible
        {
            get { return _is_Update_visible; }
            set { if (_is_Update_visible == value)return; _is_Update_visible = value; this.RaisePropertyChanged("is_Update_visible"); }
        }

        private bool _is_ingredientdetail_visible;
        public bool is_ingredientdetail_visible
        {
            get { return _is_ingredientdetail_visible; }
            set { if (_is_ingredientdetail_visible == value) return; _is_ingredientdetail_visible = value; this.RaisePropertyChanged("is_ingredientdetail_visible"); }
        }

        private bool _is_ingredientlist_visible;
        public bool is_ingredientlist_visible
        {
            get { return _is_ingredientlist_visible; }
            set { if (_is_ingredientlist_visible == value) return; _is_ingredientlist_visible = value; this.RaisePropertyChanged("is_ingredientlist_visible"); }
        }
        private bool _is_recipedetail_visible;
        public bool is_recipedetail_visible
        {
            get { return _is_recipedetail_visible; }
            set { if (_is_recipedetail_visible == value) return; _is_recipedetail_visible = value; this.RaisePropertyChanged("is_recipedetail_visible"); }
        }
        private bool _is_recipelist_visible;
        public bool is_recipelist_visible
        {
            get { return _is_recipelist_visible; }
            set { if (_is_recipelist_visible == value) return; _is_recipelist_visible = value; this.RaisePropertyChanged("is_recipelist_visible"); }
        }

        private bool _is_valvedetail_visible;
        public bool is_valvedetail_visible
        {
            get { return _is_valvedetail_visible; }
            set { if (_is_valvedetail_visible == value) return; _is_valvedetail_visible = value; this.RaisePropertyChanged("is_valvedetail_visible"); }
        }


        private bool _is_canisterdetail_visible;
        public bool is_canisterdetail_visible
        {
            get { return _is_canisterdetail_visible; }
            set { if (_is_canisterdetail_visible == value) return; _is_canisterdetail_visible = value; this.RaisePropertyChanged("is_canisterdetail_visible"); }
        }


        private bool _is_mixerdetail_visible;
        public bool is_mixerdetail_visible
        {
            get { return _is_mixerdetail_visible; }
            set { if (_is_mixerdetail_visible == value) return; _is_mixerdetail_visible = value; this.RaisePropertyChanged("is_mixerdetail_visible"); }
        }

        private bool _is_beandetail_visible;
        public bool is_beandetail_visible
        {
            get { return _is_beandetail_visible; }
            set { if (_is_beandetail_visible == value) return; _is_beandetail_visible = value; this.RaisePropertyChanged("is_beandetail_visible"); }
        }
        

        private bool _is_machinetestoverview_visible;
        public bool is_machinetestoverview_visible
        {
            get { return _is_machinetestoverview_visible; }
            set { if (_is_machinetestoverview_visible == value) return; _is_machinetestoverview_visible = value; this.RaisePropertyChanged("is_machinetestoverview_visible"); }
        }

        private bool _is_calibration_visible;
        public bool is_calibration_visible
        {
            get { return _is_calibration_visible; }
            set { if (_is_calibration_visible == value) return; _is_calibration_visible = value; this.RaisePropertyChanged("is_calibration_visible"); }
        }


        private bool _is_com_error_visible;
        public bool is_com_error_visible
        {
            get { return _is_com_error_visible; }
            set { if (_is_com_error_visible == value) return; _is_com_error_visible = value; this.RaisePropertyChanged("is_com_error_visible"); }
        }

        public ushort Clean_type
        {
            get
            {
                return _clean_type;
            }

            set
            {
                if (_clean_type!=value)
                {
                _clean_type = value;this.RaisePropertyChanged("Clean_type");
                }
                
            }
        }


        private bool _is_clean_block_visible;
        public bool is_clean_block_visible
        {
            get { return _is_clean_block_visible; }
            set { if (_is_clean_block_visible == value) return; _is_clean_block_visible = value; this.RaisePropertyChanged("is_clean_block_visible"); }
        }
        private void InitAll()
        {
            is_mainselect_visible = false;
            is_machineset_visible = false;
            is_machinetest_visible = false;
            is_ComSet_visible = false;
            is_Recipe_visible = false;
            is_Clean_visible = false;
            is_DB_visible = false;
            is_Update_visible = false;
            is_ingredientdetail_visible = false;
            is_ingredientlist_visible = false;
            is_recipedetail_visible = false;
            is_recipelist_visible = false;
            is_valvedetail_visible = false;
            is_canisterdetail_visible = false;
            is_mixerdetail_visible = false;
            is_machinetestoverview_visible = false;
            is_calibration_visible = false;
        }
        public void SetUiVisible(CommandCmdDef.UiIndex a)
        {
            InitAll();
            switch (a)
            {
                case CommandCmdDef.UiIndex.UI_TEST_CALIBRATION:
                    is_calibration_visible = true;
                    is_machinetest_visible = true;
                    break;
                case CommandCmdDef.UiIndex.UI_TEST_OVERVIW:
                    is_machinetestoverview_visible = true;
                    is_machinetest_visible = true;
                    break;
                case CommandCmdDef.UiIndex.UI_SET_CANISTER:
                    is_machineset_visible = true;
                    is_canisterdetail_visible = true;
                    break;
                case CommandCmdDef.UiIndex.UI_SET_MIXER:
                    is_machineset_visible = true;
                    is_mixerdetail_visible = true;
                    break;
                case CommandCmdDef.UiIndex.UI_SET_BEANHOPPER:
                    is_machineset_visible = true;
                    is_beandetail_visible = true;
                    break;
                case CommandCmdDef.UiIndex.UI_SET_VALVE:
                    is_machineset_visible = true;
                    is_valvedetail_visible = true;
                    break;
                case CommandCmdDef.UiIndex.UI_RCP_DETAIL:
                    is_Recipe_visible = true;
                    is_recipedetail_visible = true;
                    break;
                case CommandCmdDef.UiIndex.UI_RCP_LIST:
                    is_Recipe_visible = true;
                    is_recipelist_visible = true;
                    break;
                case CommandCmdDef.UiIndex.UI_ING_LIST:
                    is_Recipe_visible = true;
                    is_ingredientlist_visible = true;
                    break;
                case CommandCmdDef.UiIndex.UI_ING_DETAIL:
                    is_Recipe_visible = true;
                    is_ingredientdetail_visible = true;
                    break;
                case CommandCmdDef.UiIndex.UI_UPDATE:
                    is_Update_visible = true;
                    break;
                case CommandCmdDef.UiIndex.UI_MainSelect:
                    is_mainselect_visible = true;
                    break;
                case CommandCmdDef.UiIndex.UI_MachineSet:
                    is_machineset_visible = true;
                    Console.WriteLine("test info: is_machineset_visible =" + is_machineset_visible.ToString());

                    break;
                case CommandCmdDef.UiIndex.UI_MachineTest:
                    is_machinetest_visible = true;
                    break;
                case CommandCmdDef.UiIndex.UI_COM_SET:
                    break;
                case CommandCmdDef.UiIndex.UI_RECIPESYS:

                    is_Recipe_visible = true;
                    break;
                case CommandCmdDef.UiIndex.UI_CLEANSYS:
                    is_Clean_visible = true;
                    break;
                case CommandCmdDef.UiIndex.UI_DB:
                    is_DB_visible = true;
                    break;
                default:
                    break;
            }
        }

        public void HideUiVisble(CommandCmdDef.UiIndex a)
        {
            switch (a)
            {
                case CommandCmdDef.UiIndex.UI_MainSelect:
                    break;
                case CommandCmdDef.UiIndex.UI_MachineSet:
                    break;
                case CommandCmdDef.UiIndex.UI_MachineTest:
                    break;
                case CommandCmdDef.UiIndex.UI_RECIPESYS:
                    break;
                case CommandCmdDef.UiIndex.UI_CLEANSYS:
                    break;
                case CommandCmdDef.UiIndex.UI_DB:
                    break;
                case CommandCmdDef.UiIndex.UI_STCHECK:
                    break;
                case CommandCmdDef.UiIndex.UI_UPDATE:
                    break;
                case CommandCmdDef.UiIndex.UI_ING_DETAIL:
                    break;
                case CommandCmdDef.UiIndex.UI_ING_LIST:
                    break;
                case CommandCmdDef.UiIndex.UI_RCP_LIST:
                    break;
                case CommandCmdDef.UiIndex.UI_RCP_DETAIL:
                    break;
                case CommandCmdDef.UiIndex.UI_SET_VALVE:
                    is_valvedetail_visible = false;
                    break;
                case CommandCmdDef.UiIndex.UI_SET_CANISTER:
                    is_canisterdetail_visible = false; ;
                    break;
                case CommandCmdDef.UiIndex.UI_COM_SET:
                    break;
                case CommandCmdDef.UiIndex.UI_SET_BEANHOPPER:
                    is_beandetail_visible = false;
                    break;
                case CommandCmdDef.UiIndex.UI_SET_MIXER:
                    is_mixerdetail_visible = false;

                    break;
                default:
                    break;
            }
        }
    }
   public class MachineInfo : NotificationObject
   {
       private MachineState _machinestate;
       public MachineState machinestate
       {
           get { return _machinestate; }
           set
           {
               if (value!= _machinestate)
               {
                   _machinestate = value; this.RaisePropertyChanged("machinestate");
               }
           }
       }

       private bool _err_clean;

       public bool Err_clean
       {
           get { return _err_clean; }
           set
           {
               if (_err_clean != value)
               {
                   _err_clean = value; this.RaisePropertyChanged("Err_clean");
               }
           }
       }

       private bool _err_soldout;

       public bool Err_soldout
       {
           get { return _err_soldout; }
           set
           {
               if (_err_soldout != value)
               {
                   _err_soldout = value; this.RaisePropertyChanged("Err_soldout");
               }
           }
       }

       private bool _err_heating;

       public bool Err_heating
       {
           get { return _err_heating; }
           set
           {
               if (_err_heating != value)
               {
                   _err_heating = value; this.RaisePropertyChanged("Err_heating");
               }
           }
       }

       private bool _err_cooling;

       public bool Err_cooling
       {
           get { return _err_cooling; }
           set
           {
               if (_err_cooling != value)
               {
                   _err_cooling = value; this.RaisePropertyChanged("Err_cooling");
               }
           }
       }

       private bool _err_water;

       public bool Err_water
       {
           get { return _err_water; }
           set
           {
               if (_err_water != value)
               {
                   _err_water = value; this.RaisePropertyChanged("Err_water");
               }
           }
       }

       private float _temp_fridge;
       public float Temp_fridge
       {
           get { return _temp_fridge; }
           set
           {
               if (_temp_fridge != value)
               {
                   _temp_fridge = value; this.RaisePropertyChanged("Temp_fridge");
               }
           }
       }

       private float _temp_water;
       public float Temp_water
       {
           get { return _temp_water; }
           set
           {
               if (_temp_water != value)
               {
                   _temp_water = value; this.RaisePropertyChanged("Temp_water");
               }
           }
       }

       private float _temp_fan;
       public float Temp_fan
       {
           get { return _temp_fan; }
           set
           {
               if (_temp_fan != value)
               {
                   _temp_fan = value; this.RaisePropertyChanged("Temp_fan");
               }
           }
       }

       private bool _exist_door;
       public bool Exist_door
       {
           get { return _exist_door; }
           set
           {
               if (_exist_door != value)
               {
                   _exist_door = value; this.RaisePropertyChanged("Exist_door");
               }
           }
       }

       private bool _exist_dripswitch;
       public bool Exist_dripswitch
       {
           get { return _exist_dripswitch; }
           set
           {
               if (_exist_dripswitch != value)
               {
                   _exist_dripswitch = value; this.RaisePropertyChanged("Exist_dripswitch");
               }
           }
       }

       private bool _exist_driplevel;
       public bool Exist_driplevel
       {
           get { return _exist_driplevel; }
           set
           {
               if (_exist_driplevel != value)
               {
                   _exist_driplevel = value; this.RaisePropertyChanged("Exist_driplevel");
               }
           }
       }

       private bool _exist_cup1;
       public bool Exist_cup1
       {
           get { return _exist_cup1; }
           set
           {
               if (_exist_cup1 != value)
               {
                   _exist_cup1 = value; this.RaisePropertyChanged("Exist_cup1");
               }
           }
       }

       private bool _exist_cup2;
       public bool Exist_cup2
       {
           get { return _exist_cup2; }
           set
           {
               if (_exist_cup2 != value)
               {
                   _exist_cup2 = value; this.RaisePropertyChanged("Exist_cup2");
               }
           }
       }
        private bool _waterlevel_low;
        public bool Waterlevel_low
        {
            get { return _waterlevel_low; }
            set
            {
                if (_waterlevel_low != value)
                {
                    _waterlevel_low = value; this.RaisePropertyChanged("Waterlevel_low");
                }
            }
        }

        private bool _waterlevel_high;
        public bool Waterlevel_high
        {
            get { return _waterlevel_high; }
            set
            {
                if (_waterlevel_high != value)
                {
                    _waterlevel_high = value; this.RaisePropertyChanged("Waterlevel_high");
                }
            }
        }

        private bool _brew_sw;
        public bool Brew_sw
        {
            get { return _brew_sw; }
            set
            {
                if (_brew_sw != value)
                {
                    _brew_sw = value; this.RaisePropertyChanged("Brew_sw");
                }
            }
        }
    }
   public class MaintenanceInfo : NotificationObject
   {
       private byte _maintenanceId;

       public byte MaintenanceId
       {
           get { return _maintenanceId; }
           set { if (_maintenanceId != value) { _maintenanceId = value; this.RaisePropertyChanged("MaintenanceId"); this.RaisePropertyChanged("MaintenanceDiscription"); } }
       }
       private int _maintenanceValue;

       public int MaintenanceValue
       {
           get { return _maintenanceValue; }
           set { if (_maintenanceValue != value) { _maintenanceValue = value; this.RaisePropertyChanged("MaintenanceValue"); } }
       }
       public string MaintenanceDiscription
       {
           set { }
           get { return ""; }
       }
       private string GetMaintenanceDiscription()
       {
           string ret = "UnDefined";
           switch (_maintenanceId)
           {
               case 1:
                   break;
               default:
                   break;
           }
           return ret;
       }

   }

    public class MachineSetingInfo:NotificationObject
    {
        private string _connectst = "disconnect";

        private string _version;

        public string Version
        {
            get
            {
                return _version;
            }

            set
            {
                if (value != _version)
                {
                    _version = value;
                    this.RaisePropertyChanged("Version");

                }
            }
        }
        private DateTime _dt = new DateTime(2000, 1, 1, 0, 0, 1);

        public DateTime Dt
        {
            get
            {
                return _dt;
            }

            set
            {
                if (value!=_dt)
                {
                    _dt = value;
                    this.RaisePropertyChanged("Dt");
                } 
                
            }
        }

        private byte _ledModeIndex = 0;

        public byte LedModeIndex
        {
            get
            {
                return _ledModeIndex;
            }

            set
            {
                if (value != _ledModeIndex)
                {
                    _ledModeIndex = value;
                    this.RaisePropertyChanged("LedModeIndex");
                    
                }
            }
        }

        private byte _ledColorIndex = 0;

        public byte LedColorIndex
        {
            get
            {
                return _ledColorIndex;
            }

            set
            {
                if (value != _ledColorIndex)
                {
                    _ledColorIndex = value;
                    this.RaisePropertyChanged("LedColorIndex");
                }
            }
        }

        private byte _ledbtsIndex = 0;

        public byte LedbtsIndex
        {
            get
            {
                return _ledbtsIndex;
            }

            set
            {
                if (value != _ledbtsIndex)
                {
                    _ledbtsIndex = value;
                    this.RaisePropertyChanged("LedbtsIndex");
                }
            }
        }

        private UInt16 _temptank = 92;
        public ushort Temptank
        {
            get
            {
                return _temptank;
            }

            set
            {
                if (value!= _temptank)
                {
                    _temptank = value;
                    this.RaisePropertyChanged("Temptank");
                }
            }
        }

        private UInt16 _tempwarn = 90;
        public ushort Tempwarn
        {
            get
            {
                return _tempwarn;
            }

            set
            {
                if (value != _tempwarn)
                {
                    _tempwarn = value;
                    this.RaisePropertyChanged("Tempwarn");
                }
            }
        }

        private UInt16 _tempblock = 70;
        public ushort Tempblock
        {
            get
            {
                return _tempblock;
            }

            set
            {
                if (value != _tempblock)
                {
                    _tempblock = value;
                    this.RaisePropertyChanged("Tempblock");
                }
            }
        }

        private UInt16 _tempsave = 50;
        public ushort Tempsave
        {
            get
            {
                return _tempsave;
            }

            set
            {
                if (value != _tempsave)
                {
                    _tempsave = value;
                    this.RaisePropertyChanged("Tempsave");
                }
            }
        }

        public byte FanSpd
        {
            get
            {
                return _fanSpd;
            }

            set
            {
                if (value != _fanSpd)
                {
                    _fanSpd = value; this.RaisePropertyChanged("FanSpd");
                }
            }
        }

        public byte Fanruntm
        {
            get
            {
                return _fanruntm;
            }

            set
            {
                if (value != _fanruntm)
                {
                    _fanruntm = value; this.RaisePropertyChanged("Fanruntm");
                }
            }
        }

        public byte Fanconflag
        {
            get
            {
                return _fanconflag;
            }

            set
            {
                _fanconflag = value; this.RaisePropertyChanged("Fanconflag");
                this.RaisePropertyChanged("IsFanContinous");
            }
        }

        private bool _isFanContinous;
        public bool IsFanContinous {
            set {
                if (value!= _isFanContinous)
                {
                    _isFanContinous = value;
                    Fanconflag = (byte)(_isFanContinous == true ? 1 : 0xff);

                }
            }
            get
            {
                if (_fanconflag == 0xff)
                {
                    _isFanContinous = false;
                }
                else { _isFanContinous = true; }
                return _isFanContinous;
            }
        }

        public string Connectst
        {
            get
            {
                return _connectst;
            }

            set
            {
                if (value != _connectst)
                {
                    _connectst = value;
                    this.RaisePropertyChanged("Connectst");
                }

            }
        
        }

        private byte _fanSpd = 100;
        private byte _fanruntm = 20;
        private byte _fanconflag = 1;
    }

    public class TimeSt
    {
        private byte _setover;
        public int year { get; set; }
        public int month { get; set; }
        public int day { get; set; }
        public int hour { get; set; }
        public int mintue { get; set; }
        public int second { get; set; }
        public TimeSt()
        { _setover = 0; }
        public byte Setover
        {
            get
            {
                return _setover;
            }

            set
            {
                _setover = value;
            }
        }
        public override string ToString()
        {
            return year.ToString() + "/" + month.ToString() + "/" + day.ToString() + " " + hour.ToString() + ":" + mintue.ToString() + ":" + second.ToString();
        }
    }
}
