using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
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
using Microsoft.Win32;
using System.Windows.Forms;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Runtime.InteropServices;
using System.Collections;
using System.Threading;

/*
Background
Branding
DrinkBeverageImage      storyboard
DrinkDispensingImage    gif
Icons                   drinkpicture 
pdf                     
ScreenSaver
Video

*/



namespace EVO.TOOL.MAKEPIC
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {

        private static string FOLDER_PIC_BACKGROUND = "\\evo\\Background\\";
        private static string FOLDER_PIC_BRAND = "\\evo\\Branding\\";
        private static string FOLDER_PIC_STORY = "\\evo\\DrinkBeverageImage\\";
        private static string FOLDER_PIC_DRINKICON = "\\evo\\Icons\\";
        private static string FOLDER_PIC_GIF = "\\evo\\DrinkDispensingImage\\";

        public MainWindow()
        {
            InitializeComponent();
            foreach (System.Windows.Media.FontFamily font in Fonts.SystemFontFamilies)  //遍历字体集合中德字体
            {

                cbfont.Items.Add(new Items(font));//将参数传递到自定义控件
            }
        }
        private bool isdrag = false;
        private ImageType _crtImageType = ImageType.Background;
        private void c_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            //isdrag = true;
        }
        private void c_MouseUp(object sender, MouseButtonEventArgs e)
        {
            //isdrag = false;
        }
        private void c_MouseMove(object sender, System.Windows.Input.MouseEventArgs e)
        {
            //if (!isdrag) return;
            //var control = (sender as UIElement);
            //control.SetValue(Canvas.LeftProperty, e.GetPosition(container).X - control.DesiredSize.Width / 2);
            //control.SetValue(Canvas.TopProperty, e.GetPosition(container).Y - control.DesiredSize.Height / 2);
            //var vector = VisualTreeHelper.GetOffset(control);
            //this.Title = vector.X + "/" + vector.Y;
        }
        public List<TextBlock> _myLstText = new List<TextBlock>();
        private void Button_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Element_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            isdrag = false;

        }
        private UIElement _crtchd;
        private void Element_MouseMove(object sender, System.Windows.Input.MouseEventArgs e)
        {
            if (!isdrag) return;
            var control = (sender as UIElement);
            control.SetValue(Canvas.LeftProperty, e.GetPosition(container).X - control.DesiredSize.Width / 2);
            control.SetValue(Canvas.TopProperty, e.GetPosition(container).Y - control.DesiredSize.Height / 2);
            var vector = VisualTreeHelper.GetOffset(control);

        }

        private void Element_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            isdrag = true;
            _crtchd = sender as UIElement;

        }


        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            TextBlock mytext = new TextBlock();
            container.Children.Add(mytext);
            mytext.FontSize = _fontSize;
            mytext.Foreground = _fontColor;
            mytext.Text = TextIn.Text;
            mytext.VerticalAlignment = System.Windows.VerticalAlignment.Center;
            mytext.HorizontalAlignment = System.Windows.HorizontalAlignment.Center;
            mytext.SetValue(Canvas.TopProperty, (double)imgbk.GetValue(Canvas.HeightProperty) / 2);
            mytext.SetValue(Canvas.LeftProperty, (double)imgbk.GetValue(Canvas.WidthProperty) / 2);
            mytext.AddHandler(System.Windows.Controls.Button.MouseLeftButtonDownEvent, new MouseButtonEventHandler(Element_MouseLeftButtonDown), true);
            mytext.AddHandler(System.Windows.Controls.Button.MouseMoveEvent, new System.Windows.Input.MouseEventHandler(Element_MouseMove), true);
            mytext.AddHandler(System.Windows.Controls.Button.MouseLeftButtonUpEvent, new MouseButtonEventHandler(Element_MouseLeftButtonUp), true);
            _myLstText.Add(mytext);
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            foreach (var item in _myLstText)
            {
                if (item.Equals((_crtchd as TextBlock)))
                {
                    _myLstText.Remove(item);
                    break;
                }
            }

            container.Children.Remove(_crtchd);
        }
        private double _fontSize = 48;
        private System.Windows.Media.Brush _fontColor = System.Windows.Media.Brushes.Black;
        private System.Windows.Media.FontFamily _FontFamily = null;
        private double _sacleRate = 1;

        public static Bitmap KiResizeImage(Bitmap bmp, int newW, int newH)
        {
            try
            {
                Bitmap b = new Bitmap(newW, newH);
                Graphics g = Graphics.FromImage(b);

                g.InterpolationMode = InterpolationMode.HighQualityBicubic;

                g.DrawImage(bmp, new System.Drawing.Rectangle(0, 0, newW, newH), new System.Drawing.Rectangle(0, 0, bmp.Width, bmp.Height), GraphicsUnit.Pixel);
                g.Dispose();

                return b;
            }
            catch
            {
                return null;
            }
        }
        [DllImport("gdi32.dll", SetLastError = true)]

        private static extern bool DeleteObject(IntPtr hObject);



        /// <summary>

        /// 从bitmap转换成ImageSource

        /// </summary>

        /// <param name="icon"></param>

        /// <returns></returns>

        public static ImageSource ChangeBitmapToImageSource(Bitmap bitmap)

        {

            //Bitmap bitmap = icon.ToBitmap();

            IntPtr hBitmap = bitmap.GetHbitmap();


            ImageSource wpfBitmap = System.Windows.Interop.Imaging.CreateBitmapSourceFromHBitmap(

                hBitmap,

                IntPtr.Zero,

                Int32Rect.Empty,

                BitmapSizeOptions.FromEmptyOptions());


            if (!DeleteObject(hBitmap))

            {

                throw new System.ComponentModel.Win32Exception();

            }


            return wpfBitmap;

        }
        public System.Drawing.Bitmap WpfBitmapSourceToBitmap(BitmapSource s)
        {
            System.Drawing.Bitmap bmp = new System.Drawing.Bitmap(s.PixelWidth, s.PixelHeight, System.Drawing.Imaging.PixelFormat.Format32bppPArgb);
            System.Drawing.Imaging.BitmapData data = bmp.LockBits(new System.Drawing.Rectangle(System.Drawing.Point.Empty, bmp.Size), System.Drawing.Imaging.ImageLockMode.WriteOnly, System.Drawing.Imaging.PixelFormat.Format32bppPArgb);
            s.CopyPixels(Int32Rect.Empty, data.Scan0, data.Height * data.Stride, data.Stride);
            bmp.UnlockBits(data);
            return bmp;
        }
        public static BitmapSource CreateBitmapSourceFromBitmap(Bitmap bitmap)
        {
            if (bitmap == null)
                throw new ArgumentNullException("bitmap");

            return System.Windows.Interop.Imaging.CreateBitmapSourceFromHBitmap(
                bitmap.GetHbitmap(),
                IntPtr.Zero,
                Int32Rect.Empty,
                BitmapSizeOptions.FromEmptyOptions());
        }
        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
           if( img.Source == null)
            { System.Windows.MessageBox.Show("Please select the picture source first!");return; }
            BitmapSource bgImage = CreateBitmapSourceFromBitmap(KiResizeImage(WpfBitmapSourceToBitmap((BitmapSource)img.Source), (int)CrtPicWidth, (int)CrtPicHeight));
            //(BitmapSource)img.Source;
            RenderTargetBitmap composeImage = new RenderTargetBitmap((int)CrtPicWidth, (int)CrtPicHeight, bgImage.DpiX, bgImage.DpiY, PixelFormats.Default);
            double scaleX = bgImage.Width / imgbk.ActualWidth;
            double scaleY = bgImage.Height / imgbk.ActualHeight;

            DrawingVisual drawingVisual = new DrawingVisual();
            DrawingContext drawingContext = drawingVisual.RenderOpen();
            drawingContext.DrawImage(bgImage, new Rect(0, 0, bgImage.Width, bgImage.Height));

            foreach (var item in _myLstText)
            {
                FormattedText signatureTxt = new FormattedText(item.Text,
                                                   System.Globalization.CultureInfo.CurrentCulture,
                                                   System.Windows.FlowDirection.LeftToRight,
                                                   new Typeface(System.Windows.SystemFonts.MessageFontFamily, FontStyles.Normal, FontWeights.Normal, FontStretches.Normal),
                                                   item.FontSize,
                                                   item.Foreground);



                double x2 = ((double)item.GetValue(Canvas.LeftProperty));
                double y2 = ((double)item.GetValue(Canvas.TopProperty));
                drawingContext.DrawText(signatureTxt, new System.Windows.Point(x2, y2));
            }

            drawingContext.Close();
            composeImage.Render(drawingVisual);
            //定义一个JPG编码器
            //JpegBitmapEncoder bitmapEncoder = new JpegBitmapEncoder();
            //加入第一帧
            PngBitmapEncoder bitmapEncoder = new PngBitmapEncoder();
            bitmapEncoder.Frames.Add(BitmapFrame.Create(composeImage));

            //保存至文件（不会修改源文件，将修改后的图片保存至程序目录下）


            Microsoft.Win32.SaveFileDialog openFileDialog = new Microsoft.Win32.SaveFileDialog();
            openFileDialog.RestoreDirectory = true;
            openFileDialog.Filter = "png文件|*.png|jpg文件|*.jpg|所有文件|*.*";
            openFileDialog.FilterIndex = 1;
            string dfp = AppDomain
                .CurrentDomain.BaseDirectory + "PicMg\\background\\";
            switch (_crtImageType)
            {
                case ImageType.Background:
                    dfp = AppDomain
                .CurrentDomain.BaseDirectory + "PicMg\\background\\";
                    break;
                case ImageType.StroyBoard:
                    dfp = AppDomain
                .CurrentDomain.BaseDirectory + "PicMg\\storyboard\\";
                    break;
                case ImageType.Drinkicon:
                    dfp = AppDomain
                .CurrentDomain.BaseDirectory + "PicMg\\drinkicon\\";
                    break;
                case ImageType.Brand:
                    dfp = AppDomain
                .CurrentDomain.BaseDirectory + "PicMg\\Brand\\";
                    break;
                case ImageType.other:
                    break;
                default:
                    break;
            }
            if (tb_picName.Text.Equals(""))
            {
                System.Windows.Forms.MessageBox.Show("Please Insert the name for picture!");
            }
            string savePath = (dfp + tb_picName.Text+".png");
            try
            {
                FileStream fs = new FileStream(savePath, FileMode.OpenOrCreate);
                bitmapEncoder.Save(fs);
                fs.Close();
                System.Windows.Forms.MessageBox.Show("Save picture OK!");
            }
            catch (Exception ex)
            {

                System.Windows.Forms.MessageBox.Show("Save picture failed!");
            }
                
            
        }

        private void Button_Click_4(object sender, RoutedEventArgs e)
        {
            Microsoft.Win32.OpenFileDialog openFileDialog = new Microsoft.Win32.OpenFileDialog();

            tbwidth.Text = CrtPicWidth.ToString();
            tbheight.Text = CrtPicHeight.ToString();
            openFileDialog.Title = "Select File";
            openFileDialog.Filter = "png文件|*.png|jpg文件|*.jpg|所有文件|*.*";
            openFileDialog.FileName = string.Empty;
            openFileDialog.FilterIndex = 1;
            openFileDialog.RestoreDirectory = true;
            if ((bool)openFileDialog.ShowDialog().GetValueOrDefault())
            {
                img.Source = new BitmapImage(new Uri(openFileDialog.FileName, UriKind.RelativeOrAbsolute));
            }
        }

        private void Button_Click_5(object sender, RoutedEventArgs e)
        {
            ColorDialog colorDialog = new ColorDialog();
            colorDialog.AllowFullOpen = true;
            colorDialog.ShowDialog();
            System.Windows.Media.SolidColorBrush scb = new System.Windows.Media.SolidColorBrush();
            System.Windows.Media.Color color = new System.Windows.Media.Color();
            color.A = colorDialog.Color.A;
            color.B = colorDialog.Color.B;
            color.G = colorDialog.Color.G;
            color.R = colorDialog.Color.R;
            scb.Color = color;
            _fontColor = new SolidColorBrush(color);
            rectcolor.Fill = new SolidColorBrush(color);
            if (_crtchd != null)
            {
                (_crtchd as TextBlock).Foreground = rectcolor.Fill;
            }
        }

        private void Slider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            fontsize.Text = (sender as Slider).Value.ToString();
            _fontSize = (sender as Slider).Value;
            if (_crtchd != null)
            {
                (_crtchd as TextBlock).FontSize = (sender as Slider).Value;
            }
        }

        private void font_chg(object sender, SelectionChangedEventArgs e)
        {
            object tmp = (sender as System.Windows.Controls.ComboBox).SelectedItem;
            if (tmp != null)
            {
                Items myfont = tmp as Items;
                _FontFamily = myfont.GetFontFamily;
                if (_crtchd != null)
                {
                    (_crtchd as TextBlock).FontFamily = _FontFamily;

                }
            }
        }

        private void tbwidth_LostFocus(object sender, RoutedEventArgs e)
        {
            try
            {
                imgbk.Width = double.Parse(tbwidth.Text);
                this.Title = imgbk.GetValue(Canvas.LeftProperty).ToString() + "/" + imgbk.GetValue(Canvas.TopProperty).ToString();


            }
            catch (Exception)
            {

                System.Windows.MessageBox.Show("Error width");
            }
        }

        private void tbheight_LostFocus(object sender, RoutedEventArgs e)
        {
            try
            {
                imgbk.Height = double.Parse(tbheight.Text);
                this.Title = imgbk.GetValue(Canvas.LeftProperty).ToString() + "/" + imgbk.GetValue(Canvas.TopProperty).ToString();


            }
            catch (Exception)
            {

                System.Windows.MessageBox.Show("Error Height");
            }
        }

        private double CrtPicWidth;
        private double CrtPicHeight;
        private void btnscaleup_Click(object sender, RoutedEventArgs e)
        {
            if (_sacleRate * 10 <= 10000)
            {
                _sacleRate = _sacleRate * 10;
            }
            var group = mywin.FindResource("myscale") as TransformGroup;
            var transform = group.Children[0] as ScaleTransform;
            transform.ScaleX += 0.1;
            transform.ScaleY += 0.1;
            CrtPicWidth = imgbk.Width * transform.ScaleX;
            CrtPicHeight = imgbk.Height * transform.ScaleY;
            tbwidth.Text = CrtPicWidth.ToString();
            tbheight.Text = CrtPicHeight.ToString();
        }

        private void btnscaledown_Click(object sender, RoutedEventArgs e)
        {
            if (_sacleRate / 10 > 0.0001)
            {
                _sacleRate = _sacleRate / 10;
            }
            var group = mywin.FindResource("myscale") as TransformGroup;
            var transform = group.Children[0] as ScaleTransform;
            transform.ScaleX -= 0.1;
            transform.ScaleY -= 0.1;
            CrtPicWidth = imgbk.Width * transform.ScaleX;
            CrtPicHeight = imgbk.Height * transform.ScaleY;
            tbwidth.Text = CrtPicWidth.ToString();
            tbheight.Text = CrtPicHeight.ToString();
        }

        private void btn_enable_Click(object sender, RoutedEventArgs e)
        {
            if (!tbwidth.IsEnabled)
            {
                btn_enable.Content = "Locked";
            }
            else
            {
                btn_enable.Content = "Edit";
            }
            tbwidth.IsEnabled = !tbwidth.IsEnabled;
            tbheight.IsEnabled = !tbheight.IsEnabled;
        }

        private bool _Isready = false;
        private double GetTextIntValue(System.Windows.Controls.TextBox a, double defautvalue)
        {
            double ret = defautvalue;
            try
            {
                ret = double.Parse(a.Text);
            }
            catch (Exception)
            {
                System.Windows.MessageBox.Show("Not a valid");
            }

            return ret;
        }
        private void tbwidth_TextChanged(object sender, TextChangedEventArgs e)
        {
            CrtPicWidth = GetTextIntValue(sender as System.Windows.Controls.TextBox, CrtPicWidth);
            tbwidth.Text = CrtPicWidth.ToString();
            this.imgbk.Width = CrtPicWidth;

        }

        private void tbheight_TextChanged(object sender, TextChangedEventArgs e)
        {
            CrtPicHeight = GetTextIntValue(sender as System.Windows.Controls.TextBox, CrtPicHeight);
            tbheight.Text = CrtPicHeight.ToString();
            this.imgbk.Height = CrtPicHeight;
        }

        private void ComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var aa = (sender as System.Windows.Controls.ComboBox).SelectedItem;
            if (aa == null)
            {
                (sender as System.Windows.Controls.ComboBox).SelectedIndex = 0;
                aa = (sender as System.Windows.Controls.ComboBox).SelectedItem;
            }
            ComboBoxItem item = aa as ComboBoxItem;
            if (item.Tag.ToString().Equals("bg"))
            {
                this.imgbk.Width = 768;
                this.imgbk.Height = 1024;
                CrtPicHeight = 1024;
                CrtPicWidth = 768;
                _crtImageType = ImageType.Background;
            }
            else if (item.Tag.ToString().Equals("st"))
            {
                _crtImageType = ImageType.StroyBoard;

                this.imgbk.Width = 768;
                this.imgbk.Height = 510;
                CrtPicHeight = 510;
                CrtPicWidth = 768;
            }
            else if (item.Tag.ToString().Equals("di"))
            {
                _crtImageType = ImageType.Drinkicon;

                this.imgbk.Width = 172;
                this.imgbk.Height = 172;
                CrtPicHeight = 172;
                CrtPicWidth = 172;
            }
            else if (item.Tag.ToString().Equals("bd"))
            {
                _crtImageType = ImageType.other;

            }
        }

        private void Button_Click_6(object sender, RoutedEventArgs e)
        {
            if (IsImport)
            {
                System.Windows.MessageBox.Show("Import is under processing!");
                return;
            }
            string removedevicename = "";
            DriveInfo[] s = DriveInfo.GetDrives();

            foreach (DriveInfo i in s)
            {
                try
                {
                if (i.DriveType == DriveType.Removable && i.VolumeLabel.Equals("ROCKCHIPS"))
                {
                    removedevicename = i.Name;
                }
                }
                catch (Exception)
                {

                }
                
            }
            if (removedevicename.Equals(""))
            {
                System.Windows.MessageBox.Show("PAD not found,Please trun on the storage on the PAD and Retry!!");
                return;
            }

            MessageBoxResult rsl = System.Windows.MessageBox.Show("Do you want Import the Picture to the PAD?", "Warning", MessageBoxButton.OKCancel);
            if (rsl == MessageBoxResult.OK)
            {
                Thread tmp = new Thread(new ThreadStart(importprocess));
                tmp.Start();
            }
        }
        private bool IsImport = false;

        private void importprocess()
        {
            IsImport = true;
            try
            {
                System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() =>
                {
                    pbtxt.Text = "准备导入图片资源";
                }));
                Thread.Sleep(500);
                DirectoryInfo d = new DirectoryInfo(AppDomain
                    .CurrentDomain.BaseDirectory + "PicMg\\background\\");
                ArrayList bklist = GetAll(d);
                d = new DirectoryInfo(AppDomain
                    .CurrentDomain.BaseDirectory + "PicMg\\storyboard\\");
                ArrayList stlist = GetAll(d);
                d = new DirectoryInfo(AppDomain
                    .CurrentDomain.BaseDirectory + "PicMg\\drinkicon\\");
                ArrayList dilist = GetAll(d);
                d = new DirectoryInfo(AppDomain
                    .CurrentDomain.BaseDirectory + "PicMg\\brand\\");
                ArrayList bdlist = GetAll(d);
                d = new DirectoryInfo(AppDomain
                    .CurrentDomain.BaseDirectory + "PicMg\\gif\\");
                ArrayList gflist = GetAll(d);
                System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() =>
                {
                    pb.Maximum = bklist.Count + stlist.Count + dilist.Count+ bdlist.Count;
                    pb.Value = 0;
                }));
                System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() =>
                {
                    pbtxt.Text = "开始导入background图片资源";

                }));

                Thread.Sleep(500);
                foreach (var item in bklist)
                {
                    Thread.Sleep(500);
                    System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() =>
                    {
                        pbtxt.Text = (item.ToString());
                        pb.Value++;
                    }));


                }
                System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() =>
                {
                    pbtxt.Text = "开始导入storyboard图片资源";

                }));
                Thread.Sleep(500);
                foreach (var item in stlist)
                {
                    Thread.Sleep(500);
                    System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() =>
                    {
                        pbtxt.Text = (item.ToString()); pb.Value++;
                    }));



                }
                System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() =>
                {
                    pbtxt.Text = "开始导入drinkicon图片资源";
                }));
                Thread.Sleep(500);
                foreach (var item in dilist)
                {
                    Thread.Sleep(500);
                    System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() =>
                    {
                        pbtxt.Text = (item.ToString()); pb.Value++;
                    }));



                }
                System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(() =>
                {
                    pbtxt.Text = "import finished!";
                }));
            }
            catch (Exception)
            {

                System.Windows.MessageBox.Show("import Picture failed！！！");
            }
            finally
            {
                IsImport = false;
            }
           
            

        }
         
        private ArrayList GetAll(DirectoryInfo dir)//搜索文件夹中的文件
        {
            ArrayList FileList = new ArrayList();
            FileInfo[] allFile = dir.GetFiles();
            foreach (FileInfo fi in allFile)
            {
                
                FileList.Add(dir.FullName+fi.Name);
            }
            return FileList;
        }       
    }


    public enum ImageType
    {
        Background,
        StroyBoard,
        Drinkicon,
        Brand,
        other
    }
}
