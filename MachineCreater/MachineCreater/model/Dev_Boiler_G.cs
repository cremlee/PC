using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
    public class Dev_Boiler_G : Boiler
    {
        public Dev_Boiler_G(int position) : base(0x0002, position) { }
    }
}
