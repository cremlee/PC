   M S B A M L   `   `   `  ����I  EMachineCreater, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullG(clr-namespace:MachineCreater.propertywinMachineCreater.propertywin  5   	   ;"clr-namespace:MachineCreater.modelMachineCreater.model  5   	   /    )MachineCreater.propertywin.win_peripheral   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   :local(clr-namespace:MachineCreater.propertywin     5   	   ;localconvert"clr-namespace:MachineCreater.model     5   	     � Title$  Grinder Settings��5	   	   $	��300��6"   $	��400��6/    � WindowStyle$
 None=�6;    � 	Resources 5
      ,   &MachineCreater.model.DeviceNameConvert   NameConvert��%   &	          5   
   6?   5      .��5      �  � RowDefinitions 5   
   �� 5      $��1* �6   �� 5      $��8* �6   �� 5      $��1* �6   .+�5   
   � ��5      �� 5       �� EndPoint$ 0.5,1&�6&    �� 
StartPoint$ 0.5,0&�67   .��5      �  � Color$ 	#FFF9F6F6��6#    � Offset$ 0Q�65   � 5      $ 	#FFF7F3F3��6#   $ 1Q�65   5       � ColumnDefinitions 5      �� 5      $
��1.2* �6#   �� 5      $��1* �6#   �� 5      $��* �6#   .+�5      �� $��Center=�6   
Device ID:6@   �� 5       $��1��6   $��Center=�6&   {�.  .��6T   
000002016^   5!      � 5"   
   $��1��6    5#      �� 5$      $��1* �6    �� 5%      $��7* �6    .+�5(      � ���	#FFD4CECE 5)      �� 5*      $��2* �6'   �� 5+      $��1* �6'   .+�5-      �� $��Italic$�6   $��Peripheral Parts ��61   �� 5.      -   5        $��1��5.      $
��0001��6?   $��3q�6W   .��6b   Add6g   5/      �� 50      |�.  $��2��6-   
�������$��Stretch=�51      $��Right=�61   6P   � 52      $��1��6   .+�53      �� -   5        $��	part_list��53      	 �� View	 54      �� 55      P�56      �� 57   "   $��
DeviceName��62   
 �� Width$
 90��6F    �� DisplayMemberBinding 6Q   ��  �� Path$ DeviceID� �� 	Converter# [  �� 58   "   $��DeviceID��62   $	
 100��6D    6P   �� $ DeviceID� �� StringFormat$ X8���� 59   "   $
��Edit��62   $
 90��6@    �� CellTemplate 5:   &   �� 5;   *   .R�5<   .   �� -   5        $��删除��5<   5   $��60��6C   $��23��6N   $
��0002��6o   
 � Tag 6�   �� $ DeviceID�5=   +   5?   #   �� 5@   "   $��Delete��62   $
 90��6B    5A   &   �� 5B   *   .R�5C   .   �� -   5        $��编辑��5C   5   $��60��6C   $��23��6N   $
��0003��6o    6�   �� $ DeviceID�5D   +   5F   #   5H      5J      5K      5L      � 5M   
   $��2��6    5N      �� 5O      $��1* �6#   �� 5P      $��1* �6#   .+�5R      �� $
��10,0q�6   $��Cancel��6#   $y�Hidden=�64   �� 5S      -   5         ��Name$ btn_save��5S      $
��10,0q�6'   $��1��65   $
��Save��6E   $
 Peri��6T   5T      5U      5V      