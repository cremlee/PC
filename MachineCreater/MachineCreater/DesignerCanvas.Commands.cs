using System;
using System.Collections;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Xml;
using System.Xml.Linq;
using Microsoft.Win32;
using MachineCreater.model;
using System.Text;

namespace MachineCreater
{
    public partial class DesignerCanvas
    {
        public static RoutedCommand Group = new RoutedCommand();
        public static RoutedCommand Ungroup = new RoutedCommand();
        public static RoutedCommand BringForward = new RoutedCommand();
        public static RoutedCommand BringToFront = new RoutedCommand();
        public static RoutedCommand SendBackward = new RoutedCommand();
        public static RoutedCommand SendToBack = new RoutedCommand();
        public static RoutedCommand AlignTop = new RoutedCommand();
        public static RoutedCommand AlignVerticalCenters = new RoutedCommand();
        public static RoutedCommand AlignBottom = new RoutedCommand();
        public static RoutedCommand AlignLeft = new RoutedCommand();
        public static RoutedCommand AlignHorizontalCenters = new RoutedCommand();
        public static RoutedCommand AlignRight = new RoutedCommand();
        public static RoutedCommand DistributeHorizontal = new RoutedCommand();
        public static RoutedCommand DistributeVertical = new RoutedCommand();
        public static RoutedCommand SelectAll = new RoutedCommand();

        public DesignerCanvas()
        {
            this.CommandBindings.Add(new CommandBinding(ApplicationCommands.New, New_Executed));
            this.CommandBindings.Add(new CommandBinding(ApplicationCommands.Open, Open_Executed));
            this.CommandBindings.Add(new CommandBinding(ApplicationCommands.Save, Save_Executed));
            this.CommandBindings.Add(new CommandBinding(ApplicationCommands.Print, Print_Executed));
            this.CommandBindings.Add(new CommandBinding(ApplicationCommands.Cut, Cut_Executed, Cut_Enabled));
            this.CommandBindings.Add(new CommandBinding(ApplicationCommands.Copy, Copy_Executed, Copy_Enabled));
            this.CommandBindings.Add(new CommandBinding(ApplicationCommands.Paste, Paste_Executed, Paste_Enabled));
            this.CommandBindings.Add(new CommandBinding(ApplicationCommands.Delete, Delete_Executed, Delete_Enabled));
            this.CommandBindings.Add(new CommandBinding(DesignerCanvas.Group, Group_Executed, Group_Enabled));
            this.CommandBindings.Add(new CommandBinding(DesignerCanvas.Ungroup, Ungroup_Executed, Ungroup_Enabled));
            this.CommandBindings.Add(new CommandBinding(DesignerCanvas.BringForward, BringForward_Executed, Order_Enabled));
            this.CommandBindings.Add(new CommandBinding(DesignerCanvas.BringToFront, BringToFront_Executed, Order_Enabled));
            this.CommandBindings.Add(new CommandBinding(DesignerCanvas.SendBackward, SendBackward_Executed, Order_Enabled));
            this.CommandBindings.Add(new CommandBinding(DesignerCanvas.SendToBack, SendToBack_Executed, Order_Enabled));
            this.CommandBindings.Add(new CommandBinding(DesignerCanvas.AlignTop, AlignTop_Executed, Align_Enabled));
            this.CommandBindings.Add(new CommandBinding(DesignerCanvas.AlignVerticalCenters, AlignVerticalCenters_Executed, Align_Enabled));
            this.CommandBindings.Add(new CommandBinding(DesignerCanvas.AlignBottom, AlignBottom_Executed, Align_Enabled));
            this.CommandBindings.Add(new CommandBinding(DesignerCanvas.AlignLeft, AlignLeft_Executed, Align_Enabled));
            this.CommandBindings.Add(new CommandBinding(DesignerCanvas.AlignHorizontalCenters, AlignHorizontalCenters_Executed, Align_Enabled));
            this.CommandBindings.Add(new CommandBinding(DesignerCanvas.AlignRight, AlignRight_Executed, Align_Enabled));
            this.CommandBindings.Add(new CommandBinding(DesignerCanvas.DistributeHorizontal, DistributeHorizontal_Executed, Distribute_Enabled));
            this.CommandBindings.Add(new CommandBinding(DesignerCanvas.DistributeVertical, DistributeVertical_Executed, Distribute_Enabled));
            this.CommandBindings.Add(new CommandBinding(DesignerCanvas.SelectAll, SelectAll_Executed));
            SelectAll.InputGestures.Add(new KeyGesture(Key.A, ModifierKeys.Control));

            this.AllowDrop = true;
            Clipboard.Clear();
        }




        public enum DeviceType
        {
            DEV_Init    = 0xffff,
            DEV_BREWER  = 0x0001,
            DEV_GRINDER = 0x0002,
            DEV_CANISTER = 0x0003,
            DEV_MIXER    = 0x0004,
            DEV_FLOW_METER    = 0x0005,
            DEV_NTC    = 0x0006,
            DEV_WATER_LEVEL   = 0x0007,
            DEV_PUMP = 0x000a,
            DEV_BOILER   = 0x000f,
            DEV_FAN     = 0x0014,
            DEV_HOPPER  = 0x0015,
            DEV_CUP     =0x0008,
            DEV_LED     =0x000c,
            DEV_DRIP    =0x0018,
            DEV_WASTER  =0x0019,
            DEV_DOOR    =0x001a,
            DEV_VIRMACHINE = 0xf001
        }


        private SortedList<Guid, DesignerItem> _machineDevicelist = new SortedList<Guid, DesignerItem>(5);

        private List<int> GrinderPositionIDList = new List<int>() { 1, 2 };

        private List<int> HopperPositionIDList = new List<int>() { 1, 2, 3 };

        private List<int> BrewerPositionIDList = new List<int>() { 1, 2, 3 };

        private List<int> FanPositionIDList = new List<int>() { 1, 2, 3, 4, 5 };

        private List<int> CanisterPositionIDList = new List<int>() { 1, 2, 3, 4 };

        private List<int> MixerPositionIDList = new List<int>() { 1, 2 };

        private List<int> BoilerPositionIDList = new List<int>() { 1 };

        private List<int> NtcPositionIDList = new List<int>() { 1 };

        private List<int> WaterLevelPositionIDList = new List<int>() { 1 };

        private List<int> CupSensorPositionIDList = new List<int>() { 1,2 };
        private List<int> LEDPositionIDList = new List<int>() { 1 };
        private List<int> DriptrayPositionIDList = new List<int>() { 1 };
        private List<int> WasterbinPositionIDList = new List<int>() { 1 };
        private List<int> DoorSensorPositionIDList = new List<int>() { 1 };


        private List<int> VirMachineSensorPositionIDList = new List<int>() { 1 };
        private List<int> waterpumpPositionIDList = new List<int>() { 1,2 };

        public bool isValid(DeviceType a)
        {
            bool ret = false;
            switch (a)
            {
                case DeviceType.DEV_PUMP:
                    ret = waterpumpPositionIDList.Count > 0 ? true : false;
                    break;
                case DeviceType.DEV_VIRMACHINE:
                    ret = VirMachineSensorPositionIDList.Count > 0 ? true : false;
                    break;
                case DeviceType.DEV_CUP:
                    ret = CupSensorPositionIDList.Count > 0 ? true : false;
                    break;
                case DeviceType.DEV_LED:
                    ret = LEDPositionIDList.Count > 0 ? true : false;
                    break;
                case DeviceType.DEV_DRIP:
                    ret = DriptrayPositionIDList.Count > 0 ? true : false;
                    break;
                case DeviceType.DEV_WASTER:
                    ret = WasterbinPositionIDList.Count > 0 ? true : false;
                    break;
                case DeviceType.DEV_DOOR:
                    ret = DoorSensorPositionIDList.Count > 0 ? true : false;
                    break;
                case DeviceType.DEV_NTC:
                    ret = NtcPositionIDList.Count > 0 ? true : false;
                    break;
                case DeviceType.DEV_WATER_LEVEL:
                    ret = WaterLevelPositionIDList.Count > 0 ? true : false;
                    break;
                case DeviceType.DEV_BOILER:
                    ret = BoilerPositionIDList.Count > 0 ? true : false;
                    break;
                case DeviceType.DEV_Init:
                    ret = true;
                    break;
                case DeviceType.DEV_BREWER:
                    ret = BrewerPositionIDList.Count > 0 ? true : false;
                    break;
                case DeviceType.DEV_GRINDER:
                    ret = GrinderPositionIDList.Count > 0 ? true : false;
                    break;
                case DeviceType.DEV_CANISTER:
                    ret = CanisterPositionIDList.Count > 0 ? true : false;
                    break;
                case DeviceType.DEV_MIXER:
                    ret = MixerPositionIDList.Count > 0 ? true : false;
                    break;
                case DeviceType.DEV_FAN:
                    ret = FanPositionIDList.Count > 0 ? true : false;
                    break;
                case DeviceType.DEV_HOPPER:
                    ret = HopperPositionIDList.Count > 0 ? true : false;
                    break;
                default:
                    break;
            }
            return ret;
        }


