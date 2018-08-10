using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Data;

namespace MachineCreater.model
{
    public class DeviceNameConvert : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value == null)
                return DependencyProperty.UnsetValue;

            if (((int)value).ToString("X8").StartsWith("0008"))
                return "Cup Sensor";
            if (((int)value).ToString("X8").StartsWith("000c", StringComparison.OrdinalIgnoreCase))
                return "LED";
            if (((int)value).ToString("X8").StartsWith("0018"))
                return "Drip tray";
            if (((int)value).ToString("X8").StartsWith("0019"))
                return "Waster bin";
            if (((int)value).ToString("X8").StartsWith("001a", StringComparison.OrdinalIgnoreCase))
                return "Door Sensor";
            return "Unknown";
            
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}
