   M S B A M L   `   `   `  ���� I  EMachineCreater, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullG(clr-namespace:MachineCreater.propertywinMachineCreater.propertywin  *    $MachineCreater.propertywin.win_mixer   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     @d2http://schemas.microsoft.com/expression/blend/2008     Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     :local(clr-namespace:MachineCreater.propertywin       � Title$  win_es_brewer��$	��500��$	��300��.���  � RowDefinitions �� $��1* ��� $��8* ��� $��1* �.+�� ����  �� EndPoint$ 0.5,1&� �� 
StartPoint$ 0.5,0&�.���  � Color$ 	#FFF9F6F6�� � Offset$ 0Q�� $ 	#FFF7F3F3��$ 1Q� � ColumnDefinitions �� $
��1.2* ��� $��1* ��� $
��0.5* ��� $
��0.5* ��� $��3* �.+��� $��Center=��� $�
Device ID:���� $��1��$��Center=�{�.  ���� *
Group_id+ �� StringFormat$ X4���� -    ��Name$ id_type��$��2��$��Center=�{�.  ���� *Compent_type+$ X2���� -   $ id_position��$��3��$��Center=�{�.  ���� *Position_id+$ X2��� $��1��.+��� .+��� $��Italic$����	#FFD4CECE�� $�Common Properties���� |�.  $��1�����	#FFA3B6BD$��Stretch=�$��Stretch=�� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=�$	��100���� $�Max Capability���� -   $��
cb_max_cap��$��1��$	��100��$	��0,2q�.@��� $��1.0 L��$
��Left=�$��98��
	 � Tag$	 10���� $��1.5 L��$
��Left=�$��98��$	 15���� $��2.0 L��$
��Left=�$��98��$	 20���� $��2.5 L��$
��Left=�$��98��$	 25��� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=�$	��100���� $�Mixer motor speed���� -   $ tb_mixer_speed��$��1��$��Center=�$��Center=�$	��100������ *	Run_speed+�� $��Italic$����	#FFD4CECE�� $�calibration Properties���� |�.  $��1�����	#FFA3B6BD$��Stretch=�$��Stretch=�� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=�$	��100���� $�Hot valve flow���� -   $ 
tb_cal_hot��$��1��$��Center=�$��Center=�$	��100������ *Hot_valve_flow+� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=�$	��100���� $�Cold valve flow���� -   $ tb_cal_cold��$��1��$��Center=�$��Center=�$	��100������ *Cold_valve_flow+�� $��Italic$����	#FFD4CECE�� $�maintenace Properties���� |�.  $��1�����	#FFA3B6BD$��Stretch=�$��Stretch=�� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=�$	��100���� $�Mixer motor life���� -   $ tb_life_motor��$��1��$��Center=�$��Center=�$	��100������ *
Life_motor+� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=�$	��100���� $�Cwater valve life���� -   $ tb_life_cold_valve��$��1��$��Center=�$��Center=�$	��100������ *Life_cold_valve+� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=�$	��100���� $�Hwater valve life���� -	   $ tb_life_hot_valve��$��1��$��Center=�$��Center=�$	��100������ *Life_hot_valve+� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=�$	��100���� $�Whipper life���� -
   $ tb_life_whipper��$��1��$��Center=�$��Center=�$	��100������ *Life_whipper+�� $��Italic$����	#FFD4CECE�� $�Fan Properties���� |�.  $��1�����	#FFA3B6BD$��Stretch=�$��Stretch=��� -   $��ckb_fan��$��Center=�$
��Left=�$
��25,2q�.���� $�
Use or not���� -   $��gd_fan��.+�� $��25��$
��25,2q� �� $
��1.2* ��� $��1* ��� $
��0.5* ��� $��* �.+��� $��Center=��� $�
Device ID:���� $��1��$��Center=�{�.  $��001401���� $��2��$��Center=�{�.  ���� *Position_id+$ X2��� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=�$	��100���� $�	Fan speed���� -   $ tb_fan_speed��$��1��$��Center=�$��Center=�$	��100������ *	Run_speed+� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=�$	��100���� $�Fan motor life���� -   $ tb_fan_motor��$��1��$��Center=�$��Center=�$	��100������ *
Life_motor+� $��2�� �� $��1* ��� $��1* �.+��� $
��10,0q�$��Cancel��$y�Hidden=��� -   
 ��Name$
 btn_save��$
��10,0q�$��1��$
��Save��$	 Mixer��