using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

namespace LanguageTools.model
{
    [DataContract]
    class DrinkItem:IComparable<DrinkItem>
    {
        [DataMember]
        public int id { get; set; }
        [DataMember]
        public int pid { get; set; }
        [DataMember]
        public String name { get; set; }
        [DataMember]
        public int localinfo { get; set; }
        public DrinkItem(int pid,int localinfo,string name)
        {
            this.pid = pid;
            this.localinfo = localinfo;
            this.name = name;
        }
        public int CompareTo(DrinkItem other)
        {
            if(null == other)
            {
                return 1;
            }
            return other.pid.CompareTo(this.pid);
        }
    }
}
