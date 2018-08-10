using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
    public class Dev_Mixer_L:Mixer
    {
        public Dev_Mixer_L(int position):base(0x01, position) { }
    }
}
