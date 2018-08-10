using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
    public class Dev_SenWater:Sensor
    {

        public Dev_SenWater(int position) : base(0x0007, 0x01, position) { }
    }
}
