   M S B A M L   `   `   `  ���� C  ?CREM.EVO, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null#clr-namespace:CREM.EVOCREM.EVO      CREM.EVO.EvoDrinkUi   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35U QWPFToolkit, Version=3.5.40128.1, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     @d2http://schemas.microsoft.com/expression/blend/2008     (localclr-namespace:CREM.EVO     Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006       � Title$  
EvoDrinkUi��$	��800��$	��600��.��(�  (� Stretch$
 Fill=�.��� $	��800��$	��600������  �� ImageSource$ images/BG.jpg��.+�� -    �Name$ grd_layout1�� � RowDefinitions �� $��6* ��� $��2* �.+��� $��1��$��Choose a beverage��$��28(�$��Center=�$	��Top=�$
��Bold"����	#FFFDDC63$��176,20,176,0q��� $��1��$��Center=�$	��Top=�$��80��$��80��$��256,76,264,0q����� $ images/Logo.png���� -   $��tbdata��$��2015-7-2 12:00��$��36(�
���� ��$��Center=�$	��Top=�$��20q�� $��0��$��	0,100,0,0q�.+��� -    ��Name$
 Btn1��   DrinkButtonStyle#��[  ���� $ Icon/Americano.jpg���� -   $
 Btn2��#��[  ���� $ Icon/black coffee.jpg���� -   $
 Btn3��#��[  ���� $ Icon/cafe crema.jpg���� -   $
 Btn4��#��[  ���� $ Icon/Cafe Latte.jpg���� -   $
 Btn5��#��[  ���� $ Icon/Cappuccino.jpg���� -   $
 Btn6��#��[  ���� $ Icon/double espresso.jpg���� -	   $
 Btn7��#��[  ���� $ Icon/single espresso.jpg���� -
   $
 Btn8��#��[  ���� $ Icon/Tea.jpg���� -   $
 Btn9��#��[  ���� $ Icon/double espresso.jpg��� -   $ grd_preselect�� �� $	��80* ��� $
��120* �.+�� $��0��.+��� -   $��btn_icon��#��[  $��220,58,220,102q����� $ Icon/Americano.jpg���� -   $��Right=�$	��Top=�  BackButtonStyle#��[ $��50��$��	0,10,10,0q�� $��1��
������� J� Opacity$	 0.4Q�� $��1��$��0,0,0,60q�$��Center=�$��Bottom=�.+��� -   $��	btn_start��$��3��  StartButtonStyle#��[ ���� $ Icon/start.png��� -   $��grd_fun��$��1��$��150,40,150,220q�� -   $��grd_cup��$��1��$��150,280,150,150q� � ColumnDefinitions �� $��1* ��� $��1* ��� $��1* �.+��� -     SubButtonStyle#��[ �� -   $��2��  AddButtonStyle#��[ � $��1������ $ images/cups.png��.+��� -   $��tb_cups��$��Center=�$��Center=�$��36(�$
��Bold"�1� -   $ grd_process��
�������$	 0.8Q�.+�� $��0,300q�
���   �$	 0.5Q�.+��� $��Dispense,Please Wait�� �� TextAlignment$ Center=�$��48(�
�������$��Center=�$��Center=��� -   $ btn_start_Copy��#��[ $��258,662,262,58q����� $ Icon/stop.png��