using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
    public class Dev_SenCup:Sensor
    {
        public Dev_SenCup(int position):base(0x0008,0x0001, position) { }
    }
}
