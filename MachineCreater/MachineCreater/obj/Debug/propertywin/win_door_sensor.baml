   M S B A M L   `   `   `  ����I  EMachineCreater, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullG(clr-namespace:MachineCreater.propertywinMachineCreater.propertywin  5   	   0    *MachineCreater.propertywin.win_door_sensor   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   :local(clr-namespace:MachineCreater.propertywin     5   	     � Title$  win_door_sensor��5   	   $	��200��6!   $	��300��6.   .��5	      �  � RowDefinitions 5
   
   �� 5      $��1* �6   �� 5      $��5* �6   �� 5      $��1* �6   .+�5   
   � ��5      �� 5       �� EndPoint$ 0.5,1&�6&    �� 
StartPoint$ 0.5,0&�67   .��5      �  � Color$ 	#FFF9F6F6��6#    � Offset$ 0Q�65   � 5      $ 	#FFF7F3F3��6#   $ 1Q�65   5       � ColumnDefinitions 5      �� 5      $
��1.2* �6#   �� 5      $��1* �6#   �� 5      $
��0.5* �6#   �� 5      $
��0.5* �6#   �� 5      $��3* �6#   .+�5      �� $��Center=�6   �� 65   $�
Device ID:��69   6N   �� 5      $��1��6   $��Center=�6&   {�.  ��6S   �� *
Group_id+ �� StringFormat$ X4���� 5      -   5         ��Name$ id_type��5      $��2��6'   $��Center=�67   {�.  ��6d   �� *Compent_type+$ X2���� 5       -   5        $ id_position��5       $��3��6+   $��Center=�6;   {�.  ��6h   �� *Position_id+$ X2��5!      �� 5"   
   $��1��6   .+�5&      �� $��Italic$�6   ���	#FFD4CECE�� 6D   $�maintenace Properties��6H   6h   �� 5'      |�.  $��1��6-   ���	#FFA3B6BD$��Stretch=�5(      $��Stretch=�6"   � 5)      $��25��6    5*      �� 5+      $��1* �6'   �� 5,      $��1* �6'   .+�5.      �� $��Center=�6   $��Center=�67   $	��100��6V   �� 6d   $�Sensor life��6h   6~   �� 5/      $��1��6   $��Center=�6,   $��Center=�6G   $	��100��6d   ��6q   �� *Life_sensor+6�   50      51      � 52   
   $��2��6    53      �� 54      $��1* �6#   �� 55      $��1* �6#   .+�57      �� $
��10,0q�6   $��Cancel��6#   $y�Hidden=�64   �� 58      -   5        	 ��Name$	 btn_save��58      $
��10,0q�6'   $��1��65   $
��Save��6E   

 � Tag$

 door��6T   59      5:      5;      