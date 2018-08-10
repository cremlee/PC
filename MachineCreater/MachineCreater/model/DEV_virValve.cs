using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
   public class DEV_virValve : Device
    {
        public DEV_virValve(int position) : base(0x0000,00, position) { }
    }
}
