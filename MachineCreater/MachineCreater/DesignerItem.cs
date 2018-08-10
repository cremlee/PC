using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using MachineCreater.Controls;
using MachineCreater.propertywin;
using MachineCreater.model;
using System.Collections.ObjectModel;

namespace MachineCreater
{
    //These attributes identify the types of the named parts that are used for templating
    [TemplatePart(Name = "PART_DragThumb", Type = typeof(DragThumb))]
    [TemplatePart(Name = "PART_ResizeDecorator", Type = typeof(Control))]
    [TemplatePart(Name = "PART_ConnectorDecorator", Type = typeof(Control))]
    [TemplatePart(Name = "PART_ContentPresenter", Type = typeof(ContentPresenter))]
    public class DesignerItem : ContentControl, ISelectable, IGroupable
    {

        #region DeviceID
        private String deviceid;
        public String Device_ID
        {
            get { return deviceid; }
            set { deviceid = value; }
        }
        #endregion


        #region ID
        private Guid id;
        public Guid ID
        {
            get { return id; }
        }
        #endregion

        #region ParentID
        public Guid ParentID
        {
            get { return (Guid)GetValue(ParentIDProperty); }
            set { SetValue(ParentIDProperty, value); }
        }
        public static readonly DependencyProperty ParentIDProperty = DependencyProperty.Register("ParentID", typeof(Guid), typeof(DesignerItem));
        #endregion

        #region IsGroup
        public bool IsGroup
        {
            get { return (bool)GetValue(IsGroupProperty); }
            set { SetValue(IsGroupProperty, value); }
        }
        public static readonly DependencyProperty IsGroupProperty =
            DependencyProperty.Register("IsGroup", typeof(bool), typeof(DesignerItem));
        #endregion

        #region IsSelected Property

        public bool IsSelected
        {
            get { return (bool)GetValue(IsSelectedProperty); }
            set { SetValue(IsSelectedProperty, value); }
        }
        public static readonly DependencyProperty IsSelectedProperty =
          DependencyProperty.Register("IsSelected",
                                       typeof(bool),
                                       typeof(DesignerItem),
                                       new FrameworkPropertyMetadata(false));

        #endregion

        #region DragThumbTemplate Property

        // can be used to replace the default template for the DragThumb
        public static readonly DependencyProperty DragThumbTemplateProperty =
            DependencyProperty.RegisterAttached("DragThumbTemplate", typeof(ControlTemplate), typeof(DesignerItem));

        public static ControlTemplate GetDragThumbTemplate(UIElement element)
        {
            return (ControlTemplate)element.GetValue(DragThumbTemplateProperty);
        }

        public static void SetDragThumbTemplate(UIElement element, ControlTemplate value)
        {
            element.SetValue(DragThumbTemplateProperty, value);
        }

        #endregion

        #region ConnectorDecoratorTemplate Property

        // can be used to replace the default template for the ConnectorDecorator
        public static readonly DependencyProperty ConnectorDecoratorTemplateProperty =
            DependencyProperty.RegisterAttached("ConnectorDecoratorTemplate", typeof(ControlTemplate), typeof(DesignerItem));

 
        public static ControlTemplate GetConnectorDecoratorTemplate(UIElement element)
        {
            return (ControlTemplate)element.GetValue(ConnectorDecoratorTemplateProperty);
        }

        public static void SetConnectorDecoratorTemplate(UIElement element, ControlTemplate value)
        {
            element.SetValue(ConnectorDecoratorTemplateProperty, value);
        }

        #endregion

        #region IsDragConnectionOver

        // while drag connection procedure is ongoing and the mouse moves over 
        // this item this value is true; if true the ConnectorDecorator is triggered
        // to be visible, see template
        public bool IsDragConnectionOver
        {
            get { return (bool)GetValue(IsDragConnectionOverProperty); }
            set { SetValue(IsDragConnectionOverProperty, value); }
        }
        public static readonly DependencyProperty IsDragConnectionOverProperty =
            DependencyProperty.Register("IsDragConnectionOver",
                                         typeof(bool),
                                         typeof(DesignerItem),
                                         new FrameworkPropertyMetadata(false));

