using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
    public class Dev_SenNtc:Sensor
    {

        //1）temp-block
        //2）temp-eco
        //3）temp-warning
        //4）temp-noraml
        //5）temp-offset
        private int temperature_block =70;
        private int temperature_eco=60;
        private int temperature_warning=85;
        private int temperature_normal=95;
        private int temperature_offset=0;

        public int Temperature_block
        {
            get { return temperature_block; }
            set
            {
                if (value != temperature_block)
                {
                    temperature_block = value;
                    this.RaisePropertyChanged("Temperature_block");
                }
            }
        }

        public int Temperature_eco
        {
            get { return temperature_eco; }
            set
            {
                if (value != temperature_eco)
                {
                    temperature_eco = value;
                    this.RaisePropertyChanged("Temperature_eco");
                }
            }
        }

        public int Temperature_warning
        {
            get { return temperature_warning; }
            set
            {
                if (value != temperature_warning)
                {
                    temperature_warning = value;
                    this.RaisePropertyChanged("Temperature_warning");
                }
            }
        }

        public int Temperature_normal
        {
            get { return temperature_normal; }
            set
            {
                if (value != temperature_normal)
                {
                    temperature_normal = value;
                    this.RaisePropertyChanged("Temperature_normal");
                }
            }
        }

        public int Temperature_offset
        {
            get { return temperature_offset; }
            set
            {
                if (value != temperature_offset)
                {
                    temperature_offset = value;
                    this.RaisePropertyChanged("Temperature_offset");
                }
            }
        }

        public Dev_SenNtc(int postion) : base(0x0006, 0x01, postion) { }

    }
}
