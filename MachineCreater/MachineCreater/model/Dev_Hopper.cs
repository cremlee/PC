using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
    public class Dev_Hopper:Device
    {
        private int powder_type = 0x81;
        private int motor_life  = 5000;
        private int max_capability = 15;
        private int dosage_value = 5;

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
        public int Powder_type
        {
            get { return powder_type; }
            set
            {
                if(value!= powder_type)
                {
                    powder_type = value;
                    this.RaisePropertyChanged("Powder_type");
                }
            }
        }
        public int Motor_life {
            get { return motor_life; }
            set
            {
                if(value != motor_life)
                {
                    motor_life = value;
                    this.RaisePropertyChanged("Motor_life");
                }
            }

        }

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
        public Dev_Hopper():base(0x0015,1)
        {

        }

        public Dev_Hopper(int position):base(0x0015, 1,position)
        {

        }


    }
}
