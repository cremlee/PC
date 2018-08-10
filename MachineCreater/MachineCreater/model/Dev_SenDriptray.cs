using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
    public class Dev_SenDriptray:Sensor
    {
        private int max_capability = 10;

        public int Max_capability
        {
            get { return max_capability; }
            set
            {
                if (value != max_capability)
                {
                    max_capability = value;
                    this.RaisePropertyChanged("Max_capability");
                }
            }
        }
        public Dev_SenDriptray(int position) : base(0x0018, 01, position) { }

    }
}
