   M S B A M L   `   `   `  ���� I  EMachineCreater, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullG(clr-namespace:MachineCreater.propertywinMachineCreater.propertywin  ;"clr-namespace:MachineCreater.modelMachineCreater.model  /    )MachineCreater.propertywin.win_peripheral   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     @d2http://schemas.microsoft.com/expression/blend/2008     Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     :local(clr-namespace:MachineCreater.propertywin     ;localconvert"clr-namespace:MachineCreater.model       � Title$  Grinder Settings��$	��300��$	��400�� � WindowStyle$
 None=� � 	Resources ,   &MachineCreater.model.DeviceNameConvert   NameConvert��%   &	          .���  � RowDefinitions �� $��1* ��� $��8* ��� $��1* �.+�� ����  �� EndPoint$ 0.5,1&� �� 
StartPoint$ 0.5,0&�.���  � Color$ 	#FFF9F6F6�� � Offset$ 0Q�� $ 	#FFF7F3F3��$ 1Q� � ColumnDefinitions �� $
��1.2* ��� $��1* ��� $��* �.+��� $��Center=�
Device ID:�� $��1��$��Center=�{�.  .��
00000201� $��1�� �� $��1* ��� $��7* �.+�� ���	#FFD4CECE �� $��2* ��� $��1* �.+��� $��Italic$�$��Peripheral Parts ���� -   $��1��$
��0001��$��3q�.��Add�� |�.  $��2��
�������$��Stretch=�$��Right=�� $��1��.+��� -   $��	part_list��	 �� View	 �� P��� $��
DeviceName��
 �� Width$
 90�� �� DisplayMemberBinding ��  �� Path$ DeviceID� �� 	Converter# [  �� $��DeviceID��$	
 100�� �� $ DeviceID� �� StringFormat$ X8���� $
��Edit��$
 90�� �� CellTemplate �� .R��� -   $��删除��$��60��$��23��$
��0002��
 � Tag �� $ DeviceID��� $��Delete��$
 90�� �� .R��� -   $��编辑��$��60��$��23��$
��0003�� �� $ DeviceID�� $��2�� �� $��1* ��� $��1* �.+��� $
��10,0q�$��Cancel��$y�Hidden=��� -    ��Name$ btn_save��$
��10,0q�$��1��$
��Save��$
 Peri��