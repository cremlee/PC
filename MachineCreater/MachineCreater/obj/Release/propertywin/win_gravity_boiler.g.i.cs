﻿#pragma checksum "..\..\..\propertywin\win_gravity_boiler.xaml" "{ff1816ec-aa5e-4d10-87f7-6f4963833460}" "8BFF9CA8ACD944FD72DE533ACE27EACC3471533D"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using MachineCreater.propertywin;
using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;
using System.Windows.Media.TextFormatting;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Shell;


namespace MachineCreater.propertywin {
    
    
    /// <summary>
    /// win_gravity_boiler
    /// </summary>
    public partial class win_gravity_boiler : System.Windows.Window, System.Windows.Markup.IComponentConnector {
        
        
        #line 30 "..\..\..\propertywin\win_gravity_boiler.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox id_position;
        
        #line default
        #line hidden
        
        
        #line 49 "..\..\..\propertywin\win_gravity_boiler.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.ComboBox cb_max_cap;
        
        #line default
        #line hidden
        
        
        #line 62 "..\..\..\propertywin\win_gravity_boiler.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.ComboBox cb_water_type;
        
        #line default
        #line hidden
        
        
        #line 84 "..\..\..\propertywin\win_gravity_boiler.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox tb_life_valve;
        
        #line default
        #line hidden
        
        
        #line 91 "..\..\..\propertywin\win_gravity_boiler.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.StackPanel sp_water;
        
        #line default
        #line hidden
        
        
        #line 111 "..\..\..\propertywin\win_gravity_boiler.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.ComboBox cb_level_type;
        
        #line default
        #line hidden
        
        
        #line 119 "..\..\..\propertywin\win_gravity_boiler.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.StackPanel sp_ntc;
        
        #line default
        #line hidden
        
        
        #line 142 "..\..\..\propertywin\win_gravity_boiler.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.ComboBox cb_ntc_type;
        
        #line default
        #line hidden
        
        
        #line 197 "..\..\..\propertywin\win_gravity_boiler.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Button btn_save;
        
        #line default
        #line hidden
        
        private bool _contentLoaded;
        
        /// <summary>
        /// InitializeComponent
        /// </summary>
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        public void InitializeComponent() {
            if (_contentLoaded) {
                return;
            }
            _contentLoaded = true;
            System.Uri resourceLocater = new System.Uri("/MachineCreater;component/propertywin/win_gravity_boiler.xaml", System.UriKind.Relative);
            
            #line 1 "..\..\..\propertywin\win_gravity_boiler.xaml"
            System.Windows.Application.LoadComponent(this, resourceLocater);
            
            #line default
            #line hidden
        }
        
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Maintainability", "CA1502:AvoidExcessiveComplexity")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1800:DoNotCastUnnecessarily")]
        void System.Windows.Markup.IComponentConnector.Connect(int connectionId, object target) {
            switch (connectionId)
            {
            case 1:
            this.id_position = ((System.Windows.Controls.TextBox)(target));
            return;
            case 2:
            this.cb_max_cap = ((System.Windows.Controls.ComboBox)(target));
            
            #line 49 "..\..\..\propertywin\win_gravity_boiler.xaml"
            this.cb_max_cap.SelectionChanged += new System.Windows.Controls.SelectionChangedEventHandler(this.cb_max_cap_SelectionChanged);
            
            #line default
            #line hidden
            return;
            case 3:
            this.cb_water_type = ((System.Windows.Controls.ComboBox)(target));
            
            #line 62 "..\..\..\propertywin\win_gravity_boiler.xaml"
            this.cb_water_type.SelectionChanged += new System.Windows.Controls.SelectionChangedEventHandler(this.cb_water_type_SelectionChanged);
            
            #line default
            #line hidden
            return;
            case 4:
            this.tb_life_valve = ((System.Windows.Controls.TextBox)(target));
            return;
            case 5:
            this.sp_water = ((System.Windows.Controls.StackPanel)(target));
            return;
            case 6:
            this.cb_level_type = ((System.Windows.Controls.ComboBox)(target));
            
            #line 111 "..\..\..\propertywin\win_gravity_boiler.xaml"
            this.cb_level_type.SelectionChanged += new System.Windows.Controls.SelectionChangedEventHandler(this.cb_level_type_SelectionChanged);
            
            #line default
            #line hidden
            return;
            case 7:
            this.sp_ntc = ((System.Windows.Controls.StackPanel)(target));
            return;
            case 8:
            this.cb_ntc_type = ((System.Windows.Controls.ComboBox)(target));
            
            #line 142 "..\..\..\propertywin\win_gravity_boiler.xaml"
            this.cb_ntc_type.SelectionChanged += new System.Windows.Controls.SelectionChangedEventHandler(this.cb_ntc_type_SelectionChanged);
            
            #line default
            #line hidden
            return;
            case 9:
            this.btn_save = ((System.Windows.Controls.Button)(target));
            return;
            }
            this._contentLoaded = true;
        }
    }
}
