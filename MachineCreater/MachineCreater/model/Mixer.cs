using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
    public class Mixer:Device
    {    
        //      2）Mixer最大容积 max_volume
        //      3）热水阀的水量校准值（cal_hot_volume）
        //      4）冷水阀的水量校准值（cal_cold_volume）
        //      5）热水阀的使用周期（life_hot_valve）
        //      6）冷水阀的使用周期（life_cold_valve）
        //      7）马达的速度 motor_speed
        //      8）马达的使用周期 life_motor;
        //      9) 搅拌部件的使用周期 life_whipper
        
        private int max_capability = 10;
        private int run_speed = 80;
        private int hot_valve_flow  = 10;
        private int cold_valve_flow = 10;
        private int life_motor = 5000;
        private int life_hot_valve = 5000;
        private int life_cold_valve = 5000;
        private int life_whipper = 5000;

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

        public int Run_speed
        {
            get { return run_speed; }
            set
            {
                if (value != run_speed)
                {
                    run_speed = value;
                    this.RaisePropertyChanged("Run_speed");
                }
            }
        }

        public int Hot_valve_flow
        {
            get { return hot_valve_flow; }
            set
            {
                if (value != hot_valve_flow)
                {
                    hot_valve_flow = value;
                    this.RaisePropertyChanged("Hot_valve_flow");
                }
            }
        }

        public int Cold_valve_flow
        {
            get { return cold_valve_flow; }
            set
            {
                if (value != cold_valve_flow)
                {
                    cold_valve_flow = value;
                    this.RaisePropertyChanged("Cold_valve_flow");
                }
            }
        }

        public int Life_motor
        {
            get { return life_motor; }
            set
            {
                if (value != life_motor)
                {
                    life_motor = value;
                    this.RaisePropertyChanged("Life_motor");
                }
            }
        }

        public int Life_hot_valve
        {
            get { return life_hot_valve; }
            set
            {
                if (value != life_hot_valve)
                {
                    life_hot_valve = value;
                    this.RaisePropertyChanged("Life_hot_valve");
                }
            }
        }

        public int Life_whipper
        {
            get { return life_whipper; }
            set
            {
                if (value != life_whipper)
                {
                    life_whipper = value;
                    this.RaisePropertyChanged("Life_whipper");
                }
            }
        }

        public int Life_cold_valve
        {
            get { return life_cold_valve; }
            set
            {
                if (value != life_cold_valve)
                {
                    life_cold_valve = value;
                    this.RaisePropertyChanged("Life_cold_valve");
                }
            }
        }

        public Mixer(int type,int position):base(0x0004, type, position) { }
        
    }
}
