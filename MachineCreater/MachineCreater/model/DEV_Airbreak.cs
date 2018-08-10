using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
   public class DEV_Airbreak:Device
    {
        public DEV_Airbreak(int position) : base(0x000e, 0x01, position) { }
    }
}
