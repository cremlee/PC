using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
   public class DEV_Flowmeter:Sensor
    {
        private int pluse = 1250;
        public int Pluse
        {
            get { return pluse; }
            set
            {
                if (value != pluse)
                {
                    pluse = value;
                    this.RaisePropertyChanged("Pluse");
                }
            }
        }
        public DEV_Flowmeter(int type,int position) : base(0x0005, type, position) { }
    }
}
