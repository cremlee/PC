namespace KeyManager
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tb_ali = new System.Windows.Forms.TabControl();
            this.p1 = new System.Windows.Forms.TabPage();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.button1 = new System.Windows.Forms.Button();
            this.rtb_pb = new System.Windows.Forms.RichTextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.rtb_pv = new System.Windows.Forms.RichTextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.tb_appid1 = new System.Windows.Forms.TextBox();
            this.p2 = new System.Windows.Forms.TabPage();
            this.button2 = new System.Windows.Forms.Button();
            this.rtb_pv2 = new System.Windows.Forms.RichTextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.tb_mchid = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.tb_appid2 = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.tb_name1 = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.tb_name2 = new System.Windows.Forms.TextBox();
            this.tb_ali.SuspendLayout();
            this.p1.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.p2.SuspendLayout();
            this.SuspendLayout();
            // 
            // tb_ali
            // 
            this.tb_ali.Controls.Add(this.p1);
            this.tb_ali.Controls.Add(this.p2);
            this.tb_ali.Location = new System.Drawing.Point(12, 12);
            this.tb_ali.Name = "tb_ali";
            this.tb_ali.SelectedIndex = 0;
            this.tb_ali.Size = new System.Drawing.Size(639, 390);
            this.tb_ali.TabIndex = 0;
            // 
            // p1
            // 
            this.p1.Controls.Add(this.label7);
            this.p1.Controls.Add(this.tb_name1);
            this.p1.Controls.Add(this.groupBox1);
            this.p1.Controls.Add(this.button1);
            this.p1.Controls.Add(this.rtb_pb);
            this.p1.Controls.Add(this.label3);
            this.p1.Controls.Add(this.rtb_pv);
            this.p1.Controls.Add(this.label2);
            this.p1.Controls.Add(this.label1);
            this.p1.Controls.Add(this.tb_appid1);
            this.p1.Location = new System.Drawing.Point(4, 22);
            this.p1.Name = "p1";
            this.p1.Padding = new System.Windows.Forms.Padding(3);
            this.p1.Size = new System.Drawing.Size(631, 364);
            this.p1.TabIndex = 0;
            this.p1.Text = "Ali-Key";
            this.p1.UseVisualStyleBackColor = true;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.radioButton2);
            this.groupBox1.Controls.Add(this.radioButton1);
            this.groupBox1.Location = new System.Drawing.Point(351, 65);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(168, 243);
            this.groupBox1.TabIndex = 8;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Key type";
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(19, 78);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(53, 17);
            this.radioButton2.TabIndex = 1;
            this.radioButton2.TabStop = true;
            this.radioButton2.Text = "RSA2";
            this.radioButton2.UseVisualStyleBackColor = true;
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Location = new System.Drawing.Point(19, 36);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(53, 17);
            this.radioButton1.TabIndex = 0;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "RSA2";
            this.radioButton1.UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(525, 232);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(89, 76);
            this.button1.TabIndex = 7;
            this.button1.Text = "generate key";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // rtb_pb
            // 
            this.rtb_pb.Location = new System.Drawing.Point(132, 195);
            this.rtb_pb.Name = "rtb_pb";
            this.rtb_pb.Size = new System.Drawing.Size(213, 113);
            this.rtb_pb.TabIndex = 6;
            this.rtb_pb.Text = "";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(23, 242);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(69, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "PUBLIC-KEY";
            // 
            // rtb_pv
            // 
            this.rtb_pv.Location = new System.Drawing.Point(132, 65);
            this.rtb_pv.Name = "rtb_pv";
            this.rtb_pv.Size = new System.Drawing.Size(213, 113);
            this.rtb_pv.TabIndex = 4;
            this.rtb_pv.Text = "";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(23, 112);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(77, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "PRIVATE-KEY";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(23, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(42, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "APP ID";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // tb_appid1
            // 
            this.tb_appid1.Location = new System.Drawing.Point(132, 30);
            this.tb_appid1.Name = "tb_appid1";
            this.tb_appid1.Size = new System.Drawing.Size(213, 20);
            this.tb_appid1.TabIndex = 0;
            // 
            // p2
            // 
            this.p2.Controls.Add(this.label8);
            this.p2.Controls.Add(this.tb_name2);
            this.p2.Controls.Add(this.button2);
            this.p2.Controls.Add(this.rtb_pv2);
            this.p2.Controls.Add(this.label6);
            this.p2.Controls.Add(this.label5);
            this.p2.Controls.Add(this.tb_mchid);
            this.p2.Controls.Add(this.label4);
            this.p2.Controls.Add(this.tb_appid2);
            this.p2.Location = new System.Drawing.Point(4, 22);
            this.p2.Name = "p2";
            this.p2.Padding = new System.Windows.Forms.Padding(3);
            this.p2.Size = new System.Drawing.Size(631, 364);
            this.p2.TabIndex = 1;
            this.p2.Text = "Wechat-key";
            this.p2.UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(519, 256);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(89, 76);
            this.button2.TabIndex = 8;
            this.button2.Text = "generate key";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // rtb_pv2
            // 
            this.rtb_pv2.Location = new System.Drawing.Point(130, 157);
            this.rtb_pv2.Name = "rtb_pv2";
            this.rtb_pv2.Size = new System.Drawing.Size(213, 113);
            this.rtb_pv2.TabIndex = 7;
            this.rtb_pv2.Text = "";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(21, 204);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(77, 13);
            this.label6.TabIndex = 6;
            this.label6.Text = "PRIVATE-KEY";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(21, 107);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(45, 13);
            this.label5.TabIndex = 5;
            this.label5.Text = "MCH ID";
            // 
            // tb_mchid
            // 
            this.tb_mchid.Location = new System.Drawing.Point(130, 102);
            this.tb_mchid.Name = "tb_mchid";
            this.tb_mchid.Size = new System.Drawing.Size(213, 20);
            this.tb_mchid.TabIndex = 4;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(21, 49);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(42, 13);
            this.label4.TabIndex = 3;
            this.label4.Text = "APP ID";
            // 
            // tb_appid2
            // 
            this.tb_appid2.Location = new System.Drawing.Point(130, 44);
            this.tb_appid2.Name = "tb_appid2";
            this.tb_appid2.Size = new System.Drawing.Size(213, 20);
            this.tb_appid2.TabIndex = 2;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(364, 32);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(54, 13);
            this.label7.TabIndex = 10;
            this.label7.Text = "Key name";
            // 
            // tb_name1
            // 
            this.tb_name1.Location = new System.Drawing.Point(438, 28);
            this.tb_name1.MaxLength = 20;
            this.tb_name1.Name = "tb_name1";
            this.tb_name1.Size = new System.Drawing.Size(175, 20);
            this.tb_name1.TabIndex = 9;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(359, 50);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(54, 13);
            this.label8.TabIndex = 12;
            this.label8.Text = "Key name";
            // 
            // tb_name2
            // 
            this.tb_name2.Location = new System.Drawing.Point(433, 46);
            this.tb_name2.MaxLength = 20;
            this.tb_name2.Name = "tb_name2";
            this.tb_name2.Size = new System.Drawing.Size(175, 20);
            this.tb_name2.TabIndex = 11;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(663, 424);
            this.Controls.Add(this.tb_ali);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.tb_ali.ResumeLayout(false);
            this.p1.ResumeLayout(false);
            this.p1.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.p2.ResumeLayout(false);
            this.p2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tb_ali;
        private System.Windows.Forms.TabPage p1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox tb_appid1;
        private System.Windows.Forms.TabPage p2;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.RichTextBox rtb_pb;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.RichTextBox rtb_pv;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RichTextBox rtb_pv2;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox tb_mchid;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox tb_appid2;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox tb_name1;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox tb_name2;
    }
}

