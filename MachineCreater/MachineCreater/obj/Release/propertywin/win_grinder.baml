   M S B A M L   `   `   `  ���� I  EMachineCreater, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullG(clr-namespace:MachineCreater.propertywinMachineCreater.propertywin  ,    &MachineCreater.propertywin.win_grinder   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     @d2http://schemas.microsoft.com/expression/blend/2008     Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     :local(clr-namespace:MachineCreater.propertywin       � Title$  Grinder Settings��$	��300��$	��600�� � WindowStyle$
 None=�.���  � RowDefinitions �� $��1* ��� $��8* ��� $��1* �.+�� ����  �� EndPoint$ 0.5,1&� �� 
StartPoint$ 0.5,0&�.���  � Color$ 	#FFF9F6F6�� � Offset$ 0Q�� $ 	#FFF7F3F3��$ 1Q� � ColumnDefinitions �� $
��1.2* ��� $��1* ��� $
��0.5* ��� $��3* �.+��� $��Center=�
Device ID:�� $��1��$��Center=�{�.  .��000201�� $��2��$��Center=�{�.  ���� *Position_id+ �� StringFormat$ X2��� $��1�� �� $��1* ��� $��1* �.+��� .+��� $��Italic$����	#FFD4CECECommon Properties�� |�.  $��1�����	#FFA3B6BD$��Stretch=�$��Stretch=�� $��30�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=�dosage�� $��1��$��Center=�$��Center=�$��66��$��	47,4,10,4q����� *Dosage_value+�� $��Italic$����	#FFD4CECEmaintenace Properties�� |�.  $��1�����	#FFA3B6BD$��Stretch=�$��Stretch=�� $��30�� �� $��3* ��� $��1* �.+��� $��Center=�$��Center=�$��	42,7,60,7q�motor life cycle�� $��Center=�$��Stretch=�$��2��$��
171,4,13,4q����� *
Motor_life+�� $��Italic$����	#FFD4CECE$��Parts ���� -   $��50��$��50��$��0,20,0,0q�$
��0001��.��Add�� |�.  $��2��
�������$��Stretch=�$��Right=��� $��1��.+��� $��Italic$����	#FFD4CECE$��
Parts list���� -   $��	part_list��	 �� View	 �� P��� $��No��
 �� Width$
 40�� �� DisplayMemberBinding ��  �� Path$ Position_id��� $��DeviceID��$
 85�� �� $ DeviceID�$ X8���� $
��Edit�� �� CellTemplate �� .R��� -   $��删除��$��60��$��23��$
��0002��
 � Tag �� $ DeviceID��� $��Delete�� �� .R��� -   $��编辑��$��60��$��23��$
��0003�� �� $ DeviceID�� $��2�� �� $��1* ��� $��1* �.+��� $
��10,0q�$��Cancel��$y�Hidden=��� -    ��Name$ btn_save��$
��10,0q�$��1��$
��Save��$ grinder��