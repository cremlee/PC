using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
  public  class DEV_Waterpump:Pump
    {
        public DEV_Waterpump(int type, int position) : base(0x000a, type, position) { }
    }
}