        #endregion

        static DesignerItem()
        {
            // set the key to reference the style for this control
            FrameworkElement.DefaultStyleKeyProperty.OverrideMetadata(
                typeof(DesignerItem), new FrameworkPropertyMetadata(typeof(DesignerItem)));
        }

        public DesignerItem(Guid id,DesignerCanvas parent)
        {
            _DesignerCanvas = parent;
            this.id = id;
            attach_Device_list = new ObservableCollection<Device>();
            this.Loaded += new RoutedEventHandler(DesignerItem_Loaded);
            this.MouseDoubleClick += DesignerItem_MouseDoubleClick;
        }

        
        /// <summary>
        /// 硬件类型
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
       public Device main_Device { get; set; }

       public ObservableCollection<Device> attach_Device_list { get; set; }

        private win_grinder _win_grinder;
        private win_es_brewer _win_es_brewer;
        private win_canister _win_canister;
        private win_mixer _win_mixer;
        private win_gravity_boiler _win_gravity_boiler;
        private win_peripheral _win_peripheral;
        private win_es_boiler _win_es_boiler;
        private win_water_pump _win_water_pump;
        private void DesignerItem_MouseDoubleClick(object sender, MouseButtonEventArgs e)
        {
            
            Console.WriteLine("DesignerItem_MouseDoubleClick"+this.Uid);
            Console.WriteLine("ID=" + this.ID);
            switch (this.Uid)
            {
                case "0001-01": //ES
                    _win_es_brewer = new win_es_brewer((Dev_ES)main_Device, attach_Device_list);
                    _win_es_brewer.Owner = App.Current.Windows[0];
                    _win_es_brewer._DesignerCanvas = _DesignerCanvas;
                    _win_es_brewer.WindowStartupLocation = WindowStartupLocation.CenterOwner;
                    _win_es_brewer.btn_save.Click += Btn_save_Click;
                    _win_es_brewer.ShowDialog();
                    break;
                case "0002-01":
                    _win_grinder = new win_grinder((Dev_Grinder)main_Device, attach_Device_list);
                    _win_grinder.Owner = App.Current.Windows[0];
                    _win_grinder.WindowStartupLocation = WindowStartupLocation.CenterOwner;
                    _win_grinder._DesignerCanvas = _DesignerCanvas;
                    _win_grinder.btn_save.Click += Btn_save_Click;
                    _win_grinder.ShowDialog();
                    break;
                case "0003-01":
                    _win_canister = new win_canister((Dev_Canister)main_Device);
                    _win_canister.Owner = App.Current.Windows[0];
                    _win_canister.WindowStartupLocation = WindowStartupLocation.CenterOwner;
                    _win_canister._DesignerCanvas = _DesignerCanvas;
                    _win_canister.btn_save.Click += Btn_save_Click;
                    _win_canister.ShowDialog();
                    break;
                case "0004-01":
                    _win_mixer = new win_mixer((Dev_Mixer_L)main_Device, attach_Device_list);
                    _win_mixer.Owner = App.Current.Windows[0];
                    _win_mixer.WindowStartupLocation = WindowStartupLocation.CenterOwner;
                    _win_mixer._DesignerCanvas = _DesignerCanvas;
                    _win_mixer.btn_save.Click += Btn_save_Click;
                    _win_mixer.ShowDialog();
                    break;
                case "000f-02":   //gravity-boiler
                    _win_gravity_boiler = new  win_gravity_boiler((Dev_Boiler_G)main_Device, attach_Device_list);
                    _win_gravity_boiler.Owner = App.Current.Windows[0];
                    _win_gravity_boiler.WindowStartupLocation = WindowStartupLocation.CenterOwner;
                    _win_gravity_boiler._DesignerCanvas = _DesignerCanvas;
                    _win_gravity_boiler.btn_save.Click += Btn_save_Click;
                    _win_gravity_boiler.ShowDialog();
                    break;
                case "000f-03": //es-boiler
                    _win_es_boiler = new win_es_boiler((Dev_Boiler_ES)main_Device, attach_Device_list);
                    _win_es_boiler.Owner = App.Current.Windows[0];
                    _win_es_boiler.WindowStartupLocation = WindowStartupLocation.CenterOwner;
                    _win_es_boiler._DesignerCanvas = _DesignerCanvas;
                    _win_es_boiler.btn_save.Click += Btn_save_Click;
                    _win_es_boiler.ShowDialog();
                    break;
                case "0000-02": //waiwei shebei
                    _win_peripheral = new  win_peripheral((DEV_virMachine)main_Device,attach_Device_list);
                    _win_peripheral.Owner = App.Current.Windows[0];
                    _win_peripheral.WindowStartupLocation = WindowStartupLocation.CenterOwner;
                    _win_peripheral._DesignerCanvas = _DesignerCanvas;
                    _win_peripheral.btn_save.Click += Btn_save_Click;
                    _win_peripheral.ShowDialog();
                    break;
                case "000a-01":
                    _win_water_pump = new win_water_pump((DEV_Waterpump)main_Device, attach_Device_list);
                    _win_water_pump.Owner = App.Current.Windows[0];
                    _win_water_pump.WindowStartupLocation = WindowStartupLocation.CenterOwner;
                    _win_water_pump._DesignerCanvas = _DesignerCanvas;
                    _win_water_pump.btn_save.Click += Btn_save_Click;
                    _win_water_pump.ShowDialog();
                    break;
                default:
                    break;
            }
        }

