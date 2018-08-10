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
using CREM.EVO.MODEL;
using CREM.EVO.Utility;
using CREM.EVO.BLL;

namespace CREM.EVO
{
    /// <summary>
    /// EVOLedColorManage.xaml 的交互逻辑
    /// </summary>
    public partial class EVOLedColorManage : Window
    {
        protected EVOLedColorMgt _EVOLedColorMgt;
        public EVOLedColorManage()
        {
            InitializeComponent();
            InitVar();
            comunication.EVOEvent += comunication_EVOEvent;
        }

        private void comunication_EVOEvent(object sender, EVOData e)
        {
            if (e._cmdType == CmdType.B2M_CMD_COLOR_SET)
            {
                B2MColorSet cmd = new B2MColorSet(e.datain, 0);
                if (cmd.Result == 1)
                {
                    MessageBox.Show("Set Color Ok");
                    System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() => 
                    {
                        EVOLedColor tmp = (EVOLedColor)_EVOLedColorMgt.m_EVOLedColorList.First(c => c.ColorNB == this.cb_Led.SelectedIndex);
                        tmp.Color.RED = (byte)sld_r.Value;
                        tmp.Color.GREEN = (byte)sld_g.Value;
                        tmp.Color.BLUE = (byte)sld_b.Value;
                        Function.XmlSerializer.SaveToXml("EVO.LedSetting.xml", _EVOLedColorMgt, typeof(EVOLedColorMgt), null);

                    }
                    ));

                }
            }
        }

        private void InitVar()
        {
            _EVOLedColorMgt = (EVOLedColorMgt)Function.XmlSerializer.LoadFromXml("EVO.LedSetting.xml", typeof(EVOLedColorMgt));
            if (_EVOLedColorMgt != null)
            {

            }
            else
            {
                _EVOLedColorMgt = new EVOLedColorMgt();
                _EVOLedColorMgt.Init();
                Function.XmlSerializer.SaveToXml("EVO.LedSetting.xml", _EVOLedColorMgt, typeof(EVOLedColorMgt), null);
            }
        }

        private void cb_Led_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if ((sender as ComboBox).SelectedItem != null)
            {
                InitGui((byte)(sender as ComboBox).SelectedIndex);
            }
        }
        private void InitGui(byte colorNb)
        {
            EVOLedColor tmp = (EVOLedColor)_EVOLedColorMgt.m_EVOLedColorList.First(c => c.ColorNB == colorNb);
            sld_r.Value = tmp.Color.RED;
            sld_g.Value = tmp.Color.GREEN;
            sld_b.Value = tmp.Color.BLUE;

        }

        private void rgb_changed(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            
            color_show.Background = new SolidColorBrush(Color.FromRgb((byte)sld_r.Value, (byte)sld_g.Value, (byte)sld_b.Value));
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            if (this.cb_Led.SelectedIndex ==-1)
            {
                MessageBox.Show("Please select color number firs！");return;
            }
            M2BLedClrSet tmp = new M2BLedClrSet(0x03);
            tmp.setcolor.ColorNB = (byte)this.cb_Led.SelectedIndex;
            tmp.setcolor.Color.RED = (byte)sld_r.Value;
            tmp.setcolor.Color.GREEN = (byte)sld_g.Value;
            tmp.setcolor.Color.BLUE = (byte)sld_b.Value;
            byte[] sendcmd = tmp.EnCode();
            comunication.Getinstance().AddtoSend(sendcmd, (byte)sendcmd.Length);

        }
    }
}
