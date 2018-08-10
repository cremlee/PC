using CREM.EVO.MODEL;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
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
    /// Interaction logic for EVODrinkBtnSetting.xaml
    /// </summary>
    public partial class EVODrinkBtnSetting : Window
    {
        public ObservableCollection<RecipeInfo> _lstRecipeInfo { get; set; }
        public event MouseButtonEventHandler Save;
        private DrinkItem _DrinkItem;
        public EVODrinkBtnSetting(ObservableCollection<RecipeInfo> a,DrinkItem drinkID)
        {
            InitializeComponent();
            _lstRecipeInfo = a;
            _DrinkItem = drinkID;
            this.cb.ItemsSource = _lstRecipeInfo;
            SetTbCaption();
        }
        private void SetTbCaption()
        {
            this.tbbtnname.Text = "Button: ["+_DrinkItem.DrinkPostion.ToString()+"]";
            if (!_DrinkItem.DrinkID.Equals(0))
            {
                this.cb.SelectedValue = _DrinkItem.DrinkID;
            }
        }
        
        private void btn_click(object sender, RoutedEventArgs e)
        {
            string tmp = (sender as Button).Tag.ToString();
            if (tmp.Equals("C"))
            {
                this.Close();
            }
            else if (tmp.Equals("O"))
            {
                _DrinkItem.DrinkID = (UInt16)this.cb.SelectedValue;
                _DrinkItem.DrinkName = this.cb.Text;
                Save.BeginInvoke(_DrinkItem, null, null, null);
                this.Close();
            }
        }

        
    }
}
