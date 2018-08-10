using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
    public class Dev_Canister:Dev_Hopper
    {
        public Dev_Canister(int type,int position)
        {
            this.Group_id = 0x0003;
            this.Compent_type = type;
            this.Position_id = position;
        }
    }
}
