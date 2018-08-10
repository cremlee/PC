using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
    public class IDevice: NotificationObject
    {
        public static int  GROUP_BREWER = 0x0001;
        public  static  int GROUP_GRINDER = 0x0002;
         /* compnent type */
        public  static  int TYPE_ESBREWER = 0x0001;
        public  static  int TYPE_MONOBREWER = 0x0002;
        public static  int TYPE_FILTERBREWER = 0x0003;
    }
}
