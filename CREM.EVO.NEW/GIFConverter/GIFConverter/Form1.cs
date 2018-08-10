using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Drawing2D;
using System.IO;
using Gif.Components;
using System.Threading;

namespace GIFConverter
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        #region variances
        private string curFileName = null;
        //private Bitmap curBitmap = null;
        private List<string> pathString = new List<string>();
        private List<Bitmap> thumbnailImage = new List<Bitmap>();
        private List<Bitmap> srcImage = new List<Bitmap>();
        private Bitmap temp = null;
        private int count = 0;
        private int number = 0;
        private int deleteNumber = 0;
        private int currentindex = 0;
        #endregion
        private int tm = 100;

        public delegate void updateui(string outputfile);
        #region Functions
        //Open Function
        public void Updateui(string outputfile)
        {
            if (Ispreview)
            {
                imageBox.Image = ImageHelper.BytesToImage(ImageHelper.getImageByte(outputfile));
            }else
            {
                MessageBox.Show("convert OK!!");
            }
            this.button1.Enabled = true;
            this.button2.Enabled = true;
        }

        
        public void OpenImage()
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "所有图像文件 | *.bmp; *.pcx; *.png; *.jpg; *.gif;" +
                   "*.tif; *.ico; *.dxf; *.cgm; *.cdr; *.wmf; *.eps; *.emf|" +
                   "位图( *.bmp; *.jpg; *.png;...) | *.bmp; *.pcx; *.png; *.jpg; *.gif; *.tif; *.ico|" +
                   "矢量图( *.wmf; *.eps; *.emf;...) | *.dxf; *.cgm; *.cdr; *.wmf; *.eps; *.emf";
            ofd.ShowHelp = true;
            ofd.Multiselect = true;
            ofd.Title = "打开图像文件";
            if (ofd.ShowDialog() == DialogResult.OK)
            {
                this.progressBar1.Value = 0;
                this.progressBar1.Maximum = ofd.FileNames.Length;
                for (int i = 0; i < ofd.FileNames.Length; i++)
                {
                    curFileName = ofd.FileNames[i];
                    try
                    {
                        dealwithpic(curFileName);
                    }
                    catch (Exception exp)
                    { MessageBox.Show(exp.Message); }
                }
                
            }
            DisplayImages();
        }

        private void dealwithpic(string picname)
        {

           Bitmap curBitmap = (Bitmap)System.Drawing.Image.FromFile(picname);
            pathString.Insert(currentindex,picname);
            srcImage.Add(new Bitmap(curBitmap));
            if (curBitmap.Width >= curBitmap.Height)
                temp = new Bitmap(curBitmap, new Size(100, (int)(100 * curBitmap.Height / curBitmap.Width)));
            else
                temp = new Bitmap(curBitmap, new Size((int)(100 * curBitmap.Width / curBitmap.Height), 100));
            thumbnailImage.Insert(currentindex, new Bitmap(temp));
            this.progressBar1.Value++;
            count++;
        }

        //Save Function
        public void SaveImage()
        {
            if (imageBox.Image != null)
            {
                SaveFileDialog sfd = new SaveFileDialog();
                sfd.Filter = "(*.gif)|*.gif";
                if (sfd.ShowDialog() == DialogResult.OK)
                {
                    if (File.Exists(sfd.FileName))
                    {
                        File.Delete(sfd.FileName);
                        imageBox.Image.Save(sfd.FileName);
                    }
                    else
                        imageBox.Image.Save(sfd.FileName);
                }
            }
            else
            {
                MessageBox.Show("Please open an image!");
            }
        }

        //Display function
        private void DisplayImages()
        {
            listView1.Clear();
            imageList1.Images.Clear();
            if (count != 0)
            {
                listView1.View = View.LargeIcon;
                for (int i = 0; i < count; i++)
                {
                    imageList1.ColorDepth = ColorDepth.Depth32Bit;
                    imageList1.ImageSize = new Size(100,75);
                    imageList1.Images.Add(Image.FromFile(pathString[i]));
                    listView1.LargeImageList = imageList1;
                    listView1.Items.Add(i.ToString());
                    listView1.Items[i].ImageIndex = i;
                }
            }

        }
        #endregion

        #region Others
        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            label1.Text = "Time interval:"+trackBar1.Value.ToString()+"ms";
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenImage();
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveImage();
        }

        private void deleteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            pathString.RemoveAt(deleteNumber);
            thumbnailImage.RemoveAt(deleteNumber);
            srcImage.RemoveAt(deleteNumber);
            count--;
            DisplayImages();
        }

        private void setToolStripVisible(ToolTriptype tooltriptype,bool isvisible)
        {
            switch (tooltriptype)
            {
                case ToolTriptype.all:
                    this.addToolStripMenuItem.Visible = isvisible;
                    this.deleteToolStripMenuItem.Visible = isvisible;
                    break;
                case ToolTriptype.add:
                    this.addToolStripMenuItem.Visible = isvisible;
                    //this.deleteToolStripMenuItem.Visible = isvisible;
                    break;
                case ToolTriptype.del:
                    this.deleteToolStripMenuItem.Visible = isvisible;
                    break;
                default:
                    break;
            }
        }
        private void listView1_MouseDown(object sender, MouseEventArgs e)
        {
            if (listView1.HitTest(e.X, e.Y).Item != null)
            {
               
                deleteNumber = listView1.HitTest(e.X, e.Y).Item.Index;
                currentindex = deleteNumber + 1;
                if (e.Button == MouseButtons.Right)
                {
                    //contextMenuStrip1.Visible = true;
                    setToolStripVisible(ToolTriptype.all, true);
                }
            }else
            {               
                    setToolStripVisible(ToolTriptype.del, false);
                currentindex = thumbnailImage.Count;
            }

        }

        public enum ToolTriptype
        {
            all =0x01,
            add =0x02,
            del =0x03
        }
        private void blogLinkToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //System.Diagnostics.Process.Start("IEXPLORE.EXE", "http://dongtingyueh.blog.163.com/");
        }

        #endregion


        private void addToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenImage();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (srcImage.Count <= 0)
            {
                MessageBox.Show("Select picture first!");
                return;
            }

            Ispreview = false;
            imageBox.Image = null;
            String outputPath = "";
            SaveFileDialog sdg = new SaveFileDialog();
            sdg.Filter = "GIF | *.gif";
            if (sdg.ShowDialog() == DialogResult.OK)
            {
                 outputPath = sdg.FileName;
                if (File.Exists(outputPath))
                {
                    File.Delete(outputPath);
                }
                AnimatedGifEncoder gif = new AnimatedGifEncoder();
                tm = trackBar1.Value;
                this.button1.Enabled = false;
                this.button2.Enabled = false;
                this.progressBar1.Value = 0;
                this.progressBar1.Maximum = srcImage.Count;
                startConvertThread(outputPath);
            }
            
        }

        private void startConvertThread(string outputfile)
        {
            ThreadPool.SetMaxThreads(1, 1);
            ThreadPool.QueueUserWorkItem(new WaitCallback(convert2gif), outputfile);

        }
        private void convert2gif(object outputfile)
        {
            lock (this)
            {
                AnimatedGifEncoder gif = new AnimatedGifEncoder();
                gif.Start((string)outputfile);
                gif.SetDelay(tm);
                gif.SetRepeat(0);            
                for (int i = 0; i < count; i++)
                {
                    gif.AddFrame(srcImage.ElementAt(i));
                    this.BeginInvoke(new updateui(c => { this.progressBar1.Value++; }), "");
                }
                gif.Finish();
                this.BeginInvoke(new updateui(Updateui), outputfile);
            }
        }
        private bool Ispreview = false;
        private void button1_Click(object sender, EventArgs e)
        {
            if (srcImage.Count<=0)
            {
                MessageBox.Show("Select picture first!");
                return;
            }
            this.progressBar1.Value = 0;
            this.progressBar1.Maximum = srcImage.Count;
            Ispreview = true;
            imageBox.Image = null;
            String outputPath = AppDomain.CurrentDomain.BaseDirectory + "preview.gif";
            if (File.Exists(outputPath))
            {
                File.Delete(outputPath);
            }
            tm = trackBar1.Value;
            this.button1.Enabled = false;
            this.button2.Enabled = false;
            startConvertThread(outputPath);
        }
    }
}
