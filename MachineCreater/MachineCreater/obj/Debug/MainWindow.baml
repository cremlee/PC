   M S B A M L   `   `   `  ����I  EMachineCreater, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null/clr-namespace:MachineCreaterMachineCreater  5   	       MachineCreater.MainWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   .localclr-namespace:MachineCreater     5   	     � WindowStartupLocation$  CenterScreen=�5   	    � Title$ 
MainWindow��5	   	   $	��850��6   $
��1000��6)   .��5
      � $��10q�6    � RowDefinitions 5   
   �� 5      $
��Auto �6   �� 5      $��* �6   .+�5   
   ��    	MyToolbar#��[  6   � 5   
   $��1��6   $��0,10,0,0q�6    � ColumnDefinitions 5      �� 5      $	��200 �6#   �� 5      .+�5      �� $��0��6   $��0,0,5,0q�6)   .+�5      9� $��	Component��6     
Imageitems#��[ 6.    9� 
IsExpanded . $	��500��6f   9� 5      $��
Properties��6    . $	��170��6B   5      �� 5      |�.  $��2��6-   
�������$��Stretch=�5      $��Right=�61   �� 5      $��Diagram��6   $��1��6(   $��3,0,0,0q�68   .��5      �� $
��Auto=�6   $
��Auto=�5       .��5!      #   MachineCreater.DesignerCanvas  -   5          Name$ 
MyDesigner��5!   <   |�.   WindowBackgroundBrush#��[ 5"      $��10q�5#       � FocusVisualStyle 6)   Z� 5%      5&      5'      5(      5)      