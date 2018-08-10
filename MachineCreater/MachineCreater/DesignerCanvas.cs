using System;
using System.Linq;
using System.Collections.Generic;
using System.IO;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Markup;
using System.Xml;
using MachineCreater.model;

namespace MachineCreater
{
    public partial class DesignerCanvas : Canvas
    {

        private Point? rubberbandSelectionStartPoint = null;

        private SelectionService selectionService;
        internal SelectionService SelectionService
        {
            get
            {
                if (selectionService == null)
                    selectionService = new SelectionService(this);

                return selectionService;
            }
        }

        protected override void OnMouseDown(MouseButtonEventArgs e)
        {
            base.OnMouseDown(e);
            if (e.Source == this)
            {
                // in case that this click is the start of a 
                // drag operation we cache the start point
                this.rubberbandSelectionStartPoint = new Point?(e.GetPosition(this));

                // if you click directly on the canvas all 
                // selected items are 'de-selected'
                SelectionService.ClearSelection();
                Focus();
                e.Handled = true;
            }
        }

        protected override void OnMouseMove(MouseEventArgs e)
        {
            base.OnMouseMove(e);

            // if mouse button is not pressed we have no drag operation, ...
            if (e.LeftButton != MouseButtonState.Pressed)
                this.rubberbandSelectionStartPoint = null;

            // ... but if mouse button is pressed and start
            // point value is set we do have one
            if (this.rubberbandSelectionStartPoint.HasValue)
            {
                // create rubberband adorner
                AdornerLayer adornerLayer = AdornerLayer.GetAdornerLayer(this);
                if (adornerLayer != null)
                {
                    RubberbandAdorner adorner = new RubberbandAdorner(this, rubberbandSelectionStartPoint);
                    if (adorner != null)
                    {
                        adornerLayer.Add(adorner);
                    }
                }
            }
            e.Handled = true;
        }

        protected override void OnDrop(DragEventArgs e)
        {
            base.OnDrop(e);
            DragObject dragObject = e.Data.GetData(typeof(DragObject)) as DragObject;
            if (dragObject != null && !String.IsNullOrEmpty(dragObject.Xaml))
            {
                DesignerItem newItem = null;
                Object content = XamlReader.Load(XmlReader.Create(new StringReader(dragObject.Xaml)));

                DeviceType itemtype = DeviceType.DEV_Init;
                if (dragObject.UID.StartsWith("0001"))   // 
                {
                    itemtype = DeviceType.DEV_BREWER;
                }
                else if (dragObject.UID.StartsWith("0002")) // this is for grinder                   
                {
                    itemtype = DeviceType.DEV_GRINDER;
                }
                else if (dragObject.UID.StartsWith("0003")) // this is for canister                   
                {
                    itemtype = DeviceType.DEV_CANISTER;
                }
                else if (dragObject.UID.StartsWith("0004")) // this is for mixer                   
                {
                    itemtype = DeviceType.DEV_MIXER;
                }
                else if (dragObject.UID.StartsWith("000f")) // this is for boiler                   
                {
                    itemtype = DeviceType.DEV_BOILER;
                }
                else if (dragObject.UID.StartsWith("0008")) // this is for machine  
                {
                    itemtype = DeviceType.DEV_CUP;
                }
                else if (dragObject.UID.StartsWith("000c")) // this is for machine  
                {
                    itemtype = DeviceType.DEV_LED;
                }
                else if (dragObject.UID.StartsWith("0018")) // this is for machine  
                {
                    itemtype = DeviceType.DEV_DRIP;
                }
                else if (dragObject.UID.StartsWith("0019")) // this is for machine  
                {
                    itemtype = DeviceType.DEV_WASTER;
                }
                else if (dragObject.UID.StartsWith("001a")) // this is for machine  
                {
                    itemtype = DeviceType.DEV_DOOR;
                }
                else if (dragObject.UID.StartsWith("0000-02")) // this is for machine  
                {
                    itemtype = DeviceType.DEV_VIRMACHINE;
                }
                if (!isValid(itemtype))
                {
                    MessageBox.Show("can not create more!");
                    return;
                }


                if (content != null)
                {
                    newItem = new DesignerItem(dragObject.UID,this);

                    newItem.Content = content;                
                    Point position = e.GetPosition(this);

                    if (dragObject.DesiredSize.HasValue)
                    {
                        Size desiredSize = dragObject.DesiredSize.Value;
                        newItem.Width = desiredSize.Width;
                        newItem.Height = desiredSize.Height;

                        DesignerCanvas.SetLeft(newItem, Math.Max(0, position.X - newItem.Width / 2));
                        DesignerCanvas.SetTop(newItem, Math.Max(0, position.Y - newItem.Height / 2));
                    }
                    else
                    {
                        DesignerCanvas.SetLeft(newItem, Math.Max(0, position.X));
                        DesignerCanvas.SetTop(newItem, Math.Max(0, position.Y));
                    }
                                      
                    Canvas.SetZIndex(newItem, this.Children.Count);
                    this.Children.Add(newItem);
                    
                    _machineDevicelist.Add(newItem.ID, newItem);
                    SetConnectorDecoratorTemplate(newItem);
                    Control decorator = newItem.Template.FindName("PART_ConnectorDecorator", newItem) as Control;
                    if (dragObject.UID.Equals("0000-00"))   // this is for valve
                    {                        
                        if (decorator != null)
                            decorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_valve");
                    }
                    else if (dragObject.UID.StartsWith("0001")) // this is for brewer                   
                    {
                        if (decorator != null)
                            decorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_brewer");
                    }
                    else if (dragObject.UID.StartsWith("0002")) // this is for grinder                   
                    {
                        if (decorator != null)
                            decorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_grinder");
                    }
                    else if (dragObject.UID.StartsWith("0003")) // this is for canister                   
                    {
                        if (decorator != null)
                            decorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_can");
                    }
                    else if (dragObject.UID.StartsWith("0004")) // this is for mixer                   
                    {
                        if (decorator != null)
                            decorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_brewer");
                    }
                    else if(dragObject.UID.StartsWith("000f")) // this is for boiler                   
                    {
                        if (decorator != null)
                            decorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_boiler");
                    }
                    else if (dragObject.UID.StartsWith("000a")) // this is for boiler                   
                    {
                        if (decorator != null)
                            decorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_pump");
                    }
                    else if (dragObject.UID.StartsWith("0008"))
                    {
                        if (decorator != null)
                            decorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_end");
                    }
                    //update selection
                    this.SelectionService.SelectItem(newItem);
                    newItem.Focus();
                }

                e.Handled = true;
            }
        }

