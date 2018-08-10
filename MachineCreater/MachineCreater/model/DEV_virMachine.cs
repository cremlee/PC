using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
   public class DEV_virMachine:Device
    {
        public DEV_virMachine(int position) : base(0x0000,02, position) { }
    }
}
