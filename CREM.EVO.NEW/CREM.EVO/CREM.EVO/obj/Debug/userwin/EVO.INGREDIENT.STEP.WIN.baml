   M S B A M L   `   `   `  ����K  GCREM.EVO.Utility, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullM8clr-namespace:CREM.EVO.Utility;assembly=CREM.EVO.UtilityCREM.EVO.Utility  5   	    CREM.EVO   CREM.EVO.EVO   5   	   W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35U QWPFToolkit, Version=3.5.40128.1, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   X TXceed.Wpf.Toolkit, Version=2.5.0.0, Culture=neutral, PublicKeyToken=3e4669d2f30244f4:
extToolkit)http://schemas.xceed.com/wpf/xaml/toolkit  5   	   Bxxx8clr-namespace:CREM.EVO.Utility;assembly=CREM.EVO.Utility  5   	     � Title$	  EVO��5   	   $	��300��6   $	��300��6"    � 	Resources 5      0   *CREM.EVO.Utility.BoolToVisibilityConverter   BoolToVisibilityConverter:   4CREM.EVO.Utility.IngredientTypeToVisibilityConverter ' #IngredientTypeToVisibilityConverter%   CREM.EVO.Utility.IntToIsChecked  IntToIsChecked'   !CREM.EVO.Utility.IntToselectIndex  IntToselectIndex"   CREM.EVO.Utility.IntToPicScr  IntToPicScr'   !CREM.EVO.Utility.MsToSecConverter  MsToSecConverter&    CREM.EVO.Utility.MgToGgConverter  MgToGgConverter+   %CREM.EVO.Utility.boolToColorConverter  boolToColorConverter.	   (CREM.EVO.Utility.ValueToProcessConverter  ValueToProcessConverter �� 
TargetType �� Property �� Value��%l  &	        &	      &	 &     &	 9     &	 L     &	 _     &	 r     &	 �     &	 �     '�� �       5   
   6(     5	   
   62     5
   
   6     5   
   6     5   
   6     5   
   6:     5   
   6     5   
   6#   	  5   
   6(   �� 5   
   " ��6   .�5      ��  � ��$ Microsoft YaHei UI)�6+   6H   5      5      .��5      (�  (� Stretch$
 Fill=�6   .��5   
   � $	��900��6   $
��1200��6    � RowDefinitions 5      �� 5      $��1* �6    �� 5      $��1* �6    �� 5      $��1* �6    �� 5      $��1* �6    .+�5      �� $��80(�6   $��Center=�6&   $��Center=�6A   Ingredient Selection6t   �� 5      -   5        $��cb��5   �   $��Center=�6P   $��Center=�6t   $��1��6�   $��200,50q�6�   $��56(�6�    �� SelectedValuePath$ ID��5       �� DisplayMemberPath$
 Name��5       ��5      �� *_lstIngredientInfo+	 �� Mode$	 OneWay=�5       �� 5"      $��2��6   $��Start Time:��6%   $��Center=�68   $��Center=�6S   $��56(�6p   $��200,75,706,75q�6~   6�   $
  Xceed.Wpf.Toolkit.DoubleUpDown
  5$      -   5        $��tx��5$   &   $��2��60   $	��400��6=   $��56(�6L   $��597,72,203,72q�6Z   ,  &Xceed.Wpf.Toolkit.Primitives.InputBase
   TextAlignment$
 Center=�6�   �  �Xceed.Wpf.Toolkit.NumericUpDown`1[[System.Nullable`1[[System.Double, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]   	Increment$	 0.1X�6�   �  �Xceed.Wpf.Toolkit.Primitives.UpDownBase`1[[System.Nullable`1[[System.Double, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]   Value 6q   �� *	StartTime+ �� 	Converter# [ $	 TwoWay=�6�   �� 5%      -   5        $��3��5%      $��Cancel��6"   $��36(�63   $	��120��6A   $��200,72,658,1q�6N   6d   �� 5&      -   5         ��Name$ BtnOk��5&      $��3��6$   $��OK��61   $��36(�6>   $	��120��6L   $��664,72,200,1q�6Y   6o   5'      5(      5)      