        private void Btn_save_Click(object sender, RoutedEventArgs e)
        {
            Button b = sender as Button;
            if(b.Tag.ToString().Equals("grinder"))
            {
                main_Device = _win_grinder._grinder;
                attach_Device_list.Clear();
                foreach (var item in _win_grinder._attach_dev)
                {
                    attach_Device_list.Add(item);
                }
                _win_grinder.Close();
            }
            else if(b.Tag.ToString().Equals("ES"))
            {
                main_Device = _win_es_brewer._esbrewer;
                attach_Device_list.Clear();
                foreach (var item in _win_es_brewer._attach_dev)
                {
                    attach_Device_list.Add(item);
                }
                _win_es_brewer.Close();
            }
            else if(b.Tag.ToString().Equals("Canister"))
            {
                main_Device = _win_canister.canisteritem;
                attach_Device_list.Clear();
                _win_canister.Close();
            }
            else if (b.Tag.ToString().Equals("Mixer"))
            {
                main_Device = _win_mixer._mixer;
                attach_Device_list.Clear();
                foreach (var item in _win_mixer._attach_dev)
                {
                    attach_Device_list.Add(item);
                }
                _win_mixer.Close();
            }
            else if (b.Tag.ToString().Equals("GB"))
            {
                main_Device = _win_gravity_boiler._gravity_boiler;
                attach_Device_list.Clear();
                foreach (var item in _win_gravity_boiler._attach_dev)
                {
                    attach_Device_list.Add(item);
                }
                _win_gravity_boiler.Close();
            }
            else if (b.Tag.ToString().Equals("EB"))
            {
                main_Device = _win_es_boiler._gravity_boiler;
                attach_Device_list.Clear();
                foreach (var item in _win_es_boiler._attach_dev)
                {
                    attach_Device_list.Add(item);
                }
                _win_es_boiler.Close();
            }
            else if (b.Tag.ToString().Equals("Peri"))
            {
                main_Device = _win_peripheral._DEV_virMachine;
                attach_Device_list.Clear();
                foreach (var item in _win_peripheral._attach_dev)
                {
                    attach_Device_list.Add(item);
                }
                _win_peripheral.Close();
            }
            else if (b.Tag.ToString().Equals("WF"))
            {
                main_Device = _win_water_pump._data_pump;
                attach_Device_list.Clear();               
                attach_Device_list.Add(_win_water_pump._data_flow);
                _win_water_pump.Close();
            }

        }

