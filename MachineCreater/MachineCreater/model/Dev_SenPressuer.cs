using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
    public class Dev_SenPressuer : Sensor
    {
        public Dev_SenPressuer(int type,int position) : base(0x0009, type, position) { }
    }
}
