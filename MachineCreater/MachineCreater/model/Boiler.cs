using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
    public class Boiler:Device
    {
        //1）水箱容量 max_volume
        //2）进水类型 water_type
        //3）进水阀的使用周期 life-valve
        //4）锅炉的清洗周期 life-tank-clean(hour)
        private int max_capability     = 20;
        private int inlet_water_type   = 1;
        private int life_intlet_valve  = 5000;
        private int cycle_boiler_clean = 6000;

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

        public int Inlet_water_type
        {
            get { return inlet_water_type; }
            set
            {
                if (value != inlet_water_type)
                {
                    inlet_water_type = value;
                    this.RaisePropertyChanged("Inlet_water_type");
                }
            }
        }

        public int Life_intlet_valve
        {
            get { return life_intlet_valve; }
            set
            {
                if (value != life_intlet_valve)
                {
                    life_intlet_valve = value;
                    this.RaisePropertyChanged("Life_intlet_valve");
                }
            }
        }

        public int Cycle_boiler_clean
        {
            get { return cycle_boiler_clean; }
            set
            {
                if (value != cycle_boiler_clean)
                {
                    cycle_boiler_clean = value;
                    this.RaisePropertyChanged("Cycle_boiler_clean");
                }
            }
        }

        public Boiler(int type,int position) : base(0x000f, type, position) { }
    }
}
