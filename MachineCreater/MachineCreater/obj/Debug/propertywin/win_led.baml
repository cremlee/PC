   M S B A M L   `   `   `  ����I  EMachineCreater, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullG(clr-namespace:MachineCreater.propertywinMachineCreater.propertywin  5   	   (    "MachineCreater.propertywin.win_led   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   :local(clr-namespace:MachineCreater.propertywin     5   	     � Title$  win_cup_sensor��5   	   $	��350��6    $	��300��6-   .��5	      �  � RowDefinitions 5
   
   �� 5      $��1* �6   �� 5      $��8* �6   �� 5      $��1* �6   .+�5   
   � ��5      �� 5       �� EndPoint$ 0.5,1&�6&    �� 
StartPoint$ 0.5,0&�67   .��5      �  � Color$ 	#FFF9F6F6��6#    � Offset$ 0Q�65   � 5      $ 	#FFF7F3F3��6#   $ 1Q�65   5       � ColumnDefinitions 5      �� 5      $
��1.2* �6#   �� 5      $��1* �6#   �� 5      $
��0.5* �6#   �� 5      $
��0.5* �6#   �� 5      $��3* �6#   .+�5      �� $��Center=�6   �� 65   $�
Device ID:��69   6N   �� 5      $��1��6   $��Center=�6&   {�.  ��6S   �� *
Group_id+ �� StringFormat$ X4���� 5      -   5         ��Name$ id_type��5      $��2��6'   $��Center=�67   {�.  ��6d   �� *Compent_type+$ X2���� 5       -   5        $ id_position��5       $��3��6+   $��Center=�6;   {�.  ��6h   �� *Position_id+$ X2��5!      �� 5"   
   $��1��6   .+�5#      �� $��Italic$�6   ���	#FFD4CECE�� 6D   $�Common Properties��6H   6d   �� 5$      |�.  $��1��6-   ���	#FFA3B6BD$��Stretch=�5%      $��Stretch=�6"   � 5&      $��25��6    5'      �� 5(      $��1* �6'   �� 5)      $��1* �6'   .+�5+      �� $��Center=�6   $��Center=�67   $	��100��6T   �� 6a   $�Led Type��6e   6x   �� 5,      -   5        $��cb_led_1��5,      $��1��6+   $	��100��6;   $	��0,2q�6G   .@�5-      �� $��single color��6#   $
��Left=�6:   $��98��6U   
	 � Tag$	 1��6`   �� 5.      $��three color��6#   $