        private DesignerCanvas _DesignerCanvas;
        public DesignerItem(String Uid, DesignerCanvas parent)
            : this(Guid.NewGuid(),parent)
        {
            this.Uid = Uid;
            // _DesignerCanvas = parent;
            // attach_Device_list = new ObservableCollection<Device>();
            if (Uid.StartsWith("0001-01"))  //ES brewer
            {
                main_Device = new Dev_ES(parent.GetPositionID(DesignerCanvas.DeviceType.DEV_BREWER));
            }
            else if(Uid.StartsWith("0002")) //grinder
            {
                main_Device = new Dev_Grinder(parent.GetPositionID(DesignerCanvas.DeviceType.DEV_GRINDER));
            }
            else if(Uid.StartsWith("0003")) //canister
            {
                main_Device = new Dev_Canister(0x01, parent.GetPositionID(DesignerCanvas.DeviceType.DEV_CANISTER));
            }
            else if (Uid.StartsWith("0004")) //mixer
            {
                main_Device = new Dev_Mixer_L(parent.GetPositionID(DesignerCanvas.DeviceType.DEV_MIXER));
            }
            else if (Uid.StartsWith("000f-02")) //gravity
            {
                main_Device = new Dev_Boiler_G(parent.GetPositionID(DesignerCanvas.DeviceType.DEV_BOILER));
            }
            else if (Uid.StartsWith("000f-03")) //es
            {
                main_Device = new Dev_Boiler_ES(parent.GetPositionID(DesignerCanvas.DeviceType.DEV_BOILER));
            }
            else if (Uid.StartsWith("0000-02")) //waiwei
            {
                main_Device = new DEV_virMachine(parent.GetPositionID(DesignerCanvas.DeviceType.DEV_VIRMACHINE));
            }
            else if (Uid.StartsWith("000a-01")) //pump
            {
                main_Device = new DEV_Waterpump(1,1);
            }

        }
        public DesignerItem()
            : this(Guid.NewGuid(),null)
        {
           
        }

        protected override void OnPreviewMouseDown(MouseButtonEventArgs e)
        {
            base.OnPreviewMouseDown(e);
            DesignerCanvas designer = VisualTreeHelper.GetParent(this) as DesignerCanvas;

            // update selection
            if (designer != null)
            {
                if ((Keyboard.Modifiers & (ModifierKeys.Shift | ModifierKeys.Control)) != ModifierKeys.None)
                    if (this.IsSelected)
                    {
                        designer.SelectionService.RemoveFromSelection(this);
                    }
                    else
                    {
                        designer.SelectionService.AddToSelection(this);
                    }
                else if (!this.IsSelected)
                {
                    designer.SelectionService.SelectItem(this);
                }
                Focus();
            }

            e.Handled = false;
        }

        void DesignerItem_Loaded(object sender, RoutedEventArgs e)
        {
            if (base.Template != null)
            {
                ContentPresenter contentPresenter =
                    this.Template.FindName("PART_ContentPresenter", this) as ContentPresenter;
                if (contentPresenter != null)
                {
                    UIElement contentVisual = VisualTreeHelper.GetChild(contentPresenter, 0) as UIElement;
                    if (contentVisual != null)
                    {
                        DragThumb thumb = this.Template.FindName("PART_DragThumb", this) as DragThumb;
                        if (thumb != null)
                        {
                            ControlTemplate template =
                                DesignerItem.GetDragThumbTemplate(contentVisual) as ControlTemplate;
                            if (template != null)
                                thumb.Template = template;
                        }
                    }
                }
            }
        }



    }
}
