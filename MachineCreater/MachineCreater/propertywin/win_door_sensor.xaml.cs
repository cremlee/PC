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
    /// Interaction logic for win_cup_sensor.xaml
    /// </summary>
    public partial class win_door_sensor : Window
    {
        public Dev_SenDoor _data { get; set; }
        public win_door_sensor(Dev_SenDoor a)
        {
            if (a != null)
                _data = a;
            else
                _data = new Dev_SenDoor(1);
            InitializeComponent();
            this.DataContext = _data;
        }
    }
}
