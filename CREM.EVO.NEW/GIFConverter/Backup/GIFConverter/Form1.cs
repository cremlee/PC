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
        private Bitmap curBitmap = null;
        private List<string> pathString = new List<string>();
        private List<Bitmap> thumbnailImage = new List<Bitmap>();
        private List<Bitmap> srcImage = new List<Bitmap>();
        private Bitmap temp = null;
        private int count = 0;
        private int number = 0;
        private int deleteNumber = 0;
        #endregion

        #region Functions
        //Open Function
        public void OpenImage()
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "所有图像文件 | *.bmp; *.pcx; *.png; *.jpg; *.gif;" +
                   "*.tif; *.ico; *.dxf; *.cgm; *.cdr; *.wmf; *.eps; *.emf|" +
                   "位图( *.bmp; *.jpg; *.png;...) | *.bmp; *.pcx; *.png; *.jpg; *.gif; *.tif; *.ico|" +
                   "矢量图( *.wmf; *.eps; *.emf;...) | *.dxf; *.cgm; *.cdr; *.wmf; *.eps; *.emf";
            ofd.ShowHelp = true;
            ofd.Title = "打开图像文件";
            if (ofd.ShowDialog() == DialogResult.OK)
            {
                curFileName = ofd.FileName;
                try
                {
                    curBitmap = (Bitmap)System.Drawing.Image.FromFile(curFileName);
                    pathString.Add(curFileName);
                    srcImage.Add(new Bitmap(curBitmap));
                    if (curBitmap.Width >= curBitmap.Height)
                        temp = new Bitmap(curBitmap, new Size(100, (int)(100 * curBitmap.Height / curBitmap.Width)));
                    else
                        temp = new Bitmap(curBitmap, new Size((int)(100 * curBitmap.Width / curBitmap.Height), 100));
                    thumbnailImage.Add(new Bitmap(temp));
                    count++;
                }
                catch (Exception exp)
                { MessageBox.Show(exp.Message); }
            }
            DisplayImages();
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
                for (int i = 0; i < count; i++)
                {
                    imageList1.ColorDepth = ColorDepth.Depth24Bit;
                    imageList1.ImageSize = new Size(thumbnailImage.ElementAt(i).Width, thumbnailImage.ElementAt(i).Height);
                    imageList1.Images.Add((Image)thumbnailImage.ElementAt(i));
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

        private void convertToGifToolStripMenuItem_Click(object sender, EventArgs e)
        {
            String outputPath = "C:\\"+number.ToString ()+".gif";
            if (File.Exists(outputPath))
            {
                imageBox.Image = null;
                number++;
                outputPath = "C:\\" + number.ToString() + ".gif";
            }
            AnimatedGifEncoder gif = new AnimatedGifEncoder();
            gif.Start(outputPath);
            gif.SetDelay(trackBar1.Value);
            gif.SetRepeat(0);
            for (int i = 0; i < count; i++)
            {
                gif.AddFrame(srcImage.ElementAt(i));
            }
            gif.Finish();
            imageBox.Image = (Image)Image.FromFile(outputPath);
            imageBox.Width = srcImage.ElementAt(0).Width;
            imageBox.Height = srcImage.ElementAt(0).Height;
            MessageBox.Show("Done!");
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

        private void listView1_MouseDown(object sender, MouseEventArgs e)
        {
            if (listView1.HitTest(e.X, e.Y).Item != null)
            {
                deleteNumber = listView1.HitTest(e.X, e.Y).Item.Index;
                if (e.Button == MouseButtons.Right)
                {
                    contextMenuStrip1.Visible = true;
                }
            }
        }

        private void blogLinkToolStripMenuItem_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("IEXPLORE.EXE", "http://dongtingyueh.blog.163.com/");
        }
        #endregion

      
    }
}
