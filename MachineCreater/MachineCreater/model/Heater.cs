using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
    public class Heater:Device
    {
        private int max_heat_time=180;
        private int life_times = 100000;
        public int Max_heat_time
        {
            get { return max_heat_time; }
            set
            {
                if (value != max_heat_time)
                {
                    max_heat_time = value;
                    this.RaisePropertyChanged("Max_heat_time");
                }
            }
        }
        public int Life_times
        {
            get { return life_times; }
            set
            {
                if (value != life_times)
                {
                    life_times = value;
                    this.RaisePropertyChanged("Life_times");
                }
            }
        }
        public Heater(int group,int type,int position) : base(group, type, position) { }
    }
}
