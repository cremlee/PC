﻿#pragma checksum "..\..\..\propertywin\win_canister.xaml" "{ff1816ec-aa5e-4d10-87f7-6f4963833460}" "053E7BC667D9E299502D5FA788D1903C7D235DE7"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using MachineCreater.model;
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
    /// win_canister
    /// </summary>
    public partial class win_canister : System.Windows.Window, System.Windows.Markup.IComponentConnector {
        
        
        #line 32 "..\..\..\propertywin\win_canister.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox id_type;
        
        #line default
        #line hidden
        
        
        #line 33 "..\..\..\propertywin\win_canister.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox id_position;
        
        #line default
        #line hidden
        
        
        #line 46 "..\..\..\propertywin\win_canister.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.ComboBox cb_canister;
        
        #line default
        #line hidden
        
        
        #line 58 "..\..\..\propertywin\win_canister.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.ComboBox cb_max_cap;
        
        #line default
        #line hidden
        
        
        #line 71 "..\..\..\propertywin\win_canister.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.ComboBox cb_type;
        
        #line default
        #line hidden
        
        
        #line 97 "..\..\..\propertywin\win_canister.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox tb_life;
        
        #line default
        #line hidden
        
        
        #line 107 "..\..\..\propertywin\win_canister.xaml"
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
            System.Uri resourceLocater = new System.Uri("/MachineCreater;component/propertywin/win_canister.xaml", System.UriKind.Relative);
            
            #line 1 "..\..\..\propertywin\win_canister.xaml"
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
            this.id_type = ((System.Windows.Controls.TextBox)(target));
            return;
            case 2:
            this.id_position = ((System.Windows.Controls.TextBox)(target));
            return;
            case 3:
            this.cb_canister = ((System.Windows.Controls.ComboBox)(target));
            
            #line 46 "..\..\..\propertywin\win_canister.xaml"
            this.cb_canister.SelectionChanged += new System.Windows.Controls.SelectionChangedEventHandler(this.cb_canister_SelectionChanged);
            
            #line default
            #line hidden
            return;
            case 4:
            this.cb_max_cap = ((System.Windows.Controls.ComboBox)(target));
            
            #line 58 "..\..\..\propertywin\win_canister.xaml"
            this.cb_max_cap.SelectionChanged += new System.Windows.Controls.SelectionChangedEventHandler(this.cb_max_cap_SelectionChanged);
            
            #line default
            #line hidden
            return;
            case 5:
            this.cb_type = ((System.Windows.Controls.ComboBox)(target));
            
            #line 71 "..\..\..\propertywin\win_canister.xaml"
            this.cb_type.SelectionChanged += new System.Windows.Controls.SelectionChangedEventHandler(this.ComboBox_SelectionChanged);
            
            #line default
            #line hidden
            return;
            case 6:
            this.tb_life = ((System.Windows.Controls.TextBox)(target));
            return;
            case 7:
            this.btn_save = ((System.Windows.Controls.Button)(target));
            return;
            }
            this._contentLoaded = true;
        }
    }
}

