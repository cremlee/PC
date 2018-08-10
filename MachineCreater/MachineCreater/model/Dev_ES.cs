using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
   public class Dev_ES:Brewer
    {
        //1）四个位置电压（）	vol_max_up;
        //                    vol_touch;
        //		vol_press;
        //		vol_max_down;

        private float vol_max_up = 3.3f;
        private float vol_touch = 3.3f;
        private float vol_press = 3.3f;
        private float vol_max_down = 3.3f;

        public float Vol_max_up { get { return vol_max_up; } }
        public float Vol_touch { get { return vol_touch; } }
        public float Vol_press { get { return vol_press; } }
        public float Vol_max_down { get { return vol_max_down; } }

     
        public Dev_ES(int position):base(01,position)
        {

        }
    }
}
