using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
    public class Dev_SenDoor:Sensor
    {
        public Dev_SenDoor(int position) : base(0x001a, 0x01, position) { }
    }
}
