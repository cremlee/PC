   M S B A M L   `   `   `  ���� O  Kmscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e0891&clr-namespace:System;assembly=mscorlibSystem   EVO.Tool.LogManage#   EVO.Tool.LogManage.MainWindow   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     6sys&clr-namespace:System;assembly=mscorlib       � Title$  	LogManage��$	��600��$	��800��.��(�  (� Stretch$
 Fill=�.��� $	��600��$	��800�� � RowDefinitions �� $��1* ��� $	��18* �.+��� $��0��
�������$��2q�._�� .+�o� $��Stretch=�$	��Top=�$��28��.@�m� $��16(�$
��File��.@�m� -   $��16(�$
��Open��
 � Tag$
 open���� m� -   $��16(�$	��New��$	 new���� m� -   $��16(�$
��Save��$
 save��� $��1�� � ColumnDefinitions �� $��3* ��� $��9* �.+��� -   $��grd_filter_fun��$��0��
�������$��2q�._��  �� $��1* ��� $��1* ��� $��1* ��� $��1* ��� $��5* �.+�� $��0�� �� $��1* ��� $��1* �.+��� $��0��$��Center=�$��Center=�$��20(�	File Type�� -   $��cbtype��$��1��$
��20,0q�$��18(�.@��� .��� $	��120�� �� $��30 ��� $��* �.+��� 
�������$��2q�$��2��� 
���  ��$��3q��� $��Center=�$��Error��$��Center=�$��1���� .��� $	��120�� �� $��30 ��� $��* �.+��� 
�������$��2q�$��2��� 
��� ���$��3q��� $��Center=�$��Warning��$��Center=�$��1���� .��� $	��120�� �� $��30 ��� $��* �.+��� 
�������$��2q�$��2��� 
��� � �$��3q��� $��Center=�$��Operate��$��Center=�$��1���� .��� $	��120�� �� $��30 ��� $��* �.+��� 
�������$��2q�$��2��� 
���   �$��3q��� $��Center=�$	��All��$��Center=�$��1��� $��1�� �� $��1* ��� $��1* �.+��� $��
Start Time��$��20(�$��Center=�$��Center=�(  "System.Windows.Controls.DatePicker  $��1��$
��20,5q�
 �� Now   SelectedDate# Z � $��2�� �� $��1* ��� $��1* �.+��� $��	Stop Time��$��20(�$��Center=�$��Center=�  $��1��$
��20,5q�# Z � $��4��.+��� -   $��50,140q�$��Search��$��20(��� -   $��grd_file_fun��$��1��
�������$��2q�._�� .+��� -   $��Fun_Show_txt��