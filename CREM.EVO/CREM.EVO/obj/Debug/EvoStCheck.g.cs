﻿#pragma checksum "..\..\EvoStCheck.xaml" "{406ea660-64cf-4c82-b6f0-42d48172a799}" "848388C3BD42737A15835EFF19750CA0"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using CREM.EVO;
using CREM.EVO.Utility;
using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Controls.DataVisualization;
using System.Windows.Controls.DataVisualization.Charting;
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


namespace CREM.EVO {
    
    
    /// <summary>
    /// EvoStCheck
    /// </summary>
    public partial class EvoStCheck : System.Windows.Window, System.Windows.Markup.IComponentConnector {
        
        
        #line 114 "..\..\EvoStCheck.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.ListBox lbinfo;
        
        #line default
        #line hidden
        
        
        #line 254 "..\..\EvoStCheck.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.DataVisualization.Charting.Chart waitingtasks;
        
        #line default
        #line hidden
        
        
        #line 270 "..\..\EvoStCheck.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.DataVisualization.Charting.LineSeries tm1;
        
        #line default
        #line hidden
        
        
        #line 272 "..\..\EvoStCheck.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.DataVisualization.Charting.LineSeries tm2;
        
        #line default
        #line hidden
        
        
        #line 279 "..\..\EvoStCheck.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Canvas MapCanvas;
        
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
            System.Uri resourceLocater = new System.Uri("/CREM.EVO;component/evostcheck.xaml", System.UriKind.Relative);
            
            #line 1 "..\..\EvoStCheck.xaml"
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
            this.lbinfo = ((System.Windows.Controls.ListBox)(target));
            return;
            case 2:
            this.waitingtasks = ((System.Windows.Controls.DataVisualization.Charting.Chart)(target));
            
            #line 254 "..\..\EvoStCheck.xaml"
            this.waitingtasks.MouseWheel += new System.Windows.Input.MouseWheelEventHandler(this.waitingtasks_MouseWheel);
            
            #line default
            #line hidden
            return;
            case 3:
            this.tm1 = ((System.Windows.Controls.DataVisualization.Charting.LineSeries)(target));
            return;
            case 4:
            this.tm2 = ((System.Windows.Controls.DataVisualization.Charting.LineSeries)(target));
            return;
            case 5:
            this.MapCanvas = ((System.Windows.Controls.Canvas)(target));
            return;
            case 6:
            
            #line 280 "..\..\EvoStCheck.xaml"
            ((System.Windows.Controls.Slider)(target)).ValueChanged += new System.Windows.RoutedPropertyChangedEventHandler<double>(this.Slider_ValueChanged);
            
            #line default
            #line hidden
            return;
            case 7:
            
            #line 285 "..\..\EvoStCheck.xaml"
            ((System.Windows.Controls.CheckBox)(target)).Unchecked += new System.Windows.RoutedEventHandler(this.CheckBox_Unchecked);
            
            #line default
            #line hidden
            
            #line 285 "..\..\EvoStCheck.xaml"
            ((System.Windows.Controls.CheckBox)(target)).Checked += new System.Windows.RoutedEventHandler(this.CheckBox_Checked);
            
            #line default
            #line hidden
            return;
            }
            this._contentLoaded = true;
        }
    }
}