        public int GetPositionID(DeviceType a)
        {
            int ret = -1;
            switch (a)
            {
                case DeviceType.DEV_PUMP:
                    if (waterpumpPositionIDList.Count > 0)
                    {
                        ret = waterpumpPositionIDList[0];
                        waterpumpPositionIDList.RemoveAt(0);
                    }
                    break;
                case DeviceType.DEV_VIRMACHINE:
                    if (VirMachineSensorPositionIDList.Count > 0)
                    {
                        ret = VirMachineSensorPositionIDList[0];
                        VirMachineSensorPositionIDList.RemoveAt(0);
                    }
                    break;
                case DeviceType.DEV_CUP:
                    if (CupSensorPositionIDList.Count > 0)
                    {
                        ret = CupSensorPositionIDList[0];
                        CupSensorPositionIDList.RemoveAt(0);
                    }
                    break;
                case DeviceType.DEV_LED:
                    if (LEDPositionIDList.Count > 0)
                    {
                        ret = LEDPositionIDList[0];
                        LEDPositionIDList.RemoveAt(0);
                    }
                    break;
                case DeviceType.DEV_DRIP:
                    if (DriptrayPositionIDList.Count > 0)
                    {
                        ret = DriptrayPositionIDList[0];
                        DriptrayPositionIDList.RemoveAt(0);
                    }
                    break;
                case DeviceType.DEV_WASTER:
                    if (WasterbinPositionIDList.Count > 0)
                    {
                        ret = WasterbinPositionIDList[0];
                        WasterbinPositionIDList.RemoveAt(0);
                    }
                    break;
                case DeviceType.DEV_DOOR:
                    if (DoorSensorPositionIDList.Count > 0)
                    {
                        ret = DoorSensorPositionIDList[0];
                        DoorSensorPositionIDList.RemoveAt(0);
                    }
                    break;
                case DeviceType.DEV_NTC:
                    if (NtcPositionIDList.Count > 0)
                    {
                        ret = NtcPositionIDList[0];
                        NtcPositionIDList.RemoveAt(0);
                    }                    
                    break;
                case DeviceType.DEV_WATER_LEVEL:
                    if (WaterLevelPositionIDList.Count > 0)
                    {
                        ret = WaterLevelPositionIDList[0];
                        WaterLevelPositionIDList.RemoveAt(0);
                    }
                    break;
                case DeviceType.DEV_BOILER:
                    if (BoilerPositionIDList.Count > 0)
                    {
                        ret = BoilerPositionIDList[0];
                        BoilerPositionIDList.RemoveAt(0);
                    }
                    break;
                case DeviceType.DEV_MIXER:
                    if (MixerPositionIDList.Count > 0)
                    {
                        ret = MixerPositionIDList[0];
                        MixerPositionIDList.RemoveAt(0);
                    }
                    break;
                case DeviceType.DEV_CANISTER:
                    if (CanisterPositionIDList.Count > 0)
                    {
                        ret = CanisterPositionIDList[0];
                        CanisterPositionIDList.RemoveAt(0);
                    }
                    break;
                case DeviceType.DEV_BREWER:
                    if (BrewerPositionIDList.Count > 0)
                    {
                        ret = BrewerPositionIDList[0];
                        BrewerPositionIDList.RemoveAt(0);
                    }
                    break;
                case DeviceType.DEV_GRINDER:
                    if(GrinderPositionIDList.Count>0)
                    {
                        ret = GrinderPositionIDList[0];
                        GrinderPositionIDList.RemoveAt(0);
                    }
                    break;
                case DeviceType.DEV_HOPPER:
                    if (HopperPositionIDList.Count > 0)
                    {
                        ret = HopperPositionIDList[0];
                        HopperPositionIDList.RemoveAt(0);
                    }
                    break;
                case DeviceType.DEV_FAN:
                    if (FanPositionIDList.Count > 0)
                    {
                        ret = FanPositionIDList[0];
                        FanPositionIDList.RemoveAt(0);
                    }
                    break;
                default:
                    break;
            }
            return ret;
        }

        public void ReleasePositionID(int id, DeviceType a)
        {
            switch (a)
            {
                case DeviceType.DEV_PUMP:                 
                    waterpumpPositionIDList.Add(id);
                    waterpumpPositionIDList.Sort();
                    break;
                case DeviceType.DEV_VIRMACHINE:                   
                    VirMachineSensorPositionIDList.Add(id);
                    VirMachineSensorPositionIDList.Sort();
                    break;
                case DeviceType.DEV_CUP:
                    CupSensorPositionIDList.Add(id);
                    CupSensorPositionIDList.Sort();
                    break;
                case DeviceType.DEV_LED:
                    LEDPositionIDList.Add(id);
                    LEDPositionIDList.Sort();
                    break;
                case DeviceType.DEV_DRIP:
                    DriptrayPositionIDList.Add(id);
                    DriptrayPositionIDList.Sort();
                    break;
                case DeviceType.DEV_WASTER:
                    WasterbinPositionIDList.Add(id);
                    WasterbinPositionIDList.Sort();
                    break;
                case DeviceType.DEV_DOOR:
                    DoorSensorPositionIDList.Add(id);
                    DoorSensorPositionIDList.Sort();
                    break;
                case DeviceType.DEV_NTC:                    
                    NtcPositionIDList.Add(id);
                    NtcPositionIDList.Sort();
                    break;
                case DeviceType.DEV_WATER_LEVEL:                    
                    WaterLevelPositionIDList.Add(id);
                    WaterLevelPositionIDList.Sort();
                    break;
                case DeviceType.DEV_BOILER:
                    BoilerPositionIDList.Add(id);
                    BoilerPositionIDList.Sort();
                    break;
                case DeviceType.DEV_MIXER:
                    MixerPositionIDList.Add(id);
                    MixerPositionIDList.Sort();
                    break;
                case DeviceType.DEV_CANISTER:
                    CanisterPositionIDList.Add(id);
                    CanisterPositionIDList.Sort();
                    break;
                case DeviceType.DEV_BREWER:
                    BrewerPositionIDList.Add(id);
                    BrewerPositionIDList.Sort();
                    break;
                case DeviceType.DEV_GRINDER:
                    GrinderPositionIDList.Add(id);
                    GrinderPositionIDList.Sort();
                    break;
                case DeviceType.DEV_HOPPER:
                    HopperPositionIDList.Add(id);
                    HopperPositionIDList.Sort();
                    break;
                case DeviceType.DEV_FAN:
                    FanPositionIDList.Add(id);
                    FanPositionIDList.Sort();
                    break;
                default:
                    break;
            }
            
        }



        private List<Device> SaveallDeviceConfig(IEnumerable<DesignerItem> designerItems, IEnumerable<Connection> connections)
        {
            List<Device> devices = new List<Device>(10);
            foreach (var item in designerItems)
            {
                if (item.main_Device != null)
                {
                    item.main_Device.parent_id_list.Clear();
                    item.main_Device.son_id_list.Clear();

                    //todo boiler system de teshu chuli 

                    if (item.main_Device.Group_id == 0x000f) // this is boiler
                    {
                        if (item.attach_Device_list.Count > 0)  // find the son
                        {

                            foreach (var attachitem in item.attach_Device_list)
                            {
                                attachitem.son_id_list.Clear();
                                //item.main_Device.parent_id_list.Add(attachitem.DeviceID);
                                //attachitem.son_id_list.Add(item.main_Device.DeviceID);
                                if(attachitem.Group_id == 0x0007) //water level
                                {
                                    item.main_Device.parent_id_list.Add(attachitem.DeviceID);
                                    attachitem.son_id_list.Add(item.main_Device.DeviceID);
                                }
                                else if(attachitem.Group_id ==0x0016)  //Heater
                                {
                                    var selectmany = item.attach_Device_list.Where(c => c.Group_id == 0x0006).ToList<Device>();
                                    if(selectmany!=null && selectmany.Count>0)
                                    {
                                        attachitem.parent_id_list.Clear();
                                        foreach (var ntc in selectmany)
                                        {
                                            attachitem.parent_id_list.Add(ntc.DeviceID);                                                                         
                                        }
                                    }
                                }
                                else if(attachitem.Group_id == 0x0006) //ntc
                                {
                                    attachitem.son_id_list.Clear();
                                    var heater = item.attach_Device_list.First(c => c.Group_id == 0x0016);
                                    if (heater != null)
                                        attachitem.son_id_list.Add(heater.DeviceID);
                                }
                                devices.Add(attachitem);
                            }
                        }
                    }
                    else if(item.main_Device.Group_id == 0x000a) //water pump
                    {
                        Device attachitem = item.attach_Device_list[0];
                        item.main_Device.son_id_list.Add(attachitem.DeviceID);
                        attachitem.parent_id_list.Clear();
                        attachitem.parent_id_list.Add(item.main_Device.DeviceID);
                        devices.Add(attachitem);
                    }
                    else
                    {

                        if (item.attach_Device_list.Count > 0)  //parent
                        {

                            foreach (var attachitem in item.attach_Device_list)
                            {
                                attachitem.son_id_list.Clear();
                                item.main_Device.parent_id_list.Add(attachitem.DeviceID);
                                attachitem.son_id_list.Add(item.main_Device.DeviceID);
                                devices.Add(attachitem);
                            }
                        }
                    }

                    foreach (var con in connections)
                    {
                        if (con.Sink.ParentDesignerItem.ID == item.ID)  //find parent
                        {

                            Device temp = designerItems.First(c => c.ID == con.Source.ParentDesignerItem.ID).main_Device;
                            if (temp != null)
                                item.main_Device.parent_id_list.Add(temp.DeviceID);
                        }
                        if (con.Source.ParentDesignerItem.ID == item.ID)  //find son
                        {
                            Device temp = designerItems.First(c => c.ID == con.Sink.ParentDesignerItem.ID).main_Device;
                            if (temp != null)
                                item.main_Device.son_id_list.Add(temp.DeviceID);
                        }
                    }
                    item.main_Device.ID = item.ID;
                    devices.Add(item.main_Device);
                }

            }
            Console.WriteLine("devices.Count=" + devices.Count);
            return devices;
        }

