using KeyManager.module;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace KeyManager
{
    public partial class Form1 : Form
    {
        private Alikey _Alikey;
        private Wechatkey _Wechatkey;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            _Alikey = new Alikey();
            _Wechatkey = new Wechatkey();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private string _EncryptKey = "Crem1234";
        /// <summary>
        /// 进行DES加密。
        /// </summary>
        /// <param name="pToEncrypt">要加密的字符串。</param>
        /// <param name="sKey">密钥，且必须为8位。</param>
        /// <returns>以Base64格式返回的加密字符串。</returns>
        public byte[] Encrypt(byte[] inputByteArray)
        {
            using (DESCryptoServiceProvider des = new DESCryptoServiceProvider())
            {

                des.Key = ASCIIEncoding.ASCII.GetBytes(_EncryptKey);
                des.IV = ASCIIEncoding.ASCII.GetBytes(_EncryptKey);
                System.IO.MemoryStream ms = new System.IO.MemoryStream();
                using (CryptoStream cs = new CryptoStream(ms, des.CreateEncryptor(), CryptoStreamMode.Write))
                {
                    cs.Write(inputByteArray, 0, inputByteArray.Length);
                    cs.FlushFinalBlock();
                    cs.Close();
                }
                string aa = Convert.ToBase64String(ms.ToArray());
                ms.Close();
                byte[] ret = System.Text.Encoding.UTF8.GetBytes(aa);
                return ret;
            }
        }
        private void button1_Click(object sender, EventArgs e)
        {
            _Alikey.appid = this.tb_appid1.Text.ToString().Replace(" ", ""); ;
            _Alikey.pvkey = this.rtb_pv.Text.ToString().Replace(" ", "");
            _Alikey.pbkey = this.rtb_pb.Text.ToString().Replace(" ","");
            _Alikey.authtype = "RSA2";
            _Alikey.info = this.tb_name1.Text.ToString().Replace(" ", ""); ;
            byte[] fileheader = new byte[20];
            byte[] tmp = System.Text.Encoding.ASCII.GetBytes(_Alikey.info);
            Array.Copy(tmp, fileheader, (int)(tmp.Length > 20 ? 20 : tmp.Length));
            byte[] tlv = new byte[1024];
            int len_tlv = 0;
            //header        
            Array.Copy(fileheader, 0, tlv, len_tlv, 20);
            len_tlv += 20;
            //appid
            tlv[len_tlv] = 1;
            len_tlv++;
            tmp = System.Text.Encoding.ASCII.GetBytes(_Alikey.appid);
            tlv[len_tlv ] = (byte)(tmp.Length >>8);
            tlv[len_tlv + 1] =(byte)(tmp.Length);
            len_tlv += 2;
            Array.Copy(tmp, 0,tlv, len_tlv, tmp.Length);
            len_tlv += tmp.Length;
            //pvkey
            tlv[len_tlv] = 2;
            len_tlv++;
            tmp = System.Text.Encoding.ASCII.GetBytes(_Alikey.pvkey);
            tlv[len_tlv ] = (byte)(tmp.Length >> 8);
            tlv[len_tlv + 1] = (byte)(tmp.Length);
            len_tlv += 2;
            Array.Copy(tmp, 0, tlv, len_tlv, tmp.Length);
            len_tlv += tmp.Length;
            //pbkey
            tlv[len_tlv] = 3;
            len_tlv++;
            tmp = System.Text.Encoding.ASCII.GetBytes(_Alikey.pbkey);
            tlv[len_tlv + 0] = (byte)(tmp.Length >> 8);
            tlv[len_tlv + 1] = (byte)(tmp.Length);
            len_tlv += 2;
            Array.Copy(tmp, 0, tlv, len_tlv, tmp.Length);
            len_tlv += tmp.Length;
            //authkey
            tlv[len_tlv] = 5;
            len_tlv++;
            tmp = System.Text.Encoding.ASCII.GetBytes(_Alikey.authtype);
            tlv[len_tlv + 0] = (byte)(tmp.Length >> 8);
            tlv[len_tlv + 1] = (byte)(tmp.Length);
            len_tlv += 2;
            Array.Copy(tmp, 0, tlv, len_tlv, tmp.Length);
            len_tlv += tmp.Length;

            byte[] outbuf = new byte[len_tlv];
            Array.Copy(tlv,outbuf, len_tlv);

            byte[] doencry = Encrypt(outbuf);

            FileStream fs = new FileStream("d:\\pay.auk", FileMode.Create);
            BinaryWriter bw = new BinaryWriter(fs);
            fs.Write(doencry, 0, doencry.Length);
            bw.Close();
            fs.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            _Wechatkey.appid = this.tb_appid2.Text.ToString().Replace(" ", ""); ;
            _Wechatkey.pvkey = this.rtb_pv2.Text.ToString().Replace(" ", "");
            _Wechatkey.mchid = this.tb_mchid.Text.ToString().Replace(" ", "");
            _Wechatkey.info = this.tb_name2.Text.ToString().Replace(" ", ""); ;
            byte[] fileheader = new byte[20];
            byte[] tmp = System.Text.Encoding.ASCII.GetBytes(_Wechatkey.info);
            Array.Copy(tmp, fileheader, (int)(tmp.Length > 20 ? 20 : tmp.Length));
            byte[] tlv = new byte[1024];
            int len_tlv = 0;
            //header        
            Array.Copy(fileheader, 0, tlv, len_tlv, 20);
            len_tlv += 20;
            //appid
            tlv[len_tlv] = 1;
            len_tlv++;
            tmp = System.Text.Encoding.ASCII.GetBytes(_Wechatkey.appid);
            tlv[len_tlv] = (byte)(tmp.Length >> 8);
            tlv[len_tlv + 1] = (byte)(tmp.Length);
            len_tlv += 2;
            Array.Copy(tmp, 0, tlv, len_tlv, tmp.Length);
            len_tlv += tmp.Length;
            //pvkey
            tlv[len_tlv] = 2;
            len_tlv++;
            tmp = System.Text.Encoding.ASCII.GetBytes(_Wechatkey.pvkey);
            tlv[len_tlv] = (byte)(tmp.Length >> 8);
            tlv[len_tlv + 1] = (byte)(tmp.Length);
            len_tlv += 2;
            Array.Copy(tmp, 0, tlv, len_tlv, tmp.Length);
            len_tlv += tmp.Length;
            //pbkey
            tlv[len_tlv] = 4;
            len_tlv++;
            tmp = System.Text.Encoding.ASCII.GetBytes(_Wechatkey.mchid);
            tlv[len_tlv + 0] = (byte)(tmp.Length >> 8);
            tlv[len_tlv + 1] = (byte)(tmp.Length);
            len_tlv += 2;
            Array.Copy(tmp, 0, tlv, len_tlv, tmp.Length);
            len_tlv += tmp.Length;

            byte[] outbuf = new byte[len_tlv];
            Array.Copy(tlv, outbuf, len_tlv);

            byte[] doencry = Encrypt(outbuf);

            FileStream fs = new FileStream("d:\\pay.wuk", FileMode.Create);
            BinaryWriter bw = new BinaryWriter(fs);
            fs.Write(doencry, 0, doencry.Length);
            bw.Close();
            fs.Close();
            
        }
    }
}
