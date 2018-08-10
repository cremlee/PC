using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace CREM.EVO.MODEL
{
    [XmlRootAttribute("LEDColorSetting")]
    public class EVOLedColorMgt
    {
        public ObservableCollection<EVOLedColor> m_EVOLedColorList;
        public EVOLedColorMgt()
        {
            m_EVOLedColorList = new ObservableCollection<EVOLedColor>();

        }
        public void Init()
        {
            m_EVOLedColorList.Clear();
            for (int i = 0; i <7; i++)
            {
                EVOLedColor tmp = new EVOLedColor();
                tmp.ColorNB = (byte)i;
                tmp.Color.RED = 255;
                tmp.Color.GREEN = 255;
                tmp.Color.BLUE = 255;
                m_EVOLedColorList.Add(tmp);

            }
        }
        public void Modify(EVOLedColor a)
        {
            EVOLedColor tmp = m_EVOLedColorList.First(c => c.ColorNB == a.ColorNB);
            if (tmp != null)
            {
                tmp.Color.RED = a.Color.RED;
                tmp.Color.GREEN = a.Color.GREEN;
                tmp.Color.BLUE = a.Color.BLUE;
            }
            else
            {
                throw new EVOException("Error:002");
            }
        }
    }
    [XmlRootAttribute("LEDColor")]
    public class EVOLedColor
    {
        [XmlAttribute("ColorNumber")]
        public byte ColorNB { get; set; }
        public RGBColor Color { get; set; }
        public EVOLedColor()
        {
            Color = new RGBColor();
        }
    }
    [XmlRootAttribute("RGBColor")]
    public class RGBColor
    {
        [XmlAttribute("RED")]
        public byte RED { get; set; }
        [XmlAttribute("GREEN")]
        public byte GREEN { get; set; }
        [XmlAttribute("BLUE")]
        public byte BLUE { get; set; }

    }
}