        private void SerializeDevice(List<Device> devices,string filename)
        {
            //var serializedConnections = new XElement("Devices",
            //               from item in devices
            //               where item.Group_id ==1
            //               select new XElement("Devices",
            //                          new XElement("DeviceID", item.DeviceID.ToString("X8")),
            //                          new XElement("ParentCount", item.parent_id_list.Count),                                      
            //                          new XElement("SonCount", item.son_id_list.Count)                                     
            //                         )
            //                      );

            //return serializedConnections;
            XmlDocument doc = new XmlDocument();
            doc.CreateXmlDeclaration("1.0", "utf-8", "yes");
            XmlElement root = doc.CreateElement("Device_Map");
            doc.AppendChild(root);
            if (devices!=null && (devices.Count>0))
            {
                foreach (var item in devices)
                {
                    XmlElement xmlItem = doc.CreateElement("Device");
                    xmlItem.SetAttribute("GUID", item.ID.ToString());
                    xmlItem.SetAttribute("ID", item.DeviceID.ToString("X8"));
                    if (item.Group_id == 0x0000)
                    {
                        if (item.Compent_type == 0) //valve
                        { }
                        else if (item.Compent_type == 1) //end
                        { }
                        else if (item.Compent_type == 2) //waiwei
                        {
                            xmlItem.SetAttribute("Name", "Machine");
                        }
                    }
                    else if (item.Group_id == 0x0001)
                    {
                        if (item.Compent_type == 1)
                            xmlItem.SetAttribute("Name", "ES-Brewer");
                        else if(item.Compent_type == 2)
                            xmlItem.SetAttribute("Name", "Mono-Brewer");
                        
                        xmlItem.SetAttribute("Max_Capability",(item as Dev_ES).Max_capability.ToString());
                        xmlItem.SetAttribute("Flow_Meter", (item as Dev_ES).Inlet_flow.ToString());
                        xmlItem.SetAttribute("Life_Motor", (item as Dev_ES).Life_brewer_motor.ToString());
                        xmlItem.SetAttribute("Life_Valve", (item as Dev_ES).Life_inlet_valve.ToString());                       
                    }
                    else if(item.Group_id == 0x0002)
                    {
                        xmlItem.SetAttribute("Name", "Grinder");
                        xmlItem.SetAttribute("Life_Motor", (item as Dev_Grinder).Motor_life.ToString());
                        xmlItem.SetAttribute("Dosage_Value", (item as Dev_Grinder).Dosage_value.ToString());
                    }
                    else if (item.Group_id == 0x0003)
                    {
                        xmlItem.SetAttribute("Name", "Canister");
                        xmlItem.SetAttribute("Life_Motor", (item as Dev_Canister).Motor_life.ToString());
                        xmlItem.SetAttribute("Type", (item as Dev_Canister).Compent_type.ToString());
                        xmlItem.SetAttribute("Dosage_Value", (item as Dev_Canister).Dosage_value.ToString());
                        xmlItem.SetAttribute("Powder", (item as Dev_Canister).Powder_type.ToString());
                        xmlItem.SetAttribute("Max_Capability", (item as Dev_Canister).Max_capability.ToString());
                    }
                    else if (item.Group_id == 0x0004)
                    {
                        xmlItem.SetAttribute("Name", "Mixer");
                        xmlItem.SetAttribute("Max_Capability", (item as Dev_Mixer_L).Max_capability.ToString());
                        xmlItem.SetAttribute("Speed", (item as Dev_Mixer_L).Run_speed.ToString());
                        xmlItem.SetAttribute("Hot_flow", (item as Dev_Mixer_L).Hot_valve_flow.ToString());
                        xmlItem.SetAttribute("Cold_flow", (item as Dev_Mixer_L).Cold_valve_flow.ToString());
                        xmlItem.SetAttribute("Life_Motor", (item as Dev_Mixer_L).Life_motor.ToString());
                        xmlItem.SetAttribute("Life_hot_valve", (item as Dev_Mixer_L).Life_hot_valve.ToString());
                        xmlItem.SetAttribute("Life_cold_valve", (item as Dev_Mixer_L).Life_cold_valve.ToString());
                        xmlItem.SetAttribute("Life_whipper", (item as Dev_Mixer_L).Life_whipper.ToString());                       
                    }
                    else if (item.Group_id == 0x0005)
                    {
                        xmlItem.SetAttribute("Name", "Flowmeter");
                        xmlItem.SetAttribute("Pluse", (item as DEV_Flowmeter).Pluse.ToString());
                    }
                    else if (item.Group_id == 0x0006)
                    {
                        xmlItem.SetAttribute("Name", "NTC");
                        xmlItem.SetAttribute("Type", (item as Dev_SenNtc).Compent_type.ToString());
                        xmlItem.SetAttribute("Life_Sensor", (item as Dev_SenNtc).Life_sensor.ToString());
                        xmlItem.SetAttribute("Normal", (item as Dev_SenNtc).Temperature_normal.ToString());
                        xmlItem.SetAttribute("Warn", (item as Dev_SenNtc).Temperature_warning.ToString());
                        xmlItem.SetAttribute("Block", (item as Dev_SenNtc).Temperature_block.ToString());
                        xmlItem.SetAttribute("ECO", (item as Dev_SenNtc).Temperature_eco.ToString());
                        xmlItem.SetAttribute("Offset", (item as Dev_SenNtc).Temperature_offset.ToString());
                    }
                    else if (item.Group_id == 0x0007)
                    {
                        xmlItem.SetAttribute("Name", "Water_level");
                        xmlItem.SetAttribute("Type", (item as Dev_SenWater).Compent_type.ToString());
                        xmlItem.SetAttribute("Life_Sensor", (item as Dev_SenWater).Life_sensor.ToString());
                    }
                    else if (item.Group_id == 0x0008)
                    {
                        xmlItem.SetAttribute("Name", "Cup_sensor");
                        xmlItem.SetAttribute("Life_Sensor", (item as Dev_SenCup).Life_sensor.ToString());

                    }
                    else if (item.Group_id == 0x0009)
                    {
                        xmlItem.SetAttribute("Name", "Pressure_sensor");
                        xmlItem.SetAttribute("Type", (item as Dev_SenPressuer).Compent_type.ToString());
                        xmlItem.SetAttribute("Life_Sensor", (item as Dev_SenPressuer).Life_sensor.ToString());

                    }
                    else if (item.Group_id == 0x000a)
                    {
                        xmlItem.SetAttribute("Name", "Waterpump");
                        xmlItem.SetAttribute("Type", (item as DEV_Waterpump).Compent_type.ToString());
                        xmlItem.SetAttribute("Speed", (item as DEV_Waterpump).Speed.ToString());
                        xmlItem.SetAttribute("Motor_life", (item as DEV_Waterpump).Motor_life.ToString());

                    }
                    else if (item.Group_id == 0x000c)
                    {
                        xmlItem.SetAttribute("Name", "LED");
                        xmlItem.SetAttribute("Type", (item as Dev_Led).Compent_type.ToString());
                        xmlItem.SetAttribute("IdleMode", (item as Dev_Led).Led_idel_mode.ToString());
                        xmlItem.SetAttribute("IdleColor", (item as Dev_Led).Led_idel_color.ToString());
                        xmlItem.SetAttribute("IdleInt", (item as Dev_Led).Led_idel_intensity.ToString());
                        xmlItem.SetAttribute("WarnMode", (item as Dev_Led).Led_warn_mode.ToString());
                        xmlItem.SetAttribute("WarnColor", (item as Dev_Led).Led_warn_color.ToString());
                        xmlItem.SetAttribute("WarnInt", (item as Dev_Led).Led_warn_intensity.ToString());
                        xmlItem.SetAttribute("LedLife", (item as Dev_Led).Life_led.ToString());

                    }
                    else if (item.Group_id == 0x000e)
                    {
                        xmlItem.SetAttribute("Name", "Airbreak");                    

                    }
                    else if (item.Group_id == 0x0018)
                    {
                        xmlItem.SetAttribute("Name", "Drip_tray");
                        xmlItem.SetAttribute("Max_Capability", (item as Dev_SenDriptray).Max_capability.ToString());
                        xmlItem.SetAttribute("Life_Sensor", (item as Dev_SenDriptray).Life_sensor.ToString());
                    }
                    else if (item.Group_id == 0x0019)
                    {
                        xmlItem.SetAttribute("Name", "Waster_bin");
                        xmlItem.SetAttribute("Max_Capability", (item as Dev_SenWaster).Max_capability.ToString());
                        xmlItem.SetAttribute("Life_Sensor", (item as Dev_SenWaster).Life_sensor.ToString());
                    }
                    else if (item.Group_id == 0x001a)
                    {
                        xmlItem.SetAttribute("Name", "Door");
                        //xmlItem.SetAttribute("Life_Sensor", (item as Dev_SenCup).Life_sensor.ToString());
                        xmlItem.SetAttribute("Life_Sensor", (item as Dev_SenDoor).Life_sensor.ToString());
                    }
                    else if (item.Group_id == 0x000f)
                    {
                        if (item.Compent_type == 3)
                            xmlItem.SetAttribute("Name", "ES-Boiler");
                        else if (item.Compent_type == 2)
                            xmlItem.SetAttribute("Name", "Gravity-Boiler");                        
                        xmlItem.SetAttribute("Max_Capability", (item as Boiler).Max_capability.ToString());
                        xmlItem.SetAttribute("Water", (item as Boiler).Inlet_water_type.ToString());
                        xmlItem.SetAttribute("Life_inlet_valve", (item as Boiler).Life_intlet_valve.ToString());
                        xmlItem.SetAttribute("Clean_cycle", (item as Boiler).Cycle_boiler_clean.ToString());
                    }
                    else if (item.Group_id == 0x0014)
                    {
                        xmlItem.SetAttribute("Name", "Fan");
                        xmlItem.SetAttribute("Life_Motor", (item as Dev_Fan).Life_motor.ToString());
                        xmlItem.SetAttribute("Speed", (item as Dev_Fan).Run_speed.ToString());
                    }
                    else if(item.Group_id == 0x0015)
                    {
                        xmlItem.SetAttribute("Name", "Hopper");
                        xmlItem.SetAttribute("Powder", (item as Dev_Hopper).Powder_type.ToString());
                        xmlItem.SetAttribute("Life_Motor", (item as Dev_Hopper).Motor_life.ToString());
                        xmlItem.SetAttribute("Max_Capability", (item as Dev_Hopper).Max_capability.ToString());
                    }
                    else if (item.Group_id == 0x0016) //heater
                    {
                        xmlItem.SetAttribute("Name", "Heater");
                        xmlItem.SetAttribute("Max_heat_time", (item as DEV_Heater).Max_heat_time.ToString());
                        xmlItem.SetAttribute("Life_times", (item as DEV_Heater).Life_times.ToString());
                    }
                    ////////////////////////tong yong bu feng////////////////////////////////
                    XmlElement parentitem = doc.CreateElement("Parents");
                    parentitem.SetAttribute("Count", item.parent_id_list.Count.ToString());

                    xmlItem.AppendChild(parentitem);

                    for (int i = 0; i < item.parent_id_list.Count; i++)
                    {
                        XmlElement parent = doc.CreateElement("Parent");
                        parent.SetAttribute("ID", item.parent_id_list[i].ToString("X8"));
                        parentitem.AppendChild(parent);
                    }
                    XmlElement sonitem = doc.CreateElement("Sons");
                    sonitem.SetAttribute("Count", item.son_id_list.Count.ToString());
                    xmlItem.AppendChild(sonitem);
                    for (int i = 0; i < item.son_id_list.Count; i++)
                    {
                        XmlElement son = doc.CreateElement("Son");
                        son.SetAttribute("ID", item.son_id_list[i].ToString("X8"));
                        sonitem.AppendChild(son);
                    }
                    root.AppendChild(xmlItem);
                }
                doc.Save(filename);
               
            }
        }

