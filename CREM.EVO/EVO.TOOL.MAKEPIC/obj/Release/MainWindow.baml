   M S B A M L   `   `   `  ����   EVO.TOOL.MAKEPIC!    EVO.TOOL.MAKEPIC.MainWindow   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     -   $��mywin��  � Title$  EVO.PICMAKER��$	��600��$	��800�� � WindowStyle$ SingleBorderWindow=� � 
ResizeMode$ NoResize=� � 	Resources    myscale��%   &	        V� .~��� .���  � ColumnDefinitions �� $��7* ��� $��3* �.+�� $��0��
���   ��� -   $��	container��$��0��.+�(� -   $��imgbk��$	��420��$	��450�� (� Stretch$ Uniform=� (� StretchDirection$
 Both=�$
��Left=�$	��Top=� �� Left$ 58��
 �� Top$ 78��#z�[  .��� .+��� -   $	��img��$��images/EVO_Zoegas03.jpg��� $��1��	 � RowDefinitions	 �� $��1* ��� $��1* �.+�� $��1��	 �� $��1* ��� $��1* �.+��� $��0��.+��� -   $��30��$	��180��$
��0,10q�$��20(�.��Select Background�� -   $��30��$	��180��$
��0,10q�$��20(�.��Save� $��1��.+��� .+��� $��Width��$��18(�$ 10��$ 13���� -   $��tbwidth��$	��120��$��18(�$ 82��$ 10��{�.  �� $��Height��$��18(�$ 10��$ 48���� -   
 ��Name$
 tbheight��$	��120��$��18(�$ 82��$ 45��{�.  �� -	   $��
btnscaleup��$��Scale+��$ 10��$ 88��$��40��$��40���� -
   $��btnscaledown��$��Scale-��$ 63��$ 88��$��40��$��40��� $��0��	 �� $��1* ��� $��1* ��� $��1* ��� $��1* ��� $��1* ��� $��1* �.+��� -   $��TextIn��$	��5,5q�$��0��$��Stretch=�$��Stretch=�$��Center=�$��Center=�$��24(��� -   $��5��$��144,10,10,10q�$��18(�.��	AddText�� -   $��5��$��10,9,149,10q�$��18(�.��Delete�� -   $��1��$��10,10,165,5q�$��18(� J� RenderTransformOrigin$ 0.962,0.684&�.��Color�� -   $��	rectcolor��$��1��$��78,10,125,5q�
���   ��� -   $��cbfont��$��1��$��Right=�$
��0,10q�$��94���� $
��Left=�$��	10,23,0,0q�$��2��$��	FontSize:��$	��Top=��� -   $��fontsize��$
��Left=�$��	69,23,0,0q�$��2��$��48��$	��Top=��� -   $
��Left=�$��	98,19,0,0q�$��2��$	��Top=�$	��130�� � Maximum$ 60Q� � Minimum$ 8Q� � LargeChange$ 12Q� � SmallChange$ 1Q� � Cursor$  �� � Value$ 48Q