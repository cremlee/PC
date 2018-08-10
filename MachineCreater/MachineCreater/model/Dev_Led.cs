using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
    public class Dev_Led:Device
    {
        private int led_idel_mode=1;
        private int led_idel_color=3;
        private int led_idel_intensity=1;
        private int led_warn_mode=2;
        private int led_warn_color=1;
        private int led_warn_intensity=1;
        private int life_led=5000;

        public int Led_idel_mode
        {
            get { return led_idel_mode; }
            set
            {
                if (value != led_idel_mode)
                {
                    led_idel_mode = value;
                    this.RaisePropertyChanged("Led_idel_mode");
                }
            }
        }

        public int Led_idel_color
        {
            get { return led_idel_color; }
            set
            {
                if (value != led_idel_color)
                {
                    led_idel_color = value;
                    this.RaisePropertyChanged("Led_idel_color");
                }
            }
        }

        public int Led_idel_intensity
        {
            get { return led_idel_intensity; }
            set
            {
                if (value != led_idel_intensity)
                {
                    led_idel_intensity = value;
                    this.RaisePropertyChanged("Led_idel_intensity");
                }
            }
        }

        public int Led_warn_mode
        {
            get { return led_warn_mode; }
            set
            {
                if (value != led_warn_mode)
                {
                    led_warn_mode = value;
                    this.RaisePropertyChanged("Led_warn_mode");
                }
            }
        }

        public int Led_warn_color
        {
            get { return led_warn_color; }
            set
            {
                if (value != led_warn_color)
                {
                    led_warn_color = value;
                    this.RaisePropertyChanged("Led_warn_color");
                }
            }
        }

        public int Led_warn_intensity
        {
            get { return led_warn_intensity; }
            set
            {
                if (value != led_warn_intensity)
                {
                    led_warn_intensity = value;
                    this.RaisePropertyChanged("Led_warn_intensity");
                }
            }
        }

        public int Life_led
        {
            get { return life_led; }
            set
            {
                if (value != life_led)
                {
                    life_led = value;
                    this.RaisePropertyChanged("Life_led");
                }
            }
        }

        public Dev_Led(int type,int position) : base(0x000c, type, position) { }
    }
}
