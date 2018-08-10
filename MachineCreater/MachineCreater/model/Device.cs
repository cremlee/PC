using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MachineCreater.model
{
   public abstract class Device :IDevice
    {

        public Guid ID { get; set; }


        private int group_id;
        private int compent_type;
        private int position_id =1;



        public int Group_id
        {
            get { return group_id; }
            set
            {
                if (value != group_id)
                {
                    group_id = value;
                    this.RaisePropertyChanged("Group_id");
                }
            }
        }
        public int Compent_type
        {
            get { return compent_type; }
            set
            {
                if (value != compent_type)
                {
                    compent_type = value;
                    this.RaisePropertyChanged("Compent_type");
                }
            }
        }
        public int Position_id
        {
            get { return position_id; }
            set
            {
                if (value != position_id)
                {
                    position_id = value;
                    this.RaisePropertyChanged("Position_id");
                    this.RaisePropertyChanged("DeviceID");
                }
            }
        }

        public int DeviceID { get { return GetDeviceId(); } }

        public List<Int32> son_id_list { get; set; }
        public List<Int32> parent_id_list { get; set; }

        public Device() {
            son_id_list = new List<int>(1);
            parent_id_list = new List<int>(1);
        }

        public Device(int group_id,int compent_type,int position_id):this()
        {
            this.group_id = group_id;
            this.compent_type = compent_type;
            this.position_id = position_id;
        }

        public Device(int group_id, int compent_type) : this()
        {
            this.group_id = group_id;
            this.compent_type = compent_type;
        }

        public Device(int position_id) : this()
        {
            this.position_id = position_id;
        }
        public int getparentCount()
        {
            return parent_id_list.Count;
        }

        public int GetDeviceId()
        {
            return (group_id << 16) + (compent_type << 8) + (position_id);
        }

    }
}
