   M S B A M L   `   `   `  ���� I  EMachineCreater, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullG(clr-namespace:MachineCreater.propertywinMachineCreater.propertywin  ;"clr-namespace:MachineCreater.modelMachineCreater.model  +    %MachineCreater.propertywin.win_hopper   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     @d2http://schemas.microsoft.com/expression/blend/2008     Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     :local(clr-namespace:MachineCreater.propertywin     4model"clr-namespace:MachineCreater.model       � Title$  Bean Hopper��$	��300��$	��300�� � WindowStyle$
 None=�.���  � RowDefinitions �� $��1* ��� $��8* ��� $��1* �.+�� ����  �� EndPoint$ 0.5,1&� �� 
StartPoint$ 0.5,0&�.���  � Color$ 	#FFF9F6F6�� � Offset$ 0Q�� $ 	#FFF7F3F3��$ 1Q� � ColumnDefinitions �� $
��1.2* ��� $��1* ��� $
��0.5* ��� $��3* �.+��� $��Center=��� $�
Device ID:���� $��1��$��Center=�{�.  $��001501���� -    ��Name$ id_position��$��2��$��Center=�{�.  ���� *Position_id+	 �� StringFormat$	 X2��� $��1��.+��� .+��� $��Italic$����	#FFD4CECE�� $�Common Properties���� |�.  $��1�����	#FFA3B6BD$��Stretch=�$��Stretch=�� $��30�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=��� $�
Power type���� -   
 ��Name$
 cb_type��$��1��$��Center=�$��Center=�$	��100��.@��� $��Bean 1��$
��Left=�$��98��
 � Tag$
 0x81���� $��Bean 2��$
��Left=�$��98��$
 0x82��� $��25�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=��� $�Max Capability���� -   $��
cb_max_cap��$��1��$	��100��$	��0,2q�.@��� $��1.0 L��$
��Left=�$��98��$ 10���� $��1.5 L��$
��Left=�$��98��$ 15���� $��2.0 L��$
��Left=�$��98��$ 20���� $��2.5 L��$
��Left=�$��98��$ 25���� $��Italic$����	#FFD4CECE�� $�maintenace Properties���� |�.  $��1�����	#FFA3B6BD$��Stretch=�$��Stretch=�� $��30�� �� $��1* ��� $��1* �.+��� $��Center=�$��Center=�$	��100���� $�motor life cycle���� -   $ tb_life��$��1��$��Center=�$��Center=�$	��100������ *
Motor_life+� $��2�� �� $��1* ��� $��1* �.+��� $
��10,0q�$��Cancel��$y�Hidden=��� -    ��Name$ btn_save��$
��10,0q�$��1��$
��Save��