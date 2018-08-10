using LanguageTools.model;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Json;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace LanguageTools
{
   
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private int _lastIndex = -1;
        private List<DrinkItem> m_ls = null;
        private List<int> m_pid = new List<int>();
        public MainWindow()
        {
            InitializeComponent();
            btn_save.IsEnabled = false;
        }

        private void initComboxdata()
        {
            m_pid.Clear();
            m_ls.Sort();
            //chu shi hua combox
            foreach (var item in m_ls)
            {
                if(!m_pid.Contains(item.pid))
                    m_pid.Add(item.pid);
            }
        }
        private void btn_import_Click(object sender, RoutedEventArgs e)
        {

            // Create OpenFileDialog 
            Microsoft.Win32.OpenFileDialog dlg = new Microsoft.Win32.OpenFileDialog();

            // Set filter for file extension and default file extension 
            dlg.DefaultExt = ".lang";
            dlg.Filter = "Language File (.lang)|*.lang";

            // Display OpenFileDialog by calling ShowDialog method 
            Nullable<bool> result = dlg.ShowDialog();

            // Get the selected file name and display in a TextBox 
            if (result == true)
            {
                // Open document 
                string filename = dlg.FileName;           
                using (FileStream fsRead = new FileStream(filename, FileMode.Open))
                {
                    int fsLen = (int)fsRead.Length;
                    byte[] heByte = new byte[fsLen];
                    int r = fsRead.Read(heByte, 0, heByte.Length);
                    string myStr = System.Text.Encoding.UTF8.GetString(heByte);
                    Console.WriteLine(myStr);
                    DataContractJsonSerializer serializer = new DataContractJsonSerializer(typeof(List<DrinkItem>));
                    MemoryStream stream = new MemoryStream(Encoding.UTF8.GetBytes(myStr));
                    object ob = serializer.ReadObject(stream);
                    m_ls = (List<DrinkItem>)ob;

                }
                if (m_ls != null)
                {
                    initComboxdata();
                    foreach (var item in m_pid)
                    {
                        ComboBoxItem tmp = new ComboBoxItem();
                        tmp.Content = "Drink ID:" + item.ToString();
                        tmp.Tag = item;
                        this.cb_drink.Items.Add(tmp);
                    }

                }
            }
        }
        private void cb_drink_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (_lastIndex == this.cb_drink.SelectedIndex)
                return;
            if (_lastIndex != -1 && _lastIndex != this.cb_drink.SelectedIndex)
            {
                savelang();
                _lastIndex = this.cb_drink.SelectedIndex;              
            }
            if(_lastIndex ==-1)
            {
                _lastIndex = this.cb_drink.SelectedIndex;
            }
            TB_1.Text = "";
            TB_2.Text = "";
            TB_3.Text = "";
            TB_4.Text = "";
            TB_5.Text = "";
            TB_6.Text = "";
            TB_7.Text = "";
            TB_8.Text = "";

            ComboBoxItem tmp = this.cb_drink.SelectedItem as ComboBoxItem;
            int pid = (int)tmp.Tag;
            List<DrinkItem> aa= m_ls.FindAll(c => c.pid.Equals(pid));
            if(aa!=null)
            {
                showinfo(aa);
                btn_save.IsEnabled = true;
            }
        }

        private void showinfo(List<DrinkItem> aa)
        {
            foreach (var item in aa)
            {
                switch (item.localinfo)
                {
                    case 1:
                        TB_1.Text = item.name;
                        break;
                    case 2:
                        TB_2.Text = item.name;
                        break;
                    case 3:
                        TB_3.Text = item.name;
                        break;
                    case 4:
                        TB_4.Text = item.name;
                        break;
                    case 5:
                        TB_5.Text = item.name;
                        break;
                    case 6:
                        TB_6.Text = item.name;
                        break;
                    case 7:
                        TB_7.Text = item.name;
                        break;
                    case 8:
                        TB_8.Text = item.name;
                        break;
                    default:
                        break;
                }
            }
        }

        private void btn_save_Click(object sender, RoutedEventArgs e)
        {
            ComboBoxItem tmp = this.cb_drink.SelectedItem as ComboBoxItem;
            int pid = (int)tmp.Tag;
            List<DrinkItem> aa = new List<DrinkItem>(8);
            if (!TB_1.Text.Equals(""))
                aa.Add(new DrinkItem(pid, 1, TB_1.Text.ToString()));
            if (!TB_2.Text.Equals(""))
                aa.Add(new DrinkItem(pid, 2, TB_2.Text.ToString()));
            if (!TB_3.Text.Equals(""))
                aa.Add(new DrinkItem(pid, 3, TB_3.Text.ToString()));
            if (!TB_4.Text.Equals(""))
                aa.Add(new DrinkItem(pid, 4, TB_4.Text.ToString()));
            if (!TB_5.Text.Equals(""))
                aa.Add(new DrinkItem(pid, 5, TB_5.Text.ToString()));
            if (!TB_6.Text.Equals(""))
                aa.Add(new DrinkItem(pid, 6, TB_6.Text.ToString()));
            if (!TB_7.Text.Equals(""))
                aa.Add(new DrinkItem(pid, 7, TB_7.Text.ToString()));
            if (!TB_8.Text.Equals(""))
                aa.Add(new DrinkItem(pid, 8, TB_8.Text.ToString()));
            if (aa.Count > 0)
            {
                m_ls.RemoveAll(c => c.pid.Equals(pid));
                m_ls.AddRange(aa);
            }
        }

        private void savelang()
        {
            ComboBoxItem tmp = this.cb_drink.Items[_lastIndex] as ComboBoxItem;
            int pid = (int)tmp.Tag;
            List<DrinkItem> aa = new List<DrinkItem>(8);
            if (!TB_1.Text.Equals(""))
                aa.Add(new DrinkItem(pid, 1, TB_1.Text.ToString()));
            if (!TB_2.Text.Equals(""))
                aa.Add(new DrinkItem(pid, 2, TB_2.Text.ToString()));
            if (!TB_3.Text.Equals(""))
                aa.Add(new DrinkItem(pid, 3, TB_3.Text.ToString()));
            if (!TB_4.Text.Equals(""))
                aa.Add(new DrinkItem(pid, 4, TB_4.Text.ToString()));
            if (!TB_5.Text.Equals(""))
                aa.Add(new DrinkItem(pid, 5, TB_5.Text.ToString()));
            if (!TB_6.Text.Equals(""))
                aa.Add(new DrinkItem(pid, 6, TB_6.Text.ToString()));
            if (!TB_7.Text.Equals(""))
                aa.Add(new DrinkItem(pid, 7, TB_7.Text.ToString()));
            if (!TB_8.Text.Equals(""))
                aa.Add(new DrinkItem(pid, 8, TB_8.Text.ToString()));
            if (aa.Count > 0)
            {
                m_ls.RemoveAll(c => c.pid.Equals(pid));
                m_ls.AddRange(aa);
            }
        }

        private void btn_export_Click(object sender, RoutedEventArgs e)
        {
            Microsoft.Win32.SaveFileDialog dlg = new Microsoft.Win32.SaveFileDialog();
            dlg.DefaultExt = ".lang";
            dlg.Filter = "Language File (.lang)|*.lang";
            dlg.RestoreDirectory = true;
            bool? result = dlg.ShowDialog();
            if (result == true)
            {
                string ocalFilePath = dlg.FileName.ToString();
                DataContractJsonSerializer serializer = new DataContractJsonSerializer(typeof(List<DrinkItem>));
                //创建存储区为内存流
                System.IO.MemoryStream ms = new MemoryStream();
                //将json字符串写入内存流中
                serializer.WriteObject(ms, m_ls);
                System.IO.StreamReader reader = new StreamReader(ms);
                ms.Position = 0;
                string strRes = reader.ReadToEnd();
                reader.Close();
                ms.Close();
                byte[] myByte = System.Text.Encoding.UTF8.GetBytes(strRes);
                using (FileStream fsWrite = new FileStream(ocalFilePath, FileMode.Create))
                {
                    fsWrite.Write(myByte, 0, myByte.Length);
                };
            }
        }
    }
}