        protected override Size MeasureOverride(Size constraint)
        {
            Size size = new Size();

            foreach (UIElement element in this.InternalChildren)
            {
                double left = Canvas.GetLeft(element);
                double top = Canvas.GetTop(element);
                left = double.IsNaN(left) ? 0 : left;
                top = double.IsNaN(top) ? 0 : top;

                //measure desired size for each child
                element.Measure(constraint);

                Size desiredSize = element.DesiredSize;
                if (!double.IsNaN(desiredSize.Width) && !double.IsNaN(desiredSize.Height))
                {
                    size.Width = Math.Max(size.Width, left + desiredSize.Width);
                    size.Height = Math.Max(size.Height, top + desiredSize.Height);
                }
            }
            // add margin 
            size.Width += 10;
            size.Height += 10;
            return size;
        }

        private void SetConnectorDecoratorTemplate(DesignerItem item)
        {
            if (item.ApplyTemplate() && item.Content is UIElement)
            {
                Control decorator = item.Template.FindName("PART_ConnectorDecorator", item) as Control;

                if (item.Uid.Equals("0000-00"))   // this is for valve
                {

                    if (decorator != null)
                        decorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_valve");
                }
                else if (item.Uid.StartsWith("0001")) // this is for brewer                   
                {
                    if (decorator != null)
                        decorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_brewer");
                }
                else if (item.Uid.StartsWith("0002")) // this is for grinder                   
                {
                    if (decorator != null)
                        decorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_grinder");
                }
                else if (item.Uid.StartsWith("0003")) // this is for canister                   
                {
                    if (decorator != null)
                        decorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_can");
                }
                else if (item.Uid.StartsWith("0004")) // this is for mixer                   
                {
                    if (decorator != null)
                        decorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_brewer");
                }
                else if (item.Uid.StartsWith("000f")) // this is for boiler                   
                {
                    if (decorator != null)
                        decorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_boiler");
                }   
                else if(item.Uid.StartsWith("000a"))
                {
                    if (decorator != null)
                        decorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_pump");
                }
                else if (item.Uid.StartsWith("0008"))
                {
                    if (decorator != null)
                        decorator.SetResourceReference(Control.TemplateProperty, "ConnectorDecoratorTemplate_end");
                }
            }
        }
    }
}
