   M S B A M L   `   `   `  ���� I  EMachineCreater, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullG(clr-namespace:MachineCreater.propertywinMachineCreater.propertywin  3    -MachineCreater.propertywin.win_gravity_boiler   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     @d2http://schemas.microsoft.com/expression/blend/2008     Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     :local(clr-namespace:MachineCreater.propertywin       � Title$  win_es_brewer��$	��300��$	��500��.���  � RowDefinitions �� $��1* ��� $��8* ��� $��1* �.+�� ����  �� EndPoint$ 0.5,1&� �� 
StartPoint$ 0.5,0&�.���  � Color$ 	#FFF9F6F6�� � Offset$ 0Q�� $ 	#FFF7F3F3��$ 1Q� � ColumnDefinitions �� $
��1.2* ��� $��1* ��� $
��0.5* ��� $��3* �.+��� $��Center=��� $�
Device ID:���� $��1��$��Center=�{�.  $��000f02���� -    ��Name$ id_position��$��2��{�.  $��Center=����� *Position_id+ �� StringFormat$ X2��� $��1�� �� $��1* ��� $
��auto ��� $��1* �.+��� $	��2,0q�.+��� $��Italic$����	#FFD4CECE�� $�Common Properties���� |�.  $��1�����	#FFA3B6BD$��Stretch=�$��Stretch=�� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=��� $�Max Capability���� -   $��
cb_max_cap��$��1��$	��100��$	��0,2q�.@��� $��1.0 L��$
��Left=�$��98��
	 � Tag$	 10���� $��1.5 L��$
��Left=�$��98��$	 15���� $��2.0 L��$
��Left=�$��98��$	 20���� $��2.5 L��$
��Left=�$��98��$	 25��� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=��� $�Inlet water type���� -   $��cb_water_type��$��1��$	��100��$	��0,2q�.@��� $��Normal��$
��Left=�$��98��$	 0���� $
��Pure��$
��Left=�$��98��$	 1���� $��Italic$����	#FFD4CECE�� $�maintenace Properties���� |�.  $��1�����	#FFA3B6BD$��Stretch=�$��Stretch=�� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=�$	��100���� $�Life inlet valve���� $��1��$��Center=�$��Center=�$	��100������ *Life_intlet_valve+� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=�$	��100���� $�Boiler clean cycle���� -   $ tb_life_valve��$��1��$��Center=�$��Center=�$	��100������ *Cycle_boiler_clean+�� |�.  $��1�����	#FFA3B6BD$��Stretch=�$��Stretch=��� $��Italic$����	#FFD4CECE�� $�Water Level Properties���� |�.  $��1�����	#FFA3B6BD$��Stretch=�$��Stretch=��� -   $��sp_water��.+�� $��25��$
��25,2q� �� $
��1.2* ��� $��1* ��� $
��0.5* ��� $
��0.5* ��� $��* �.+��� $��Center=��� $�
Device ID:���� $��1��$��Center=�{�.  ���� *
Group_id+$ X4���� $��2��$��Center=�{�.  ���� *Compent_type+$ X2���� $��3��$��Center=�{�.  ���� *Position_id+$ X2��� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=��� $�Sensor type���� -   $��cb_level_type��$��1��$	��100��$	��0,2q�.@��� $��single��$
��Left=�$��98��$	 1���� $��double��$
��Left=�$��98��$	 2���� -   $��sp_ntc��$��2��$	��2,0q�.+��� $��Italic$����	#FFD4CECE�� $�NTC Properties���� |�.  $��1�����	#FFA3B6BD$��Stretch=�$��Stretch=�� $��25��$
��25,2q� �� $
��1.2* ��� $��1* ��� $
��0.5* ��� $
��0.5* ��� $��* �.+��� $��Center=��� $�
Device ID:���� $��1��$��Center=�{�.  ���� *
Group_id+$ X4���� $��2��$��Center=�{�.  ���� *Compent_type+$ X2���� $��3��$��Center=�{�.  ���� *Position_id+$ X2��� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=��� $�Sensor type���� -   $��cb_ntc_type��$��1��$	��100��$	��0,2q�.@��� $��single��$
��Left=�$��98��$	 1���� $��double��$
��Left=�$��98��$	 2��� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=�$	��100���� $�Temperature offset���� $��1��$��Center=�$��Center=�$	��100������ *Temperature_offset+� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=�$	��120���� $�Temperature normal���� $��1��$��Center=�$��Center=�$	��100������ *Temperature_normal+� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=�$	��120���� $�Temperature warning���� $��1��$��Center=�$��Center=�$	��100������ *Temperature_warning+� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=�$	��100���� $�Temperature block���� $��1��$��Center=�$��Center=�$	��100������ *Temperature_block+� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=�$	��100���� $�Temperature eco���� $��1��$��Center=�$��Center=�$	��100������ *Temperature_eco+�� $��1��$��1�����	#FF999595� $��2�� �� $��1* ��� $��1* �.+��� $
��10,0q�$��Cancel��$y�Hidden=��� -	   
 ��Name$
 btn_save��$
��10,0q�$��1��$
��Save��$	 GB��