        private void CreateCheckFile(String devicepath,String layoutpath)
        {
            String deviceMdvalue = GetMD5HashFromFile(devicepath);
            String layoutMdvalue = GetMD5HashFromFile(layoutpath);
            FileInfo fi = new FileInfo(devicepath);
            String filename = fi.Name;
            fi = new FileInfo(layoutpath);
            String filename1 = fi.Name;
            XmlDocument doc = new XmlDocument();
            doc.CreateXmlDeclaration("1.0", "utf-8", "yes");
            XmlElement root = doc.CreateElement("machine");
            doc.AppendChild(root);
            XmlElement xmlItem = doc.CreateElement("Device");              
            XmlElement xmlname = doc.CreateElement("Name");
            xmlname.InnerXml = filename;       
            XmlElement xmlmd = doc.CreateElement("Check");
            xmlmd.InnerXml = deviceMdvalue;
            xmlItem.AppendChild(xmlname);
            xmlItem.AppendChild(xmlmd);  
            root.AppendChild(xmlItem);
            xmlItem = doc.CreateElement("Layout");
            xmlname = doc.CreateElement("Name");
            xmlname.InnerXml = filename1;
            xmlmd = doc.CreateElement("Check");
            xmlmd.InnerXml = layoutMdvalue;
            xmlItem.AppendChild(xmlname);
            xmlItem.AppendChild(xmlmd);
            root.AppendChild(xmlItem);
            doc.Save(fi.DirectoryName + "\\config.chk");

        }

        private static string GetMD5HashFromFile(string fileName)
        {
            try
            {
                FileStream file = new FileStream(fileName, FileMode.Open);
                System.Security.Cryptography.MD5 md5 = new System.Security.Cryptography.MD5CryptoServiceProvider();
                byte[] retVal = md5.ComputeHash(file);
                file.Close();

                System.Text.StringBuilder sb = new StringBuilder();
                for (int i = 0; i < retVal.Length; i++)
                {
                    sb.Append(retVal[i].ToString("x2"));
                }
                return sb.ToString();
            }
            catch (Exception ex)
            {
                throw new Exception("GetMD5HashFromFile() fail,error:" + ex.Message);
            }
        }

        #region New Command

        private void New_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            this.Children.Clear();
            this.SelectionService.ClearSelection();
        }

        #endregion

        #region Open Command

        private void Open_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            XElement[] xmls = new XElement[2];                   
                xmls = LoadSerializedDataFromFile();
            if (xmls == null)
                return;
            XElement root = xmls[0];
            XElement rootdata = xmls[1];
            if (root == null)
                return;

            this.Children.Clear();
            this.SelectionService.ClearSelection();

            IEnumerable<XElement> itemsXML = root.Elements("DesignerItems").Elements("DesignerItem");
            foreach (XElement itemXML in itemsXML)
            {
                Guid id = new Guid(itemXML.Element("ID").Value);
                DesignerItem itemtemp = DeserializeDesignerItem(itemXML, id, 0, 0);
                DesignerItem item = DeserializeDesignerItemDate(rootdata, itemtemp);

                //add
                this.Children.Add(item);
                SetConnectorDecoratorTemplate(item);
            }

            this.InvalidateVisual();

