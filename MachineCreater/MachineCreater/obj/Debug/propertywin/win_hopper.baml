   M S B A M L   `   `   `  ����I  EMachineCreater, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullG(clr-namespace:MachineCreater.propertywinMachineCreater.propertywin  5   	   ;"clr-namespace:MachineCreater.modelMachineCreater.model  5   	   +    %MachineCreater.propertywin.win_hopper   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   :local(clr-namespace:MachineCreater.propertywin     5   	   4model"clr-namespace:MachineCreater.model     5   	     � Title$  Bean Hopper��5	   	   $	��300��6   $	��300��6*    � WindowStyle$
 None=�66   .��5
      �  � RowDefinitions 5   
   �� 5      $��1* �6   �� 5      $��8* �6   �� 5      $��1* �6   .+�5   
   � ��5      �� 5       �� EndPoint$ 0.5,1&�6&    �� 
StartPoint$ 0.5,0&�67   .��5      �  � Color$ 	#FFF9F6F6��6#    � Offset$ 0Q�65   � 5      $ 	#FFF7F3F3��6#   $ 1Q�65   5       � ColumnDefinitions 5      �� 5      $
��1.2* �6#   �� 5      $��1* �6#   �� 5      $
��0.5* �6#   �� 5      $��3* �6#   .+�5      �� $��Center=�6   �� 65   $�
Device ID:��69   6N   �� 5      $��1��6   $��Center=�6&   {�.  $��001501��6S   �� 5      -   5         ��Name$ id_position��5      $��2��6+   $��Center=�6;   {�.  ��6h   �� *Position_id+	 �� StringFormat$	 X2��5       � 5!   
   $��1��6   .+�5"      �� .+�5#      �� $��Italic$�6   ���	#FFD4CECE�� 6H   $�Common Properties��6L   6h   �� 5$      |�.  $��1��61   ���	#FFA3B6BD$��Stretch=�5%      $��Stretch=�6"   � 5&      $��30��6    5'      �� 5(      $��1* �6+   �� 5)      $��1* �6+   .+�5+      �� $��Center=�6    $��Center=�6;   �� 6Y   $�
Power type��6]   6r   �� 5,      -   5        
 ��Name$
 cb_type��5,      $��1��60   $��Center=�6@   $��Center=�6[   $	��100��6x   .@�5-      �� $��Bean 1��6'   $
��Left=�68   $��98��6S   
 � Tag$
 0x81��6^   �� 5.      $��Bean 2��6'   $
��Left=�68   $��98��6S   $
 0x82��6^   5/      50      � 51      $��25��6    52      �� 53      $��1* �6+   �� 54      $��1* �6+   .+�56      �� $��Center=�6    $��Center=�6;   �� 6Y   $�Max Capability��6]   6v   �� 57      -   5        $��
cb_max_cap��57      $��1��61   $	��100��6A   $	��0,2q�6M   .@�58      �� $��1.0 L��6'   $
��Left=�67   $��98��6R   $ 10��6]   �� 59      $��1.5 L��6'   $
��Left=�67   $��98��6R   $ 15��6]   �� 5:      $��2.0 L��6'   $
��Left=�67   $��98��6R   $ 20��6]   �� 5;      $��2.5 L��6'   $
��Left=�67   $��98��6R   $ 25��6]   5<      5=      �� 5>      $��Italic$�6   ���	#FFD4CECE�� 6H   $�maintenace Properties��6L   6l   �� 5?      |�.  $��1��61   ���	#FFA3B6BD$��Stretch=�5@      $��Stretch=�6"   � 5A      $��30��6    5B      �� 5C      $��1* �6+   �� 5D      $��1* �6+   .+�5F      �� $��Center=�6    $��Center=�6;   $	��100��6Z   �� 6h   $�motor life cycle��6l   6�   �� 5G      -   5        $ tb_life��5G      $��1��6/   $��Center=�6?   $��Center=�6Z   $	��100��6w   ��6�   �� *
Motor_life+6�   5H      5I      5J      � 5K   
   $��2��6    5L      �� 5M      $��1* �6#   �� 5N      $��1* �6#   .+�5P      �� $
��10,0q�6   $��Cancel��6#   $y�Hidden=�64   �� 5Q      -   5         ��Name$ btn_save��5Q      $
��10,0q�6'   $��1��65   $
��Save��6E   5R      5S      5T      