��Left=�69   $��98��6T   $	 2��6_   5/      50      � 51      $��25��6    52      �� 53      $��1* �6'   �� 54      $��1* �6'   .+�56      �� $��Center=�6   $��Center=�67   $	��100��6V   �� 6d   $�Idle Led mode��6h   6�   �� 57      -   5        $��cb_led_2��57      $��1��6+   $	��100��6;   $	��0,2q�6G   .@�58      �� $��	always on��6#   $
��Left=�67   $��98��6R   $	 1��6]   �� 59      $��flash��6#   $
��Left=�63   $��98��6N   $	 2��6Y   �� 5:      $��breath��6#   $
��Left=�64   $��98��6O   $	 3��6Z   �� 5;      $��circling��6#   $
��Left=�66   $��98��6Q   $	 4��6\   �� 5<      $	��off��6#   $
��Left=�61   $��98��6L   $	 5��6W   5=      5>      � 5?      $��25��6    5@      �� 5A      $��1* �6'   �� 5B      $��1* �6'   .+�5D      �� $��Center=�6   $��Center=�67   $	��100��6V   �� 6d   $�Idle Led color��6h   6�   �� 5E      -   5        $��cb_led_3��5E      $��1��6+   $	��100��6;   $	��0,2q�6G   .@�5F      �� $	��red��6#   $
��Left=�61   $��98��6L   $	 1��6W   �� 5G      $��green��6#   $
��Left=�63   $��98��6N   $	 2��6Y   �� 5H      $
��blue��6#   $
��Left=�62   $��98��6M   $	 3��6X   �� 5I      $��orange��6#   $
��Left=�64   $��98��6O   $	 4��6Z   �� 5J      $��yello��6#   $
��Left=�63   $��98��6N   $	 5��6Y   �� 5K      $��purple��6#   $
��Left=�64   $��98��6O   $	 6��6Z   �� 5L      $��white��6#   $
��Left=�63   $��98��6N   $	 7��6Y   5M      5N      � 5O      $��25��6    5P      �� 5Q      $��1* �6'   �� 5R      $��1* �6'   .+�5T      �� $��Center=�6   $��Center=�67   $	��100��6V   �� 6d   $�Idle led intensity��6h   6�   �� 5U      -   5        $��cb_led_4��5U      $��1��6+   $	��100��6;   $	��0,2q�6G   .@�5V      �� $��normal��6#   $
��Left=�64   $��98��6O   $	 1��6Z   �� 5W      $
��weak��6#   $
��Left=�62   $��98��6M   $	 2��6X   5X      5Y      � 5Z      $��25��6    5[      �� 5\      $��1* �6'   �� 5]      $��1* �6'   .+�5_      �� $��Center=�6   $��Center=�67   $	��100��6V   �� 6d   $�Warn Led mode��6h   6�   �� 5`      -   5        $��cb_led_5��5`      $��1��6+   $	��100��6;   $	��0,2q�6G   .@�5a      �� $��	always on��6#   $
��Left=�67   $��98��6R   $	 1��6]   �� 5b      $��flash��6#   $
��Left=�63   $��98��6N   $	 2��6Y   �� 5c      $��breath��6#   $
��Left=�64   $��98��6O   $	 3��6Z   �� 5d      $��circling��6#   $
��Left=�66   $��98��6Q   $	 4��6\   �� 5e      $	��off��6#   $
��Left=�61   $��98��6L   $	 5��6W   5f      5g      � 5h      $��25��6    5i      �� 5j      $��1* �6'   �� 5k      $��1* �6'   .+�5m      �� $��Center=�6   $��Center=�67   $	��100��6V   �� 6d   $�Warn Led color��6h   6�   �� 5n      -   5        $��cb_led_6��5n      $��1��6+   $	��100��6;   $	��0,2q�6G   .@�5o      �� $	��red��6#   $
��Left=�61   $��98��6L   $	 1��6W   �� 5p      $��green��6#   $
��Left=�63   $��98��6N   $	 2��6Y   �� 5q      $
��blue��6#   $
��Left=�62   $��98��6M   $	 3��6X   �� 5r      $��orange��6#   $
��Left=�64   $��98��6O   $	 4��6Z   �� 5s      $��yello��6#   $
��Left=�63   $��98��6N   $	 5��6Y   �� 5t      $��purple��6#   $
��Left=�64   $��98��6O   $	 6��6Z   �� 5u      $��white��6#   $
��Left=�63   $��98��6N   $	 7��6Y   5v      5w      � 5x      $��25��6    5y      �� 5z      $��1* �6'   �� 5{      $��1* �6'   .+�5}      �� $��Center=�6   $��Center=�67   $	��100��6V   �� 6d   $�warn Led intensity��6h   6�   �� 5~      -	   5        $��cb_led_7��5~      $��1��6+   $	��100��6;   $	��0,2q�6G   .@�5      �� $��normal��6#   $
��Left=�64   $��98��6O   $	 1��6Z   �� 5�      $
��weak��6#   $
��Left=�62   $��98��6M   $	 2��6X   5�      5�      �� 5�      $��Italic$�6   ���	#FFD4CECE�� 6D   $�maintenace Properties��6H   6h   �� 5�      |�.  $��1��6-   ���	#FFA3B6BD$��Stretch=�5�      $��Stretch=�6"   � 5�      $��25��6    5�      �� 5�      $��1* �6'   �� 5�      $��1* �6'   .+�5�      �� $��Center=�6   $��Center=�67   $	��100��6V   �� 6d   $�Led life��6h   6{   �� 5�      $��1��6   $��Center=�6,   $��Center=�6G   $	��100��6d   ��6q   �� *
Life_led+6�   5�      5�      � 5�   
   $��2��6    5�      �� 5�      $��1* �6#   �� 5�      $��1* �6#   .+�5�      �� $
��10,0q�6   $��Cancel��6#   $y�Hidden=�64   �� 5�      -
   5        
 ��Name$
 btn_save��5�      $
��10,0q�6'   $��1��65   $
��Save��6E   $		 led��6T   5�      5�      5�      