            IEnumerable<XElement> connectionsXML = root.Elements("Connections").Elements("Connection");
            foreach (XElement connectionXML in connectionsXML)
            {
                Guid sourceID = new Guid(connectionXML.Element("SourceID").Value);
                Guid sinkID = new Guid(connectionXML.Element("SinkID").Value);

                String sourceConnectorName = connectionXML.Element("SourceConnectorName").Value;
                String sinkConnectorName = connectionXML.Element("SinkConnectorName").Value;

                Connector sourceConnector = GetConnector(sourceID, sourceConnectorName);
                Connector sinkConnector = GetConnector(sinkID, sinkConnectorName);

                Connection connection = new Connection(sourceConnector, sinkConnector);
                Canvas.SetZIndex(connection, Int32.Parse(connectionXML.Element("zIndex").Value));
                this.Children.Add(connection);
            }
        }

        #endregion

        #region Save Command

        private void Save_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            IEnumerable<DesignerItem> designerItems = this.Children.OfType<DesignerItem>();
            IEnumerable<Connection> connections = this.Children.OfType<Connection>();

            XElement designerItemsXML = SerializeDesignerItems(designerItems);
            XElement connectionsXML = SerializeConnections(connections);
            // XElement devicexml = 
            XElement devicelayoutxml = SerializeDesignerItemsforapp(designerItems);

            XElement root = new XElement("Root");
            root.Add(designerItemsXML);
            root.Add(connectionsXML);
           // root.Add(devicexml);

            SaveFile(root, devicelayoutxml, SaveallDeviceConfig(designerItems, connections));
        }

        #endregion

        #region Print Command

        private void Print_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            SelectionService.ClearSelection();

            PrintDialog printDialog = new PrintDialog();

            if (true == printDialog.ShowDialog())
            {
                printDialog.PrintVisual(this, "WPF Diagram");
            }
        }

        #endregion

        #region Copy Command

        private void Copy_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            CopyCurrentSelection();
        }

        private void Copy_Enabled(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = SelectionService.CurrentSelection.Count() > 0;
        }

        #endregion

        #region Paste Command

        private void Paste_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            XElement root = LoadSerializedDataFromClipBoard();

            if (root == null)
                return;

            // create DesignerItems
            Dictionary<Guid, Guid> mappingOldToNewIDs = new Dictionary<Guid, Guid>();
            List<ISelectable> newItems = new List<ISelectable>();
            IEnumerable<XElement> itemsXML = root.Elements("DesignerItems").Elements("DesignerItem");

            double offsetX = Double.Parse(root.Attribute("OffsetX").Value, CultureInfo.InvariantCulture);
            double offsetY = Double.Parse(root.Attribute("OffsetY").Value, CultureInfo.InvariantCulture);

            foreach (XElement itemXML in itemsXML)
            {
                Guid oldID = new Guid(itemXML.Element("ID").Value);
                Guid newID = Guid.NewGuid();
                mappingOldToNewIDs.Add(oldID, newID);
                DesignerItem item = DeserializeDesignerItem(itemXML, newID, offsetX, offsetY);
                this.Children.Add(item);
                SetConnectorDecoratorTemplate(item);
                newItems.Add(item);
            }

            // update group hierarchy
            SelectionService.ClearSelection();
            foreach (DesignerItem el in newItems)
            {
                if (el.ParentID != Guid.Empty)
                    el.ParentID = mappingOldToNewIDs[el.ParentID];
            }


            foreach (DesignerItem item in newItems)
            {
                if (item.ParentID == Guid.Empty)
                {
                    SelectionService.AddToSelection(item);
                }
            }

            // create Connections
            IEnumerable<XElement> connectionsXML = root.Elements("Connections").Elements("Connection");
            foreach (XElement connectionXML in connectionsXML)
            {
                Guid oldSourceID = new Guid(connectionXML.Element("SourceID").Value);
                Guid oldSinkID = new Guid(connectionXML.Element("SinkID").Value);

                if (mappingOldToNewIDs.ContainsKey(oldSourceID) && mappingOldToNewIDs.ContainsKey(oldSinkID))
                {
                    Guid newSourceID = mappingOldToNewIDs[oldSourceID];
                    Guid newSinkID = mappingOldToNewIDs[oldSinkID];

                    String sourceConnectorName = connectionXML.Element("SourceConnectorName").Value;
                    String sinkConnectorName = connectionXML.Element("SinkConnectorName").Value;

                    Connector sourceConnector = GetConnector(newSourceID, sourceConnectorName);
                    Connector sinkConnector = GetConnector(newSinkID, sinkConnectorName);

                    Connection connection = new Connection(sourceConnector, sinkConnector);
                    Canvas.SetZIndex(connection, Int32.Parse(connectionXML.Element("zIndex").Value));
                    this.Children.Add(connection);

                    SelectionService.AddToSelection(connection);
                }
            }

            DesignerCanvas.BringToFront.Execute(null, this);

            // update paste offset
            root.Attribute("OffsetX").Value = (offsetX + 10).ToString();
            root.Attribute("OffsetY").Value = (offsetY + 10).ToString();
            Clipboard.Clear();
            Clipboard.SetData(DataFormats.Xaml, root);
        }

        private void Paste_Enabled(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = Clipboard.ContainsData(DataFormats.Xaml);
        }

        #endregion

        #region Delete Command

        private void Delete_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            DeleteCurrentSelection();
        }

        private void Delete_Enabled(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = this.SelectionService.CurrentSelection.Count() > 0;
        }

        #endregion

        #region Cut Command

        private void Cut_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            CopyCurrentSelection();
            DeleteCurrentSelection();
        }

        private void Cut_Enabled(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = this.SelectionService.CurrentSelection.Count() > 0;
        }

        #endregion

        #region Group Command

        private void Group_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            var items = from item in this.SelectionService.CurrentSelection.OfType<DesignerItem>()
                        where item.ParentID == Guid.Empty
                        select item;

            Rect rect = GetBoundingRectangle(items);

            DesignerItem groupItem = new DesignerItem();
            groupItem.IsGroup = true;
            groupItem.Width = rect.Width;
            groupItem.Height = rect.Height;
            Canvas.SetLeft(groupItem, rect.Left);
            Canvas.SetTop(groupItem, rect.Top);
            Canvas groupCanvas = new Canvas();
            groupItem.Content = groupCanvas;
            Canvas.SetZIndex(groupItem, this.Children.Count);
            this.Children.Add(groupItem);

            foreach (DesignerItem item in items)
                item.ParentID = groupItem.ID;

            this.SelectionService.SelectItem(groupItem);
        }

        private void Group_Enabled(object sender, CanExecuteRoutedEventArgs e)
        {
            int count = (from item in SelectionService.CurrentSelection.OfType<DesignerItem>()
                         where item.ParentID == Guid.Empty
                         select item).Count();

            e.CanExecute = count > 1;
        }

        #endregion

        #region Ungroup Command

        private void Ungroup_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            var groups = (from item in SelectionService.CurrentSelection.OfType<DesignerItem>()
                          where item.IsGroup && item.ParentID == Guid.Empty
                          select item).ToArray();

            foreach (DesignerItem groupRoot in groups)
            {
                var children = from child in SelectionService.CurrentSelection.OfType<DesignerItem>()
                               where child.ParentID == groupRoot.ID
                               select child;

                foreach (DesignerItem child in children)
                    child.ParentID = Guid.Empty;

                this.SelectionService.RemoveFromSelection(groupRoot);
                this.Children.Remove(groupRoot);
                UpdateZIndex();
            }
        }

        private void Ungroup_Enabled(object sender, CanExecuteRoutedEventArgs e)
        {
            var groupedItem = from item in SelectionService.CurrentSelection.OfType<DesignerItem>()
                              where item.ParentID != Guid.Empty
                              select item;


            e.CanExecute = groupedItem.Count() > 0;
        }

        #endregion

        #region BringForward Command

        private void BringForward_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            List<UIElement> ordered = (from item in SelectionService.CurrentSelection
                                       orderby Canvas.GetZIndex(item as UIElement) descending
                                       select item as UIElement).ToList();

            int count = this.Children.Count;

            for (int i = 0; i < ordered.Count; i++)
            {
                int currentIndex = Canvas.GetZIndex(ordered[i]);
                int newIndex = Math.Min(count - 1 - i, currentIndex + 1);
                if (currentIndex != newIndex)
                {
                    Canvas.SetZIndex(ordered[i], newIndex);
                    IEnumerable<UIElement> it = this.Children.OfType<UIElement>().Where(item => Canvas.GetZIndex(item) == newIndex);

                    foreach (UIElement elm in it)
                    {
                        if (elm != ordered[i])
                        {
                            Canvas.SetZIndex(elm, currentIndex);
                            break;
                        }
                    }
                }
            }
        }

        private void Order_Enabled(object sender, CanExecuteRoutedEventArgs e)
        {
            //e.CanExecute = SelectionService.CurrentSelection.Count() > 0;
            e.CanExecute = true;
        }

        #endregion

        #region BringToFront Command

        private void BringToFront_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            List<UIElement> selectionSorted = (from item in SelectionService.CurrentSelection
                                               orderby Canvas.GetZIndex(item as UIElement) ascending
                                               select item as UIElement).ToList();

            List<UIElement> childrenSorted = (from UIElement item in this.Children
                                              orderby Canvas.GetZIndex(item as UIElement) ascending
                                              select item as UIElement).ToList();

            int i = 0;
            int j = 0;
            foreach (UIElement item in childrenSorted)
            {
                if (selectionSorted.Contains(item))
                {
                    int idx = Canvas.GetZIndex(item);
                    Canvas.SetZIndex(item, childrenSorted.Count - selectionSorted.Count + j++);
                }
                else
                {
                    Canvas.SetZIndex(item, i++);
                }
            }
        }

        #endregion

        #region SendBackward Command

        private void SendBackward_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            List<UIElement> ordered = (from item in SelectionService.CurrentSelection
                                       orderby Canvas.GetZIndex(item as UIElement) ascending
                                       select item as UIElement).ToList();

            int count = this.Children.Count;

            for (int i = 0; i < ordered.Count; i++)
            {
                int currentIndex = Canvas.GetZIndex(ordered[i]);
                int newIndex = Math.Max(i, currentIndex - 1);
                if (currentIndex != newIndex)
                {
                    Canvas.SetZIndex(ordered[i], newIndex);
                    IEnumerable<UIElement> it = this.Children.OfType<UIElement>().Where(item => Canvas.GetZIndex(item) == newIndex);

                    foreach (UIElement elm in it)
                    {
                        if (elm != ordered[i])
                        {
                            Canvas.SetZIndex(elm, currentIndex);
                            break;
                        }
                    }
                }
            }
        }

        #endregion

        #region SendToBack Command

        private void SendToBack_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            List<UIElement> selectionSorted = (from item in SelectionService.CurrentSelection
                                               orderby Canvas.GetZIndex(item as UIElement) ascending
                                               select item as UIElement).ToList();

            List<UIElement> childrenSorted = (from UIElement item in this.Children
                                              orderby Canvas.GetZIndex(item as UIElement) ascending
                                              select item as UIElement).ToList();
            int i = 0;
            int j = 0;
            foreach (UIElement item in childrenSorted)
            {
                if (selectionSorted.Contains(item))
                {
                    int idx = Canvas.GetZIndex(item);
                    Canvas.SetZIndex(item, j++);

                }
                else
                {
                    Canvas.SetZIndex(item, selectionSorted.Count + i++);
                }
            }
        }        

        #endregion

        #region AlignTop Command

        private void AlignTop_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            var selectedItems = from item in SelectionService.CurrentSelection.OfType<DesignerItem>()
                                where item.ParentID == Guid.Empty
                                select item;

            if (selectedItems.Count() > 1)
            {
                double top = Canvas.GetTop(selectedItems.First());

                foreach (DesignerItem item in selectedItems)
                {
                    double delta = top - Canvas.GetTop(item);
                    foreach (DesignerItem di in SelectionService.GetGroupMembers(item))
                    {
                        Canvas.SetTop(di, Canvas.GetTop(di) + delta);
                    }
                }
            }
        }

        private void Align_Enabled(object sender, CanExecuteRoutedEventArgs e)
        {
            //var groupedItem = from item in SelectionService.CurrentSelection.OfType<DesignerItem>()
            //                  where item.ParentID == Guid.Empty
            //                  select item;


            //e.CanExecute = groupedItem.Count() > 1;
            e.CanExecute = true;
        }

        #endregion

        #region AlignVerticalCenters Command

        private void AlignVerticalCenters_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            var selectedItems = from item in SelectionService.CurrentSelection.OfType<DesignerItem>()
                                where item.ParentID == Guid.Empty
                                select item;

            if (selectedItems.Count() > 1)
            {
                double bottom = Canvas.GetTop(selectedItems.First()) + selectedItems.First().Height / 2;

                foreach (DesignerItem item in selectedItems)
                {
                    double delta = bottom - (Canvas.GetTop(item) + item.Height / 2);
                    foreach (DesignerItem di in SelectionService.GetGroupMembers(item))
                    {
                        Canvas.SetTop(di, Canvas.GetTop(di) + delta);
                    }
                }
            }
        }

        #endregion

        #region AlignBottom Command

        private void AlignBottom_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            var selectedItems = from item in SelectionService.CurrentSelection.OfType<DesignerItem>()
                                where item.ParentID == Guid.Empty
                                select item;

            if (selectedItems.Count() > 1)
            {
                double bottom = Canvas.GetTop(selectedItems.First()) + selectedItems.First().Height;

                foreach (DesignerItem item in selectedItems)
                {
                    double delta = bottom - (Canvas.GetTop(item) + item.Height);
                    foreach (DesignerItem di in SelectionService.GetGroupMembers(item))
                    {
                        Canvas.SetTop(di, Canvas.GetTop(di) + delta);
                    }
                }
            }
        }

        #endregion

        #region AlignLeft Command

        private void AlignLeft_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            var selectedItems = from item in SelectionService.CurrentSelection.OfType<DesignerItem>()
                                where item.ParentID == Guid.Empty
                                select item;

            if (selectedItems.Count() > 1)
            {
                double left = Canvas.GetLeft(selectedItems.First());

                foreach (DesignerItem item in selectedItems)
                {
                    double delta = left - Canvas.GetLeft(item);
                    foreach (DesignerItem di in SelectionService.GetGroupMembers(item))
                    {
                        Canvas.SetLeft(di, Canvas.GetLeft(di) + delta);
                    }
                }
            }
        }

        #endregion

        #region AlignHorizontalCenters Command

        private void AlignHorizontalCenters_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            var selectedItems = from item in SelectionService.CurrentSelection.OfType<DesignerItem>()
                                where item.ParentID == Guid.Empty
                                select item;

            if (selectedItems.Count() > 1)
            {
                double center = Canvas.GetLeft(selectedItems.First()) + selectedItems.First().Width / 2;

                foreach (DesignerItem item in selectedItems)
                {
                    double delta = center - (Canvas.GetLeft(item) + item.Width / 2);
                    foreach (DesignerItem di in SelectionService.GetGroupMembers(item))
                    {
                        Canvas.SetLeft(di, Canvas.GetLeft(di) + delta);
                    }
                }
            }
        }

        #endregion

        #region AlignRight Command

        private void AlignRight_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            var selectedItems = from item in SelectionService.CurrentSelection.OfType<DesignerItem>()
                                where item.ParentID == Guid.Empty
                                select item;

            if (selectedItems.Count() > 1)
            {
                double right = Canvas.GetLeft(selectedItems.First()) + selectedItems.First().Width;

                foreach (DesignerItem item in selectedItems)
                {
                    double delta = right - (Canvas.GetLeft(item) + item.Width);
                    foreach (DesignerItem di in SelectionService.GetGroupMembers(item))
                    {
                        Canvas.SetLeft(di, Canvas.GetLeft(di) + delta);
                    }
                }
            }
        }

        #endregion

        #region DistributeHorizontal Command

        private void DistributeHorizontal_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            var selectedItems = from item in SelectionService.CurrentSelection.OfType<DesignerItem>()
                                where item.ParentID == Guid.Empty
                                let itemLeft = Canvas.GetLeft(item)
                                orderby itemLeft
                                select item;

            if (selectedItems.Count() > 1)
            {
                double left = Double.MaxValue;
                double right = Double.MinValue;
                double sumWidth = 0;
                foreach (DesignerItem item in selectedItems)
                {
                    left = Math.Min(left, Canvas.GetLeft(item));
                    right = Math.Max(right, Canvas.GetLeft(item) + item.Width);
                    sumWidth += item.Width;
                }

                double distance = Math.Max(0, (right - left - sumWidth) / (selectedItems.Count() - 1));
                double offset = Canvas.GetLeft(selectedItems.First());

                foreach (DesignerItem item in selectedItems)
                {
                    double delta = offset - Canvas.GetLeft(item);
                    foreach (DesignerItem di in SelectionService.GetGroupMembers(item))
                    {
                        Canvas.SetLeft(di, Canvas.GetLeft(di) + delta);
                    }
                    offset = offset + item.Width + distance;
                }
            }
        }

        private void Distribute_Enabled(object sender, CanExecuteRoutedEventArgs e)
        {
            //var groupedItem = from item in SelectionService.CurrentSelection.OfType<DesignerItem>()
            //                  where item.ParentID == Guid.Empty
            //                  select item;


            //e.CanExecute = groupedItem.Count() > 1;
            e.CanExecute = true;
        }

        #endregion

        #region DistributeVertical Command

        private void DistributeVertical_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            var selectedItems = from item in SelectionService.CurrentSelection.OfType<DesignerItem>()
                                where item.ParentID == Guid.Empty
                                let itemTop = Canvas.GetTop(item)
                                orderby itemTop
                                select item;

            if (selectedItems.Count() > 1)
            {
                double top = Double.MaxValue;
                double bottom = Double.MinValue;
                double sumHeight = 0;
                foreach (DesignerItem item in selectedItems)
                {
                    top = Math.Min(top, Canvas.GetTop(item));
                    bottom = Math.Max(bottom, Canvas.GetTop(item) + item.Height);
                    sumHeight += item.Height;
                }

                double distance = Math.Max(0, (bottom - top - sumHeight) / (selectedItems.Count() - 1));
                double offset = Canvas.GetTop(selectedItems.First());

                foreach (DesignerItem item in selectedItems)
                {
                    double delta = offset - Canvas.GetTop(item);
                    foreach (DesignerItem di in SelectionService.GetGroupMembers(item))
                    {
                        Canvas.SetTop(di, Canvas.GetTop(di) + delta);
                    }
                    offset = offset + item.Height + distance;
                }
            }
        }

        #endregion

        #region SelectAll Command

        private void SelectAll_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            SelectionService.SelectAll();
        }

        #endregion

        #region Helper Methods

        private XElement[] LoadSerializedDataFromFile()
        {
            XElement[] ret = new XElement[2];
            OpenFileDialog openFile = new OpenFileDialog();
            openFile.Filter = "Designer Files (*.xml)|*.xml|All Files (*.*)|*.*";

            if (openFile.ShowDialog() == true)
            {
                try
                {
                    ret[0]= XElement.Load(openFile.FileName);
                    ret[1] = XElement.Load(openFile.FileName+"d");
                }
                catch (Exception e)
                {
                    MessageBox.Show(e.StackTrace, e.Message, MessageBoxButton.OK, MessageBoxImage.Error);
                    return null;
                }
            }

            return ret;
        }




        void SaveFile(XElement xElement, XElement layout, List<Device> devices)
        {
            SaveFileDialog saveFile = new SaveFileDialog();
            saveFile.Filter = "Files (*.xml)|*.xml|All Files (*.*)|*.*";
            if (saveFile.ShowDialog() == true)
            {
                try
                {                   
                    SerializeDevice(devices, saveFile.FileName+"d");
                    xElement.Save(saveFile.FileName);
                    layout.Save(saveFile.FileName + "l");
                    CreateCheckFile(saveFile.FileName + "d", saveFile.FileName + "l");
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.StackTrace, ex.Message, MessageBoxButton.OK, MessageBoxImage.Error);
                }
            }
        }


        private XElement LoadSerializedDataFromClipBoard()
        {
            if (Clipboard.ContainsData(DataFormats.Xaml))
            {
                String clipboardData = Clipboard.GetData(DataFormats.Xaml) as String;

                if (String.IsNullOrEmpty(clipboardData))
                    return null;
                try
                {
                    return XElement.Load(new StringReader(clipboardData));
                }
                catch (Exception e)
                {
                    MessageBox.Show(e.StackTrace, e.Message, MessageBoxButton.OK, MessageBoxImage.Error);
                }
            }

            return null;
        }

        private XElement SerializeDesignerItems(IEnumerable<DesignerItem> designerItems)
        {
            XElement serializedItems = new XElement("DesignerItems",
                                       from item in designerItems
                                       let contentXaml = XamlWriter.Save(((DesignerItem)item).Content)
                                       select new XElement("DesignerItem",
                                                  new XElement("Uid", item.Uid),
                                                  new XElement("Left", Canvas.GetLeft(item)),
                                                  new XElement("Top", Canvas.GetTop(item)),
                                                  new XElement("Width", item.Width),
                                                  new XElement("Height", item.Height),
                                                  new XElement("ID", item.ID),
                                                  new XElement("zIndex", Canvas.GetZIndex(item)),
                                                  new XElement("IsGroup", item.IsGroup),
                                                  new XElement("ParentID", item.ParentID),
                                                  new XElement("Content", contentXaml)
                                              )
                                   );

            return serializedItems;
        }

        private XElement SerializeDesignerItemsforapp(IEnumerable<DesignerItem> designerItems)
        {
            XElement serializedItems = new XElement("DeviceItems",
                                       from item in designerItems
                                       let contentXaml = XamlWriter.Save(((DesignerItem)item).Content)
                                       select new XElement("DeviceItem",
                                                  new XElement("Uid", item.main_Device==null?item.Uid:item.main_Device.DeviceID.ToString("X8")),
                                                  new XElement("Left", Canvas.GetLeft(item)),
                                                  new XElement("Top", Canvas.GetTop(item)),
                                                  new XElement("Width", item.Width),
                                                  new XElement("Height", item.Height)                                                 
                                              )
                                   );

            return serializedItems;
        }

        private XElement SerializeConnections(IEnumerable<Connection> connections)
        {
            var serializedConnections = new XElement("Connections",
                           from connection in connections
                           select new XElement("Connection",
                                      new XElement("SourceID", connection.Source.ParentDesignerItem.ID),
                                      new XElement("SinkID", connection.Sink.ParentDesignerItem.ID),
                                      new XElement("SourceConnectorName", connection.Source.Name),
                                      new XElement("SinkConnectorName", connection.Sink.Name),
                                      new XElement("SourceArrowSymbol", connection.SourceArrowSymbol),
                                      new XElement("SinkArrowSymbol", connection.SinkArrowSymbol),
                                      new XElement("zIndex", Canvas.GetZIndex(connection))
                                     )
                                  );

            return serializedConnections;
        }

        private  DesignerItem DeserializeDesignerItem(XElement itemXML, Guid id, double OffsetX, double OffsetY)
        {
            DesignerItem item = new DesignerItem(id,this);
            item.Uid = itemXML.Element("Uid").Value;
            item.Width = Double.Parse(itemXML.Element("Width").Value, CultureInfo.InvariantCulture);
            item.Height = Double.Parse(itemXML.Element("Height").Value, CultureInfo.InvariantCulture);
            item.ParentID = new Guid(itemXML.Element("ParentID").Value);
            item.IsGroup = Boolean.Parse(itemXML.Element("IsGroup").Value);
            Canvas.SetLeft(item, Double.Parse(itemXML.Element("Left").Value, CultureInfo.InvariantCulture) + OffsetX);
            Canvas.SetTop(item, Double.Parse(itemXML.Element("Top").Value, CultureInfo.InvariantCulture) + OffsetY);
            Canvas.SetZIndex(item, Int32.Parse(itemXML.Element("zIndex").Value));
            Object content = XamlReader.Load(XmlReader.Create(new StringReader(itemXML.Element("Content").Value)));
            item.Content = content;
            return item;
        }



    

        //private List<int> HopperPositionIDList = new List<int>() { 1, 2, 3 };
        //private List<int> FanPositionIDList = new List<int>() { 1, 2, 3, 4, 5 };     
        //private List<int> BoilerPositionIDList = new List<int>() { 1 };
        //private List<int> NtcPositionIDList = new List<int>() { 1 };
        //private List<int> WaterLevelPositionIDList = new List<int>() { 1 };
        //private List<int> CupSensorPositionIDList = new List<int>() { 1, 2 };
        //private List<int> LEDPositionIDList = new List<int>() { 1 };
        //private List<int> DriptrayPositionIDList = new List<int>() { 1 };
        //private List<int> WasterbinPositionIDList = new List<int>() { 1 };
        //private List<int> DoorSensorPositionIDList = new List<int>() { 1 };


        //private List<int> VirMachineSensorPositionIDList = new List<int>() { 1 };

        private  DesignerItem DeserializeDesignerItemDate(XElement itemXML,DesignerItem item)
        {
            bool isboiler = false;
            DesignerItem ret = item;
            if (item.Uid.Equals("0000-00"))
            {
                return ret;
            }            
            IEnumerable<XElement> itemsXML = itemXML.Elements("Device");
            XElement devXML = itemsXML.First(c => c.Attribute("GUID").Value.Equals(item.ID.ToString()));
            //about main device
            Device temp;
            if(devXML.Attribute("ID").Value.StartsWith("000101")) //esbrew
            {
                temp = new Dev_ES(Convert.ToInt32(devXML.Attribute("ID").Value.Substring(6)));
                (temp as Dev_ES).Inlet_flow = Convert.ToInt32(devXML.Attribute("Flow_Meter").Value, 10);
                (temp as Dev_ES).Max_capability = Convert.ToInt32(devXML.Attribute("Max_Capability").Value, 10);
                (temp as Dev_ES).Life_brewer_motor = Convert.ToInt32(devXML.Attribute("Life_Motor").Value, 10);
                (temp as Dev_ES).Life_inlet_valve = Convert.ToInt32(devXML.Attribute("Life_Valve").Value, 10);
                ret.main_Device = temp;
                BrewerPositionIDList.Remove(temp.Position_id);
            }
            else if (devXML.Attribute("ID").Value.StartsWith("000201")) //grinder
            {
                temp = new Dev_Grinder(Convert.ToInt32(devXML.Attribute("ID").Value.Substring(6)));
                (temp as Dev_Grinder).Dosage_value = Convert.ToInt32(devXML.Attribute("Dosage_Value").Value, 10);
                (temp as Dev_Grinder).Motor_life = Convert.ToInt32(devXML.Attribute("Life_Motor").Value, 10);
                ret.main_Device = temp;
                GrinderPositionIDList.Remove(temp.Position_id);
            }
            else if (devXML.Attribute("ID").Value.StartsWith("0003")) //canister
            {
                temp = new Dev_Canister(Convert.ToInt32(devXML.Attribute("Type").Value), Convert.ToInt32(devXML.Attribute("ID").Value.Substring(6)));
                (temp as Dev_Canister).Dosage_value = Convert.ToInt32(devXML.Attribute("Dosage_Value").Value, 10);
                (temp as Dev_Canister).Motor_life = Convert.ToInt32(devXML.Attribute("Life_Motor").Value, 10);
                (temp as Dev_Canister).Max_capability = Convert.ToInt32(devXML.Attribute("Max_Capability").Value, 10);
                (temp as Dev_Canister).Powder_type = Convert.ToInt32(devXML.Attribute("Powder").Value, 10);
                ret.main_Device = temp;
                CanisterPositionIDList.Remove(temp.Position_id);
            }
            else if (devXML.Attribute("ID").Value.StartsWith("0004")) //mixer
            {
                temp = new Dev_Mixer_L( Convert.ToInt32(devXML.Attribute("ID").Value.Substring(6)));
                (temp as Dev_Mixer_L).Run_speed = Convert.ToInt32(devXML.Attribute("Speed").Value, 10);
                (temp as Dev_Mixer_L).Hot_valve_flow = Convert.ToInt32(devXML.Attribute("Hot_flow").Value, 10);
                (temp as Dev_Mixer_L).Max_capability = Convert.ToInt32(devXML.Attribute("Max_Capability").Value, 10);
                (temp as Dev_Mixer_L).Cold_valve_flow = Convert.ToInt32(devXML.Attribute("Cold_flow").Value, 10);
                (temp as Dev_Mixer_L).Life_cold_valve = Convert.ToInt32(devXML.Attribute("Life_cold_valve").Value, 10);
                (temp as Dev_Mixer_L).Life_hot_valve = Convert.ToInt32(devXML.Attribute("Life_hot_valve").Value, 10);
                (temp as Dev_Mixer_L).Life_motor = Convert.ToInt32(devXML.Attribute("Life_Motor").Value, 10);
                (temp as Dev_Mixer_L).Life_whipper = Convert.ToInt32(devXML.Attribute("Life_whipper").Value, 10);
                ret.main_Device = temp;
                MixerPositionIDList.Remove(temp.Position_id);
            }
            else if (devXML.Attribute("ID").Value.StartsWith("000F02")) //gravity-boiler
            {
                isboiler = true;
                temp = new Dev_Boiler_G(Convert.ToInt32(devXML.Attribute("ID").Value.Substring(6)));
                (temp as Dev_Boiler_G).Max_capability = Convert.ToInt32(devXML.Attribute("Max_Capability").Value, 10);
                (temp as Dev_Boiler_G).Inlet_water_type = Convert.ToInt32(devXML.Attribute("Water").Value, 10);
                (temp as Dev_Boiler_G).Life_intlet_valve = Convert.ToInt32(devXML.Attribute("Life_inlet_valve").Value, 10);
                ret.main_Device = temp;
            }
            else if (devXML.Attribute("ID").Value.StartsWith("000F03")) //es-boiler
            {
                isboiler = true;
                temp = new Dev_Boiler_ES(Convert.ToInt32(devXML.Attribute("ID").Value.Substring(6)));
                (temp as Dev_Boiler_ES).Max_capability = Convert.ToInt32(devXML.Attribute("Max_Capability").Value, 10);
                (temp as Dev_Boiler_ES).Inlet_water_type = Convert.ToInt32(devXML.Attribute("Water").Value, 10);
                (temp as Dev_Boiler_ES).Life_intlet_valve = Convert.ToInt32(devXML.Attribute("Life_inlet_valve").Value, 10);
                ret.main_Device = temp;
            }
            else if(devXML.Attribute("ID").Value.StartsWith("000002")) //virmachine
            {
                temp = new DEV_virMachine(Convert.ToInt32(devXML.Attribute("ID").Value.Substring(6)));
                ret.main_Device = temp;
            }

            Device tempp = null;
            //chuli boiler
            if (isboiler)
            {
              var heater =itemsXML.First(c => c.Attribute("ID").Value.StartsWith("0016"));
                if(heater!=null)
                {
                    tempp = new DEV_Heater(Convert.ToInt32(heater.Attribute("ID").Value.Substring(4, 2)), Convert.ToInt32(heater.Attribute("ID").Value.Substring(6)));
                    (tempp as DEV_Heater).Life_times = Convert.ToInt32(heater.Attribute("Life_times").Value, 10);
                    (tempp as DEV_Heater).Max_heat_time = Convert.ToInt32(heater.Attribute("Max_heat_time").Value, 10);
                    ret.attach_Device_list.Add(tempp);
                    tempp = null;
                }
                var ntcs = itemsXML.Where(c => c.Attribute("ID").Value.StartsWith("0006")).ToList<XElement>();
                if(ntcs!=null && ntcs.Count>0)
                {
                    foreach (var ntc in ntcs)
                    {
                        tempp = new Dev_SenNtc(Convert.ToInt32(ntc.Attribute("ID").Value.Substring(6)));
                        (tempp as Dev_SenNtc).Compent_type = Convert.ToInt32(ntc.Attribute("Type").Value, 10);
                        (tempp as Dev_SenNtc).Life_sensor = Convert.ToInt32(ntc.Attribute("Life_Sensor").Value, 10);
                        (tempp as Dev_SenNtc).Temperature_block = Convert.ToInt32(ntc.Attribute("Block").Value, 10);
                        (tempp as Dev_SenNtc).Temperature_eco = Convert.ToInt32(ntc.Attribute("ECO").Value, 10);
                        (tempp as Dev_SenNtc).Temperature_normal = Convert.ToInt32(ntc.Attribute("Normal").Value, 10);
                        (tempp as Dev_SenNtc).Temperature_offset = Convert.ToInt32(ntc.Attribute("Offset").Value, 10);
                        (tempp as Dev_SenNtc).Temperature_warning = Convert.ToInt32(ntc.Attribute("Warn").Value, 10);
                        ret.attach_Device_list.Add(tempp);
                        tempp = null;
                    }
                }
            }

            //dealwith attach device
            int attachcnt = Convert.ToInt32(devXML.Element("Parents").Attribute("Count").Value, 10);
            if (attachcnt > 0)
            {
                IEnumerable<XElement> parnetsXML = devXML.Element("Parents").Elements("Parent");
                String[] parentids = new string[attachcnt];
                int pos = 0;
                foreach (XElement pxml in parnetsXML)
                {
                    parentids[pos++] = pxml.Attribute("ID").Value;
                }
                
                for (int i = 0; i < attachcnt; i++)
                {
                    devXML = itemsXML.First(c => c.Attribute("ID").Value.Equals(parentids[i]));
                    if (devXML.Attribute("ID").Value.StartsWith("0006")) //ntc
                    {
                        tempp = new Dev_SenNtc(Convert.ToInt32(devXML.Attribute("ID").Value.Substring(6)));
                        (tempp as Dev_SenNtc).Compent_type = Convert.ToInt32(devXML.Attribute("Type").Value, 10);
                        (tempp as Dev_SenNtc).Life_sensor = Convert.ToInt32(devXML.Attribute("Life_Sensor").Value, 10);
                        (tempp as Dev_SenNtc).Temperature_block = Convert.ToInt32(devXML.Attribute("Block").Value, 10);
                        (tempp as Dev_SenNtc).Temperature_eco = Convert.ToInt32(devXML.Attribute("ECO").Value, 10);
                        (tempp as Dev_SenNtc).Temperature_normal = Convert.ToInt32(devXML.Attribute("Normal").Value, 10);
                        (tempp as Dev_SenNtc).Temperature_offset = Convert.ToInt32(devXML.Attribute("Offset").Value, 10);
                        (tempp as Dev_SenNtc).Temperature_warning = Convert.ToInt32(devXML.Attribute("Warn").Value, 10);

                    }
                    else if (devXML.Attribute("ID").Value.StartsWith("0005")) //Flow meter
                    {
                        tempp = new DEV_Flowmeter(Convert.ToInt32(devXML.Attribute("ID").Value.Substring(4, 2)), Convert.ToInt32(devXML.Attribute("ID").Value.Substring(6)));
                        (tempp as DEV_Flowmeter).Pluse = Convert.ToInt32(devXML.Attribute("Pluse").Value, 10);
                    }
                    else if (devXML.Attribute("ID").Value.StartsWith("0007")) //water level
                    {
                        tempp = new Dev_SenWater(Convert.ToInt32(devXML.Attribute("ID").Value.Substring(6)));
                        (tempp as Dev_SenWater).Compent_type = Convert.ToInt32(devXML.Attribute("Type").Value, 10);
                        (tempp as Dev_SenWater).Life_sensor = Convert.ToInt32(devXML.Attribute("Life_Sensor").Value, 10);
                    }
                    else if (devXML.Attribute("ID").Value.StartsWith("0008")) //cup sensor
                    {
                        tempp = new Dev_SenCup(Convert.ToInt32(devXML.Attribute("ID").Value.Substring(6)));                        
                        (tempp as Dev_SenCup).Life_sensor = Convert.ToInt32(devXML.Attribute("Life_Sensor").Value, 10);
                    }
                    else if (devXML.Attribute("ID").Value.StartsWith("0009")) //pressure sensor
                    {
                        tempp = new Dev_SenPressuer(Convert.ToInt32(devXML.Attribute("ID").Value.Substring(4, 2)), Convert.ToInt32(devXML.Attribute("ID").Value.Substring(6)));
                        (tempp as Dev_SenPressuer).Life_sensor = Convert.ToInt32(devXML.Attribute("Life_Sensor").Value, 10);
                    }
                    else if (devXML.Attribute("ID").Value.StartsWith("000A")) //pump water
                    {
                        tempp = new DEV_Waterpump(Convert.ToInt32(devXML.Attribute("ID").Value.Substring(4, 2)), Convert.ToInt32(devXML.Attribute("ID").Value.Substring(6)));
                        (tempp as DEV_Waterpump).Motor_life = Convert.ToInt32(devXML.Attribute("Motor_life").Value, 10);
                        (tempp as DEV_Waterpump).Speed = Convert.ToInt32(devXML.Attribute("Speed").Value, 10);
                    }
                    else if (devXML.Attribute("ID").Value.StartsWith("000C")) //cup sensor
                    {
                        tempp = new Dev_Led(Convert.ToInt32(devXML.Attribute("ID").Value.Substring(4, 2)),Convert.ToInt32(devXML.Attribute("ID").Value.Substring(6)));
                       // (tempp as Dev_Led).Life_sensor = Convert.ToInt32(devXML.Attribute("Life_Sensor").Value, 10);
                    }
                    else if (devXML.Attribute("ID").Value.StartsWith("000E")) //air
                    {
                        tempp = new DEV_Airbreak(Convert.ToInt32(devXML.Attribute("ID").Value.Substring(6)));
                        // (tempp as Dev_Led).Life_sensor = Convert.ToInt32(devXML.Attribute("Life_Sensor").Value, 10);
                    }
                    else if (devXML.Attribute("ID").Value.StartsWith("0018")) //cup sensor
                    {
                        tempp = new Dev_SenDriptray(Convert.ToInt32(devXML.Attribute("ID").Value.Substring(6)));
                        (tempp as Dev_SenDriptray).Life_sensor = Convert.ToInt32(devXML.Attribute("Life_Sensor").Value, 10);
                        (tempp as Dev_SenDriptray).Max_capability = Convert.ToInt32(devXML.Attribute("Max_Capability").Value, 10);
                    }
                    else if (devXML.Attribute("ID").Value.StartsWith("0019")) //cup sensor
                    {
                        tempp = new Dev_SenWaster(Convert.ToInt32(devXML.Attribute("ID").Value.Substring(6)));
                        (tempp as Dev_SenWaster).Life_sensor = Convert.ToInt32(devXML.Attribute("Life_Sensor").Value, 10);
                        (tempp as Dev_SenWaster).Max_capability = Convert.ToInt32(devXML.Attribute("Max_Capability").Value, 10);
                    }
                    else if (devXML.Attribute("ID").Value.StartsWith("001A")) //cup sensor
                    {
                        tempp = new Dev_SenDoor(Convert.ToInt32(devXML.Attribute("ID").Value.Substring(6)));
                        (tempp as Dev_SenDoor).Life_sensor = Convert.ToInt32(devXML.Attribute("Life_Sensor").Value, 10);
                    }
                    else if (devXML.Attribute("ID").Value.StartsWith("0014")) //fan
                    {
                         tempp = new Dev_Fan(Convert.ToInt32(devXML.Attribute("ID").Value.Substring(6)));
                        (tempp as Dev_Fan).Life_motor = Convert.ToInt32(devXML.Attribute("Life_Motor").Value, 10);
                        (tempp as Dev_Fan).Run_speed = Convert.ToInt32(devXML.Attribute("Speed").Value, 10);
                    }
                    else if (devXML.Attribute("ID").Value.StartsWith("0015")) //hopper
                    {
                        tempp = new Dev_Hopper(Convert.ToInt32(devXML.Attribute("ID").Value.Substring(6)));
                        (tempp as Dev_Hopper).Max_capability = Convert.ToInt32(devXML.Attribute("Max_Capability").Value, 10);
                        (tempp as Dev_Hopper).Powder_type = Convert.ToInt32(devXML.Attribute("Powder").Value, 10);
                        (tempp as Dev_Hopper).Motor_life = Convert.ToInt32(devXML.Attribute("Life_Motor").Value, 10);
                    }
                    else if (devXML.Attribute("ID").Value.StartsWith("0016")) //heater
                    {
                        tempp = new DEV_Heater(Convert.ToInt32(devXML.Attribute("ID").Value.Substring(4, 2)), Convert.ToInt32(devXML.Attribute("ID").Value.Substring(6)));
                        (tempp as DEV_Heater).Life_times = Convert.ToInt32(devXML.Attribute("Life_times").Value, 10);
                        (tempp as DEV_Heater).Max_heat_time = Convert.ToInt32(devXML.Attribute("Max_heat_time").Value, 10);
                    }
                    if (tempp != null)
                        ret.attach_Device_list.Add(tempp);
                    tempp = null;
                }
            }
            return ret;

        }





        private void CopyCurrentSelection()
        {
            IEnumerable<DesignerItem> selectedDesignerItems =
                this.SelectionService.CurrentSelection.OfType<DesignerItem>();

            List<Connection> selectedConnections =
                this.SelectionService.CurrentSelection.OfType<Connection>().ToList();

            foreach (Connection connection in this.Children.OfType<Connection>())
            {
                if (!selectedConnections.Contains(connection))
                {
                    DesignerItem sourceItem = (from item in selectedDesignerItems
                                               where item.ID == connection.Source.ParentDesignerItem.ID
                                               select item).FirstOrDefault();

                    DesignerItem sinkItem = (from item in selectedDesignerItems
                                             where item.ID == connection.Sink.ParentDesignerItem.ID
                                             select item).FirstOrDefault();

                    if (sourceItem != null &&
                        sinkItem != null &&
                        BelongToSameGroup(sourceItem, sinkItem))
                    {
                        selectedConnections.Add(connection);
                    }
                }
            }

            XElement designerItemsXML = SerializeDesignerItems(selectedDesignerItems);
            XElement connectionsXML = SerializeConnections(selectedConnections);

            XElement root = new XElement("Root");
            root.Add(designerItemsXML);
            root.Add(connectionsXML);

            root.Add(new XAttribute("OffsetX", 10));
            root.Add(new XAttribute("OffsetY", 10));

            Clipboard.Clear();
            Clipboard.SetData(DataFormats.Xaml, root);
        }

        private void DeleteCurrentSelection()
        {
            foreach (Connection connection in SelectionService.CurrentSelection.OfType<Connection>())
            {
                this.Children.Remove(connection);
            }

            foreach (DesignerItem item in SelectionService.CurrentSelection.OfType<DesignerItem>())
            {
                Control cd = item.Template.FindName("PART_ConnectorDecorator", item) as Control;

                List<Connector> connectors = new List<Connector>();
                GetConnectors(cd, connectors);

                foreach (Connector connector in connectors)
                {
                    foreach (Connection con in connector.Connections)
                    {
                        this.Children.Remove(con);
                    }
                }
                this._machineDevicelist.Remove(item.ID);
                this.Children.Remove(item);
                if (item.Uid.StartsWith("0001-01"))   //brewer
                {
                    this.ReleasePositionID(item.main_Device.Position_id, DeviceType.DEV_BREWER);
                    for (int i = 0; i < item.attach_Device_list.Count; i++)
                    {
                        this.ReleasePositionID(item.attach_Device_list[i].Position_id, DeviceType.DEV_FAN);
                    }
                }
                else if (item.Uid.StartsWith("0002")) //grinder
                {
                    this.ReleasePositionID(item.main_Device.Position_id,DeviceType.DEV_GRINDER);
                    for (int i = 0; i < item.attach_Device_list.Count; i++)
                    {
                        this.ReleasePositionID(item.attach_Device_list[i].Position_id, DeviceType.DEV_HOPPER);
                    }

                }
                else if (item.Uid.StartsWith("0003")) //cansiter
                {
                    this.ReleasePositionID(item.main_Device.Position_id, DeviceType.DEV_CANISTER);                    
                }
                else if (item.Uid.StartsWith("0004"))   //mixer
                {
                    this.ReleasePositionID(item.main_Device.Position_id, DeviceType.DEV_MIXER);
                    for (int i = 0; i < item.attach_Device_list.Count; i++)
                    {
                        this.ReleasePositionID(item.attach_Device_list[i].Position_id, DeviceType.DEV_FAN);
                    }
                }
               else  if (item.Uid.StartsWith("000f"))   //boiler
                {
                    this.ReleasePositionID(item.main_Device.Position_id, DeviceType.DEV_BOILER);
                    for (int i = 0; i < item.attach_Device_list.Count; i++)
                    {
                        if(item.attach_Device_list[i].Group_id == 0x0006)   
                            this.ReleasePositionID(item.attach_Device_list[i].Position_id, DeviceType.DEV_NTC);
                        else if (item.attach_Device_list[i].Group_id == 0x0007)
                            this.ReleasePositionID(item.attach_Device_list[i].Position_id, DeviceType.DEV_WATER_LEVEL);
                    }
                }
               else if (item.Uid.StartsWith("0000-02"))   //waiwei
                {
                    this.ReleasePositionID(item.main_Device.Position_id, DeviceType.DEV_VIRMACHINE);
                    for (int i = 0; i < item.attach_Device_list.Count; i++)
                    {
                        if (item.attach_Device_list[i].Group_id == 0x0008)
                            this.ReleasePositionID(item.attach_Device_list[i].Position_id, DeviceType.DEV_CUP);
                        else if (item.attach_Device_list[i].Group_id == 0x000c)
                            this.ReleasePositionID(item.attach_Device_list[i].Position_id, DeviceType.DEV_LED);
                        else if (item.attach_Device_list[i].Group_id == 0x0018)
                            this.ReleasePositionID(item.attach_Device_list[i].Position_id, DeviceType.DEV_DRIP);
                        else if (item.attach_Device_list[i].Group_id == 0x0019)
                            this.ReleasePositionID(item.attach_Device_list[i].Position_id, DeviceType.DEV_WASTER);
                        else if (item.attach_Device_list[i].Group_id == 0x001a)
                            this.ReleasePositionID(item.attach_Device_list[i].Position_id, DeviceType.DEV_DOOR);
                    }
                }
            }

            SelectionService.ClearSelection();
            UpdateZIndex();
        }

        private void UpdateZIndex()
        {
            List<UIElement> ordered = (from UIElement item in this.Children
                                       orderby Canvas.GetZIndex(item as UIElement)
                                       select item as UIElement).ToList();

            for (int i = 0; i < ordered.Count; i++)
            {
                Canvas.SetZIndex(ordered[i], i);
            }
        }

        private static Rect GetBoundingRectangle(IEnumerable<DesignerItem> items)
        {
            double x1 = Double.MaxValue;
            double y1 = Double.MaxValue;
            double x2 = Double.MinValue;
            double y2 = Double.MinValue;

            foreach (DesignerItem item in items)
            {
                x1 = Math.Min(Canvas.GetLeft(item), x1);
                y1 = Math.Min(Canvas.GetTop(item), y1);

                x2 = Math.Max(Canvas.GetLeft(item) + item.Width, x2);
                y2 = Math.Max(Canvas.GetTop(item) + item.Height, y2);
            }

            return new Rect(new Point(x1, y1), new Point(x2, y2));
        }

        private void GetConnectors(DependencyObject parent, List<Connector> connectors)
        {
            int childrenCount = VisualTreeHelper.GetChildrenCount(parent);
            for (int i = 0; i < childrenCount; i++)
            {
                DependencyObject child = VisualTreeHelper.GetChild(parent, i);
                if (child is Connector)
                {
                    connectors.Add(child as Connector);
                }
                else
                    GetConnectors(child, connectors);
            }
        }

        private Connector GetConnector(Guid itemID, String connectorName)
        {
            DesignerItem designerItem = (from item in this.Children.OfType<DesignerItem>()
                                         where item.ID == itemID
                                         select item).FirstOrDefault();
            
            Control connectorDecorator = designerItem.Template.FindName("PART_ConnectorDecorator", designerItem) as Control;
            
           if( designerItem.Uid.StartsWith("0001"))
                connectorDecorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_brewer");
           else if( designerItem.Uid.StartsWith("0002"))
                connectorDecorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_grinder");

            else if (designerItem.Uid.Equals("0000-00"))   // this is for valve
            {

                connectorDecorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_valve");
            }           
            else if (designerItem.Uid.StartsWith("0003")) // this is for canister                   
            {
                connectorDecorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_can");
            }
            else if (designerItem.Uid.StartsWith("0004")) // this is for mixer                   
            {
                connectorDecorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_brewer");
            }
            else if (designerItem.Uid.StartsWith("000f")) // this is for boiler                   
            {
                connectorDecorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_boiler");
            }
            else if (designerItem.Uid.StartsWith("000a")) // this is for boiler                   
            {
                connectorDecorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_pump");
            }
            else if (designerItem.Uid.StartsWith("0008")) // this is for boiler                   
            {
                connectorDecorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_end");
            }
            connectorDecorator.ApplyTemplate();
            return connectorDecorator.Template.FindName(connectorName, connectorDecorator) as Connector;
        }

        private bool BelongToSameGroup(IGroupable item1, IGroupable item2)
        {
            IGroupable root1 = SelectionService.GetGroupRoot(item1);
            IGroupable root2 = SelectionService.GetGroupRoot(item2);

            return (root1.ID == root2.ID);
        }

        #endregion
    }
}
