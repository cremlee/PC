using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
    public class Brewer:Device
    {
        //1）	进水阀的水量校准值（cal_volume）
        //2）	进水阀使用周期(life_inlet_valve)
        //3）	马达的使用周期(life_motor)
        //4）	Brewer的最大容积 max_volume

        private int max_capability =10;
        private int inlet_flow=10;
        private int life_inlet_valve=10000;
        private int life_brewer_motor=5000;

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

        public int Inlet_flow
        {
            get { return inlet_flow; }
            set
            {
                if (value != inlet_flow)
                {
                    inlet_flow = value;
                    this.RaisePropertyChanged("Inlet_flow");
                }
            }
        }

        public int Life_inlet_valve
        {
            get { return life_inlet_valve; }
            set
            {
                if (value != life_inlet_valve)
                {
                    life_inlet_valve = value;
                    this.RaisePropertyChanged("Life_inlet_valve");
                }
            }
        }

        public int Life_brewer_motor
        {
            get { return life_brewer_motor; }
            set
            {
                if (value != life_brewer_motor)
                {
                    life_brewer_motor = value;
                    this.RaisePropertyChanged("Life_brewer_motor");
                }
            }
        }

        public Brewer():base()
        {

        }

        public Brewer(int componttype,int position):base(0x0001,componttype,position)
        {

        }

    }
}
