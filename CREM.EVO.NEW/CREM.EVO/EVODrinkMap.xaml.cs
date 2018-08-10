using CREM.EVO.MODEL;
using CREM.EVO.Utility;
using System;
using System.Collections.Generic;
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
using System.Windows.Shapes;

namespace CREM.EVO
{
    /// <summary>
    /// Interaction logic for EVODrinkMap.xaml
    /// </summary>
    public partial class EVODrinkMap : Window
    {
        protected EvoRecipe _EvoRecipe;
        protected PanelRef _PanelRef;
        
        public EVODrinkMap(EvoRecipe a)
        {
            InitializeComponent();
            _EvoRecipe = a;
            InitVar();
            InitGui();
        }
        private void InitVar()
        {
            _PanelRef =(PanelRef) Function.XmlSerializer.LoadFromXml("EVO.DrinkMap.xml", typeof(PanelRef));
            if (_PanelRef!=null)
            {

            }else
            {
                _PanelRef = new PanelRef();
                _PanelRef.Init();
                Function.XmlSerializer.SaveToXml("EVO.DrinkMap.xml", _PanelRef, typeof(PanelRef), null);

            }
        }
        private void InitGui()
        {
            foreach (var item in _PanelRef.m_DrinkItemList)
            {
              object tmp=  this.FindName("btn" + item.DrinkPostion.ToString());
                if (tmp is Button)
                {
                    (tmp as Button).Content = item.ShowName;
                    (tmp as Button).Tag = item;
                    
                }
            }
        }
        private void btn_Click(object sender, RoutedEventArgs e)
        {
            DrinkItem id = (DrinkItem)(sender as Button).Tag;
            EVODrinkBtnSetting tmp = new EVODrinkBtnSetting(_EvoRecipe._lstRecipeInfo,id);
            tmp.Save += Tmp_Save;
            tmp.Show();
        }

        private void Tmp_Save(object sender, MouseButtonEventArgs e)
        {
            DrinkItem tmp = sender as DrinkItem;
            _PanelRef.Modify(tmp);
            Function.XmlSerializer.SaveToXml("EVO.DrinkMap.xml", _PanelRef,typeof(PanelRef),null);
            System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(()=> InitGui()));
        }
    }
}
