
namespace SubwayGUI
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.label_traverse = new System.Windows.Forms.Label();
            this.textBox_traverse = new System.Windows.Forms.TextBox();
            this.button_traverse = new System.Windows.Forms.Button();
            this.label_station = new System.Windows.Forms.Label();
            this.pictureBox_trian = new System.Windows.Forms.PictureBox();
            this.pictureBox_people = new System.Windows.Forms.PictureBox();
            this.pictureBox_stations = new System.Windows.Forms.PictureBox();
            this.pictureBox_logo = new System.Windows.Forms.PictureBox();
            this.pictureBox_map = new System.Windows.Forms.PictureBox();
            this.pictureBox_background = new System.Windows.Forms.PictureBox();
            this.label_shortest = new System.Windows.Forms.Label();
            this.textBox_start = new System.Windows.Forms.TextBox();
            this.textBox_end = new System.Windows.Forms.TextBox();
            this.button_shortest = new System.Windows.Forms.Button();
            this.label_line = new System.Windows.Forms.Label();
            this.textBox_line = new System.Windows.Forms.TextBox();
            this.button_line = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_trian)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_people)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_stations)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_logo)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_map)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_background)).BeginInit();
            this.SuspendLayout();
            // 
            // label_traverse
            // 
            this.label_traverse.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.label_traverse.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label_traverse.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_traverse.Location = new System.Drawing.Point(562, 578);
            this.label_traverse.Name = "label_traverse";
            this.label_traverse.Size = new System.Drawing.Size(107, 25);
            this.label_traverse.TabIndex = 2;
            this.label_traverse.Text = "遍历查询：";
            // 
            // textBox_traverse
            // 
            this.textBox_traverse.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox_traverse.Font = new System.Drawing.Font("宋体", 6.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.textBox_traverse.Location = new System.Drawing.Point(567, 601);
            this.textBox_traverse.Name = "textBox_traverse";
            this.textBox_traverse.Size = new System.Drawing.Size(86, 22);
            this.textBox_traverse.TabIndex = 3;
            this.textBox_traverse.Text = "请输入起始站";
            // 
            // button_traverse
            // 
            this.button_traverse.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.button_traverse.Font = new System.Drawing.Font("微软雅黑", 6.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.button_traverse.Location = new System.Drawing.Point(567, 623);
            this.button_traverse.Name = "button_traverse";
            this.button_traverse.Size = new System.Drawing.Size(53, 27);
            this.button_traverse.TabIndex = 4;
            this.button_traverse.Text = "确认";
            this.button_traverse.UseVisualStyleBackColor = true;
            this.button_traverse.Click += new System.EventHandler(this.button_traverse_Click);
            // 
            // label_station
            // 
            this.label_station.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.label_station.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label_station.Font = new System.Drawing.Font("微软雅黑", 26F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_station.Location = new System.Drawing.Point(805, 572);
            this.label_station.Name = "label_station";
            this.label_station.Size = new System.Drawing.Size(117, 78);
            this.label_station.TabIndex = 9;
            this.label_station.Text = "0";
            // 
            // pictureBox_trian
            // 
            this.pictureBox_trian.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.pictureBox_trian.Image = global::SubwayGUI.Properties.Resources.icon;
            this.pictureBox_trian.Location = new System.Drawing.Point(710, 578);
            this.pictureBox_trian.Name = "pictureBox_trian";
            this.pictureBox_trian.Size = new System.Drawing.Size(63, 58);
            this.pictureBox_trian.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_trian.TabIndex = 8;
            this.pictureBox_trian.TabStop = false;
            // 
            // pictureBox_people
            // 
            this.pictureBox_people.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pictureBox_people.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pictureBox_people.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox_people.Image")));
            this.pictureBox_people.Location = new System.Drawing.Point(124, 554);
            this.pictureBox_people.Name = "pictureBox_people";
            this.pictureBox_people.Size = new System.Drawing.Size(47, 96);
            this.pictureBox_people.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_people.TabIndex = 7;
            this.pictureBox_people.TabStop = false;
            // 
            // pictureBox_stations
            // 
            this.pictureBox_stations.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.pictureBox_stations.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pictureBox_stations.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox_stations.Image")));
            this.pictureBox_stations.Location = new System.Drawing.Point(710, 475);
            this.pictureBox_stations.Name = "pictureBox_stations";
            this.pictureBox_stations.Size = new System.Drawing.Size(212, 100);
            this.pictureBox_stations.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_stations.TabIndex = 6;
            this.pictureBox_stations.TabStop = false;
            // 
            // pictureBox_logo
            // 
            this.pictureBox_logo.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pictureBox_logo.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pictureBox_logo.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox_logo.Image")));
            this.pictureBox_logo.Location = new System.Drawing.Point(445, 0);
            this.pictureBox_logo.Name = "pictureBox_logo";
            this.pictureBox_logo.Size = new System.Drawing.Size(388, 129);
            this.pictureBox_logo.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_logo.TabIndex = 5;
            this.pictureBox_logo.TabStop = false;
            // 
            // pictureBox_map
            // 
            this.pictureBox_map.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pictureBox_map.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pictureBox_map.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox_map.Image")));
            this.pictureBox_map.Location = new System.Drawing.Point(37, 76);
            this.pictureBox_map.Name = "pictureBox_map";
            this.pictureBox_map.Size = new System.Drawing.Size(885, 527);
            this.pictureBox_map.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_map.TabIndex = 1;
            this.pictureBox_map.TabStop = false;
            // 
            // pictureBox_background
            // 
            this.pictureBox_background.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pictureBox_background.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pictureBox_background.Image = global::SubwayGUI.Properties.Resources.whitebackground;
            this.pictureBox_background.Location = new System.Drawing.Point(0, 0);
            this.pictureBox_background.Name = "pictureBox_background";
            this.pictureBox_background.Size = new System.Drawing.Size(961, 659);
            this.pictureBox_background.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_background.TabIndex = 0;
            this.pictureBox_background.TabStop = false;
            // 
            // label_shortest
            // 
            this.label_shortest.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.label_shortest.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label_shortest.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_shortest.Location = new System.Drawing.Point(347, 578);
            this.label_shortest.Name = "label_shortest";
            this.label_shortest.Size = new System.Drawing.Size(129, 25);
            this.label_shortest.TabIndex = 10;
            this.label_shortest.Text = "最短路查询：";
            // 
            // textBox_start
            // 
            this.textBox_start.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox_start.Font = new System.Drawing.Font("宋体", 6.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.textBox_start.Location = new System.Drawing.Point(348, 601);
            this.textBox_start.Name = "textBox_start";
            this.textBox_start.Size = new System.Drawing.Size(91, 22);
            this.textBox_start.TabIndex = 11;
            this.textBox_start.Text = "请输入起始站";
            // 
            // textBox_end
            // 
            this.textBox_end.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox_end.Font = new System.Drawing.Font("宋体", 6.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.textBox_end.Location = new System.Drawing.Point(435, 601);
            this.textBox_end.Name = "textBox_end";
            this.textBox_end.Size = new System.Drawing.Size(93, 22);
            this.textBox_end.TabIndex = 12;
            this.textBox_end.Text = "请输入终点站";
            // 
            // button_shortest
            // 
            this.button_shortest.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.button_shortest.Font = new System.Drawing.Font("微软雅黑", 6.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.button_shortest.Location = new System.Drawing.Point(348, 623);
            this.button_shortest.Name = "button_shortest";
            this.button_shortest.Size = new System.Drawing.Size(52, 27);
            this.button_shortest.TabIndex = 13;
            this.button_shortest.Text = "确认";
            this.button_shortest.UseVisualStyleBackColor = true;
            this.button_shortest.Click += new System.EventHandler(this.button_shortest_Click);
            // 
            // label_line
            // 
            this.label_line.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.label_line.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label_line.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_line.Location = new System.Drawing.Point(207, 578);
            this.label_line.Name = "label_line";
            this.label_line.Size = new System.Drawing.Size(105, 23);
            this.label_line.TabIndex = 14;
            this.label_line.Text = "线路查询：";
            // 
            // textBox_line
            // 
            this.textBox_line.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox_line.Font = new System.Drawing.Font("宋体", 6.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.textBox_line.Location = new System.Drawing.Point(212, 601);
            this.textBox_line.Name = "textBox_line";
            this.textBox_line.Size = new System.Drawing.Size(87, 22);
            this.textBox_line.TabIndex = 15;
            this.textBox_line.Text = "请输入线路名";
            // 
            // button_line
            // 
            this.button_line.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.button_line.Font = new System.Drawing.Font("微软雅黑", 6.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.button_line.Location = new System.Drawing.Point(212, 623);
            this.button_line.Name = "button_line";
            this.button_line.Size = new System.Drawing.Size(50, 27);
            this.button_line.TabIndex = 16;
            this.button_line.Text = "确认";
            this.button_line.UseVisualStyleBackColor = true;
            this.button_line.Click += new System.EventHandler(this.button_line_Click);
            // 
            // Form1
            // 
            this.AllowDrop = true;
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.None;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(961, 659);
            this.Controls.Add(this.textBox_line);
            this.Controls.Add(this.textBox_end);
            this.Controls.Add(this.textBox_start);
            this.Controls.Add(this.textBox_traverse);
            this.Controls.Add(this.button_line);
            this.Controls.Add(this.label_line);
            this.Controls.Add(this.button_shortest);
            this.Controls.Add(this.label_shortest);
            this.Controls.Add(this.label_station);
            this.Controls.Add(this.pictureBox_trian);
            this.Controls.Add(this.label_traverse);
            this.Controls.Add(this.pictureBox_people);
            this.Controls.Add(this.pictureBox_stations);
            this.Controls.Add(this.pictureBox_logo);
            this.Controls.Add(this.button_traverse);
            this.Controls.Add(this.pictureBox_map);
            this.Controls.Add(this.pictureBox_background);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "地铁查询系统";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_trian)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_people)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_stations)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_logo)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_map)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_background)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox_background;
        private System.Windows.Forms.PictureBox pictureBox_map;
        private System.Windows.Forms.Label label_traverse;
        private System.Windows.Forms.TextBox textBox_traverse;
        private System.Windows.Forms.Button button_traverse;
        private System.Windows.Forms.PictureBox pictureBox_logo;
        private System.Windows.Forms.PictureBox pictureBox_stations;
        private System.Windows.Forms.PictureBox pictureBox_people;
        private System.Windows.Forms.PictureBox pictureBox_trian;
        private System.Windows.Forms.Label label_station;
        private System.Windows.Forms.Label label_shortest;
        private System.Windows.Forms.TextBox textBox_start;
        private System.Windows.Forms.TextBox textBox_end;
        private System.Windows.Forms.Button button_shortest;
        private System.Windows.Forms.Label label_line;
        private System.Windows.Forms.TextBox textBox_line;
        private System.Windows.Forms.Button button_line;
    }
}

