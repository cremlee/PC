using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
   public class Pump:Device
    {
        private int motor_life= 0xe9dad0;
        private int speed=100;
        public int Motor_life
        {
            get { return motor_life; }
            set
            {
                if (value != motor_life)
                {
                    motor_life = value;
                    this.RaisePropertyChanged("Motor_life");
                }
            }
        }
        public int Speed
        {
            get { return speed; }
            set
            {
                if (value != speed)
                {
                    speed = value;
                    this.RaisePropertyChanged("Speed");
                }
            }
        }
        public Pump(int group,int type, int position):base(group, type, position) { }
    }
}
