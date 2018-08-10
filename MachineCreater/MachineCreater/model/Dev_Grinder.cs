using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
   public class Dev_Grinder :Device
    {
        private int dosage_value =5;
        private int motor_life=5000;
        public int Dosage_value
        {
            get { return dosage_value; }
            set
            {
                if (value != dosage_value)
                {
                    dosage_value = value;
                    this.RaisePropertyChanged("Dosage_value");
                }
            }
        }
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

        public Dev_Grinder(int position):base(0x0002,01,position)
        {

        }       
    }  
}
