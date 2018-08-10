using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
    public class Sensor:Device
    {
        private int life_sensor=500;
        public int Life_sensor
        {
            get { return life_sensor; }
            set
            {
                if (value != life_sensor)
                {
                    life_sensor = value;
                    this.RaisePropertyChanged("Life_sensor");
                }
            }
        }

        public Sensor(int group,int type,int position) : base(group, type, position) { }
    }
}
