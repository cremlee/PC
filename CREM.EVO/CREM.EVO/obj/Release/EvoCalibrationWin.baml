   M S B A M L   `   `   `  ���� K  GCREM.EVO.Utility, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullM8clr-namespace:CREM.EVO.Utility;assembly=CREM.EVO.UtilityCREM.EVO.Utility   CREM.EVO    CREM.EVO.EvoCalibrationWin   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35U QWPFToolkit, Version=3.5.40128.1, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     Gxx8clr-namespace:CREM.EVO.Utility;assembly=CREM.EVO.Utility     X TXceed.Wpf.Toolkit, Version=2.5.0.0, Culture=neutral, PublicKeyToken=3e4669d2f30244f4:
extToolkit)http://schemas.xceed.com/wpf/xaml/toolkit  :d2http://schemas.microsoft.com/expression/blend/2008  Dmc;http://schemas.openxmlformats.org/markup-compatibility/2006    � Title$  EvoCalibrationWin��$	��600��$	��800�� � 	Resources .   (CREM.EVO.Utility.ValueToProcessConverter   ValueToProcessConverter��%   &	          .��(�  (� Stretch$
 Fill=�.��� $	��800��$	��600�� � RowDefinitions �� $��1* ��� $	��10* �.+��� $��0��
�������$��3q�._��� $��Calibration��$��Center=�$��Center=�$��28(��� $��1��
�������$��3q�._�� .+�R�    TreeViewItemStyleC �� 
TargetType �� Property �� Value �� 
TargetType
 � Tag��%�   &	       �� " Q�.���  � �� �� " Q�.R�� 
�������.+��� 
�������$��3q�$��1��$	��Top=��� #��z��$��Center=�$��50,10q��� -   # z $��200,5q�$�� Calibration ��$��Right=�$��Center=�.@�Q� $��	WaterTank��$��32(�
�������$��10,10q�.@�Q� $��24(�$	 133��$��Hot Water Value��#���  Q� $��24(�$	 129��$��Mixer1 Water Value��#���  Q� $��24(�$	 130��$��Mixer2 Water Value��#���  Q� $��24(�$	 131��$��Mixer cold Water Value��#���  Q� $��24(�$	 132��$��cold Water Value��#���  Q� $��24(�$	 134��$��Carbon Water Value��#���  Q� $��24(�$	 128��$��Brew Hot Water Value��#���  Q� $��24(�$	 141��$��Water Temperature��#���  Q� $��	Canisters��$��32(�
�������$��10,10q�.@�Q� $��24(�$	 135��$��Grinder Coffee��#���  Q� $��24(�$	 138��$��Instant Canister1��#���  Q� $��24(�$	 139��$��Instant Canister2��#���  Q� $��24(�$	 140��$��Instant Canister3��#���  Q� $
��Brew��$��32(�
�������$��10,10q�.@�Q� $��24(�$	 142��$��Brew RunTime(speed=100)��#���  Q� $��24(�$	 143��$��Brew RunTime(speed=75)��#���  Q� $��24(�$	 144��$��Brew RunTime(speed=50)��#���  � -   $��grd_test��$��1��.+�� 
���   �	 J� Opacity$		 0.4Q�� $��100,120q� �� $��1* ��� $��2* ��� $��1* �.+��� 
�������$��3q�
�������$��1��._�� 
 � ColumnDefinitions
 �� $��1* ��� $��2* �.+��� 
�������$��3q�._��� $��24(�$7��1Please Enter the Calibration Value you want to do��$��Center=�$��Center=�$
��Wrap=�$  Xceed.Wpf.Toolkit.DoubleUpDown  -   $��	CalInport��$��1��$��80,40q�$��24(��� 
�������$��3q�
��� ���$��2��._�� 
 �� $��1* ��� $��1* �.+��� -   $��0��$��50,10q�$��OK��$��24(��� -   $��1��$��50,10q�$��Cancel��$��24(��� $��0��
�������$��3q�
��� ���._��� -    ��Name$ tb_title��
�������$��Center=�$��Center=�$��36(�$
��Test��� -   $��grd_cal��$��1��.+�� 
���   �$		 0.4Q�� $��100,120q� �� $��1* ��� $��2* ��� $��1* �.+��� 
�������$��3q�
��� ���._��� -   $��tb_title_cal��
�������$��0��$��Center=�$��Center=�$��36(�$
��Test���� 
�������$��3q�
�������$��1��._�� 
 �� $��1* ��� $��2* �.+��� 
�������$��3q�._��� $��24(�$8��2Please Enter the Calibration Value you measured！��$��Center=�$��Center=�$
��Wrap=�  -	   $��
CalInport1��$��1��$��80,40q�$��24(��� 
�������$��3q�
��� ���$��2��._�� 
 �� $��1* ��� $��1* �.+��� -
   $��0��$��50,10q�$��OK��$��24(��� -   $��1��$��50,10q�$��Cancel��$��24(�� -   $��grd_Process��$��1��
������ .+�� 
���   �$��20,120q�$		 0.4Q�.+�� $��250,20q�.+�� -   $
��pbar�� � Minimum$ 0Q� � Maximum$	 150Q����� " �.R��� ���� *Value+ �� 	Converter# [   �� ConverterParameter$	 100��� -   $��grd_test_temp��$��1��.+�� 
���   �$		 0.4Q�� $��100,120q� �� $��1* ��� $��2* ��� $��1* �.+��� 
�������$��3q�
��� ���._��� -   $��	tb_title1��
�������$��0��$��Center=�$��Center=�$��36(�$
��Test���� 
�������$��3q�
�������$��1��._�� 
 �� $��1* ��� $
��1.5* �.+��� 
�������$��3q�$��0��._��� $��24(�$G��APlease Mesure the Water Tank Temperature,fill in the Actual Value��$��Center=�$��Center=�$
��Wrap=�� $��1�� �� �� .+��� 
�������$��2q�._��� -   $��tb_crt_temp��$��80��$��Center=�$��Center=�$��28(��� 
�������$��2q�$��1��._�%  Xceed.Wpf.Toolkit.DecimalUpDown  -   $��
water_temp���  �Xceed.Wpf.Toolkit.Primitives.UpDownBase`1[[System.Nullable`1[[System.Decimal, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]   Value$ 0X�$��60,10q�   Minimum$ 0X�   Maximum$	 100X�$��28(��� 
�������$��3q�
��� ���$��2��._�� 
 �� $��1* ��� $��1* �.+��� -   $��0��$��50,10q�$��Calibration��$��24(��� -   $��1��$��50,10q�$��Close��$��24(�� -   $��grd_test_brew��$��1��.+�� 
���   �$		 0.4Q�� $��100,120q� �� $��1* ��� $��2* ��� $��1* �.+��� 
�������$��3q�
��� ���._��� -   $��tb_brew��
�������$��0��$��Center=�$��Center=�$��36(�$��Brew Calibration���� 
�������$��3q�
�������$��1��._�� .+��� 
�������$��3q�$��0��._��� $��24(�$]��WPlease press the start button to start brew calibration,the brew will be run one cycle.��$��Center=�$��Center=�$
��Wrap=�� $��1�� �� �� �� 
�������$��3q�
��� ���$��2��._�� 
 �� $��1* ��� $��1* �.+��� -   $��0��$��50,10q�$��Satrt��$��24(��� -   $��1��$��50,10q�$��Close��$��24(