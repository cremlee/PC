using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace CREM.EVO.MODEL
{
    [XmlRootAttribute("BTNMAP")]
    public class PanelRef:NotificationObject
    {
        public ObservableCollection<DrinkItem> m_DrinkItemList;
        public PanelRef()
        {
            m_DrinkItemList = new ObservableCollection<DrinkItem>();
           
        }
        public void Init()
        {
            m_DrinkItemList.Clear();
            for (int i = 1; i <= 16; i++)
            {
                DrinkItem tmp = new DrinkItem();
                tmp.DrinkPostion = i;
                tmp.DrinkName = "NoRecipe";
                tmp.DrinkID = 0;
                m_DrinkItemList.Add(tmp);
            }
        }
        public void Modify(DrinkItem a)
        {
            DrinkItem tmp = m_DrinkItemList.First(c => c.DrinkPostion == a.DrinkPostion);
            if(tmp !=null)
            {
                tmp.DrinkName = a.DrinkName;
                tmp.DrinkID = a.DrinkID;
            }else
            {
                throw new EVOException("Error:001");
            }
        }
    }

    public class EVOException:Exception
    {
        public EVOException() : base() { }
        public EVOException(string message) : base(message)
        { }
    }
    [XmlRootAttribute("BTN")]
    public class DrinkItem:NotificationObject
    {
       
        private UInt16 _DrinkID;
        private string _DrinkName;
        
        [XmlIgnore]
        public String ShowName { get { return "[" + _DrinkID.ToString() + "]" + _DrinkName; } }
        [XmlAttribute("DrinkPostion")]
        public int DrinkPostion { get; set; }
        [XmlAttribute("DrinkID")]
        public ushort DrinkID
        {
            get
            {
                return _DrinkID;
            }

            set
            {
                if (value != _DrinkID) { _DrinkID = value; this.RaisePropertyChanged("ShowName"); }
            }
        }
        [XmlAttribute("DrinkName")]
        public string DrinkName
        {
            get
            {
                return _DrinkName;
            }

            set
            {
                if (value != _DrinkName) { _DrinkName = value; this.RaisePropertyChanged("ShowName"); }

            }
        }
    }
}
