using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
    public class Dev_Fan:Device
    {
        private int life_motor =500;
        private int run_speed =80;

        public int Life_motor
        {
            get { return life_motor; }
            set
            {
                if(value!= life_motor)
                {
                    life_motor = value;
                    this.RaisePropertyChanged("Life_motor");
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

        public Dev_Fan(int position):base(0x0014,01,position)
        {

        }
    }
}
