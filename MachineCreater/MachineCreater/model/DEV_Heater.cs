using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
   public class DEV_Heater :Heater
    {
        public DEV_Heater(int type,int position):base(0x0016,type,position)
        {

        }
    }
}
